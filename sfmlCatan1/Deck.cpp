#include "Deck.h"

Deck::Deck()
{
    listCard = new CircularList<ResourceCard>;
}

Deck::~Deck()
{
}

int Deck::countResourceCards()
{
    return 0;
}

void Deck::shuffleCards()
{
}

void Deck::insertResourceCard(string cardNameP, int powerCardP, int positionXP, int positionYP, int quantityP)
{
    ResourceCard* info = new ResourceCard(cardNameP, powerCardP, positionXP, positionYP, quantityP);
    listCard->inserNode(info);
}
