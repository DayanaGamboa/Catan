#pragma once
#include <string>
using namespace std;
class Card
{
public:
	Card();
	~Card();
	//void changeFaceCard(); // VA SOLO EN DEVELOPMENT?
	virtual int power();
	string getCardNme();
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

