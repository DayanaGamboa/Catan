#pragma once
#include <string.h>
#include <iostream>
#include "Card.h"

class SpecialCard : public Card
{
public:
	SpecialCard(string, int, int, int);
	~SpecialCard();
	int power();
	string toString();
};

