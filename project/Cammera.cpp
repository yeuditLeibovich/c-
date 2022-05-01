#include "Cammera.h"
#include "Message.h"
#include "Discovery.h"
#include "Buffer.h"
#include "Status.h"
#include <thread>

//#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib, "Ws2_32.lib")
#include <iostream>
#include <string.h>
#include <sstream>
#include <WinSock2.h>
#include <WS2tcpip.h>
using namespace std;

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
	/*std::cout << this->buffer.getBuffer()<< "\n";*/
	for (int i = 0; i < this->index; i++)
	{
		free(arr[i]);
	}
	free(arr);
	arr = NULL;
	index = 0;
	std::cout << "send\n";
}
void Cammera::sendToServer() {
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		cout << "Winsock Connection Failed!" << endl;
		exit(1);
	}
	string getInput;
	SOCKADDR_IN addr;
	int addrLen = sizeof(addr);
	IN_ADDR ipvalue;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(3000);
	addr.sin_family = AF_INET;

	SOCKET connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(connection, (SOCKADDR*)&addr, addrLen) == 0) {
		cout << "Connected!" << endl;

		for (int i = 0; i < buffer.index; i++)
		{
			getInput = (char*)(this->buffer.getBuffer()[i]);
			send(connection, getInput.c_str(), getInput.length(), 0);
		}		
		/*getline(cin, getInput);*/
		
	}
	else {
		cout << "Error Connecting to Host" << endl;
		exit(1);
	}
	return ;
}

void Cammera::run() {
	while (isActive) {
		for (int i = 0; i < 5; i++)
		{
			generate();
		}
		sendToBuffer();
		Sleep(3);
		sendToServer();
	}

}
//void print() {
//	print();
//}

void Cammera ::stop() {
	this->buffer.getBuffer();
	this->isActive = false;
}
