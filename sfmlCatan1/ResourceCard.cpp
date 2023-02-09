#include "ResourceCard.h"
#include<sstream>

ResourceCard::ResourceCard(string cardNameP, int quantity) : Card(cardNameP)
{
    this->quantity = quantity;
}

ResourceCard::~ResourceCard()
{
}

int ResourceCard::getQuantity() {
	return quantity;
}

void ResourceCard::setQuantity(int quantityP) {
	quantity = quantityP;
}

int ResourceCard::power() {
	return 0;
}

string ResourceCard::toString() {
	stringstream s;
	s << getCardName() << "," << getQuantity() << endl;
	return s.str();
}
