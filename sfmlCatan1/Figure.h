#pragma once
#include <string>
#include <sstream>
using namespace std;

class Figure
{
public:
	Figure(string, int, int, int);
	~Figure();
	/*virtual string toString() = 0;*/
	string getCardName();
	void setCardName(string);
	int  getPositionX();
	void setPositionX(int);
	int  getPositionY();
	void setPositionY(int);
	int  getQuantity();
	void setQuantity(int);
	string toString();

private:
	string figureName;
	int quantity;
	int positionX;
	int positionY;
};

