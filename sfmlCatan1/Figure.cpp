#include "Figure.h"

Figure::Figure(string cardName, int positionX, int positionY)
{
    this->cardName = cardName;
    this->positionX = positionX;
    this->positionY = positionY;
}

Figure::~Figure()
{
}

string Figure::getCardName() {
    return cardName;
}
void Figure::setCardName(string cardName) {
    this->cardName = cardName;
}

int  Figure::getPositionX() {
    return positionX;
}
void Figure::setPositionX(int positionX) {
    this->positionX = positionX;
}

int  Figure::getPositionY() {
    return positionY;
}
void Figure::setPositionY(int positionY) {
    this->positionY = positionY;
}