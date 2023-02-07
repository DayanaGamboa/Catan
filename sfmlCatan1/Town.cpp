#include "Town.h"

Town::Town(string name, int positionX, int positionY, int quantity) : Figure(name, positionX, positionY, quantity)
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
