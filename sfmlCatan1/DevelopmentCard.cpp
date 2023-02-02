#include "DevelopmentCard.h"
#include<sstream>


DevelopmentCard::DevelopmentCard(string cardNameP, int powerCardP, int positionXP, int positionYP, int quantity, bool faceCard) : Card(cardNameP, powerCardP, positionXP, positionYP)
{
	this->quantity = quantity;
	this->faceCard = faceCard;
}

DevelopmentCard::~DevelopmentCard()
{
}

int DevelopmentCard::getQuantity() {
	return quantity;
}

void DevelopmentCard::setQuantity(int quantityP) {
	quantity = quantityP;
}

int DevelopmentCard::power() {
	return 0;
}

string DevelopmentCard::toString() {
	stringstream s;
	s << "Infromacion Carta: " << getCardName() << " " << getPowerCard() << " " << getPositionX()
		<< " " << getPositionY() << " " << getQuantity() << endl;
	return s.str();
}
