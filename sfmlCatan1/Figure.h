#pragma once
class Figure
{
public:
	Figure();
	~Figure();
	virtual string toString() = 0;
	string getCardName();
	void setCardName(string);
	int  getPositionX();
	void setPositionX(int);
	int  getPositionY();
	void setPositionY(int);

private:
	int quantity;
	int positionX;
	int positionY;
};

