#pragma once
#include "Figure.h"
#include "Deck.h"
#include "CircularList.h"
#include "Node.h"
class Player
{
public:
	Player(int);
	~Player();

	void throwsDice();
	void build();
	void trade();
	void victoryPoints();
	void useDevelopmentCards();
	void endTurn(); // EL MISMO QUE EXIT GAME EN PARTIDA??
	string toString();
	int getId();
	void setId(int);
private:
	int id;
	int victoryPoint;
	int color;
	CircularList<Figure>* list;

	//Deck deck[]; // Debería de ser una lista?

};

