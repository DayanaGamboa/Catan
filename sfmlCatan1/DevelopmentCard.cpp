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

string DevelopmentCard::getCardName() {
	return cardName;
}

void DevelopmentCard::setCardName(string cardName) {
	this->cardName = cardName;
}

int DevelopmentCard::getQuantity() {
	return quantity;
}

void DevelopmentCard::setQuantity(int quantity) {
	this->quantity = quantity;
}

bool DevelopmentCard::getFaceCrad() {
	return faceCard;
}

void DevelopmentCard::setFaceCard(bool faceCard) {
	this->faceCard = faceCard;
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
