#pragma once
#include "Figure.h"
#include "CircularList.h"
#include "Node.h"
#include "ResourceCard.h"
#include "SpecialCard.h"
#include "DevelopmentCard.h"
#include "StartWindow.h"
#include "SFML/Graphics.hpp"
#include<sstream>

using namespace std;
using namespace sf;

class Player
{
public:
	Player(int,string,int,int,Color);
	Player();
	~Player();

	Node<DevelopmentCard>* nodeDevelopment;
	Node<ResourceCard>* nodeResource;
	Node<Figure>* nodeFigure;
	Node<SpecialCard>* nodeSpecial;
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
	Color getColor();
	void setColor(Color);
	void insertResourceCard(string, int);
	void insertDevelopmentCard(string, int);
	void insertSpecialCard(string, int);
	void insertFigures(string, int, int, int);
	int countDevelopmentCard();
	void loadList();

	
	void buildTown(RenderWindow*, int, int);
	
	CircularList<ResourceCard>* resourceCardsList;
	CircularList<DevelopmentCard>* developmentCardList;
	CircularList<SpecialCard>* specialCardList;
	CircularList<Figure>* figureList;

	
private:
	int id, age, victoryPoint;
	Color color;
	string name;
	Font font;
	Event event;
	Mouse mouse;

};

