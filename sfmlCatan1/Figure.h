#pragma once
#include <string>
using namespace std;

class Figure
{
public:
	Figure(string, int, int);
	~Figure();
	virtual string toString() = 0;
	string getFigureName();
	void setFigureName(string);
	int  getPositionX();
	void setPositionX(int);
	int  getPositionY();
	void setPositionY(int);

private:
	string figureName;
	int quantity;
	int positionX;
	int positionY;
};

