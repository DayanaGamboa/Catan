#include "Card.h"

Card::Card(string cardName, int powerCard, int positionX, int positionY)
{
    this->cardName = cardName;
    this->powerCard = powerCard;
    this->positionX = positionX;
    this->positionY = positionY;
}

Card::~Card()
{
}

string Card::getCardName() {
    return cardName;
}
void Card::setCardName(string cardName) {
    this->cardName = cardName;
}
int Card::getPowerCard() {
    return powerCard;
}
void Card::setPowerCard(int powerCard) {
    this->powerCard = powerCard;
}
int  Card::getPositionX() {
    return positionX;
}
void Card::setPositionX(int positionX) {
    this->positionX = positionX;
}
int  Card::getPositionY() {
    return positionY;
}
void Card::setPositionY(int positionY) {
    this->positionY = positionY;
}
