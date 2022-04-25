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

	if (this->index == 0) {
		this->arr = (Message**)malloc(sizeof(Message*));
		arr[0] = d;
	}
	else {
		this->arr = (Message**)realloc(arr, sizeof(Message*)+1);
		arr[index] = d;
	}
	index = index + 1;

}

void Cammera::generate() {
	Discovery* d =new Discovery((float)(rand()%500), (float)(rand()%500),
		                        (float)(rand()%500), (int)(rand()%500));
	addMessage((Message*)d);

}
void Cammera::sendToBuffer() {
	for (int i = 0; i < this->index; i++)
	{
		arr[i]->parseMessage();		
		buffer.addToBuffer((char*)(arr[i]->getMessageBuffer()));
	}
	for (int i = 0; i < this->index; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

void Cammera::run() {
	while (isActive) {
		for (int i = 0; i < 3; i++)
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
