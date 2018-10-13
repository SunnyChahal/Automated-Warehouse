
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

//This thread will only be started when there is low stock
//activate bool for low stock
//getting items from delivery queue and 

class Restocking : public cpen333::thread::thread_object {
	
	 cpen333::thread::semaphore loading_bay;
public:
	
	Restocking(cpen333::thread::semaphore &loading_bay) :

		loading_bay(1) {}

	

	/**
	* Main execution function
	* @return 0 if completed
	*/
	int main() {

		
	
		cpen333::process::shared_memory memory("movie1", sizeof(no_items_present));
		no_items_present *data = (no_items_present*)memory.get();
		cpen333::process::shared_object<SharedData> Memory("lab4_maze_runner");//shared memory for warehouse; initilaize it
		while (true) {
			loading_bay.wait();
			if (Memory->Low_Stock_Arduino == true) {
				data->arduino = 5;
				safe_printf("Restocking arduinos \n");
				safe_printf("Restocked %d arduinos \n", data->arduino);
				Memory->Low_Stock_Arduino = false;
			}
			if (Memory->Low_Stock_Chocolate_Chip == true) {
				data->chocolate_chip = 5;
				safe_printf("Restocking chocolate_chip \n");
				safe_printf("Restocked %d chocolate_chip \n", data->chocolate_chip);
				Memory->Low_Stock_Chocolate_Chip = false;
			}
			if (Memory->Low_Stock_Oatmeal_Raisins == true) {
				data->oatmeal = 5;
				safe_printf("Restocking oatmeal \n");
				safe_printf("Restocked %d oatmeal \n", data->oatmeal);
				Memory->Low_Stock_Oatmeal_Raisins = false;
			}
			if (Memory->Low_Stock_brush == true) {
				data->oatmeal = 5;
				safe_printf("Restocking brush \n");
				safe_printf("Restocked %d brush \n", data->brush);
				Memory->Low_Stock_Oatmeal_Raisins = false;
			}
			if (Memory->Low_Stock_Ginger_Snap == true) {
				data->ginger_snap = 5;
				safe_printf("Restocking ginger_snap \n");
				safe_printf("Restocked %d ginger_snap \n", data->ginger_snap);
				Memory->Low_Stock_Ginger_Snap = false;
			}
			loading_bay.notify();
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
	
		



		return 0;
	}
};


#pragma once
#pragma once
