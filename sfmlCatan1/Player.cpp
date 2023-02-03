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
	cityList = new CircularList<City>;
	streetList = new CircularList<Street>;
	townList = new CircularList<Town>;
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
	cout << "Informaccion de cartas especiales que posee el jugador: " << endl << endl;
	specialCardList->dropDownList();

	return s.str();
}

void Player::insertResourceCard(string cardNameP, int powerCardP, int positionXP, int positionYP, int quantityP)
{
	if (resourceCardsList->existenceOfCard(cardNameP) == true) {
		resourceCardsList->increaseQuantity(cardNameP, quantityP);
	}
	else {
		ResourceCard* info = new ResourceCard(cardNameP, powerCardP, positionXP, positionYP, quantityP);
		resourceCardsList->inserNode(info);
	}
}

void Player::insertDevelopmentCard(string cardNameP, int powerCardP, int positionXP, int positionYP, int quantityP)
{
	if (developmentCardList->existenceOfCard(cardNameP) == true) {
		developmentCardList->increaseQuantity(cardNameP, quantityP);
	}
	else {
		DevelopmentCard* info = new DevelopmentCard(cardNameP, powerCardP, positionXP, positionYP, quantityP,false);
		developmentCardList->inserNode(info);
	}
}

void Player::insertSpecialCard(string cardNameP, int powerCardP, int positionXP, int positionYP)
{
	SpecialCard* info = new SpecialCard(cardNameP, powerCardP, positionXP, positionYP);
	specialCardList->inserNode(info);
}

void Player::insertFigures(string figureName, int positionX, int positionY)
{
	if (figureName == "city") {
		City* info = new City(figureName, positionX, positionY);
		cityList->inserNode(info);
	}
	else if (figureName == "street") {
		Street* info = new Street(figureName, positionX, positionY);
		streetList->inserNode(info);
	}
	else if (figureName == "town") {
		Town* info = new Town(figureName, positionX, positionY);
		townList->inserNode(info);
	}
}
