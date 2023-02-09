#pragma once
#include <string>
using namespace std;
class Card
{
public:
	Card(string);
	~Card();
	virtual int power() = 0;
	virtual string toString() = 0;
	string getCardName();
	void setCardName(string);
	
private:
	string cardName;
	
};

