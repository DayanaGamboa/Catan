#pragma once
#include "Card.h"
#include "CircularList.h"
#include "ResourceCard.h"
#include "DevelopmentCard.h"
#include "Node.h"

class Bank
{
public:
	Bank();
	~Bank();
	Node<DevelopmentCard>* nodeDevelopment;
	void addUpCards(string, int);
	void substtractCards(string, int, int);
	int putCards(int, int);
	int countDevelopmentCard();
	void loadLists();

	CircularList<ResourceCard>* resourceCardsList;
	CircularList<DevelopmentCard>* developmentCardList;

private:
	/*list<Card> bankCards;*/ //TEMPLATE
};

