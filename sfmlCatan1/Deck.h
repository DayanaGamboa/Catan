#include "DevelopmentCard.h"
#include "SpecialCard.h"
class Deck
{
public:
	Deck();
	~Deck();

	int countResourceCards();
	void shuffleCards();

private:
	int id;
	//ResourceCard resourceCards[]; //Template??
	//DevelopmentCard developmentCards[]; //Template??
	//SpecialCard specialCards[]; //Template??

};

