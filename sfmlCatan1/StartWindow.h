#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include<ctime>
#include<time.h> 
#include<windows.h> 

using namespace std;
using namespace sf;

#define optionMenu 4
#define X 1330 
#define Y 790

//extern RenderWindow Go;

class StartWindow
{
public:
	//const float X = 900, Y = 700;
	StartWindow(float width, float height);
	void drawWindow(RenderWindow& window);
	void moveUp();
	void moveDown();

	void mainWindow();
	void goWindow();
	void aboutWindow();


	
	
	void paintOpponentDeck(RenderWindow*, int);
	void paintSpecialCards(RenderWindow*);
	void generateGameArea(RenderWindow*);
	void paintResource(RenderWindow* Go, int x, int y);



	void exitButton(RenderWindow*);
	void saveGameButton(RenderWindow*);
	void loadGameButton(RenderWindow*);
	void paintLands(RenderWindow*);


	int StartWindowPressed() {
		return StartWindowSelected;
	}
	~StartWindow();

	RectangleShape vectorTerrenosRTS[19];
	Texture vectorTerrenosTXT[19];

	RectangleShape rtsBtnDice;
	int posXTerrenoDesierto = 0;
	int posYTerrenoDesierto = 0;

	bool terrenos = false;
	bool fichasNumeradas = false;
private:

	

	Event event;
	Mouse mouse;

	//RectangleShape rtsDice1;
	//Texture txtrRtsDice1;
	//RectangleShape rtsDice2;
	//Texture txtrRtsDice2;

	RectangleShape rtsLands;
	Texture txtrLands;


	int StartWindowSelected;
	Font font;
	Text startMenu[optionMenu];

};