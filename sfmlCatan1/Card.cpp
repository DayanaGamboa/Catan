#include "Card.h"

Card::Card(string cardName)
{
    this->cardName = cardName;
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

