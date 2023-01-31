#include "Card.h"

Card::Card()
{
    cardName = "";
    powerCard = 0;
    positionX = 0;
    positionY = 0;
}

Card::~Card()
{
}

string Card::getCardName() {
    return cardName;
}
void Card::setCardName(string cardNameP) {
    cardName = cardNameP;
}
int Card::getPowerCard() {
    return powerCard;
}
void Card::setPowerCard(int powerCardP) {
    powerCard = powerCardP;
}
int  Card::getPositionX() {
    return positionX;
}
void Card::setPositionX(int positionXP) {
    positionX = positionXP;
}
int  Card::getPositionY() {
    return positionY;
}
void Card::setPositionY(int positionYP) {
    positionY = positionYP;
}
