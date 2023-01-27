#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include<ctime>
#include<time.h> 
#include<windows.h> 

using namespace std;
using namespace sf;

#define optionMenu 3
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

	void ventanaPrincipal();
	void ventanaGo();
	void ventanaAbout();


	void pintaMateriasPrimas(RenderWindow*, int);
	void pintaDados(RenderWindow*);
	void pintaMazosContrincantes(RenderWindow*, int);
	void pintaCartasEspeciales(RenderWindow*);

	void pintaTerrenos(RenderWindow*, RectangleShape&, Texture&, int, int);
	void pintaTerrenos2(RenderWindow*);


	int StartWindowPressed() {
		return StartWindowSelected;
	}
	~StartWindow();

private:
	Event event;

	RectangleShape rtsDado1;
	Texture txtrRtsDado1;
	RectangleShape rtsDado2;
	Texture txtrRtsDado2;


	

	int StartWindowSelected;
	Font font;
	Text startMenu[optionMenu];

};

