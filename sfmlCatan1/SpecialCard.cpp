#include "SpecialCard.h"
#include<sstream>

SpecialCard::SpecialCard(string cardNameP, int powerCardP, int positionXP, int positionYP) : Card(cardNameP, powerCardP, positionXP, positionYP)
{

}

SpecialCard::~SpecialCard()
{

}

int SpecialCard::power() {
	return 0;
}

string SpecialCard::toString() {
	stringstream s;
	s << "Infromacion Carta: " << getCardName() << " " << getPowerCard() << " " << getPositionX()
		<< " " << getPositionY() << endl;
	return s.str();
}
