#pragma once
#include <string.h>
#include <iostream>
#include "Card.h"
using namespace::std;

class ResourceCard : public Card
{
public:
	ResourceCard(string,int,int,int,int);
	~ResourceCard();
private:
	int quantity;
};
