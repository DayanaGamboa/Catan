#include "Player.h"
#include<sstream>


Player::Player(int id, string name, int age, int victoryPoint, int color)
{
	this->id = id;
	this->name = name;
	this->age = age;
	this->victoryPoint = victoryPoint;
	this->color = color;

	resourceCardsList = new CircularList<ResourceCard>;
	developmentCardList = new CircularList<DevelopmentCard>;
	specialCardList = new CircularList<SpecialCard>;
	figurelist = new CircularList<Figure>;
}

Player::~Player()
{
}

int Player::getId() {
	return id;
}

void Player::setId(int id) {

	this->id = id;
}

string Player::getName() {
	return name;
}

void Player::setName(string name) {

	this->name = name;
}

int Player::getAge() {
	return age;
}

void Player::setAge(int age) {

	this->age = age;
}

int Player::getVictoryPoint() {
	return victoryPoint;
}

void Player::setVictoryPoint(int victoryPoint) {

	this->victoryPoint = victoryPoint;
}

int Player::getColor() {
	return color;
}

void Player::setColor(int color) {

	this->color = color;
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
	s << getId() << " " << getName() << " " << getAge() << " " << getVictoryPoint() << " " 
		<< getColor() << endl;
	cout << "Informaccion de cartas de recursos que posee el jugador: " << endl;
	resourceCardsList->dropDownList();
	cout << "Informaccion de cartas de desarrollo que posee el jugador: " << endl << endl;
	developmentCardList->dropDownList();
	cout << "Informaccion de cartas speciales que posee el jugador: " << endl << endl;
	specialCardList->dropDownList();

	return s.str();
}

void Player::insertResourceCard(string cardNameP, int powerCardP, int positionXP, int positionYP, int quantityP)
{
	if (resourceCardsList->existenceOfCard(cardNameP) == true) {
		//resourceCardsList->
	}
	ResourceCard* info = new ResourceCard(cardNameP, powerCardP, positionXP, positionYP, quantityP);
	resourceCardsList->inserNode(info);
}

//void Player::showCard(){
//	cout << "Informaccion de cartas de recursos que posee el jugador: " << endl;
//	resourceCardsList->showCards();
//	cout << "Informaccion de cartas de desarrollo que posee el jugador: " << endl << endl;
//	//developmentCardList->desplegarLista();
//	cout << "Informaccion de cartas speciales que posee el jugador: " << endl << endl;
//	cout << "Informaccion de figuras que posee el jugador: " << endl << endl;
//}



