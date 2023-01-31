#pragma once
#include "Figure.h"
#include "Deck.h"
#include "CircularList.h"
#include "Node.h"
#include "ResourceCard.h"
#include "SpecialCard.h"
#include "DevelopmentCard.h"
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
	string getName();
	void setName(string);
	int getAge();
	void setAge(int);
	int getVictoryPoint();
	void setVictoryPoint(int);
	int getColor();
	void setColor(int);
	void insertResourceCard(string, int, int, int, int);
	CircularList<ResourceCard>* resourceCardsList;
	CircularList<DevelopmentCard>* developmentCardList;
	CircularList<SpecialCard>* specialCardList;
	CircularList<Figure>* figurelist;

	
private:
	int id;
	string name;
	int age;
	int victoryPoint;
	int color;
	//Deck deck[]; // Deber�a de ser una lista?

};

