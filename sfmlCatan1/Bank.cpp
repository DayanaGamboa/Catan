#include "Bank.h"

Bank::Bank()
{
	resourceCardsList = new CircularList<ResourceCard>;
	developmentCardList = new CircularList<DevelopmentCard>;
}

Bank::~Bank()
{
}

void Bank::addUpCards(string name, int quantity)
{
	resourceCardsList->increaseQuantity(name, quantity);
	resourceCardsList->dropDownList();
}

void Bank::substtractCards(string name, int type, int quantity)
{
	if (type == 1) {
		resourceCardsList->decrementQuantity(name, quantity);
		resourceCardsList->dropDownList();
	}
	if (type == 2) {
		developmentCardList->decrementQuantity(name, quantity);
		developmentCardList->dropDownList();
	}	
}

int Bank::putCards(int, int)
{
	return 0;
}

int Bank::countDevelopmentCard() {
	int count = 0;
	nodeDevelopment = developmentCardList->first;
	do {
		count += nodeDevelopment->getData()->getQuantity();
		nodeDevelopment = nodeDevelopment->getNextNode();

	} while (nodeDevelopment != developmentCardList->first);

	return count;
}

void Bank::loadLists() {
	ResourceCard* wood = new ResourceCard("madera", 0, 0, 0, 19);
	ResourceCard* wool = new ResourceCard("lana", 0, 0, 0, 19);
	ResourceCard* cereal = new ResourceCard("cereal", 0, 0, 0, 19);
	ResourceCard* clay = new ResourceCard("arcilla", 0, 0, 0, 19);
	ResourceCard* mineral = new ResourceCard("mineral", 0, 0, 0, 19);
	resourceCardsList->inserNode(wood);
	resourceCardsList->inserNode(wool);
	resourceCardsList->inserNode(cereal);
	resourceCardsList->inserNode(clay);
	resourceCardsList->inserNode(mineral);

	DevelopmentCard* knight = new DevelopmentCard("caballero", 0, 0, 0, 14, false);
	DevelopmentCard* progress = new DevelopmentCard("progreso", 0, 0, 0, 6, false);
	DevelopmentCard* victoryPoints = new DevelopmentCard("PuntosVictoria", 1, 0, 0, 5, false);
	developmentCardList->inserNode(knight);
	developmentCardList->inserNode(progress);
	developmentCardList->inserNode(victoryPoints);
}
