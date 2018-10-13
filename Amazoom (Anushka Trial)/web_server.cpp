#include "central_computer.h"
#include <cpen333/process/shared_memory.h>
#include <thread>
#include <iostream>
#include "safe_printf.h"

//Testing for one item at one time right now

int main(int argc, char* argv[]) {

	//Making no_items_present for each item in the inventory shared
	cpen333::process::shared_memory memory("movie1", sizeof(no_items_present));
	no_items_present *data = (no_items_present*)memory.get();
	cpen333::process::shared_object<SharedData> Memory("lab4_maze_runner");//shared memory for warehouse; initilaize it
	// Detect number of each item wanted from command line ; Will later change it to server and client
	int client_id = 0;    //will be client id
	int no_item_wanted=0;   //no of items requested by client

	//How many of each item is wanted ?
	if (argc > 1) {
		no_item_wanted = atoi(argv[1]);
	}
	
	// Detect item type from command line
	ItemType type = ItemType::CHOCOLATE_CHIP;
	if (argc > 2) {
		std::string ctype = argv[2];   // grab type as string
		if (ctype.compare("CHOCOLATE_CHIP") == 0) {
			type = ItemType::CHOCOLATE_CHIP;    // Type =0	
		}
		else if (ctype.compare("ARDUINO") == 0) { //type =1
			type = ItemType::ARDUINO;
		}
		else if (ctype.compare("GINGER_SNAP") == 0) {
			type = ItemType::GINGER_SNAP;      //Type=2		
		}
		else if (ctype.compare("BRUSH") == 0) { //type =3
			type = ItemType::BRUSH;
		}
		else if (ctype.compare("OATMEAL_RAISIN") == 0) { //type=4
			type = ItemType::OATMEAL_RAISIN;
		}
	}

	//adding for client id
	if (argc > 3) {
		client_id = atoi(argv[3]);
	}

	//Declaring orderqueue( i.e. the queue in which order will added )
	OrderQueue queue(ORDER_QUEUE_NAME, 256);
	int i = 0;
	
	//Check for each item if its available -> if available then push it to OrderQueue
	// else alert manager about low  (keep in mind UI)

		if (type == 0) {
			if (no_item_wanted <= data->chocolate_chip) {	    //checking if it is present in stock or not

				while (i < no_item_wanted) {       
					safe_printf("No of chocolate chip present in inventory is %d \n", data->chocolate_chip);
					safe_printf("No of chocolate chip wanted by customer is %d \n", no_item_wanted);
					safe_printf("Adding chocolate chip order to queue \n");
					queue.push(Order(type, client_id, 0));
				//	no_items_added_to_queue++;                 
					data->chocolate_chip--;
					i++;
				}
				
			}
			else {
				safe_printf("No of chocolate chip present in inventory is %d \n", data->chocolate_chip);
				safe_printf("No of chocolate chip wanted by customer is %d \n", no_item_wanted);
				safe_printf("Not enough item chocolate chip -> Alert Manager \n");
				Memory->Low_Stock_Chocolate_Chip = true;
				//Update in shared a boolen which will be accessed using UI

			}
		}
		else if (type == 1) {
			if (no_item_wanted < data->arduino) {
				
				while (i < no_item_wanted) {
					safe_printf("No of arduinos present in inventory is %d \n", data->arduino);
					safe_printf("No of arduinos wanted by customer is %d \n", no_item_wanted);
					safe_printf("Adding arduino order to queue \n");
					queue.push(Order(type, client_id, 0));
				//	no_items_added_to_queue++;
					data->arduino--;
					i++;
				}
			}  
			else {
				safe_printf("No of arduinos present in inventory is %d \n", data->arduino);
				safe_printf("No of arduinos wanted by customer is %d \n", no_item_wanted);
				safe_printf("Not enough item arduinos -> Alert Manager \n");;
				Memory->Low_Stock_Arduino = true;
				//Update in shared a boolen which will be accessed using UI
			}
		}
		else if (type == 2) {
			if (no_item_wanted < data->ginger_snap) {
				
				while (i < no_item_wanted) {
					safe_printf("No of ginger_snap present in inventory is %d \n", data->ginger_snap);
					safe_printf("No of ginger_snap wanted by customer is %d \n", no_item_wanted);
					safe_printf("Adding ginger_snap order to queue \n");
					queue.push(Order(type, client_id, 0));
				//	no_items_added_to_queue++;
					data->ginger_snap--;
					i++;
				}
				//std::cout << "Poppinng order from queue to test " << std::endl;
				//Order order = queue.pop(); //TESTING IF IT WAS ADDED CORRECTLY
				//std::cout << "Item_added to queue is type " << order.type << std::endl;
				//std::cin.get();
			}
			else {
				safe_printf("No of ginger_snap present in inventory is %d \n", data->ginger_snap);
				safe_printf("No of ginger_snap wanted by customer is %d \n", no_item_wanted);
				safe_printf("Not enough item arduinos -> Alert Manager \n");;
				Memory->Low_Stock_Ginger_Snap = true;
				//Update in shared a boolen which will be accessed using UI
			}
		}
		else if (type == 3) {
			if (no_item_wanted < data->brush) {

				while (i < no_item_wanted) {
					safe_printf("No of brush present in inventory is %d \n", data->brush);
					safe_printf("No of brush wanted by customer is %d \n", no_item_wanted);
					safe_printf("Adding brush order to queue \n");
					queue.push(Order(type, client_id, 0));
					//	no_items_added_to_queue++;
					data->brush--;
					i++;
				}
			}
			else {
				safe_printf("No of brush present in inventory is %d \n", data->brush);
				safe_printf("No of brush wanted by customer is %d \n", no_item_wanted);
				safe_printf("Not enough item arduinos -> Alert Manager \n");;
				Memory->Low_Stock_brush = true;
				//Update in shared a boolen which will be accessed using UI				
			}
		}
		else if (type == 4) {
			if (no_item_wanted < data->oatmeal) {
				
				while (i < no_item_wanted) {
					safe_printf("No of oatmeal present in inventory is %d \n", data->oatmeal);
					safe_printf("No of oatmeal wanted by customer is %d \n", no_item_wanted);
					safe_printf("Adding oatmeal order to queue \n");
					queue.push(Order(type, client_id, 0));
				//	no_items_added_to_queue++;
					data->oatmeal--;
					i++;
				}
			}
			else {
				safe_printf("No of oatmeal present in inventory is %d \n", data->oatmeal);
				safe_printf("No of oatmeal wanted by customer is %d \n", no_item_wanted);
				safe_printf("Not enough item arduinos -> Alert Manager \n");;
				Memory->Low_Stock_Oatmeal_Raisins = true;
				//Update in shared a boolen which will be accessed using UI				
			}
		}
		//std::cin.get();
	return 0;
}