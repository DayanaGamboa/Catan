#pragma once
#include "Figure.h"
#include<sstream>

class Street : Figure
{
public:
	Street(string, int, int, int);
	~Street();
	string toString();
};

