#pragma once
#include <string.h>
#include <iostream>
#include "Card.h"

class DevelopmentCard : public Card
{
public:
	DevelopmentCard(string, int, int, int, int,bool);
	~DevelopmentCard();
	int power();
	string toString();
	string getCardName();
	void setCardName(string);
	int getQuantity();
	void setQuantity(int);
	bool getFaceCrad();
	void setFaceCard(bool);

private:
	string cardName;
	int quantity;
	bool faceCard;
};

