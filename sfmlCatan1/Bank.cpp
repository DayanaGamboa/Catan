#include "Bank.h"

Bank::Bank()
{
	resourceCardsList = new CircularList<ResourceCard>;
	developmentCardList = new CircularList<DevelopmentCard>;
}

Bank::~Bank()
{
}

void Bank::updateDevelopmentCard(string name, int quantity)
{
	nodeDevelopment = developmentCardList->first;
	do {
		if (nodeDevelopment->getData()->getCardName() == name) {
			cout << "seteado" << endl;
			nodeDevelopment->getData()->setQuantity(quantity);
		}
		nodeDevelopment = nodeDevelopment->getNextNode();
	} while (nodeDevelopment != developmentCardList->first);
}

void Bank::updateResourceCard(string name, int quantity)
{
	nodeResource = resourceCardsList->first;
	int count = 0;
	do {
		if (nodeResource->getData()->getCardName() == name) {
			count = nodeResource->getData()->getQuantity();
			nodeResource->getData()->setQuantity(count + quantity);
		}
		nodeResource = nodeResource->getNextNode();
	} while (nodeResource != resourceCardsList->first);

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
	ResourceCard* wood = new ResourceCard("madera", 19);
	ResourceCard* wool = new ResourceCard("lana", 19);
	ResourceCard* cereal = new ResourceCard("cereal", 19);
	ResourceCard* clay = new ResourceCard("arcilla", 19);
	ResourceCard* mineral = new ResourceCard("mineral", 19);
	resourceCardsList->inserNode(wood);
	resourceCardsList->inserNode(wool);
	resourceCardsList->inserNode(cereal);
	resourceCardsList->inserNode(clay);
	resourceCardsList->inserNode(mineral);

	DevelopmentCard* knight = new DevelopmentCard("caballero", 14);
	DevelopmentCard* progress = new DevelopmentCard("progreso", 6);
	DevelopmentCard* victoryPoints = new DevelopmentCard("PuntosVictoria", 5);
	developmentCardList->inserNode(knight);
	developmentCardList->inserNode(progress);
	developmentCardList->inserNode(victoryPoints);
}

string Bank::generateDevelopmentCard() {
	srand(time(NULL));
	int num = 0;
	num = rand() % (3);
	string name;
	name = vect[num];
	cout << name << endl;
	return name;
}
