#pragma once
#include <list>
#include "Player.h"
class Partida
{
public:
	Partida();
	~Partida();

	void startGame();
	void saveGame();
	void loadGame();
	void exitGame();

private:
	/*list<Player> players;*///? TEMPLATE
};

