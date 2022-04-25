#ifndef DISCOVERY_H
#define DISCOVERY_H
#pragma once
#include "Message.h"
#include <string.h>
#include <iostream>

class Discovery :Message
{
public:
    float distance;
    float angle;
    float speed;
    Discovery(unsigned char*, int);
    Discovery(float, float, float, int);
    virtual void  parseMessage();
    virtual void  parseBack();
    virtual void  print();
};
#endif 