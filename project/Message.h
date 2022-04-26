#ifndef MESSAGE_H
#define MESSAGE_H
#pragma once
#include <stdlib.h>
class Message
{
protected:
	unsigned char* messageBuffer;
	int messageId;
	int messageType;
public:
	Message(int);
	virtual void parseMessage();
	virtual void parseBack();
	virtual void print();
	unsigned char* getMessageBuffer();
	Message();
};
#endif
