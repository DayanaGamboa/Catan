#include "DevelopmentCard.h"
#include "SpecialCard.h"
#include "ResourceCard.h"
#include "CircularList.h"
class Deck
{
public:
	Deck();
	~Deck();

	int countResourceCards();
	void shuffleCards();

private:
	int id;
	CircularList<ResourceCard>* listCard;
	//ResourceCard resourceCards[]; //Template??
	//DevelopmentCard developmentCards[]; //Template??
	//SpecialCard specialCards[]; //Template??

};

