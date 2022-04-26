#ifndef SIMULATOR_H
#define SIMULATOR_H
#pragma once
#include "Cammera.h"
class Simulator
{
private:
	Cammera* cammeras[5];

public:
	Simulator();
	void runCammeras();
};
#endif 

