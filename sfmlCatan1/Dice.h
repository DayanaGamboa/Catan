#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
using namespace std;
using namespace sf;
class Dice
{
public:
	Dice();
	~Dice();
	int diceFinalAmount(RenderWindow*);
	bool paintDices = false;
	RectangleShape rtsDice1, rtsDice2;
	Texture txtrRtsDice1, txtrRtsDice2;
};