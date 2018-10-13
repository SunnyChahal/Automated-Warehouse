#pragma once
#include "..\Amazoom (Anushka Trial)\central_computer.h"
#include <cpen333/process/socket.h>
#include <mutex>
#include <thread>
#include <iostream>
#include <cstring>
#include <cpen333/process/shared_memory.h>
#include <cpen333/thread/thread_object.h>
#include <cpen333/thread/semaphore.h>
#include <thread>
#include <vector>
#include "safe_printf.h"
class Delivery : public cpen333::thread::thread_object {
	OrderQueue& delivery_;
	int id_;cpen333::thread::semaphore loading_bay;
public:
	
//adding a semaphore in the constructor
	Delivery( int id, cpen333::thread::semaphore &loading_bay, OrderQueue& delivery) :

		loading_bay(1),id_(id), delivery_(delivery) {}

	int id() {
		return id_;
	}

	/**
	* Main execution function
	* @return 0 if completed
	*/
	int main() {
		int truck_capacity = 3;
		int no_items_packed_for_client_1 = 0;
		int no_items_packed_for_client_2 = 0;
		int no_items_packed_for_client_3 = 0;
		int no_items_packed_for_client_4 = 0;
		int no_items_packed_for_client_5 = 0;
		int no_items_packed_for_client_6 = 0;
		OrderQueue delivery_queue(DELIVERY_QUEUE_NAME, 32);    //This is the delivery queue
		cpen333::process::shared_memory memory("movie1", sizeof(no_items_present));
		no_items_present *data = (no_items_present*)memory.get();
		cpen333::process::shared_object<SharedData> Memory("lab4_maze_runner");
		

		while (true) {
			int i = 0;
			no_items_packed_for_client_1 = 0;
			no_items_packed_for_client_2 = 0;
			no_items_packed_for_client_3 = 0;
			no_items_packed_for_client_4 = 0;
			no_items_packed_for_client_5 = 0;
			no_items_packed_for_client_6 = 0;
			/////// loading bay wait
			loading_bay.wait();
			safe_printf("Delivery truck is waiting at the dock \n");
			safe_printf("Notifying central computer \n");
			Memory->delivery_truck_arrival = true; //notifying central computer of its arrival
			////have some kind of if loop to make sure that all items are getting popped
			//Order order_1 = delivery_queue.pop();    //execution after accessing 
			//std::cout << "Popped item 1 is of type" << order_1.type <<std::endl;
			//Order order_2 = delivery_queue.pop();    //execution after accessing 
			//std::cout << "Popped item 2 is of type" << order_2.type << std::endl;
			//Order order_3 = delivery_queue.pop();    //execution after accessing 
			//std::cout << "Popped item 3 is of type" << order_3.type << std::endl;
			//Order order_4 = delivery_queue.pop();    //execution after accessing 
			//std::cout << "Popped item 4 is of type" << order_4.type << std::endl;
			//std::cout << "Order for client" << order_4.client_id << std::endl;

				//----------------------------------------packing implementation--------------------//
			while (i < truck_capacity) {
				Order order_1 = delivery_queue.pop();
				safe_printf("item of type %d is being packed for %d \n", order_1.type, order_1.client_id);
				if (order_1.client_id == 1) {
					no_items_packed_for_client_1++;
				}
				if (order_1.client_id == 2) {
					no_items_packed_for_client_2++;
				}
				if (order_1.client_id == 3) {
					no_items_packed_for_client_3++;
				}
				if (order_1.client_id == 4) {
					no_items_packed_for_client_4++;
				}
				if (order_1.client_id == 5) {
					no_items_packed_for_client_5++;
				}
				if (order_1.client_id == 6) {
					no_items_packed_for_client_6++;
				}
				i++;
			}
			safe_printf("Truck capacity is full");
			safe_printf("The truck is leaving with %d items for client 1 \n %d items for client 2 \n %d items for client 3 \n %d items for client 4 \n %d items for client 5 \n %d items for client 6 \n", no_items_packed_for_client_1, no_items_packed_for_client_2, no_items_packed_for_client_3, no_items_packed_for_client_4, no_items_packed_for_client_5, no_items_packed_for_client_6);
			safe_printf("Items are being delivered now");
			///// loading bay notify 
			loading_bay.notify();
			// std:: cin.get();
		}
			return 0;
		}
	
};


#pragma once

