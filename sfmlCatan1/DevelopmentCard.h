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
	int getQuantity();
	void setQuantity(int);
	bool getFaceCrad();
	void setFaceCard();

private:
	int quantity;
	bool faceCard;
};

