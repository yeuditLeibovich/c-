#ifndef BUFFER_H
#define BUFFER_H
#pragma once
#include "Message.h"

class Buffer
{
private:
	char** buffer = NULL;
	int index = 0;
public:
	void addToBuffer(char* );
	char** getBuffer();
	void cleanBuffer();
};
#endif

