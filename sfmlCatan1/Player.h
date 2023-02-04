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
#include "StartWindow.h"
#include "SFML/Graphics.hpp"
#include<sstream>

using namespace std;
using namespace sf;
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

	void playerRegister(RenderWindow*);
	void paintPlayerRegister(RenderWindow*);
	
	
	CircularList<ResourceCard>* resourceCardsList;
	CircularList<DevelopmentCard>* developmentCardList;
	CircularList<SpecialCard>* specialCardList;
	CircularList<City>* cityList;
	CircularList<Street>* streetList;
	CircularList<Town>* townList;
	CircularList<Player>* playerList;
	
	RectangleShape rtsBtnGuardar, rtsBtnJugar, rtsBtnAtras, rtsID, rtsNombre, rtsEdad, rtsColor, fondo;
	Texture txtrBtnGuardar, txtrBtnAtras, txtrBtnJugar;
	Text tituloJugador, titulo1, tituloID, txtID, tituloNombre, txtNombre;
	Text tituloEdad, txtEdad, tituloColor, txtCamposRequeridos;

	bool registroJugadores = false;
	int contadorJugadores = 0;
	int id = 0;
	
private:
	int age, victoryPoint, color;
	string name;
	Font font;
	Event event;
	Mouse mouse;
	//Deck deck[]; // Debería de ser una lista?

};

