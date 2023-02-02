#include "Street.h"

Street::Street(string name, int positionX, int positionY) : Figure(name,positionX, positionY)
{
}

Street::~Street()
{
}

string Street::toString() {
	stringstream s;
	s << "Infromacion Figura: " << getCardName() << " " << getPositionX()
		<< " " << getPositionY() <<  endl;
	return s.str();
}
