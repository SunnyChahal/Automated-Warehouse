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

class Robot : public cpen333::thread::thread_object {
	OrderQueue& orders_;    
	OrderQueue& delivery_;
	int id_;
public:
	/**
	* Create a new robot
	* @param id the robot's id
	* @param orders queue to read orders from
	* @param delivery queue to add found items to
	*/
	Robot(int id, OrderQueue& orders, OrderQueue& delivery) :

		id_(id), orders_(orders), delivery_(delivery) {}

	int id() {
		return id_;
	}

	/**
	* Main execution function
	* @return 0 if completed
	*/
	int main() {
	
		int carrying_capacity=2;                                 //Robot carrying capacity
		int item_picked=0;

		OrderQueue queue(ORDER_QUEUE_NAME, 32);                 //This is the order_queue
		OrderQueue delivery_queue(DELIVERY_QUEUE_NAME, 32);    //This is the delivery queue

		cpen333::process::shared_memory memory("movie1", sizeof(no_items_present));
		no_items_present *data = (no_items_present*)memory.get();

		cpen333::process::shared_object<SharedData> Memory("lab4_maze_runner");//shared memory for warehouse; initilaize it
		
		


		//lock mutex ; unlock mutex
	//	while (item_picked < carrying_capacity) {
			//gets order
		//	for(int i =0;i<2;i++){
		while(true){
			safe_printf("robot %d started \n", id_);
			Order order_in_first_hand = queue.pop();
			safe_printf("robot %d recieved order for first hand \n", id_);
			//Order order_in_second_hand = queue.pop();
			//safe_printf("robot %d recieved order for second hand \n", id_);
		//	std::cout << " Robot "<< id_<< " picked item of type " << order_in_first_hand.type<< " in first hand for client "<< order_in_first_hand.client_id <<std::endl;
		//	std::cout << " Robot " << id_ << " picked item of type " << order_in_second_hand.type << " in second hand for client " << order_in_second_hand.client_id << std::endl;
			safe_printf("robot %d Looking for item in first hand of type %d \n", id_, order_in_first_hand.type);
			//safe_printf("robot %d Looking for item in second hand of type %d \n", id_, order_in_second_hand.type);
			
			if (order_in_first_hand.type == 0) {
				safe_printf("robot %d Looking for chocolate chip in first hand \n", id_);
				safe_printf("robot %d Location column for chocolate chip [type 0] is %d \n", id_, Memory->loc_chocolate_chip[COL_IDX]);
				safe_printf("robot %d Location row for chocolate chip [type 0] is %d \n", id_, Memory->loc_chocolate_chip[ROW_IDX]);
			}
			else if (order_in_first_hand.type == 1) {
				safe_printf("robot %d Looking for arduino in first hand \n", id_);
				safe_printf("robot %d Location column for arduino [type 1] is %d \n", id_, Memory->loc_arduino[COL_IDX]);
				safe_printf("robot %d Location row for arduino [type 1] is %d \n", id_, Memory->loc_arduino[ROW_IDX]);
			}
			else if (order_in_first_hand.type == 2) {
				safe_printf("robot %d Looking for ginger snap in first hand \n", id_);
				safe_printf("robot %d Location column for ginger snap [type 2] is %d \n", id_, Memory->loc_ginger_snap[COL_IDX]);
				safe_printf("robot %d Location row for ginger snap [type 2] is %d \n", id_, Memory->loc_ginger_snap[ROW_IDX]);
			}
			else if (order_in_first_hand.type == 3) {
				safe_printf("robot %d Looking for brush in first hand \n", id_);
				safe_printf("robot %d Location column for brush [type 3] is %d \n", id_, Memory->loc_brush[COL_IDX]);
				safe_printf("robot %d Location row for brush [type 3] is %d \n", id_, Memory->loc_brush[ROW_IDX]);
			}
			else if (order_in_first_hand.type == 4) {
				safe_printf("robot %d Looking for oatmeal_raisin in first hand \n", id_);
				safe_printf("robot %d Location column for oatmeal_raisin [type 4] is %d \n", id_, Memory->loc_oatmeal_raisin[COL_IDX]);
				safe_printf("robot %d Location row for oatmeal_raisin [type 4] is %d \n", id_, Memory->loc_oatmeal_raisin[ROW_IDX]);
			}

			/*if (order_in_second_hand.type == 0) {
				safe_printf("robot %d Looking for chocolate chip in second hand \n", id_);
				safe_printf("robot %d Location column for chocolate chip [type 0] is %d \n", id_, Memory->loc_chocolate_chip[COL_IDX]);
				safe_printf("robot %d Location row for chocolate chip [type 0] is %d \n", id_, Memory->loc_chocolate_chip[ROW_IDX]);
			}
			else if (order_in_second_hand.type == 1) {
				safe_printf("robot %d Looking for arduino in second hand \n", id_);
				safe_printf("robot %d Location column for arduino [type 1] is %d \n", id_, Memory->loc_arduino[COL_IDX]);
				safe_printf("robot %d Location row for arduino [type 1] is %d \n", id_, Memory->loc_arduino[ROW_IDX]);
			}
			else if (order_in_second_hand.type == 2) {
				safe_printf("robot %d Looking for ginger snap in second hand \n", id_);
				safe_printf("robot %d Location column for ginger snap [type 2] is %d \n", id_, Memory->loc_ginger_snap[COL_IDX]);
				safe_printf("robot %d Location row for ginger snap [type 2] is %d \n", id_, Memory->loc_ginger_snap[ROW_IDX]);
			}
			else if (order_in_second_hand.type == 4) {
				safe_printf("robot %d Looking for oatmeal_raisin in second hand \n", id_);
				safe_printf("robot %d Location column for oatmeal_raisin [type 4] is %d \n", id_, Memory->loc_oatmeal_raisin[COL_IDX]);
				safe_printf("robot %d Location row for oatmeal_raisin [type 4] is %d \n", id_, Memory->loc_oatmeal_raisin[ROW_IDX]);
			}*/
			safe_printf("Robot %d is done its job and is going to push the orders \n", id_);
		//	std::cin.get();
		//	item_picked++;
			delivery_queue.push(Order(order_in_first_hand));    //Pushing the order into delivery_queue
			//delivery_queue.push(Order(order_in_second_hand));
			/*Order deli = delivery_queue.pop();
			std::cout << "added was" << order.type;*/
		}

		return 0;
	}
};


#pragma once
#pragma once
