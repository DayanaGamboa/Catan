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
	Node<ResourceCard>* nodeResource;
	void updateDevelopmentCard(string, int);
	void updateResourceCard(string, int);
	int countDevelopmentCard();
	void loadLists();
	string generateDevelopmentCard();
	string vect[3] = { "caballero","progreso","PuntosVictoria" };

	CircularList<ResourceCard>* resourceCardsList;
	CircularList<DevelopmentCard>* developmentCardList;
};

