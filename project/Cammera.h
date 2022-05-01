#ifndef CAMMERA_H
#define CAMMERA_H
#pragma once
#include "Message.h"
#include "Buffer.h"
class Cammera
{
private:
	char* id;
	Message** arr;
	int index = 0;
	Buffer buffer;
	bool isActive=true;

public:
	Cammera(char*);
	void addMessage(Message*);
	void generate();
	void sendToBuffer();
	void sendToServer();
	void run();
	void stop();
	/*void print();*/
};
#endif

