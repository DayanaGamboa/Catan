#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

#define Max_start_window 3
class StartWindow
{
public:
	StartWindow(float width, float height);
	void drawWindow(RenderWindow& window);
	void moveUp();
	void moveDown();
	void initializeWindow();
	void button();

	int StartWindowPressed() {
		return StartWindowSelected;
	}
	~StartWindow();

private:

	int StartWindowSelected;
	Font font;
	Text startMenu[Max_start_window];

};

