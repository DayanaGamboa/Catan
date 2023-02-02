#include "City.h"

City::City(string name, int positionX, int positionY) : Figure(name,positionX,positionY)
{

}

City::~City()
{

}

string City::toString() {
	stringstream s;
	s << "Infromacion Carta: " << getCardName() <<  " " << getPositionX()
		<< " " << getPositionY() << endl;
	return s.str();
}
