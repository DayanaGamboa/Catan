#include "Town.h"

Town::Town(string name, int positionX, int positionY) : Figure(name, positionX, positionY)
{

}

Town::~Town()
{
}

string Town::toString() {
	stringstream s;
	s << "Infromacion Figura: " << getFigureName() << " " << getPositionX()
		<< " " << getPositionY() << endl;
	return s.str();
}
