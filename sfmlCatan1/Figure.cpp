#include "Figure.h"

Figure::Figure(string figureName, int positionX, int positionY, int quantity)

{
    this->figureName = figureName;
    this->positionX = positionX;
    this->positionY = positionY;
    this->quantity = quantity;
}

Figure::~Figure()
{
}

string Figure::getCardName() {
    return figureName;
}
void Figure::setCardName(string figureName) {
    this->figureName = figureName;
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

int  Figure::getQuantity() {
    return quantity;
}
void Figure::setQuantity(int quantity) {
    this->quantity = quantity;
}