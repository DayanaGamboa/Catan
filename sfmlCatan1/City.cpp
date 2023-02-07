#include "City.h"

City::City(string name, int positionX, int positionY, int quantity) : Figure(name,positionX,positionY, quantity)
{

}

City::~City()
{

}

string City::toString() {
	stringstream s;
	s << "Infromacion Figura: " << getFigureName() <<  " " << getPositionX()
		<< " " << getPositionY() << endl;
	return s.str();
}
