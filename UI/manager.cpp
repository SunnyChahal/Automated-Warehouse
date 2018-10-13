#include <cpen333/process/socket.h>
#include <limits>
#include "socket.h"

// Simple chat client using sockets
int main() {

	// Address and port to connect to
	std::string server;
	int port;

	std::cout << "Enter address: ";
	std::cin >> server;
	std::cout << "Enter port:    ";
	std::cin >> port;
	std::cout << std::endl;

	// ignore the newline after we read a port, otherwise will
	//  interfere with reading a name
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	{
		// create a socket and connect to server
		cpen333::process::socket client(server, port);
		client.open();
		std::cout << "Connected to server." << std::endl << std::endl;


		std::string ITEM;

		std::cout << std::endl << "Enter \"quit\" to exit" << std::endl << std::endl;

		// send messages to server
		do {
			std::cout << "         *************************************************           " << std::endl;
			std::cout << "                   Hello Manager!                     " << std::endl;
			std::cout << "         *************************************************           " << std::endl;
			std::cout << "You can check the inventory here!" << std::endl;
			std::cout << "         *************************************************           " << std::endl;
			std::cout << "Item no.0 is CHOCOLATE_CHIP, press 0 to check it's stock " << std::endl;
			std::cout << "Item no.1 is ARDUINO, press 1 to check it's stock" << std::endl;
			std::cout << "Item no.2 is GINGER_SNAP, press 2 to check it's stock" << std::endl;
			std::cout << "Item no.3 is BRUSH, press 3 to check it's stock" << std::endl;
			std::cout << "Item no.4 is OATMEAL_RAISIN, press 4 to check it's stock" << std::endl;
			std::cout << "         *************************************************           " << std::endl;

			std::getline(std::cin, ITEM);

			// if message is "quit", send goodbye command
			if (ITEM == "quit") {
				client.write(&chat::CMD_GOODBYE, 1);
				break;
			}

			// otherwise, write a message
			client.write(&chat::CMD_MSG, 1);
			client.write(ITEM);
		} while (true);

		client.close();
	}

	cpen333::pause();
	return 0;
}