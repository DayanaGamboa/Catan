#pragma once
#include "Figure.h"
#include "Deck.h"
#include "CircularList.h"
#include "Node.h"
#include "ResourceCard.h"
#include "SpecialCard.h"
#include "DevelopmentCard.h"
#include "City.h"
#include "Street.h"
#include "Town.h"
class Player
{
public:
	Player(int,string,int,int,int);
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
	void insertDevelopmentCard(string, int, int, int, int);
	void insertSpecialCard(string, int, int, int);
	void insertFigures(string, int, int);
	void showCard();
	
	
	CircularList<ResourceCard>* resourceCardsList;
	CircularList<DevelopmentCard>* developmentCardList;
	CircularList<SpecialCard>* specialCardList;
	CircularList<City>* cityList;
	CircularList<Street>* streetList;
	CircularList<Town>* townList;

	
private:
	int id;
	string name;
	int age;
	int victoryPoint;
	int color;
	//Deck deck[]; // Debería de ser una lista?

};

