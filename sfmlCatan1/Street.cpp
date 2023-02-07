#include "Street.h"

Street::Street(string name, int positionX, int positionY, int quantity) : Figure(name,positionX, positionY, quantity)
{
}

Street::~Street()
{
}

string Street::toString() {
	stringstream s;
	s << "Infromacion Figura: " << getFigureName() << " " << getPositionX()
		<< " " << getPositionY() <<  endl;
	return s.str();
}
