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

string Player::toString() {
    stringstream s;
    s << getId() << " " << getName() << " " << getAge() << " " << getVictoryPoint() << " " << endl;

    nodeResource = resourceCardsList->first;
    do {
        s << nodeResource->getData()->toString();
        nodeResource = nodeResource->getNextNode();
    } while (nodeResource != resourceCardsList->first);


    nodeDevelopment = developmentCardList->first;
    do {
        s << nodeDevelopment->getData()->toString();
        nodeDevelopment = nodeDevelopment->getNextNode();
    } while (nodeDevelopment != developmentCardList->first);


    nodeFigure = figureList->first;
    do {
        s << nodeFigure->getData()->toString();
        nodeFigure = nodeFigure->getNextNode();
    } while (nodeFigure != figureList->first);

    nodeSpecial = specialCardList->first;
    do {
        s << nodeSpecial->getData()->toString();
        nodeSpecial = nodeSpecial->getNextNode();
    } while (nodeSpecial != specialCardList->first);

    return s.str();
}

void Player::insertResourceCard(string cardNameP, int quantityP)
{
    if (resourceCardsList->existenceOfCard(cardNameP) == true) {
        resourceCardsList->increaseQuantity(cardNameP, quantityP);
    }
    else {
        ResourceCard* info = new ResourceCard(cardNameP, quantityP);
        resourceCardsList->inserNode(info);
    }
}

void Player::insertDevelopmentCard(string cardNameP, int quantityP)
{
    if (developmentCardList->existenceOfCard(cardNameP) == true) {
        developmentCardList->increaseQuantity(cardNameP, quantityP);
    }
    else {
        DevelopmentCard* info = new DevelopmentCard(cardNameP, quantityP);
        developmentCardList->inserNode(info);
    }
}

void Player::insertSpecialCard(string cardNameP, int quantityP)
{
    if (specialCardList->existenceOfCard(cardNameP) == true) {
        specialCardList->increaseQuantity(cardNameP, quantityP);
    }
    else {
        SpecialCard* info = new SpecialCard(cardNameP, quantityP);
        specialCardList->inserNode(info);
    }
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

void Player::loadList() {
    insertResourceCard("madera", 2);
    insertResourceCard("arcilla", 2);
    insertResourceCard("lana", 2);
    insertResourceCard("mineral", 0);
    insertResourceCard("cereal", 2);
    insertDevelopmentCard("caballero", 0);
    insertDevelopmentCard("progreso", 0);
    insertDevelopmentCard("PuntosVictoria", 0);
    insertFigures("carretera", 0, 0, 15);
    insertFigures("poblado", 0, 0, 4);
    insertFigures("ciudad", 0, 0, 5);
    insertSpecialCard("mayor ruta", 0);
    insertSpecialCard("mayor ejercito", 0);
}
