#pragma once
#include <string.h>
#include <iostream>
#include "Card.h"
using namespace::std;

class ResourceCard : public Card
{
public:
	ResourceCard(string,int);
	~ResourceCard();
	int power();
	string toString();
	int getQuantity();
	void setQuantity(int);
private:
	int quantity;
};
