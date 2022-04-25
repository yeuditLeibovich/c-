#include "Simulator.h"
#include <thread>
#include <iostream>
#include "Cammera.h"

void Simulator::runCammeras() {
	std::thread myThreads[10];

	for (int i = 0; i < 10; i++)
	{
		//myThreads[i] = new thread(i);
		std::thread Threads(&Cammera::run, myThreads[i]);
		std::cout << "enter to stop";
		int x;
		std::cin >> x;
		for (int i = 0; i < 10; i++)
		{
			this->cammeras[i].stop();

		}
	
	}
}
