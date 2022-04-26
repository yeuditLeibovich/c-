#include "Simulator.h"
#include <thread>
#include <iostream>
#include "Cammera.h"
#include <thread>

Simulator::Simulator() {

}

void Simulator::runCammeras() {

	for (int i = 0; i < 5; i++)
	{
		cammeras[i] = new Cammera((char*) i);
	}

	std::thread t[5];

	for (int i = 0; i < 5; i++)
	{
		//myThreads[i] = new thread(i);
		t[i]=std::thread(&Cammera::run,(*(cammeras[i])));
		std::cout << "enter to stop";
		int x;
		std::cin >> x;
		for (int i = 0; i < 5; i++)
		{
			cammeras[i]->stop();
			t[i].detach();
		}	
	}
}
