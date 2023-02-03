#include "Player.h"


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
	//figurelist = new CircularList<Figure>;
    if (!font.loadFromFile("Fonts/Wintertime.ttf")) {
        cout << "¡¡No Font!!";
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
void Player::paintPlayerRegister(RenderWindow* playerData) {
    
    //MENU
    fondo.setSize(Vector2f(700, 700));
    fondo.setFillColor(Color(220, 245, 255));

    titulo1.setFont(font);
    titulo1.setString("Registro de jugadores: (3-4)");
    titulo1.setFillColor(Color::Black);
    titulo1.setPosition(200, 10);
    titulo1.setCharacterSize(50);

    //Boton de aceptar    
    rtsBtnAceptar.setPosition(Vector2f(300, 600));
    rtsBtnAceptar.setSize(Vector2f(120, 50));  
    txtrBtnAceptar.loadFromFile("resouceImages/btnSave.png");
    rtsBtnAceptar.setTexture(&txtrBtnAceptar);

    //JUGADOR 1    
    tituloJugador.setFont(font);    
    tituloJugador.setFillColor(Color::Black);
    tituloJugador.setPosition(300, 160);

    //titulo ID    
    tituloID.setFont(font);
    tituloID.setString("ID ");
    tituloID.setFillColor(Color::Black);
    tituloID.setPosition(180, 230 + 10);

    // Caja de texto ID   
    rtsID.setSize(Vector2f(200, 50));
    rtsID.setFillColor(Color(187, 208, 216));
    rtsID.setPosition(250, 230);

    //Texto para la caja ID    
    txtID.setFont(font);    
    txtID.setFillColor(Color::Black);
    txtID.setPosition(250, 230);

    //titulo nombre   
    tituloNombre.setFont(font);
    tituloNombre.setString("Nombre ");
    tituloNombre.setFillColor(Color::Black);
    tituloNombre.setPosition(180, 310);

    //Caja de texto nombre  
    rtsNombre.setSize(Vector2f(200, 50));
    rtsNombre.setFillColor(Color(187, 208, 216));
    rtsNombre.setPosition(250, 300);

    //Texto para la caja nombre    
    txtNombre.setFont(font);  
    txtNombre.setFillColor(Color::Black);
    txtNombre.setPosition(250, 300);

    //titulo edad    
    tituloEdad.setFont(font);
    tituloEdad.setString("Edad ");
    tituloEdad.setFillColor(Color::Black);
    tituloEdad.setPosition(180, 380);

    //Caja de texto Edad    
    rtsEdad.setSize(Vector2f(200, 50));
    rtsEdad.setFillColor(Color(187, 208, 216));
    rtsEdad.setPosition(250, 370);

    //Texto para la caja Edad  
    txtEdad.setFont(font);   
    txtEdad.setFillColor(Color::Black);
    txtEdad.setPosition(250, 370);

    //titulo color  
    tituloColor.setFont(font);
    tituloColor.setString("Color");
    tituloColor.setFillColor(Color::Black);
    tituloColor.setPosition(180, 460);

    //Caja de texto Color  
    rtsColor.setSize(Vector2f(200, 50));   
    rtsColor.setPosition(250, 450);

    //Text para campos requeridos   
    txtCamposRequeridos.setFont(font);   
    txtCamposRequeridos.setFillColor(Color::Black);
    txtCamposRequeridos.setPosition(250, 500);


    playerData->draw(fondo);
    playerData->draw(titulo1);
    playerData->draw(rtsBtnAceptar);

    playerData->draw(tituloJugador);

    playerData->draw(tituloID);
    playerData->draw(rtsID);
    playerData->draw(txtID);

    playerData->draw(tituloNombre);
    playerData->draw(rtsNombre);
    playerData->draw(txtNombre);

    playerData->draw(tituloEdad);
    playerData->draw(rtsEdad);
    playerData->draw(txtEdad);

    playerData->draw(tituloColor);
    playerData->draw(rtsColor);

    playerData->draw(txtCamposRequeridos);

}
