#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

class GameArea
{

private:
	Font font;
	
	const string gameName = "CATAN";
	//Banca banca;
	//Ladron ladron;
public:

	GameArea(float width, float height);
	void generateGameArea();
	void putThief();
	void putConstructionCosts();
	void putCardsCradle();
	void putSpecialCards();
	void assignPlayerColor();
	void assignPlayerShift();
	void button();


};

