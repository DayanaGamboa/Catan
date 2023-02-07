#pragma once
#include "Figure.h"
#include<sstream>

class Town : Figure
{
public:
	Town(string, int, int, int);
	~Town();
	string toString();

};
