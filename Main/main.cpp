#include <iostream>
#include <thread>
#include "..\Amazoom (Anushka Trial)\central_computer.h"
#include <cpen333/util.h>
#include <cpen333/process/subprocess.h>
#include <cpen333/process/shared_memory.h>
#include "robot.h"
#include "Delivery_Truck.h"
#include "Restocking_Truck.h"
#include <fstream>
#include <cpen333/thread/semaphore.h>
#include "safe_printf.h"
/**
* Reads a maze from a filename and populates the maze
* @param filename file to load maze from
* @param minfo maze info to populate
*/
void load_maze(const std::string& filename, MazeInfo& minfo) {
	// initialize number of rows and columns
	minfo.rows = 0;
	minfo.cols = 0;
	std::ifstream fin(filename);
	std::string line;
	// read maze file
	if (fin.is_open()) {
		//	std::cout << "file open" << std::endl;
		int row = 0;  // zeroeth row
		while (std::getline(fin, line)) {
			int cols = line.length();
			if (cols > 0) {
				// longest row defines columns
				if (cols > minfo.cols) {
					minfo.cols = cols;
				}
				for (size_t col = 0; col<cols; ++col) {
					minfo.maze[col][row] = line[col];
				}
				++row;
			}
		}
		minfo.rows = row;
		std::cout << "numCols: " << minfo.cols << std::endl;
		std::cout << "numRows: " << minfo.rows << std::endl;
		fin.close();
	}
}

int main(int argc, char* argv[]) {

	
	OrderQueue queue(ORDER_QUEUE_NAME, 32);             // OrderQueue
	OrderQueue delivery_queue(DELIVERY_QUEUE_NAME, 32); // DeliveryQueue
	OrderQueue restock_queue(RESTOCKING_QUEUE_NAME, 32);             // OrderQueue

	cpen333::process::shared_memory memory("movie1", sizeof(no_items_present));    //shared memory for no_items in warehouse
	no_items_present *data = (no_items_present*)memory.get();   
	data->arduino = 5;                                      //Initializing no of items in inventory
	data->chocolate_chip = 5;
	data->ginger_snap = 5;
	data->brush = 5;
	data->oatmeal = 5;

	//adding semaphore for loading bat for trucks
	cpen333::thread::semaphore loading_bay(1);	
	std::string maze = "data/maze0.txt"; // CHANGE IT FOR DIFFERENT WAREHOUSE LAYOUTS :// read maze from command-line, default to maze0
	if (argc > 1) {
		maze = argv[1];
	}
	cpen333::process::shared_object<SharedData> Memory("lab4_maze_runner");//shared memory for warehouse; initilaize it
	Memory->loc_chocolate_chip[COL_IDX] = -1;
	Memory->loc_chocolate_chip[ROW_IDX] = -1;
	Memory->loc_arduino[COL_IDX] = -1;
	Memory->loc_arduino[ROW_IDX] = -1;
	Memory->loc_ginger_snap[COL_IDX] = -1;
	Memory->loc_ginger_snap[ROW_IDX] = -1;
	Memory->loc_brush[COL_IDX] = -1;
	Memory->loc_brush[ROW_IDX] = -1;
	Memory->loc_oatmeal_raisin[COL_IDX] = -1;
	Memory->loc_oatmeal_raisin[ROW_IDX] = -1;

	Memory->magic = 0x0000EFE0;
	
    //loading warehouse layout and retrieving location for each type and tsoring it in shared memory 
	load_maze(maze, Memory->minfo); //LOADING MAZE FILE 
	int nrows = Memory->minfo.rows;           // getting number of rows
	int ncols = Memory->minfo.cols;           //getting number of columns
	for (int j = 0; j < nrows; j++) {                     //checking every row 
		for (int i = 0; i < ncols; i++) {              //checking all the columns for each row and then after checking all the columns for every row and then increment row
													   //mutex_.lock();                       //mutex lock
			if (Memory->minfo.maze[i][j] == '0') {
				Memory->loc_chocolate_chip[COL_IDX] = i;
				Memory->loc_chocolate_chip[ROW_IDX] = j;
			}
			//		//mutex_.unlock(); //mutex unlock
		}
	}

	for (int j = 0; j < nrows; j++) {                     //checking every row 
		for (int i = 0; i < ncols; i++) {              //checking all the columns for each row and then after checking all the columns for every row and then increment row
													   //mutex_.lock();                       //mutex lock
			if (Memory->minfo.maze[i][j] == '1') {
				Memory->loc_arduino[COL_IDX] = i;
				Memory->loc_arduino[ROW_IDX] = j;
			}
			//		//mutex_.unlock(); //mutex unlock
		}
	}
	for (int j = 0; j < nrows; j++) {                     //checking every row 
		for (int i = 0; i < ncols; i++) {              //checking all the columns for each row and then after checking all the columns for every row and then increment row
													   //mutex_.lock();                       //mutex lock
			if (Memory->minfo.maze[i][j] == '2') {
				Memory->loc_ginger_snap[COL_IDX] = i;
				Memory->loc_ginger_snap[ROW_IDX] = j;
			}
			//		//mutex_.unlock(); //mutex unlock
		}
	}
	for (int j = 0; j < nrows; j++) {                     //checking every row 
		for (int i = 0; i < ncols; i++) {              //checking all the columns for each row and then after checking all the columns for every row and then increment row
													   //mutex_.lock();                       //mutex lock
			if (Memory->minfo.maze[i][j] == '3') {
				Memory->loc_brush[COL_IDX] = i;
				Memory->loc_brush[ROW_IDX] = j;
			}
			//		//mutex_.unlock(); //mutex unlock
		}
	}
	for (int j = 0; j < nrows; j++) {                     //checking every row 
		for (int i = 0; i < ncols; i++) {              //checking all the columns for each row and then after checking all the columns for every row and then increment row
													   //mutex_.lock();                       //mutex lock
			if (Memory->minfo.maze[i][j] == '4') {
				Memory->loc_oatmeal_raisin[COL_IDX] = i;
				Memory->loc_oatmeal_raisin[ROW_IDX] = j;
			}
			//		//mutex_.unlock(); //mutex unlock
		}
	}

	

	//Memory->quit = true; //
	//Memory->magic = NULL;


	//We will replace this with a server
	//Each process instantiation orders a certain of each type of item ; will change it client server later
	//cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 CHOCOLATE_CHIP 1 ", true, true); //ordering 3 chocolate chips
	//cpen333::process::subprocess web_server2("Amazoom (Anushka Trial).exe 2 ARDUINO 1", true, true);
	//cpen333::process::subprocess web_server3("Amazoom (Anushka Trial).exe 1 GINGER_SNAP 2", true, true);	
//	cpen333::process::subprocess web_server4("Amazoom (Anushka Trial).exe 4 ARDUINO", true, true);

	//CODE FOR MAZE STARTS HERE
	
    //creating a vector for robot threads 
	std::vector<Robot*> robots;      
	//number of robots ; need to change it to dynamic later
	const int nrobots = 4;          

	//creating a vector for delivery_trucks
	std::vector <Delivery*> delivery_trucks;
	const int nd_trucks = 1;
	std::vector <Restocking*> restocking_trucks;
    //////////////------------ROBOTS------------------------------
	for (int i = 0; i < nrobots; ++i) {
		robots.push_back(new Robot(i, queue, delivery_queue));
	}
	for (int i = 0; i < nd_trucks; ++i) {
		delivery_trucks.push_back(new Delivery (i, std::ref(loading_bay), delivery_queue));
	}
	for (int i = 0; i < nd_trucks; ++i) {
		restocking_trucks.push_back(new Restocking( std::ref(loading_bay)));
	}
	for (auto& robot : robots) {
		robot->start();
	}
	for (auto& d_truck : delivery_trucks) {
		d_truck->start();
	}
	for (auto& r_truck : restocking_trucks) {
		r_truck->start();
	}
	
	for (auto& robot : robots) {
		robot->join();
	}
	for (auto& d_truck : delivery_trucks) {
		d_truck->join();
	}
	for (auto& r_truck : restocking_trucks) {
		r_truck->join();
	}
	for (auto& robot : robots) {
		delete robot;
		robot = nullptr;
	}
	
	for (auto& d_truck : delivery_trucks) {
		delete d_truck;
		d_truck = nullptr;
	}
	for (auto& r_truck : restocking_trucks) {
		delete r_truck;
		r_truck = nullptr;
	}


    //Join server
	//web_server1.join();
	//web_server2.join();
	//web_server3.join();
	
	
	//std::cout << "Goodbye." << std::endl;
	cpen333::pause();

	return 0;
}