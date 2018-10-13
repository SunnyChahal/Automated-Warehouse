#include <cpen333/process/socket.h>
#include <mutex>
#include <thread>
#include <iostream>
#include <cstring>
#include "socket.h"
#include <cpen333/process/subprocess.h>
#include <cpen333/process/shared_memory.h>
#include <cpen333/thread/thread_object.h>
#include <cpen333/thread/semaphore.h>
#include <thread>
#include <vector>
#include "..\Amazoom (Anushka Trial)\central_computer.h"

/**
* Customers place orders into a queue, wait for them to be
* served, eat, then leave
*/
void service(cpen333::process::socket&& socket) {
	std::cout << "service start" << std::endl;
	cpen333::process::shared_memory memory("movie1", sizeof(no_items_present));    //shared memory for no_items in warehouse
	no_items_present *data = (no_items_present*)memory.get();
	
	// mutex for protecting print statements
	static std::mutex mutex;

	// read buffer
	static const int buffsize = 1024;
	char buff[buffsize + 1];  // extra for terminating \0
	buff[buffsize] = 0;


	// continue reading until the socket disconnects
	size_t read = 0;

	// read a single byte, corresponding to the command
	while ((read = socket.read(buff, 1)) > 0) {
		std::cout << "reading start" << std::endl;
		//    The first byte is a "command", either
		//    - a "hello" which is followed by a name
		//    - a "msg" which is a message from the client
		//    - a "goodbye" which tells us the client is leaving

		if (buff[0] == chat::CMD_MSG) {
			read = socket.read(buff, buffsize);
			std::cout << "LINE ABOVE READ>0" << std::endl;
			if (read > 0) {
				// get message
				buff[read] = 0;
				
				buff[0] = buff[0] - 48;
				int item_id = buff[0];

				if (item_id == 0) {
					std::cout << "the number of chocolate_chip in inventory is " << data->chocolate_chip << std::endl;
				}
				if (item_id == 1) {
					std::cout << "the number of arduino in inventory is " << data->arduino << std::endl;
				}
				if (item_id == 2) {
					std::cout << "the number of ginger_snap in inventory is " << data->ginger_snap << std::endl;
				}
				if (item_id == 3) {
					std::cout << "the number of brush in inventory is " << data->brush << std::endl;
				}
				if (item_id == 4) {
					std::cout << "the number of oatmeal_raisin in inventory is " << data->oatmeal << std::endl;
				}

			}//end if (read>0)
		}//end if chat::cmd::message

		else if (buff[0] == chat::CMD_GOODBYE) {
			mutex.lock();
			std::cout << "Client does not want anything" << std::endl;
			mutex.unlock();
			break;
		}

	}//end while (socket.read)


}// end void service 

int main() {
	// start the server, choose a free port
	cpen333::process::socket_server server(0);
	server.open();
	// obtain the port number and print the address path for our
	// local machine, trying to find an IP address the client
	// can connect to
	int port = server.port();
	std::vector<std::string> address = server.address_lookup();
	std::cout << "List of addresses: " << std::endl;
	for (const auto& add : address) {
		std::cout << "  " << add << std::endl;
	}
	std::cout << std::endl;

	// print best guess of address and port number
	std::cout << "Address: " << address.back() << std::endl;
	std::cout << "Port:    " << port << std::endl;
	std::cout << "Server is running..." << std::endl << std::endl;

	// continuously wait for client connections
	while (true) {
		cpen333::process::socket client;
		if (server.accept(client)) {
			std::thread thread(service, std::move(client));
			std::cout << "new client" << std::endl;
			thread.detach();
		}
	}
	return 0;
}

