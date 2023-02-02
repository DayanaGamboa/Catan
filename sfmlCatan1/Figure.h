#pragma once
#include <string>
using namespace std;

class Figure
{
public:
	Figure(string, int, int);
	~Figure();
	virtual string toString() = 0;
	string getCardName();
	void setCardName(string);
	int  getPositionX();
	void setPositionX(int);
	int  getPositionY();
	void setPositionY(int);

private:
	string cardName;
	int quantity;
	int positionX;
	int positionY;
};

