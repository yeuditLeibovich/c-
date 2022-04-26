#include "Status.h"
#include "Buffer.h"
#include "Cammera.h"
#include "Discovery.h"
#include <iostream>

void Buffer::addToBuffer(char* m) {
	if (buffer == NULL) {
		buffer = (char**)malloc(sizeof(char*));
		if (buffer == NULL) 
		{
			std::cout << "xxxx";
			exit(1);
		}
		buffer[0] = (char*)malloc(sizeof(sizeof(Discovery) > sizeof(Status) ? sizeof(Discovery) : sizeof(Status)));
		strcpy(buffer[0], m);
	}
	else {
		buffer = (char**)realloc(buffer, sizeof(char*) * (index + 1));
		if (buffer == NULL) {
			std::cout << "xxxx";
			exit(1);
		}		
		buffer[index] = (char*)malloc(sizeof(sizeof(Discovery)> sizeof(Status)? sizeof(Discovery): sizeof(Status)));
		if (buffer == NULL) {
			std::cout << "xxxx";
			exit(1);
		}
		strcpy(buffer[index], m);			
		index = index + 1;
	}
	
}
char** Buffer::getBuffer() {
	return this->buffer;
}
void Buffer::cleanBuffer() {
	for (int i = 0; i < index; i++)
	{
		free(buffer[i]);
	}
	free(buffer);
	index = 0;
}
