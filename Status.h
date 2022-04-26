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
	void  parseMessage();
	void  parseBack();
	void  print();
};
#endif
