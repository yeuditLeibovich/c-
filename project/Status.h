#ifndef STATUS_H
#define STATUS_H
#include "Message.h"
#include <string.h>
#include <iostream>

class Status :Message
{
public:
	short status1;
	Status(unsigned char*, int);
	Status(short, int);
	virtual void  parseMessage();
	virtual void  parseBack();
	virtual void  print();
};
#endif
