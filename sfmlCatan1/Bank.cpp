#include "Bank.h"

Bank::Bank()
{
	resourceCardsList = new CircularList<ResourceCard>;
	developmentCardList = new CircularList<DevelopmentCard>;
}

Bank::~Bank()
{
}

int Bank::addUpCards()
{
	return 0;
}

int Bank::substtractCards()
{
	return 0;
}

int Bank::putCards(int, int)
{
	return 0;
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
