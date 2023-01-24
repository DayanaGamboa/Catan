#pragma once
#include "Figure.h"
#include "Deck.h"
class Player
{
public:
	Player();
	~Player();

	void throwsDice();
	void build();
	void trade();
	void victoryPoints();
	void useDevelopmentCards();
	void endTurn(); // EL MISMO QUE EXIT GAME EN PARTIDA??

private:
	int id;
	int victoryPoint;
	//int color;
	//Figure constructionFigure[]; //Template
	//Deck deck[]; // Debería de ser una lista?

};

