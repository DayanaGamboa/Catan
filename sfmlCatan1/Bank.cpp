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
