#pragma once
#include "Card.h"
#include "CircularList.h"
#include "ResourceCard.h"
#include "DevelopmentCard.h"

class Bank
{
public:
	Bank();
	~Bank();
	int addUpCards();
	int substtractCards();
	int putCards(int, int);
	void loadLists();

	CircularList<ResourceCard>* resourceCardsList;
	CircularList<DevelopmentCard>* developmentCardList;

private:
	/*list<Card> bankCards;*/ //TEMPLATE
};

