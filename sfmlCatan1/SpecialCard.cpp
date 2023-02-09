#include "SpecialCard.h"
#include<sstream>

SpecialCard::SpecialCard(string cardNameP,int quantity) : Card(cardNameP)
{
	this->quantity = quantity;
}

SpecialCard::~SpecialCard()
{

}

int SpecialCard::getQuantity() {
	return quantity;
}

void SpecialCard::setQuantity(int quantityP) {
	quantity = quantityP;
}

int SpecialCard::power() {
	return 0;
}

string SpecialCard::toString() {
	stringstream s;
	s << getCardName() << "," << getQuantity() << endl;
	return s.str();
}