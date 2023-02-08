#include "Player.h"


Player::Player()
{}
Player::Player(int id, string name, int age, int victoryPoint, Color color)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->victoryPoint = victoryPoint;
    this->color = color;
    /*playerList = new CircularList<Player>;*/
  
    resourceCardsList = new CircularList<ResourceCard>;
    developmentCardList = new CircularList<DevelopmentCard>;
    specialCardList = new CircularList<SpecialCard>;
    figureList = new CircularList<Figure>;
    if (!font.loadFromFile("Fonts/LESLIE.ttf")) {
        cout << "��No Font!!";
    }
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

Color Player::getColor() {
    return color;
}

void Player::setColor(Color color) {

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
        /*<< getColor()*/ << endl;
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
        DevelopmentCard* info = new DevelopmentCard(cardNameP, powerCardP, positionXP, positionYP, quantityP, false);
        developmentCardList->inserNode(info);
    }
}

void Player::insertSpecialCard(string cardNameP, int powerCardP, int positionXP, int positionYP)
{
    SpecialCard* info = new SpecialCard(cardNameP, powerCardP, positionXP, positionYP);
    specialCardList->inserNode(info);
}

void Player::insertFigures(string cardNameP, int positionXP, int positionYP, int quantityP)
{
    if (figureList->existenceOfCard(cardNameP) == true) {
        figureList->increaseQuantity(cardNameP, quantityP);
    }
    else {
        Figure* info = new Figure(cardNameP, positionXP, positionYP, quantityP);
        figureList->inserNode(info);
    }
}
//
//void Player::showInformationPlayerInTurn() {
//
//}
void Player::buildTown(RenderWindow* Go, int verticeIndexX, int verticeIndexY)
{
    CircleShape town(8);
    town.setFillColor(Color::Red);
    town.setPosition(verticeIndexX, verticeIndexY);
    Go->draw(town);
    Go->display();
}

int Player::countDevelopmentCard() {
    int count = 0;
    nodeDevelopment = developmentCardList->first;
    do {
        count += nodeDevelopment->getData()->getQuantity();
        nodeDevelopment = nodeDevelopment->getNextNode();

    } while (nodeDevelopment != developmentCardList->first);

    return count;
}
