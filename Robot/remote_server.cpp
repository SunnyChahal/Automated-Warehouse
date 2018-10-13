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
				//mutex.lock();
				std::cout << "Client ordered items : " << buff << std::endl;

				int client_id = buff[0] - 48;
				int no_chocolate_chip_wanted = buff[2] - 48;  
				int no_arduino_wanted = buff[6] - 48;
				int	no_ginger_snap_wanted = buff[10] - 48;
				int no_brush_wanted = buff[14] - 48;
				int	no_oatmeal_raisin_wanted = buff[18] - 48;



				//order for first client
				if (client_id == 1) {
					if (no_chocolate_chip_wanted != 0) {
						if (no_chocolate_chip_wanted == 1) {
							std::cout << "order recieved in remote server" << std::endl;
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 CHOCOLATE_CHIP 1 ", true, true);
							//web_server1.join();
							//std::cin.get();
						}
						if (no_chocolate_chip_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 CHOCOLATE_CHIP 1 ", true, true);
						}
						if (no_chocolate_chip_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 CHOCOLATE_CHIP 1 ", true, true);
						}
						if (no_chocolate_chip_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 CHOCOLATE_CHIP 1 ", true, true);
						}
						if (no_chocolate_chip_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 CHOCOLATE_CHIP 1 ", true, true);
						}
						if (no_chocolate_chip_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 CHOCOLATE_CHIP 1 ", true, true);
						}
						if (no_chocolate_chip_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 CHOCOLATE_CHIP 1 ", true, true);
						}
						if (no_chocolate_chip_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 CHOCOLATE_CHIP 1 ", true, true);
						}
						if (no_chocolate_chip_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 CHOCOLATE_CHIP 1 ", true, true);
						}
						if (no_chocolate_chip_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 CHOCOLATE_CHIP 1 ", true, true);
						}

					}

					if (no_arduino_wanted != 0) {
						if (no_arduino_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 ARDUINO 1 ", true, true);
						}
						if (no_arduino_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 ARDUINO 1 ", true, true);
						}
						if (no_arduino_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 ARDUINO 1 ", true, true);
						}
						if (no_arduino_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 ARDUINO 1 ", true, true);
						}
						if (no_arduino_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 ARDUINO 1 ", true, true);
						}
						if (no_arduino_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 ARDUINO 1 ", true, true);
						}
						if (no_arduino_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 ARDUINO 1 ", true, true);
						}
						if (no_arduino_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 ARDUINO 1 ", true, true);
						}
						if (no_arduino_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 ARDUINO 1 ", true, true);
						}
						if (no_arduino_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 ARDUINO 1 ", true, true);
						}

					}

					if (no_ginger_snap_wanted != 0) {
						if (no_ginger_snap_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 GINGER_SNAP 1 ", true, true);
						}
						if (no_ginger_snap_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 GINGER_SNAP 1 ", true, true);
						}
						if (no_ginger_snap_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 GINGER_SNAP 1 ", true, true);
						}
						if (no_ginger_snap_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 GINGER_SNAP 1 ", true, true);
						}
						if (no_ginger_snap_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 GINGER_SNAP 1 ", true, true);
						}
						if (no_ginger_snap_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 GINGER_SNAP 1 ", true, true);
						}
						if (no_ginger_snap_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 GINGER_SNAP 1 ", true, true);
						}
						if (no_ginger_snap_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 GINGER_SNAP 1 ", true, true);
						}
						if (no_ginger_snap_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 GINGER_SNAP 1 ", true, true);
						}
						if (no_ginger_snap_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 GINGER_SNAP 1 ", true, true);
						}

					}

					if (no_brush_wanted != 0) {
						if (no_brush_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 BRUSH 1 ", true, true);
						}
						if (no_brush_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 BRUSH 1 ", true, true);
						}
						if (no_brush_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 BRUSH 1 ", true, true);
						}
						if (no_brush_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 BRUSH 1 ", true, true);
						}
						if (no_brush_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 BRUSH 1 ", true, true);
						}
						if (no_brush_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 BRUSH 1 ", true, true);
						}
						if (no_brush_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 BRUSH 1 ", true, true);
						}
						if (no_brush_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 BRUSH 1 ", true, true);
						}
						if (no_brush_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 BRUSH 1 ", true, true);
						}
						if (no_brush_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 BRUSH 1 ", true, true);
						}

					}

					if (no_oatmeal_raisin_wanted != 0) {
						if (no_oatmeal_raisin_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 OATMEAL_RAISIN 1 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 OATMEAL_RAISIN 1 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 OATMEAL_RAISIN 1 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 OATMEAL_RAISIN 1 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 OATMEAL_RAISIN 1 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 OATMEAL_RAISIN 1 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 OATMEAL_RAISIN 1 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 OATMEAL_RAISIN 1 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 OATMEAL_RAISIN 1 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 OATMEAL_RAISIN 1 ", true, true);
						}

					}
				}

				//order for second client
				if (client_id == 2) {
					if (no_chocolate_chip_wanted != 0) {
						if (no_chocolate_chip_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 CHOCOLATE_CHIP 2 ", true, true);
						}
						if (no_chocolate_chip_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 CHOCOLATE_CHIP 2 ", true, true);
						}
						if (no_chocolate_chip_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 CHOCOLATE_CHIP 2 ", true, true);
						}
						if (no_chocolate_chip_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 CHOCOLATE_CHIP 2 ", true, true);
						}
						if (no_chocolate_chip_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 CHOCOLATE_CHIP 2 ", true, true);
						}
						if (no_chocolate_chip_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 CHOCOLATE_CHIP 2 ", true, true);
						}
						if (no_chocolate_chip_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 CHOCOLATE_CHIP 2 ", true, true);
						}
						if (no_chocolate_chip_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 CHOCOLATE_CHIP 2 ", true, true);
						}
						if (no_chocolate_chip_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 CHOCOLATE_CHIP 2 ", true, true);
						}
						if (no_chocolate_chip_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 CHOCOLATE_CHIP 2 ", true, true);
						}

					}

					if (no_arduino_wanted != 0) {
						if (no_arduino_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 ARDUINO 2 ", true, true);
						}
						if (no_arduino_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 ARDUINO 2 ", true, true);
						}
						if (no_arduino_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 ARDUINO 2 ", true, true);
						}
						if (no_arduino_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 ARDUINO 2 ", true, true);
						}
						if (no_arduino_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 ARDUINO 2 ", true, true);
						}
						if (no_arduino_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 ARDUINO 2 ", true, true);
						}
						if (no_arduino_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 ARDUINO 2 ", true, true);
						}
						if (no_arduino_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 ARDUINO 2 ", true, true);
						}
						if (no_arduino_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 ARDUINO 2 ", true, true);
						}
						if (no_arduino_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 ARDUINO 2 ", true, true);
						}

					}

					if (no_ginger_snap_wanted != 0) {
						if (no_ginger_snap_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 GINGER_SNAP 2 ", true, true);
						}
						if (no_ginger_snap_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 GINGER_SNAP 2 ", true, true);
						}
						if (no_ginger_snap_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 GINGER_SNAP 2 ", true, true);
						}
						if (no_ginger_snap_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 GINGER_SNAP 2 ", true, true);
						}
						if (no_ginger_snap_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 GINGER_SNAP 2 ", true, true);
						}
						if (no_ginger_snap_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 GINGER_SNAP 2 ", true, true);
						}
						if (no_ginger_snap_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 GINGER_SNAP 2 ", true, true);
						}
						if (no_ginger_snap_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 GINGER_SNAP 2 ", true, true);
						}
						if (no_ginger_snap_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 GINGER_SNAP 2 ", true, true);
						}
						if (no_ginger_snap_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 GINGER_SNAP 2 ", true, true);
						}

					}

					if (no_brush_wanted != 0) {
						if (no_brush_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 BRUSH 2 ", true, true);
						}
						if (no_brush_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 BRUSH 2 ", true, true);
						}
						if (no_brush_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 BRUSH 2 ", true, true);
						}
						if (no_brush_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 BRUSH 2 ", true, true);
						}
						if (no_brush_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 BRUSH 2 ", true, true);
						}
						if (no_brush_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 BRUSH 2 ", true, true);
						}
						if (no_brush_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 BRUSH 2 ", true, true);
						}
						if (no_brush_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 BRUSH 2 ", true, true);
						}
						if (no_brush_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 BRUSH 2 ", true, true);
						}
						if (no_brush_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 BRUSH 2 ", true, true);
						}

					}

					if (no_oatmeal_raisin_wanted != 0) {
						if (no_oatmeal_raisin_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 OATMEAL_RAISIN 2 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 OATMEAL_RAISIN 2 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 OATMEAL_RAISIN 2 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 OATMEAL_RAISIN 2 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 OATMEAL_RAISIN 2 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 OATMEAL_RAISIN 2 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 OATMEAL_RAISIN 2 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 OATMEAL_RAISIN 2 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 OATMEAL_RAISIN 2 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 OATMEAL_RAISIN 2 ", true, true);
						}

					}
				}


				//order for third client
				if (client_id == 3) {
					if (no_chocolate_chip_wanted != 0) {
						if (no_chocolate_chip_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 CHOCOLATE_CHIP 3 ", true, true);
						}
						if (no_chocolate_chip_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 CHOCOLATE_CHIP 3 ", true, true);
						}
						if (no_chocolate_chip_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 CHOCOLATE_CHIP 3 ", true, true);
						}
						if (no_chocolate_chip_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 CHOCOLATE_CHIP 3 ", true, true);
						}
						if (no_chocolate_chip_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 CHOCOLATE_CHIP 3 ", true, true);
						}
						if (no_chocolate_chip_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 CHOCOLATE_CHIP 3 ", true, true);
						}
						if (no_chocolate_chip_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 CHOCOLATE_CHIP 3 ", true, true);
						}
						if (no_chocolate_chip_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 CHOCOLATE_CHIP 3 ", true, true);
						}
						if (no_chocolate_chip_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 CHOCOLATE_CHIP 3 ", true, true);
						}
						if (no_chocolate_chip_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 CHOCOLATE_CHIP 3 ", true, true);
						}

					}

					if (no_arduino_wanted != 0) {
						if (no_arduino_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 ARDUINO 3 ", true, true);
						}
						if (no_arduino_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 ARDUINO 3 ", true, true);
						}
						if (no_arduino_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 ARDUINO 3 ", true, true);
						}
						if (no_arduino_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 ARDUINO 3 ", true, true);
						}
						if (no_arduino_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 ARDUINO 3 ", true, true);
						}
						if (no_arduino_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 ARDUINO 3 ", true, true);
						}
						if (no_arduino_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 ARDUINO 3 ", true, true);
						}
						if (no_arduino_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 ARDUINO 3 ", true, true);
						}
						if (no_arduino_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 ARDUINO 3 ", true, true);
						}
						if (no_arduino_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 ARDUINO 3 ", true, true);
						}

					}

					if (no_ginger_snap_wanted != 0) {
						if (no_ginger_snap_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 GINGER_SNAP 3 ", true, true);
						}
						if (no_ginger_snap_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 GINGER_SNAP 3 ", true, true);
						}
						if (no_ginger_snap_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 GINGER_SNAP 3 ", true, true);
						}
						if (no_ginger_snap_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 GINGER_SNAP 3 ", true, true);
						}
						if (no_ginger_snap_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 GINGER_SNAP 3 ", true, true);
						}
						if (no_ginger_snap_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 GINGER_SNAP 3 ", true, true);
						}
						if (no_ginger_snap_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 GINGER_SNAP 3 ", true, true);
						}
						if (no_ginger_snap_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 GINGER_SNAP 3 ", true, true);
						}
						if (no_ginger_snap_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 GINGER_SNAP 3 ", true, true);
						}
						if (no_ginger_snap_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 GINGER_SNAP 3 ", true, true);
						}

					}
					
					if (no_brush_wanted != 0) {
						if (no_brush_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 BRUSH 3 ", true, true);
						}
						if (no_brush_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 BRUSH 3 ", true, true);
						}
						if (no_brush_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 BRUSH 3 ", true, true);
						}
						if (no_brush_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 BRUSH 3 ", true, true);
						}
						if (no_brush_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 BRUSH 3 ", true, true);
						}
						if (no_brush_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 BRUSH 3 ", true, true);
						}
						if (no_brush_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 BRUSH 3 ", true, true);
						}
						if (no_brush_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 BRUSH 3 ", true, true);
						}
						if (no_brush_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 BRUSH 3 ", true, true);
						}
						if (no_brush_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 BRUSH 3 ", true, true);
						}

					}

					if (no_oatmeal_raisin_wanted != 0) {
						if (no_oatmeal_raisin_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 OATMEAL_RAISIN 3 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 OATMEAL_RAISIN 3 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 OATMEAL_RAISIN 3 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 OATMEAL_RAISIN 3 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 OATMEAL_RAISIN 3 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 OATMEAL_RAISIN 3 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 OATMEAL_RAISIN 3 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 OATMEAL_RAISIN 3 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 OATMEAL_RAISIN 3 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 OATMEAL_RAISIN 3 ", true, true);
						}

					}
				}

				//order for fourth client
				if (client_id == 4) {
					if (no_chocolate_chip_wanted != 0) {
						if (no_chocolate_chip_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 CHOCOLATE_CHIP 4 ", true, true);
						}
						if (no_chocolate_chip_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 CHOCOLATE_CHIP 4 ", true, true);
						}
						if (no_chocolate_chip_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 CHOCOLATE_CHIP 4 ", true, true);
						}
						if (no_chocolate_chip_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 CHOCOLATE_CHIP 4 ", true, true);
						}
						if (no_chocolate_chip_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 CHOCOLATE_CHIP 4 ", true, true);
						}
						if (no_chocolate_chip_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 CHOCOLATE_CHIP 4 ", true, true);
						}
						if (no_chocolate_chip_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 CHOCOLATE_CHIP 4 ", true, true);
						}
						if (no_chocolate_chip_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 CHOCOLATE_CHIP 4 ", true, true);
						}
						if (no_chocolate_chip_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 CHOCOLATE_CHIP 4 ", true, true);
						}
						if (no_chocolate_chip_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 CHOCOLATE_CHIP 4 ", true, true);
						}

					}

					if (no_arduino_wanted != 0) {
						if (no_arduino_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 ARDUINO 4 ", true, true);
						}
						if (no_arduino_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 ARDUINO 4 ", true, true);
						}
						if (no_arduino_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 ARDUINO 4 ", true, true);
						}
						if (no_arduino_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 ARDUINO 4 ", true, true);
						}
						if (no_arduino_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 ARDUINO 4 ", true, true);
						}
						if (no_arduino_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 ARDUINO 4 ", true, true);
						}
						if (no_arduino_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 ARDUINO 4 ", true, true);
						}
						if (no_arduino_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 ARDUINO 4 ", true, true);
						}
						if (no_arduino_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 ARDUINO 4 ", true, true);
						}
						if (no_arduino_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 ARDUINO 4 ", true, true);
						}

					}

					if (no_ginger_snap_wanted != 0) {
						if (no_ginger_snap_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 GINGER_SNAP 4 ", true, true);
						}
						if (no_ginger_snap_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 GINGER_SNAP 4 ", true, true);
						}
						if (no_ginger_snap_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 GINGER_SNAP 4 ", true, true);
						}
						if (no_ginger_snap_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 GINGER_SNAP 4 ", true, true);
						}
						if (no_ginger_snap_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 GINGER_SNAP 4 ", true, true);
						}
						if (no_ginger_snap_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 GINGER_SNAP 4 ", true, true);
						}
						if (no_ginger_snap_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 GINGER_SNAP 4 ", true, true);
						}
						if (no_ginger_snap_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 GINGER_SNAP 4 ", true, true);
						}
						if (no_ginger_snap_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 GINGER_SNAP 4 ", true, true);
						}
						if (no_ginger_snap_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 GINGER_SNAP 4 ", true, true);
						}

					}

					if (no_brush_wanted != 0) {
						if (no_brush_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 BRUSH 4 ", true, true);
						}
						if (no_brush_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 BRUSH 4 ", true, true);
						}
						if (no_brush_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 BRUSH 4 ", true, true);
						}
						if (no_brush_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 BRUSH 4 ", true, true);
						}
						if (no_brush_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 BRUSH 4 ", true, true);
						}
						if (no_brush_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 BRUSH 4 ", true, true);
						}
						if (no_brush_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 BRUSH 4 ", true, true);
						}
						if (no_brush_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 BRUSH 4 ", true, true);
						}
						if (no_brush_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 BRUSH 4 ", true, true);
						}
						if (no_brush_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 BRUSH 4 ", true, true);
						}

					}

					if (no_oatmeal_raisin_wanted != 0) {
						if (no_oatmeal_raisin_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 OATMEAL_RAISIN 4 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 OATMEAL_RAISIN 4 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 OATMEAL_RAISIN 4 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 OATMEAL_RAISIN 4 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 OATMEAL_RAISIN 4 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 OATMEAL_RAISIN 4 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 OATMEAL_RAISIN 4 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 OATMEAL_RAISIN 4 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 OATMEAL_RAISIN 4 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 OATMEAL_RAISIN 4 ", true, true);
						}

					}
				}


				//order for fifth client
				if (client_id == 5) {
					if (no_chocolate_chip_wanted != 0) {
						if (no_chocolate_chip_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 CHOCOLATE_CHIP 5 ", true, true);
						}
						if (no_chocolate_chip_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 CHOCOLATE_CHIP 5 ", true, true);
						}
						if (no_chocolate_chip_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 CHOCOLATE_CHIP 5 ", true, true);
						}
						if (no_chocolate_chip_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 CHOCOLATE_CHIP 5 ", true, true);
						}
						if (no_chocolate_chip_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 CHOCOLATE_CHIP 5 ", true, true);
						}
						if (no_chocolate_chip_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 CHOCOLATE_CHIP 5 ", true, true);
						}
						if (no_chocolate_chip_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 CHOCOLATE_CHIP 5 ", true, true);
						}
						if (no_chocolate_chip_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 CHOCOLATE_CHIP 5 ", true, true);
						}
						if (no_chocolate_chip_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 CHOCOLATE_CHIP 5 ", true, true);
						}
						if (no_chocolate_chip_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 CHOCOLATE_CHIP 5 ", true, true);
						}

					}

					if (no_arduino_wanted != 0) {
						if (no_arduino_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 ARDUINO 5 ", true, true);
						}
						if (no_arduino_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 ARDUINO 5 ", true, true);
						}
						if (no_arduino_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 ARDUINO 5 ", true, true);
						}
						if (no_arduino_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 ARDUINO 5 ", true, true);
						}
						if (no_arduino_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 ARDUINO 5 ", true, true);
						}
						if (no_arduino_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 ARDUINO 5 ", true, true);
						}
						if (no_arduino_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 ARDUINO 5 ", true, true);
						}
						if (no_arduino_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 ARDUINO 5 ", true, true);
						}
						if (no_arduino_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 ARDUINO 5 ", true, true);
						}
						if (no_arduino_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 ARDUINO 5 ", true, true);
						}

					}

					if (no_brush_wanted != 0) {
						if (no_brush_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 BRUSH 5 ", true, true);
						}
						if (no_brush_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 BRUSH 5 ", true, true);
						}
						if (no_brush_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 BRUSH 5 ", true, true);
						}
						if (no_brush_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 BRUSH 5 ", true, true);
						}
						if (no_brush_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 BRUSH 5 ", true, true);
						}
						if (no_brush_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 BRUSH 5 ", true, true);
						}
						if (no_brush_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 BRUSH 5 ", true, true);
						}
						if (no_brush_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 BRUSH 5 ", true, true);
						}
						if (no_brush_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 BRUSH 5 ", true, true);
						}
						if (no_brush_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 BRUSH 5 ", true, true);
						}

					}

					if (no_ginger_snap_wanted != 0) {
						if (no_ginger_snap_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 GINGER_SNAP 5 ", true, true);
						}
						if (no_ginger_snap_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 GINGER_SNAP 5 ", true, true);
						}
						if (no_ginger_snap_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 GINGER_SNAP 5 ", true, true);
						}
						if (no_ginger_snap_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 GINGER_SNAP 5 ", true, true);
						}
						if (no_ginger_snap_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 GINGER_SNAP 5 ", true, true);
						}
						if (no_ginger_snap_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 GINGER_SNAP 5 ", true, true);
						}
						if (no_ginger_snap_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 GINGER_SNAP 5 ", true, true);
						}
						if (no_ginger_snap_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 GINGER_SNAP 5 ", true, true);
						}
						if (no_ginger_snap_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 GINGER_SNAP 5 ", true, true);
						}
						if (no_ginger_snap_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 GINGER_SNAP 5 ", true, true);
						}

					}

					if (no_oatmeal_raisin_wanted != 0) {
						if (no_oatmeal_raisin_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 OATMEAL_RAISIN 5 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 OATMEAL_RAISIN 5 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 OATMEAL_RAISIN 5 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 OATMEAL_RAISIN 5 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 OATMEAL_RAISIN 5 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 OATMEAL_RAISIN 5 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 OATMEAL_RAISIN 5 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 OATMEAL_RAISIN 5 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 OATMEAL_RAISIN 5 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 OATMEAL_RAISIN 5 ", true, true);
						}

					}
				}



				//order for sixth client
				if (client_id == 6) {
					if (no_chocolate_chip_wanted != 0) {
						if (no_chocolate_chip_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 CHOCOLATE_CHIP 6 ", true, true);
						}
						if (no_chocolate_chip_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 CHOCOLATE_CHIP 6 ", true, true);
						}
						if (no_chocolate_chip_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 CHOCOLATE_CHIP 6 ", true, true);
						}
						if (no_chocolate_chip_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 CHOCOLATE_CHIP 6 ", true, true);
						}
						if (no_chocolate_chip_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 CHOCOLATE_CHIP 6 ", true, true);
						}
						if (no_chocolate_chip_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 CHOCOLATE_CHIP 6 ", true, true);
						}
						if (no_chocolate_chip_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 CHOCOLATE_CHIP 6 ", true, true);
						}
						if (no_chocolate_chip_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 CHOCOLATE_CHIP 6 ", true, true);
						}
						if (no_chocolate_chip_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 CHOCOLATE_CHIP 6 ", true, true);
						}
						if (no_chocolate_chip_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 CHOCOLATE_CHIP 6 ", true, true);
						}

					}

					if (no_arduino_wanted != 0) {
						if (no_arduino_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 ARDUINO 6 ", true, true);
						}
						if (no_arduino_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 ARDUINO 6 ", true, true);
						}
						if (no_arduino_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 ARDUINO 6 ", true, true);
						}
						if (no_arduino_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 ARDUINO 6 ", true, true);
						}
						if (no_arduino_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 ARDUINO 6 ", true, true);
						}
						if (no_arduino_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 ARDUINO 6 ", true, true);
						}
						if (no_arduino_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 ARDUINO 6 ", true, true);
						}
						if (no_arduino_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 ARDUINO 6 ", true, true);
						}
						if (no_arduino_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 ARDUINO 6 ", true, true);
						}
						if (no_arduino_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 ARDUINO 6 ", true, true);
						}

					}

					if (no_ginger_snap_wanted != 0) {
						if (no_ginger_snap_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 GINGER_SNAP 6 ", true, true);
						}
						if (no_ginger_snap_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 GINGER_SNAP 6 ", true, true);
						}
						if (no_ginger_snap_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 GINGER_SNAP 6 ", true, true);
						}
						if (no_ginger_snap_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 GINGER_SNAP 6 ", true, true);
						}
						if (no_ginger_snap_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 GINGER_SNAP 6 ", true, true);
						}
						if (no_ginger_snap_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 GINGER_SNAP 6 ", true, true);
						}
						if (no_ginger_snap_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 GINGER_SNAP 6 ", true, true);
						}
						if (no_ginger_snap_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 GINGER_SNAP 6 ", true, true);
						}
						if (no_ginger_snap_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 GINGER_SNAP 6 ", true, true);
						}
						if (no_ginger_snap_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 GINGER_SNAP 6 ", true, true);
						}

					}

					if (no_brush_wanted != 0) {
						if (no_brush_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 BRUSH 6 ", true, true);
						}
						if (no_brush_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 BRUSH 6 ", true, true);
						}
						if (no_brush_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 BRUSH 6 ", true, true);
						}
						if (no_brush_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 BRUSH 6 ", true, true);
						}
						if (no_brush_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 BRUSH 6 ", true, true);
						}
						if (no_brush_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 BRUSH 6 ", true, true);
						}
						if (no_brush_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 BRUSH 6 ", true, true);
						}
						if (no_brush_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 BRUSH 6 ", true, true);
						}
						if (no_brush_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 BRUSH 6 ", true, true);
						}
						if (no_brush_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 BRUSH 6 ", true, true);
						}

					}

					if (no_oatmeal_raisin_wanted != 0) {
						if (no_oatmeal_raisin_wanted == 1) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 1 OATMEAL_RAISIN 6 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 2) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 2 OATMEAL_RAISIN 6 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 3) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 3 OATMEAL_RAISIN 6 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 4) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 4 OATMEAL_RAISIN 6 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 5) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 5 OATMEAL_RAISIN 6 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 6) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 6 OATMEAL_RAISIN 6 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 7) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 7 OATMEAL_RAISIN 6 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 8) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 8 OATMEAL_RAISIN 6 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 9) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 9 OATMEAL_RAISIN 6 ", true, true);
						}
						if (no_oatmeal_raisin_wanted == 10) {
							cpen333::process::subprocess web_server1("Amazoom (Anushka Trial).exe 10 OATMEAL_RAISIN 6 ", true, true);
						}

					}
				}



				// detach thread to let it run on its own
				/*web_server1.detach();*/


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

			