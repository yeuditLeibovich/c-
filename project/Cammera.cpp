#include "Cammera.h"
#include "Message.h"
#include "Discovery.h"
#include "Buffer.h"
#include "Status.h"
#include <thread>

Cammera::Cammera(char* id) {
	this->id = id;
}

void Cammera::addMessage(Message* d) {

	if (index == NULL) {
		arr = (Message**)malloc(sizeof(Message*));
		if (arr == NULL) {
			std::cout << "xxx";
			exit(1);
		}
		arr[0] = d;
	}
	else {
		arr = (Message**)realloc(arr, sizeof(Message*) * (index+1));
		if (arr == NULL) {
			std::cout << "xxx";
			exit(1);
		}
		arr[index] = d;
	}
	index = index + 1;
}

void Cammera::generate() {
	Discovery* d =new Discovery((float)(rand()%500), (float)(rand()%500),
		                        (float)(rand()%500), (int)(rand()%500));
	addMessage((Message*)d);
	std::cout << "generate\n";
}

void Cammera::sendToBuffer() {
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] != NULL) {
            arr[i]->parseMessage();		
		    buffer.addToBuffer((char*)(arr[i]->getMessageBuffer()));
		}
		else {
			std::cout << "null";
		}
	}
	for (int i = 0; i < this->index; i++)
	{
		free(arr[i]);
	}
	free(arr);
	arr = NULL;
	index = 0;
	std::cout << "send\n";
}

void Cammera::run() {
	while (isActive) {
		for (int i = 0; i < 5; i++)
		{
			generate();
		}
		sendToBuffer();
	}
	//std::thread t(func);
	//std::cout << "enter to stop";
	//int x;
	//std::cin >> x;
	//stop();
}

void Cammera ::stop() {
	this->isActive = false;
}
