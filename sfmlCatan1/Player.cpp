#include "Player.h"
#include<sstream>


Player::Player(int idP)
{
	id = idP;
}

Player::~Player()
{
}

int Player::getId() {
	return id;
}

void Player::setId(int idP) {

	id = idP;
}

void Player::throwsDice()
{
}

void Player::build()
{
}

void Player::trade()
{
}

void Player::victoryPoints()
{
}

void Player::useDevelopmentCards()
{
}

void Player::endTurn()
{
}

string Player::toString() {
	stringstream s;
	s << "ide: " << getId() << endl;
	return s.str();
}


