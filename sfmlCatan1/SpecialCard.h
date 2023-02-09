#pragma once
#include <string.h>
#include <iostream>
#include "Card.h"

class SpecialCard : public Card
{
public:
	SpecialCard(string, int);
	~SpecialCard();
	int getQuantity();
	void setQuantity(int);
	int power();
	string toString();

private:
	int quantity;
};

