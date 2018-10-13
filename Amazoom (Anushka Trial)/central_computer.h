#ifndef CENTRAL_COMPUTER_H
#define CENTRAL_COMPUTER_H
#define LAB4_MAZE_RUNNER_COMMON_H

#define MAZE_MEMORY_NAME "lab4_maze_runner"
#define MAZE_MUTEX_NAME "lab4_maze_runner_mutex"

#define WALL_CHAR 'X'
#define EMPTY_CHAR ' '
#define EXIT_CHAR 'E'

#define COL_IDX 0
#define ROW_IDX 1

#define MAX_MAZE_SIZE 80
#define MAX_RUNNERS   50
#include <thread>
#include <iostream>
#include <string>
#include <cpen333/process/semaphore.h>
#include <cpen333/process/shared_memory.h>
#include <cpen333/process/mutex.h>


// Common name for shared access
#define ORDER_QUEUE_NAME "_order_queue_"
#define DELIVERY_QUEUE_NAME "_delivery_queue_"
#define RESTOCKING_QUEUE_NAME "_restocking_queue_"

// warehouse info////
//structs to hold info for the warehouse location

//similar to maze_runner_common.h//


//stores number of items in inventory;
struct no_items_present {
	int chocolate_chip;
	int arduino;
	int ginger_snap;
	int brush;
	int oatmeal;

	no_items_present(int chocolate_chip, int arduino, int ginger_snap, int brush, int oatmeal) :chocolate_chip(chocolate_chip), arduino(arduino), ginger_snap(ginger_snap), brush(brush), oatmeal(oatmeal) {}
};
// Types of items - 3 types of items;  Need to add more items later
enum ItemType {
	CHOCOLATE_CHIP, ARDUINO, GINGER_SNAP, BRUSH, OATMEAL_RAISIN
};

int no_items_added_to_queue;

//MAZE INFO ---------------------------------

struct MazeInfo {
	int rows;           // rows in maze
	int cols;           // columns in maze
	char maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE];  // maze storage
};

struct SharedData {
	MazeInfo minfo;    // maze info
	bool quit;         // tell everyone to quit
	int magic;          //Second half of part one	
	int loc_chocolate_chip[2];
	int loc_arduino[2];
	int loc_ginger_snap[2];
	int loc_brush[2];
	int loc_oatmeal_raisin[2];
	bool delivery_truck_arrival; //for delivery truck arrived
	bool restocking_truck_arrival;  //for restocking truck arrived
	bool Low_Stock_Oatmeal_Raisins;
	bool Low_Stock_Chocolate_Chip;
	bool Low_Stock_Ginger_Snap;
	bool Low_Stock_brush;
	bool Low_Stock_Arduino;
};
//MAZE INFO ENDS HERE-----------------------------------------

// Data type for our queue
struct Order {
	ItemType type;
	int robot_id;      //Not sure if we need robot id
	int client_id;     // Will need it when we move to part 2

					   // Initializing the struct 
	Order(ItemType type, int client_id, int robot_id) :
		type(type), client_id(client_id), robot_id(robot_id) {}
};

// Circular buffer with semaphores to control access
class OrderQueue {
protected:
	struct QueueInfo {
		size_t pidx;  // next index to put information at
		size_t cidx;  // next index to consume information from
		size_t size;  // size of circular buffer, in # of elements
		int initialized;    // magic number for detecting if memory is initialized
	};

	cpen333::process::shared_memory memory_;   // actual memory
	QueueInfo* info_;                          // pointer to queue information, will be at start of memory_
	Order* data_;                             // pointer to data in queue (in this case, orders), after info_ in memory
	cpen333::process::mutex pmutex_;           // mutex for protecting memory modified by producers
	cpen333::process::mutex cmutex_;           // mutex for protecting memory modified by consumers
	cpen333::process::semaphore psem_;         // semaphore controlling when producer can add a cookie
	cpen333::process::semaphore csem_;         //     "            "         consumer can remove a cookie

public:


	OrderQueue(const std::string& name, size_t size) :
		memory_(name + std::string("_memory_"), sizeof(QueueInfo) + size * sizeof(Order)), // reserve memory
		info_(nullptr), data_(nullptr), // will initialize these after memory valid
		pmutex_(name + std::string("_pmutex_")),
		cmutex_(name + std::string("_cmutex_")),
		psem_(name + std::string("_psem_"), size),  // start at size of queue
		csem_(name + std::string("_csem_"), 0) {    // start at zero

													// info is at start of memory block, followed by the actual data in the queue
		info_ = (QueueInfo*)memory_.get();
		data_ = (Order*)memory_.get(sizeof(QueueInfo));  // start of queue data is after Queue info

														 // protect memory with a mutex (either one) to check if data is initialized, and initialize if not
														 // This is only to stop multiple constructors from simultaneously trying to initialize data
		std::lock_guard<cpen333::process::mutex> lock(pmutex_);
		if (info_->initialized != 0x12345678) {
			info_->pidx = 0;
			info_->cidx = 0;
			info_->size = size;
			info_->initialized = 0x12345678;  // mark initialized
		}
	}

	// add order to queue
	void push(const Order &ordered_item) {

		//Wait until there is room to push an order into the queue
		psem_.wait();

		size_t loc = 0;
		{
			// look at index, protect memory from multiple simultaneous pushes
			std::lock_guard<cpen333::process::mutex> lock(pmutex_);
			loc = info_->pidx;
			// increment producer index for next cookie, wrap around if at end
			if ((++info_->pidx) == info_->size) {
				info_->pidx = 0;
			}
			// lock will unlock here as guard runs out of scope
		}

		data_[loc] = ordered_item;  // add item to queue

		csem_.notify();            // let consumer know a cookie is available

	}

	Order pop() {

		// wait until cookie available
		csem_.wait();

		size_t loc = 0;  // will store location of cookie to take
		{
			// look at index, protect memory from multiple simultaneous pops
			std::lock_guard<cpen333::process::mutex> lock(cmutex_);
			loc = info_->cidx;

			// increment consumer index for next cookie, wrap around if at end
			if ((++info_->cidx) == info_->size) {
				info_->cidx = 0;
			}
			// lock will unlock here as guard runs out of scope
		}


		Order ordered_item = data_[loc];  // take order out

										  // let producer know that we are done with the slot
		psem_.notify();

		return ordered_item;

	}

	size_t size() {
		std::lock_guard<cpen333::process::mutex> lock1(pmutex_);
		std::lock_guard<cpen333::process::mutex> lock2(cmutex_);

		if (info_->pidx < info_->cidx) {
			return info_->size - info_->cidx + info_->pidx;
		}
		return info_->pidx - info_->cidx;
	}
};


#endif 
