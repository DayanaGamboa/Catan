#include "Player.h"


Player::Player(int id, string name, int age, int victoryPoint, int color)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->victoryPoint = victoryPoint;
    this->color = color;
    playerList = new CircularList<Player>;
    resourceCardsList = new CircularList<ResourceCard>;
    developmentCardList = new CircularList<DevelopmentCard>;
    specialCardList = new CircularList<SpecialCard>;
    //figurelist = new CircularList<Figure>;
    if (!font.loadFromFile("Fonts/LESLIE.ttf")) {
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
        DevelopmentCard* info = new DevelopmentCard(cardNameP, powerCardP, positionXP, positionYP, quantityP, false);
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
    rtsBtnGuardar.setPosition(Vector2f(250, 580));
    rtsBtnGuardar.setSize(Vector2f(150, 80));
    txtrBtnGuardar.loadFromFile("resouceImages/btnGuardar.png");
    rtsBtnGuardar.setTexture(&txtrBtnGuardar);

    //JUGADOR 1    
    tituloJugador.setString("Datos del jugador");
    tituloJugador.setFont(font);
    tituloJugador.setFillColor(Color::Black);
    tituloJugador.setPosition(280, 160);

    //titulo ID    
    tituloID.setFont(font);
    tituloID.setString("ID ");
    tituloID.setFillColor(Color::Black);
    tituloID.setPosition(180, 230 + 10);

    // Caja de texto ID   
    rtsID.setSize(Vector2f(200, 50));
    rtsID.setFillColor(Color(187, 208, 216));
    rtsID.setPosition(270, 230);

    //Texto para la caja ID    
    txtID.setFont(font);
    txtID.setString(to_string(contadorJugadores + 1));
    txtID.setFillColor(Color::Black);
    txtID.setPosition(270, 230);

    //titulo nombre   
    tituloNombre.setFont(font);
    tituloNombre.setString("Nombre ");
    tituloNombre.setFillColor(Color::Black);
    tituloNombre.setPosition(180, 310);

    //Caja de texto nombre  
    rtsNombre.setSize(Vector2f(200, 50));
    rtsNombre.setFillColor(Color(187, 208, 216));
    rtsNombre.setPosition(270, 300);

    //Texto para la caja nombre    
    txtNombre.setFont(font);
    txtNombre.setFillColor(Color::Black);
    txtNombre.setPosition(270, 300);

    //titulo edad    
    tituloEdad.setFont(font);
    tituloEdad.setString("Edad ");
    tituloEdad.setFillColor(Color::Black);
    tituloEdad.setPosition(180, 380);

    //Caja de texto Edad    
    rtsEdad.setSize(Vector2f(200, 50));
    rtsEdad.setFillColor(Color(187, 208, 216));
    rtsEdad.setPosition(270, 370);

    //Texto para la caja Edad  
    txtEdad.setFont(font);
    txtEdad.setFillColor(Color::Black);
    txtEdad.setPosition(270, 370);

    //titulo color  
    tituloColor.setFont(font);
    tituloColor.setString("Color");
    tituloColor.setFillColor(Color::Black);
    tituloColor.setPosition(180, 460);

    //Caja de texto Color  
    rtsColor.setSize(Vector2f(200, 50));
    rtsColor.setPosition(270, 450);

    //Text para campos requeridos   
    txtCamposRequeridos.setFont(font);
    txtCamposRequeridos.setFillColor(Color::Black);
    txtCamposRequeridos.setPosition(250, 500);


    playerData->draw(fondo);
    playerData->draw(titulo1);
    playerData->draw(rtsBtnGuardar);

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
void Player::playerRegister(RenderWindow*) {
    StartWindow startWindow(X, Y);
    RenderWindow playerData(VideoMode(700, 700), "Registro de jugadores");

    rtsColor.setFillColor(Color::Blue);

    string nombre = "", edadString = "";
    Vector2i coordenadasMouse;
    int color = 0, edad = 0, puntosVictoria = 0;

    while (playerData.isOpen()) {

        Event event;
        while (playerData.pollEvent(event)) {

            if (event.type == Event::Closed) {
                playerData.close();
                startWindow.mainWindow();
            }
            if (event.type == Event::KeyPressed) {

                if (event.key.code == Keyboard::Escape) {
                    playerData.close();
                    startWindow.mainWindow();
                }
            }
            if (event.type == Event::MouseButtonPressed) {

                coordenadasMouse = mouse.getPosition(playerData);

                if (rtsBtnGuardar.getGlobalBounds().contains(Vector2<float>(coordenadasMouse))) {
                    if (contadorJugadores >= 4) {
                        txtID.setString("");
                        txtCamposRequeridos.setString("**Jugadores al limite**");
                    }
                    else if ((nombre == "") || (edadString == "")) {
                        txtCamposRequeridos.setString("**Campos requeridos**");
                    }

                    else {
                        edad = stoi(edadString);
                        id++;
                        contadorJugadores++;

                        if (contadorJugadores == 1) {
                            Player* player1 = new Player(id, nombre, edad, puntosVictoria, 1);
                            playerList->inserNode(player1);
                            cout << "Jugador 1 guardado correctamente" << endl;
                            rtsColor.setFillColor(Color::Red);
                        }
                        if (contadorJugadores == 2) {
                            Player* player2 = new Player(id, nombre, edad, puntosVictoria, 2);
                            playerList->inserNode(player2);
                            cout << "Jugador 2 guardado correctamente" << endl;
                            rtsColor.setFillColor(Color::Yellow);
                        }
                        if (contadorJugadores == 3) {
                            Player* player3 = new Player(id, nombre, edad, puntosVictoria, 3);
                            playerList->inserNode(player3);
                            registroJugadores = true;
                            cout << "Jugador 3 guardado correctamente" << endl;
                            rtsColor.setFillColor(Color::Green);
                        }
                        if (contadorJugadores == 4) {
                            Player* player4 = new Player(id, nombre, edad, puntosVictoria, 4);
                            playerList->inserNode(player4);
                            cout << "Jugador 4 guardado correctamente" << endl;
                        }

                        //Cuando guarda inicializa los valores 

                        nombre = "";
                        edadString = "";
                        puntosVictoria = 0, color = 0;

                        txtID.setString("");
                        txtNombre.setString("");
                        txtEdad.setString("");
                        txtCamposRequeridos.setString("");

                    }
                }
                if (rtsBtnAtras.getGlobalBounds().contains(Vector2<float>(coordenadasMouse))) {
                    playerData.close();
                    startWindow.mainWindow();
                }
                if (rtsBtnJugar.getGlobalBounds().contains(Vector2<float>(coordenadasMouse))) {
                    playerData.close();
                    startWindow.goWindow();
                }

            }
            if (event.type == Event::TextEntered) {

                if (rtsNombre.getGlobalBounds().contains(Vector2<float>(coordenadasMouse))) {

                    if ((event.text.unicode >= 32 && event.text.unicode <= 126) && ((txtNombre.getString().getSize() <= 20))) {
                        nombre += static_cast<char>(event.text.unicode);
                        txtNombre.setString(nombre);
                    }
                    if (event.text.unicode == 8 && nombre.length() > 0) {

                        nombre.pop_back();
                        txtNombre.setString(nombre);
                    }
                }
                if (rtsEdad.getGlobalBounds().contains(Vector2<float>(coordenadasMouse))) {

                    if ((event.text.unicode >= 48 && event.text.unicode <= 57) && ((txtEdad.getString().getSize() <= 1))) {
                        edadString += static_cast<char>(event.text.unicode);
                        txtEdad.setString(edadString);
                    }
                    if (event.text.unicode == 8 && edadString.length() > 0) {

                        edadString.pop_back();
                        txtEdad.setString(edadString);
                    }
                }
            }
        }


        playerData.clear();
        playerData.draw(rtsBtnJugar);
        paintPlayerRegister(&playerData);
        if ((contadorJugadores == 3) || (contadorJugadores == 4)) {
            //Boton de atras    

            rtsBtnJugar.setPosition(Vector2f(400, 580));
            rtsBtnJugar.setSize(Vector2f(150, 80));
            txtrBtnJugar.loadFromFile("resouceImages/btnJugar.png");
            rtsBtnJugar.setTexture(&txtrBtnJugar);
            playerData.draw(rtsBtnJugar);
        }
        playerData.display();
    }
}