#include "ResourceCard.h"
#include<sstream>

ResourceCard::ResourceCard(string cardNameP, int powerCardP, int positionXP, int positionYP, int quantity) : Card(cardNameP, powerCardP, positionXP, positionYP)
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
	s << "Infromacion Carta: " << getCardName()<< " " << getPowerCard() << " " << getPositionX() 
		<< " " << getPositionY() << " " << getQuantity() << endl;
	return s.str();
}
