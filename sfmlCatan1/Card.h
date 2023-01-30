#pragma once
#include <string>
using namespace std;
class Card
{
public:
	Card();
	~Card();
	//void changeFaceCard(); // VA SOLO EN DEVELOPMENT?
	virtual int power();

private:
	string cardName;
	int powerCard;
	int positionX;
	int positionY;
};

