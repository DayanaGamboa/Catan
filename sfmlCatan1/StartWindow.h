#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include<ctime>
#include<time.h> 
#include<windows.h> 
#include <string>
#include <list>
#include "CircularList.h"
#include "Player.h"
#include "Node.h"
#include "Dice.h"
#include "Thief.h"
#include "Graph.h"
#include "Bank.h"


using namespace std;
using namespace sf;

#define optionMenu 4
#define X 1330 
#define Y 790

//extern RenderWindow Go;

class StartWindow
{
public:
	Node<Player>* actualNode;
	Node<Player>* nodePlayer1;
	Node<Player>* nodePlayer2;
	Node<Player>* nodePlayer3;
	Node<Player>* nodePlayer4;
	Node<ResourceCard>* nodeResource;
	Node<Figure>* nodeFigure;
	Node<ResourceCard>* nodeResourceBankWood;
	Node<ResourceCard>* nodeResourceBankSheep;
	Node<ResourceCard>* nodeResourceBankMineral;
	Node<ResourceCard>* nodeResourceBankClay;
	Node<ResourceCard>* nodeResourceCereal;



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
	void paintPlayerRegister(RenderWindow* playerData);
	void playerRegister(RenderWindow*);
	void paintTowns(RenderWindow*);
	void builtTown(RenderWindow*, int);
	void accommodateColors();
	void savePlayerInfo();
	void paintBankCounters(RenderWindow*);
	void paintPlayerCountersInTurn(RenderWindow*);
	void saveResourcePlayer();
	void saveFigfurePlayer();
	void saveResourceBank();
	void paintCountersFigures(RenderWindow*);

	int StartWindowPressed() {
		return StartWindowSelected;
	}
	~StartWindow();
    RectangleShape rtsBtnSave, rtsBtnPlay, rtsBtnBack, rtsBtnDice, rtsBtnExit, rtsID, rtsName, rtsAge, rtsColor, background;
    Texture txtrBtnSave, txtrBtnBack, txtrBtnPlay;
    Text titlePlayer, txtTitle, txtTitleID, txtID, txtTitleName, txtName;
    Text txtTitleAge, txtAge, titleColor, txtRequiredFields;
	CircularList<Player> * playerList = new  CircularList<Player>;
	Bank bank;
	RectangleShape vectorLandsRTS[19];
	Texture vectorLandsTXT[19];
	RectangleShape rtsBtnStreet, rtsBtnTown, rtsBtnCity, rtsBtnEndTurn, rtsBtnDevelopment, rtsBtnTrade;
	RectangleShape rtsImgPlayer, rtsPlayerRed, rtsPlayerYellow, rtsPlayerGreen;
	Texture txtrImgPlayer, txtrPlayerRed, txtrPlayerYellow, txtrPlayerGreen;
	RectangleShape vectorTown[54], vectorBlackHouse[54];
	Texture txtTown;
	Color playersColor[5] = { Color::Blue, Color::Yellow, Color::Green, Color::Red, Color(187, 208, 216) };
	Graph graph;
	bool playersRegister = false;
	int playerCounter = 0;
	int id = 0;
	int posXDesertLand = 0;
	int posYDesertLand = 0;
	bool lands = false;
	bool numberPieces = false;
	bool townStatus = false;
	int LandsPosX[19] = { 753,672,589,552,512,550,589,670,751,791,831,791,711,632,592,632,711,750,672 };
	int LandsPosY[19] = { 228,228,228,285,344,401,457,457,457,401,344,285,285,285,344,401,401,343,343 };
	int woodR = 0, clayR = 0, mineralR = 0, sheepR = 0, cerealR = 0;
	int streetF = 0, townF = 0, cityF = 0;

private:	
	Font font;
	Event event;
	Mouse mouse;
	RectangleShape rtsLands;
	Texture txtrLands;
	int StartWindowSelected;	
	Text startMenu[optionMenu];
};