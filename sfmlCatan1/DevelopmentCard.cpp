#include "DevelopmentCard.h"
#include<sstream>


DevelopmentCard::DevelopmentCard(string cardNameP, int quantity) : Card(cardNameP)
{
	this->quantity = quantity;
}

DevelopmentCard::~DevelopmentCard()
{
}

int DevelopmentCard::getQuantity() {
	return quantity;
}

void DevelopmentCard::setQuantity(int quantity) {
	this->quantity = quantity;
}

int DevelopmentCard::power() {
	return 0;
}

string DevelopmentCard::toString() {
	stringstream s;
	s << getCardName() << "," << getQuantity() << endl;
	return s.str();
}
