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

string Figure::getFigureName() {
    return figureName;
}
void Figure::setFigureName(string figureName) {
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