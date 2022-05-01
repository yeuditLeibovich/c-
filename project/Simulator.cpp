#include "Simulator.h"
#include <thread>
#include <iostream>
#include "Cammera.h"
using namespace std;

Simulator::Simulator() {

}


void Simulator::runCammeras() {

	for (int i = 0; i < 5; i++)
	{
		cammeras[i] = new Cammera((char*) i);
	}


	std::thread t[5];
	/*std::thread sendToServer = std::thread(&sendAllCamerasToServer);*/

	for (int i = 0; i < 5; i++)
	{
		//myThreads[i] = new thread(i);
		t[i]=std::thread(&Cammera::run,(*(cammeras[i])));
		
	}
	std::cout << "enter to stop";
	int x;
	std::cin >> x;
	for (int i = 0; i < 5; i++)
	{
		/*cammeras[i]->print();*/
		cammeras[i]->stop();
		t[i].detach();
	}	

}

void Simulator::sendAllCamerasToServer() {
	while (true)
	{
		this_thread::sleep_for(20s);
		for (int i = 0; i < 5; i++)
		{
			cammeras[i]->sendToServer();
		}
	}
	
}
