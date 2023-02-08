#include "SpecialCard.h"
#include<sstream>

SpecialCard::SpecialCard(string cardNameP, int powerCardP, int positionXP, int positionYP, int quantity) : Card(cardNameP, powerCardP, positionXP, positionYP)
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
	s << "Infromacion Carta: " << getCardName() << " " << getPowerCard() << " " << getPositionX()
		<< " " << getPositionY() << endl;
	return s.str();
}
