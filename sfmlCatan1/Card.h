#pragma once
#include <string>
using namespace std;
class Card
{
public:
	Card(string, int, int, int);
	~Card();
	//void changeFaceCard(); // VA SOLO EN DEVELOPMENT?
	virtual int power() = 0;
	virtual string toString() = 0;
	string getCardName();
	void setCardName(string);
	int getPowerCard();
	void setPowerCard(int);
	int  getPositionX();
	void setPositionX(int);
	int  getPositionY();
	void setPositionY(int);


private:
	string cardName;
	int powerCard;
	int positionX;
	int positionY;
};

