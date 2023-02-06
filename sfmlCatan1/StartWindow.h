#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include<ctime>
#include<time.h> 
#include<windows.h> 
#include <string>
#include <list>


using namespace std;
using namespace sf;

#define optionMenu 4
#define X 1330 
#define Y 790

//extern RenderWindow Go;

class StartWindow
{
public:
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
	void paintNumberPieces(RenderWindow* Go);
	void exitButton(RenderWindow*);
	void saveGameButton(RenderWindow*);
	void loadGameButton(RenderWindow*);
	void paintLands(RenderWindow*);
	void PlayerInTurn(RenderWindow*);

	void paintTowns(RenderWindow*);

	int StartWindowPressed() {
		return StartWindowSelected;
	}
	~StartWindow();
	RectangleShape vectorTerrenosRTS[19];
	Texture vectorTerrenosTXT[19];
	
	RectangleShape rtsBtnDice, rtsBtnExit, rtsBtnSave;
	RectangleShape rtsBtnStreet, rtsBtnTown, rtsBtnCity, rtsBtnEndTurn, rtsBtnDevelopment, rtsBtnTrade;
	int posXTerrenoDesierto = 0;
	int posYTerrenoDesierto = 0;
	RectangleShape rtsPlayerBlue, rtsPlayerRed, rtsPlayerYellow, rtsPlayerGreen;
	Texture txtrPlayerBlue, txtrPlayerRed, txtrPlayerYellow, txtrPlayerGreen;

	bool terrenos = false;
	bool fichasNumeradas = false;
	
	bool townStatus = false;

	RectangleShape vectorTown[54];
	Texture txtTown;
	
	int TerrenosPosX[19] = { 753,672,589,552,512,550,589,670,751,791,831,791,711,632,592,632,711,750,672 };
	int TerrenosPosY[19] = { 228,228,228,285,344,401,457,457,457,401,344,285,285,285,344,401,401,343,343 };
private:	
	Font font;
	Event event;
	Mouse mouse;
	RectangleShape rtsLands;
	Texture txtrLands;
	int StartWindowSelected;	
	Text startMenu[optionMenu];
};