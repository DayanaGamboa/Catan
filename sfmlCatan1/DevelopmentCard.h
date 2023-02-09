#pragma once
#include <string.h>
#include <iostream>
#include "Card.h"

class DevelopmentCard : public Card
{
public:
	DevelopmentCard(string, int);
	~DevelopmentCard();
	int power();
	string toString();
	int getQuantity();
	void setQuantity(int);
private:
	int quantity;
};

