#include "StartWindow.h"

StartWindow::StartWindow(float widht, float height) {
    if (!font.loadFromFile("Fonts/LESLIE.ttf")) {
        cout << "��No Font!!";
    }
    int num = 200;
    for (int i = 0; i < 4; i++) {
        //Start Game
        startMenu[i].setFont(font);
        startMenu[i].setFillColor(Color::White);
        startMenu[i].setCharacterSize(70);
        startMenu[i].setPosition(800, num);
        num += 100;
    }

    startMenu[0].setString("Jugar");
    startMenu[0].setFillColor(Color::Cyan);


    startMenu[1].setString("Cargar partida");
    startMenu[2].setString("Acerca de");
    startMenu[3].setString("Salir");

    StartWindowSelected = 0;
}


StartWindow::~StartWindow() {}

//Draw Window

void StartWindow::drawWindow(RenderWindow& window) {
    for (int i = 0; i < optionMenu; i++) {
        window.draw(startMenu[i]);
    }
}


void StartWindow::moveUp() {

    if (StartWindowSelected >= 0) {

        startMenu[StartWindowSelected].setFillColor(Color::White);

        if (StartWindowSelected == 0) {
            StartWindowSelected = 4;
        }
        StartWindowSelected--;

        startMenu[StartWindowSelected].setFillColor(Color::Cyan);
    }

}

void StartWindow::moveDown() {

    if (StartWindowSelected <= 3)
    {
        startMenu[StartWindowSelected].setFillColor(Color::White);
        StartWindowSelected++;
        if (StartWindowSelected == 4) {
            StartWindowSelected = 0;
        }
        startMenu[StartWindowSelected].setFillColor(Color::Cyan);

    }
}

void StartWindow::mainWindow()
{
    RenderWindow windowMENU(VideoMode(X, Y), "Start Game Window", Style::Default);
    StartWindow  startMenu(windowMENU.getSize().x, windowMENU.getSize().y);
    Player player(0, "", 0,0,Color::White);
    RectangleShape background;
    background.setSize(Vector2f(X, Y));
    Texture startWindowImage;
    startWindowImage.loadFromFile("resouceImages/startMenu.jpg");
    background.setTexture(&startWindowImage);

    while (windowMENU.isOpen()) {

        while (windowMENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
                windowMENU.close();
            }
            if (event.type == Event::KeyReleased) {

                if (event.key.code == Keyboard::Up) {
                    startMenu.moveUp();
                    break;
                }
                if (event.key.code == Keyboard::Down) {
                    startMenu.moveDown();
                    break;
                }
                if (event.key.code == Keyboard::Return) {

                    int pos = startMenu.StartWindowPressed();
                    if (pos == 0) {
                        windowMENU.close();
                        playerRegister(&windowMENU);
                    }
                    if (pos == 1) {


                    }
                    if (pos == 2) {
                        windowMENU.close();
                        aboutWindow();
                    }
                    if (pos == 3) {
                        windowMENU.close();
                        break;
                    }
                }
            }
        }
        windowMENU.clear();
        windowMENU.draw(background);
        startMenu.drawWindow(windowMENU);
        windowMENU.display();
    }
}
void StartWindow::goWindow() {
    RenderWindow Go(VideoMode(X, Y), "Area de juego");    
    Graph graph;   
    Dice dice;
    while (Go.isOpen()) {

        while (Go.pollEvent(event)) {
            if (event.type == Event::Closed) {
                exitButton(&Go);
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {

                    exitButton(&Go);
                }
            }
            if (event.type == Event::MouseButtonPressed) {
                Vector2i coordinatesMouse = mouse.getPosition(Go);
                

                if (rtsBtnDice.getGlobalBounds().contains(Vector2<float>(coordinatesMouse))) {
                    dice.paintDices = false;
                    dice.diceFinalAmount(&Go);
                }
                if (rtsBtnExit.getGlobalBounds().contains(Vector2<float>(coordinatesMouse))) {
                    exitButton(&Go);
                }
                if (rtsBtnSave.getGlobalBounds().contains(Vector2<float>(coordinatesMouse))) {
                    cout << "Guardar" << endl;
                }
                if (rtsBtnStreet.getGlobalBounds().contains(Vector2<float>(coordinatesMouse))) {
                    cout << "Carretera" << endl;
                }
                if (rtsBtnCity.getGlobalBounds().contains(Vector2<float>(coordinatesMouse))) {
                    cout << "Ciudad" << endl;
                }
                if (rtsBtnTown.getGlobalBounds().contains(Vector2<float>(coordinatesMouse))) {
                    cout << "Poblado" << endl;
                }
                if (rtsBtnDevelopment.getGlobalBounds().contains(Vector2<float>(coordinatesMouse))) {
                    cout << "Desarrollo" << endl;
                }
                if (rtsBtnTrade.getGlobalBounds().contains(Vector2<float>(coordinatesMouse))) {
                    cout << "Comerciar" << endl;
                }
                if (rtsBtnEndTurn.getGlobalBounds().contains(Vector2<float>(coordinatesMouse))) {
                    cout << "Terminar turno" << endl;
                    actualNode = actualNode->getNextNode();
                }
                for (int i = 0; i < graph.circlesV.size(); i++) {

                    if ((graph.circlesV[i].getGlobalBounds().contains(Vector2<float>(coordinatesMouse))))
                    {
                        builtTown(&Go, i);
                        cout << "pintado" << endl;
                        break;
                    }

                }

            }
        }        
        generateGameArea(&Go);
        paintLands(&Go);
        paintNumberPieces(&Go);
        dice.diceFinalAmount(&Go); 
        graph.drawVertex(&Go);
        graph.drawEdges(&Go);
        paintTowns(&Go);
        paintResource(&Go, 10, 10);
        paintResource(&Go, 10, 670);
        paintOpponentDeck(&Go, playerList->getSize());;
        paintSpecialCards(&Go);
        PlayerInTurn(&Go);
        paintBankCounters(&Go);
        paintPlayerCountersInTurn(&Go);
        Go.display();
    }
}

void StartWindow::aboutWindow()
{
    RectangleShape aBackground;
    aBackground.setSize(Vector2f(X, Y));
    Texture aboutWindowImage;
    aboutWindowImage.loadFromFile("resouceImages/About.png");
    aBackground.setTexture(&aboutWindowImage);

    //Boton de atras    
    
    rtsBtnBack.setPosition(Vector2f(100, 720));
    rtsBtnBack.setSize(Vector2f(150, 80));
    Texture txtrBtnAtras;
    txtrBtnAtras.loadFromFile("resouceImages/btnAtras.png");
    rtsBtnBack.setTexture(&txtrBtnAtras);

    RenderWindow About(VideoMode(X, Y), "About");
    Vector2i mouseCoordinates;

    while (About.isOpen()) {

        while (About.pollEvent(event)) {
            if (event.type == Event::Closed) {
                About.close();
                mainWindow();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    About.close();
                    mainWindow();
                }
            }
            if (event.type == Event::MouseButtonPressed) {
                mouseCoordinates = mouse.getPosition(About);
                if (rtsBtnBack.getGlobalBounds().contains(Vector2<float>(mouseCoordinates))) {
                    About.close();
                    mainWindow();
                }
            }
        }
        About.clear();
        About.draw(aBackground);
        About.draw(rtsBtnBack);
        About.display();
    }
}

void StartWindow::paintResource(RenderWindow* Go, int x, int y)
{
    string path = "";
    RectangleShape rectangleShape;
    Texture texture1;
    for (int i = 0; i < 6; i++) {
        path = "resouceImages/MP";
        rectangleShape.setPosition(Vector2f(x, y));
        rectangleShape.setSize(Vector2f(70, 100));
        path += to_string(i + 1);
        path += ".png";
        texture1.loadFromFile(path);
        rectangleShape.setTexture(&texture1);
        Go->draw(rectangleShape);
        x += 90;

    }
}


void StartWindow::paintOpponentDeck(RenderWindow* Go, int quantityDecks)
{
    

    string pathImagePlayer[4] = { "resouceImages/jugadorAzul.png", "resouceImages/jugadorRojo.png", "resouceImages/jugadorAmarillo.png", "resouceImages/jugadorVerde.png" };
    RectangleShape rtsResource, rtsDevelopment;
    Texture txtrResource, txtrDevelopment;
    string routeResource = "resouceImages/MP6.png", routeDevelopment = "resouceImages/MP7.png";
    int posXResource = 10, posXDevelopment = 90, posYCards = 170, posYImage = 190, posXImage = 180;
    Text txtPVPlayers[4] = {}, txtPVPlayer1, txtPVPlayer2, txtPVPlayer3, txtPVPlayer4;

    for (int i = 0; i < quantityDecks; i++) {
        //cartas de recursos
        rtsResource.setPosition(Vector2f(posXResource, posYCards));
        rtsResource.setSize(Vector2f(70, 100));
        txtrResource.loadFromFile(routeResource);
        rtsResource.setTexture(&txtrResource);
        Go->draw(rtsResource);

        //cartas de desarrollo
        rtsDevelopment.setPosition(Vector2f(posXDevelopment, posYCards));
        rtsDevelopment.setSize(Vector2f(70, 100));
        txtrDevelopment.loadFromFile(routeDevelopment);
        rtsDevelopment.setTexture(&txtrDevelopment);
        Go->draw(rtsDevelopment);

        //cuadrado color
        RectangleShape rtsColor2;
        rtsColor2.setPosition(Vector2f(posXImage, posYImage));
        rtsColor2.setSize(Vector2f(50, 50));
        rtsColor2.setFillColor(playersColor[i]);
        Go->draw(rtsColor2);

        //imagen jugador-Negro
        rtsImgPlayer.setPosition(Vector2f(posXImage, posYImage));
        rtsImgPlayer.setSize(Vector2f(50, 50));
        txtrImgPlayer.loadFromFile("resouceImages/jugadorNegro.png");
        rtsImgPlayer.setTexture(&txtrImgPlayer);
        Go->draw(rtsImgPlayer);

        posYCards += 110;
        posYImage += 110;
    }


    txtPVPlayer1.setString(to_string(nodePlayer1->getData()->getVictoryPoint()));
    txtPVPlayer1.setFont(font);
    txtPVPlayer1.setFillColor(Color::Black);
    txtPVPlayer1.setPosition(posXImage + 60, 190 + 10);

    txtPVPlayer2.setString(to_string(nodePlayer2->getData()->getVictoryPoint()));
    txtPVPlayer2.setFont(font);
    txtPVPlayer2.setFillColor(Color::Black);
    txtPVPlayer2.setPosition(posXImage + 60, 300 + 10);

    txtPVPlayer3.setString(to_string(nodePlayer3->getData()->getVictoryPoint()));
    txtPVPlayer3.setFont(font);
    txtPVPlayer3.setFillColor(Color::Black);
    txtPVPlayer3.setPosition(posXImage + 60, 410 + 10);

    if (quantityDecks == 4) {
        txtPVPlayer4.setString(to_string(nodePlayer4->getData()->getVictoryPoint()));
        txtPVPlayer4.setFont(font);
        txtPVPlayer4.setFillColor(Color::Black);
        txtPVPlayer4.setPosition(posXImage + 60, 520 + 10);
        Go->draw(txtPVPlayer4);
    }
   

    Go->draw(txtPVPlayer1);
    Go->draw(txtPVPlayer2);
    Go->draw(txtPVPlayer3);
  
}

void StartWindow::paintSpecialCards(RenderWindow* Go)
{
    RectangleShape rts;
    Texture txtr;
    int pos = 550;
    string path = "";

    for (int i = 1; i < 4; i++) {
        path = "resouceImages/E";
        rts.setPosition(Vector2f(pos, 640));
        rts.setSize(Vector2f(110, 130));
        path += to_string(i);
        path += ".png";
        txtr.loadFromFile(path);
        rts.setTexture(&txtr);
        Go->draw(rts);
        pos += 130;
    }
}

void StartWindow::exitButton(RenderWindow* Go) {

    RenderWindow windowExit(VideoMode(400, 300), "Salir");
    //set background
    RectangleShape backExit;
    backExit.setSize(Vector2f(400, 300));
    backExit.setFillColor(Color(220, 245, 255));

    Text text("�Seguro que deseas salir?", font, 35);
    text.setFillColor(Color::Black);
    text.setPosition(Vector2f(40, 20));

    //Si
    RectangleShape rtsBtnYes;
    rtsBtnYes.setSize(Vector2f(150, 50));
    rtsBtnYes.setPosition(Vector2f(50, 200));
    Texture textureRtsBtnYes;
    textureRtsBtnYes.loadFromFile("resouceImages/btnSi.png");
    rtsBtnYes.setTexture(&textureRtsBtnYes);
    //No
    RectangleShape rtsBtnNo;
    rtsBtnNo.setSize(Vector2f(150, 50));
    rtsBtnNo.setPosition(Vector2f(200, 200));
    Texture textureRtsBtnNo;
    textureRtsBtnNo.loadFromFile("resouceImages/btnNo.png");
    rtsBtnNo.setTexture(&textureRtsBtnNo);

    while (windowExit.isOpen()) {

        while (windowExit.pollEvent(event)) {
            if (event.type == Event::MouseButtonPressed) {

                Vector2i coordinatesMouse = mouse.getPosition(windowExit);

                if (rtsBtnYes.getGlobalBounds().contains(Vector2<float>(coordinatesMouse))) {
                    windowExit.close();
                    Go->close();
                    mainWindow();
                }
                if (rtsBtnNo.getGlobalBounds().contains(Vector2<float>(coordinatesMouse))) {
                    windowExit.close();
                }
            }
        }
        windowExit.clear();
        windowExit.draw(backExit);
        windowExit.draw(rtsBtnYes);
        windowExit.draw(rtsBtnNo);
        windowExit.draw(text);

        windowExit.display();
    }
}

void StartWindow::saveGameButton(RenderWindow*)
{
    
}

void StartWindow::loadGameButton(RenderWindow*)
{
}

void StartWindow::generateGameArea(RenderWindow* Go) {
    //MAR
    RectangleShape rtsSea;
    rtsSea.setSize(Vector2f(X, Y));
    Texture textureRtsSea;
    textureRtsSea.loadFromFile("resouceImages/goGame.jpg");
    rtsSea.setTexture(&textureRtsSea);
    Go->draw(rtsSea);

    //Hexagono para los terrenos
    RectangleShape rtsLand;
    rtsLand.setPosition(Vector2f(450, 120));
    rtsLand.setSize(Vector2f(510, 510));
    Texture textureRtsLand;
    textureRtsLand.loadFromFile("resouceImages/AreaJuego.png");
    rtsLand.setTexture(&textureRtsLand);
    Go->draw(rtsLand);

    //Bank
    RectangleShape rtsBank;
    rtsBank.setPosition(Vector2f(550, 30));
    rtsBank.setSize(Vector2f(64, 64));
    Texture textureRtsBank;
    textureRtsBank.loadFromFile("resouceImages/banco.png");
    rtsBank.setTexture(&textureRtsBank);
    Go->draw(rtsBank);

    //btnDice
    rtsBtnDice.setPosition(Vector2f(700, 10));
    rtsBtnDice.setSize(Vector2f(180, 100));
    Texture textureRtsBtnDice;
    textureRtsBtnDice.loadFromFile("resouceImages/btnTirarDados.png");  
    rtsBtnDice.setTexture(&textureRtsBtnDice);
    Go->draw(rtsBtnDice);

    //btnGuardar
    rtsBtnSave.setPosition(Vector2f(1170, 10));
    rtsBtnSave.setSize(Vector2f(150, 50));
    Texture textureRtsBtnSave;
    textureRtsBtnSave.loadFromFile("resouceImages/btnGuardar.png");
    rtsBtnSave.setTexture(&textureRtsBtnSave);
    Go->draw(rtsBtnSave);

    //btnSalir
    rtsBtnExit.setPosition(Vector2f(1170, 70));
    rtsBtnExit.setSize(Vector2f(150, 50));
    Texture textureRtsBtnExit;
    textureRtsBtnExit.loadFromFile("resouceImages/btnSalir.png");
    rtsBtnExit.setTexture(&textureRtsBtnExit);
    Go->draw(rtsBtnExit);

    //btnCarretera
    rtsBtnStreet.setPosition(Vector2f(1170, 200));
    rtsBtnStreet.setSize(Vector2f(150, 50));
    Texture txtrBtnStreet;
    txtrBtnStreet.loadFromFile("resouceImages/btnCarretera.png");
    rtsBtnStreet.setTexture(&txtrBtnStreet);
    Go->draw(rtsBtnStreet);

    //btnCiudad
    rtsBtnCity.setPosition(Vector2f(1170, 260));
    rtsBtnCity.setSize(Vector2f(150, 50));
    Texture txtrBtnCity;
    txtrBtnCity.loadFromFile("resouceImages/btnCiudad.png");
    rtsBtnCity.setTexture(&txtrBtnCity);
    Go->draw(rtsBtnCity);

    //btnPoblado
    rtsBtnTown.setPosition(Vector2f(1170, 320));
    rtsBtnTown.setSize(Vector2f(150, 50));
    Texture txtrBtnTown;
    txtrBtnTown.loadFromFile("resouceImages/btnPoblado.png");
    rtsBtnTown.setTexture(&txtrBtnTown);
    Go->draw(rtsBtnTown);

    //btnDesarrollo
    rtsBtnDevelopment.setPosition(Vector2f(1170, 380));
    rtsBtnDevelopment.setSize(Vector2f(150, 50));
    Texture txtrBtnDevelopment;
    txtrBtnDevelopment.loadFromFile("resouceImages/btnDesarrollo.png");
    rtsBtnDevelopment.setTexture(&txtrBtnDevelopment);
    Go->draw(rtsBtnDevelopment);

    //btnComerciar
    rtsBtnTrade.setPosition(Vector2f(1170, 440));
    rtsBtnTrade.setSize(Vector2f(150, 50));
    Texture txtrBtnTrade;
    txtrBtnTrade.loadFromFile("resouceImages/btnComerciar.png");
    rtsBtnTrade.setTexture(&txtrBtnTrade);
    Go->draw(rtsBtnTrade);

    //btnTerminarTurno
    rtsBtnEndTurn.setPosition(Vector2f(1170, 500));
    rtsBtnEndTurn.setSize(Vector2f(150, 50));
    Texture txtrBtnEndTurn;
    txtrBtnEndTurn.loadFromFile("resouceImages/btnTerminarTurno.png");
    rtsBtnEndTurn.setTexture(&txtrBtnEndTurn);
    Go->draw(rtsBtnEndTurn);
    
}
void StartWindow::paintLands(RenderWindow* Go) {

    
    string path = "";
    Thief thief;
    //Terrenos
    if (lands == false) {

        RectangleShape rts;
        Texture txtr;
        for (int i = 0; i < 19; i++) {
            vectorLandsRTS[i] = rts;
            vectorLandsTXT[i] = txtr;
        }


        int vectorLands[6] = { 4, 4, 4, 3, 3, 1 };//para saber cuantos terrenos de cada uno
        int number = 0, contLands = 0;


        srand(time(NULL));
        while (contLands <= 18) {
            number = 0 + rand() % 6;
            if (vectorLands[number] != 0) {
                if (number == 5) {
                   /* thief.positionX = TerrenosPosX[contTerrenos];
                    thief.positionY = TerrenosPosY[contTerrenos];*/
                    posXDesertLand = LandsPosX[contLands];
                    posYDesertLand = LandsPosY[contLands];
                }
                vectorLandsRTS[contLands].setPosition(Vector2f(LandsPosX[contLands], LandsPosY[contLands]));
                vectorLandsRTS[contLands].setSize(Vector2f(68.5, 68.5));

                path = "resouceImages/T";
                path += to_string(number);
                path += ".png";
                vectorLandsTXT[contLands].loadFromFile(path);

                Texture* txt;
                txt = &vectorLandsTXT[contLands];
                vectorLandsRTS[contLands].setTexture(txt);
                //Go->draw(vectorTerrenosRTS[contTerrenos]);
                vectorLands[number] = vectorLands[number] - 1;
                contLands++;
            }
        }
        lands = true;
    }

    for (int i = 0; i < 19; i++) {
        Go->draw(vectorLandsRTS[i]);
    }

}
void StartWindow::paintNumberPieces(RenderWindow* Go) {

    RectangleShape numberPiecesRts[19], numberPieceRts;
    Texture numberPiecesTxtr[19], numberPieceTxtr;
    Texture* txt;
    string path = "";

    for (int i = 0; i < 19; i++) {

        numberPiecesRts[i] = numberPieceRts;
        numberPiecesTxtr[i] = numberPieceTxtr;
    }

    int numberedPieceNumber[18] = { 5, 2, 6, 3, 8, 10, 9, 12, 11, 4, 8, 10, 9, 4, 5, 6, 3, 11 };
    int posNumberedPieceNumber = 0;
    for (int i = 0; i < 19; i++) {
        if ((LandsPosX[i] == posXDesertLand) && (LandsPosY[i] == posYDesertLand)) { //poner las del ladron
            numberPiecesRts[i].setPosition(Vector2f(posXDesertLand, posYDesertLand));  //poner las del ladron
            numberPiecesRts[i].setSize(Vector2f(70, 70));
            numberPiecesTxtr[i].loadFromFile("resouceImages/Ladron.png");
            txt = &numberPiecesTxtr[i];
            numberPiecesRts[i].setTexture(txt);
            Go->draw(numberPiecesRts[i]);
            i++;
        }
        numberPiecesRts[i].setPosition(Vector2f(LandsPosX[i], LandsPosY[i]));
        numberPiecesRts[i].setSize(Vector2f(70, 70));

        path = "resouceImages/N";
        path += to_string(numberedPieceNumber[posNumberedPieceNumber]);
        path += ".png";

        numberPiecesTxtr[i].loadFromFile(path);

        txt = &numberPiecesTxtr[i];
        numberPiecesRts[i].setTexture(txt);
        Go->draw(numberPiecesRts[i]);
        posNumberedPieceNumber++;

    }

    for (int i = 0; i < 19; i++) {
        Go->draw(numberPiecesRts[i]);
    }
}
void StartWindow::PlayerInTurn(RenderWindow* Go) {

    string playerID = to_string(actualNode->getData()->getId()), playerName = actualNode->getData()->getName();
    Color playerColor = actualNode->getData()->getColor();
    int puntosVictoria = actualNode->getData()->getVictoryPoint();

    RectangleShape rtsBackPlayer;
    rtsBackPlayer.setPosition(950, 640);
    rtsBackPlayer.setSize(Vector2f(350, 130));
    rtsBackPlayer.setFillColor(Color(220, 245, 255));
    Go->draw(rtsBackPlayer);

    //Titulo  
    Text description;
    description.setString("Datos del jugador en turno");
    description.setFont(font);
    description.setFillColor(Color::Black);
    description.setPosition(980, 635);
    Go->draw(description);

    //titulo ID  
    Text ID;
    ID.setFont(font);
    ID.setString("ID:  ");
    ID.setFillColor(Color::Black);
    ID.setPosition(955, 670);
    ID.setString(ID.getString() + playerID);
    Go->draw(ID);

    //titulo PV 
    Text PV;
    PV.setFont(font);
    PV.setString("PV:  ");
    PV.setFillColor(Color::Black);
    PV.setPosition(1150, 670);
    PV.setString(PV.getString() + to_string(puntosVictoria));
    Go->draw(PV);

    //titulo nombre   
    Text name;
    name.setFont(font);
    name.setString("Nombre:  ");
    name.setFillColor(Color::Black);
    name.setPosition(955, 700);
    name.setString(name.getString() + playerName);
    Go->draw(name);

    //titulo color  
    Text color;
    color.setFont(font);
    color.setString("Color:  ");
    color.setFillColor(Color::Black);
    color.setPosition(955, 730);
    Go->draw(color);

    RectangleShape rtsPlayerColor;
    rtsPlayerColor.setSize(Vector2f(50, 20));
    rtsPlayerColor.setPosition(1050, 740);
    rtsPlayerColor.setFillColor(playerColor);
    Go->draw(rtsPlayerColor);
}

void  StartWindow::paintPlayerRegister(RenderWindow* playerData) {
    //MENU
    background.setSize(Vector2f(700, 700));
    background.setFillColor(Color(220, 245, 255));

    txtTitle.setFont(font);
    txtTitle.setString("Registro de jugadores: (3-4)");
    txtTitle.setFillColor(Color::Black);
    txtTitle.setPosition(200, 10);
    txtTitle.setCharacterSize(50);

    //Boton de aceptar    
    rtsBtnSave.setPosition(Vector2f(150, 580));
    rtsBtnSave.setSize(Vector2f(150, 50));
    txtrBtnSave.loadFromFile("resouceImages/btnGuardar.png");
    rtsBtnSave.setTexture(&txtrBtnSave);

    //JUGADOR 1    
    titlePlayer.setString("Datos del jugador");
    titlePlayer.setFont(font);
    titlePlayer.setFillColor(Color::Black);
    titlePlayer.setPosition(280, 160);

    //titulo ID    
    txtTitleID.setFont(font);
    txtTitleID.setString("ID ");
    txtTitleID.setFillColor(Color::Black);
    txtTitleID.setPosition(180, 230 + 10);

    // Caja de texto ID   
    rtsID.setSize(Vector2f(200, 50));
    rtsID.setFillColor(Color(187, 208, 216));
    rtsID.setPosition(270, 230);

    //Texto para la caja ID    
    txtID.setFont(font);
    txtID.setString(to_string(playerCounter + 1));
    txtID.setFillColor(Color::Black);
    txtID.setPosition(270, 230);

    //titulo nombre   
    txtTitleName.setFont(font);
    txtTitleName.setString("Nombre ");
    txtTitleName.setFillColor(Color::Black);
    txtTitleName.setPosition(180, 310);

    //Caja de texto nombre  
    rtsName.setSize(Vector2f(200, 50));
    rtsName.setFillColor(Color(187, 208, 216));
    rtsName.setPosition(270, 300);

    //Texto para la caja nombre    
    txtName.setFont(font);
    txtName.setFillColor(Color::Black);
    txtName.setPosition(270, 300);

    //titulo edad    
    txtTitleAge.setFont(font);
    txtTitleAge.setString("Edad ");
    txtTitleAge.setFillColor(Color::Black);
    txtTitleAge.setPosition(180, 380);

    //Caja de texto Edad    
    rtsAge.setSize(Vector2f(200, 50));
    rtsAge.setFillColor(Color(187, 208, 216));
    rtsAge.setPosition(270, 370);

    //Texto para la caja Edad  
    txtAge.setFont(font);
    txtAge.setFillColor(Color::Black);
    txtAge.setPosition(270, 370);

    //titulo color  
    titleColor.setFont(font);
    titleColor.setString("Color");
    titleColor.setFillColor(Color::Black);
    titleColor.setPosition(180, 460);

    //Caja de texto Color  
    rtsColor.setSize(Vector2f(200, 50));
    rtsColor.setPosition(270, 450);

    //Text para campos requeridos   
    txtRequiredFields.setFont(font);
    txtRequiredFields.setFillColor(Color::Black);
    txtRequiredFields.setPosition(250, 500);


    playerData->draw(background);
    playerData->draw(txtTitle);
    playerData->draw(rtsBtnSave);

    playerData->draw(titlePlayer);

    playerData->draw(txtTitleID);
    playerData->draw(rtsID);
    playerData->draw(txtID);

    playerData->draw(txtTitleName);
    playerData->draw(rtsName);
    playerData->draw(txtName);

    playerData->draw(txtTitleAge);
    playerData->draw(rtsAge);
    playerData->draw(txtAge);

    playerData->draw(titleColor);
    playerData->draw(rtsColor);

    playerData->draw(txtRequiredFields);
}
void  StartWindow::playerRegister(RenderWindow*) {

    RenderWindow playerData(VideoMode(700, 700), "Registro de jugadores");
    //Player* player = new Player();

    rtsColor.setFillColor(Color::Blue);

    string name = "", ageString = "";
    Vector2i mouseCoordinates;
    
    int color = 0, age = 0, victoryPoints = 0;
    txtName.setString("");
    txtAge.setString("");
    rtsColor.setFillColor(playersColor[playerCounter]);
    while (playerData.isOpen()) {
        
        Event event;
        while (playerData.pollEvent(event)) {

            if (event.type == Event::Closed) {
                playerData.close();
                mainWindow();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    playerData.close();
                    mainWindow();
                }
            }
            if (event.type == Event::MouseButtonPressed) {
                mouseCoordinates = mouse.getPosition(playerData);

                if (rtsBtnSave.getGlobalBounds().contains(Vector2<float>(mouseCoordinates))) {                   
                    if (playerCounter >= 4) {
                        txtID.setString("");
                        txtRequiredFields.setString("**Jugadores al limite**");       
                    }
                    else if ((name == "") || (ageString == "")) {
                        txtRequiredFields.setString("**Campos requeridos**");
                    }
                    else {
                        age = stoi(ageString);
                        id++;                     
                        if (playerCounter == 0) {
                            Player* player1 = new Player(id, name, age, 15, Color::Blue);
                            playerList->inserNode(player1);                                                                           
                        }
                        if (playerCounter == 1) {
                            Player* player2 = new Player(id, name, age, 30, Color::Yellow);
                            playerList->inserNode(player2);                                                                           
                        }
                        if (playerCounter == 2) {
                            Player* player3 = new Player(id, name, age, 5, Color::Green);
                            playerList->inserNode(player3);
                            playersRegister = true;
                        }
                        if (playerCounter == 3) {
                            Player* player4 = new Player(id, name, age, 70, Color::Red);
                            playerList->inserNode(player4);                          
                        }
                       
                        //Cuando guarda inicializa los valores                        
                        name = "";
                        ageString = "";
                        victoryPoints = 0, color = 0;

                        txtID.setString("");
                        txtName.setString("");
                        txtAge.setString("");
                        txtRequiredFields.setString("");                      
                        rtsColor.setFillColor(playersColor[playerCounter +1]);
                        playerCounter++;
                    }
                }
                if (rtsBtnBack.getGlobalBounds().contains(Vector2<float>(mouseCoordinates))) {
                    playerData.close();
                    mainWindow();
                }
                if (rtsBtnPlay.getGlobalBounds().contains(Vector2<float>(mouseCoordinates))) {
                    playerData.close();
                    playerList->sortPlayerListDescending();

                    actualNode = playerList->first;
                    accommodateColors();
                    savePlayerInfo();
                    goWindow();
                }
            }
            if (event.type == Event::TextEntered) {

                if (rtsName.getGlobalBounds().contains(Vector2<float>(mouseCoordinates))) {

                    if ((event.text.unicode >= 32 && event.text.unicode <= 126) && ((txtName.getString().getSize() <= 20))) {
                        name += static_cast<char>(event.text.unicode);
                        txtName.setString(name);
                    }
                    if (event.text.unicode == 8 && name.length() > 0) {
                        name.pop_back();
                        txtName.setString(name);
                    }
                }
                if (rtsAge.getGlobalBounds().contains(Vector2<float>(mouseCoordinates))) {

                    if ((event.text.unicode >= 48 && event.text.unicode <= 57) && ((txtAge.getString().getSize() <= 1))) {
                        ageString += static_cast<char>(event.text.unicode);
                        txtAge.setString(ageString);
                    }
                    if (event.text.unicode == 8 && ageString.length() > 0) {
                        ageString.pop_back();
                        txtAge.setString(ageString);
                    }
                }
            }
        }
        playerData.clear();
        playerData.draw(rtsBtnPlay);
        paintPlayerRegister(&playerData);
        if ((playerCounter == 3) || (playerCounter == 4)) {                
            rtsBtnPlay.setPosition(Vector2f(300, 580));
            rtsBtnPlay.setSize(Vector2f(150, 50));
            txtrBtnPlay.loadFromFile("resouceImages/btnJugar.png");
            rtsBtnPlay.setTexture(&txtrBtnPlay);
            playerData.draw(rtsBtnPlay);
        }
        playerData.display();
    }
}

void StartWindow::paintTowns(RenderWindow* Go)
{
    RectangleShape rts;

    if (townStatus == false) {

        for (int i = 0; i < graph.vertices.size(); i++) {

            //vectorTown[i]
            vectorTown[i].setPosition(graph.vertices[i].x, graph.vertices[i].y);
            vectorTown[i].setSize(Vector2f(20, 20));
            //vectorTown->setTexture(&txtTown);
            vectorTown[i].setFillColor(Color::Transparent);
        }
        townStatus = true;
    }
    for (int i = 0; i < graph.vertices.size(); i++) {
        Go->draw(vectorTown[i]);
    }

    if (townStatus2 == false) {

        for (int i = 0; i < graph.vertices.size(); i++) {

            vectorBlackHouse[i].setPosition(graph.vertices[i].x, graph.vertices[i].y);
            vectorBlackHouse[i].setSize(Vector2f(20, 20));
            //vectorTown->setTexture(&txtTown);
            //vectorBlackHouse[i].setFillColor(Color::Transparent);
        }
        townStatus2 = true;
    }
    for (int i = 0; i < graph.vertices.size(); i++) {
        Go->draw(vectorBlackHouse[i]);
    }
}
void StartWindow::builtTown(RenderWindow* Go, int i)
{
    if (vectorTown[i].getFillColor() == Color::Transparent) {

        vectorTown[i].setPosition(graph.vertices[i].x, graph.vertices[i].y);
        vectorTown[i].setSize(Vector2f(20, 20));
        /*vectorTown->setTexture(&txtTown);*/
        vectorTown[i].setFillColor(actualNode->getData()->getColor());
        //vectorTown[i].setTexture(&rtsHouse);

        Go->draw(vectorTown[i]);


        vectorBlackHouse[i].setPosition(graph.vertices[i].x, graph.vertices[i].y);
        txtTown.loadFromFile("resouceImages/casaNegra.png");
        vectorBlackHouse[i].setTexture(&txtTown);
        //vectorBlackHouse[i].setFillColor(Color::Red);

        Go->draw(vectorBlackHouse[i]);
    }
    else {
        cout << "No se puede pintar";
    }
}
void StartWindow::accommodateColors() {

    for (int i = 0; i < playerList->getSize(); i++) {
        playersColor[i] = actualNode->getData()->getColor();
        actualNode = actualNode->getNextNode();
    }

}
void StartWindow::savePlayerInfo() {
    nodePlayer1 = playerList->first;
    nodePlayer2 = nodePlayer1->getNextNode();
    nodePlayer3 = nodePlayer2->getNextNode();
    nodePlayer4 = nodePlayer3->getNextNode();
}
void StartWindow::paintBankCounters(RenderWindow* Go) {

    Text sheep, wood, mineral, cereals, clay, development;
    RectangleShape rtsBlanco;
    int posXTxt = 0;
    int x = 10;
    int y = 10;

    for (int i = 0; i < 6; i++) {
        //cuadrado color blanco
        RectangleShape rtsBlanco;
        rtsBlanco.setPosition(Vector2f(x, y));
        rtsBlanco.setSize(Vector2f(20, 25));
        rtsBlanco.setFillColor(Color::White);
        Go->draw(rtsBlanco);
        x += 90;
    }
    
    posXTxt = 13;   
    sheep.setFont(font);
    sheep.setFillColor(Color::Black);
    sheep.setPosition(posXTxt, 2.5);
    sheep.setString("0");

    posXTxt += 90;   
    wood.setFont(font);
    wood.setFillColor(Color::Black);
    wood.setPosition(posXTxt, 2.5);
    wood.setString("0");
    posXTxt += 90;

    mineral.setFont(font);
    mineral.setFillColor(Color::Black);
    mineral.setPosition(posXTxt, 2.5);
    mineral.setString("0");
    posXTxt += 90;

    cereals.setFont(font);
    cereals.setFillColor(Color::Black);
    cereals.setPosition(posXTxt, 2.5);
    cereals.setString("0");
    posXTxt += 90;

    clay.setFont(font);
    clay.setFillColor(Color::Black);
    clay.setPosition(posXTxt, 2.5);
    clay.setString("0");
    posXTxt += 90;
    
    development.setFont(font);
    development.setFillColor(Color::Black);
    development.setPosition(posXTxt, 2.5);
    development.setString("0");

    Go->draw(sheep);
    Go->draw(wood);
    Go->draw(mineral);
    Go->draw(cereals);
    Go->draw(clay);
    Go->draw(development);

    
}
void StartWindow::paintPlayerCountersInTurn(RenderWindow* Go) {

    Text sheep, wood, mineral, cereals, clay, development;
    RectangleShape rtsBlanco;
    int posXTxt = 0;
    int posYTxt = 662;
    int x = 10;
    int y = 670;

    for (int i = 0; i < 6; i++) {
        //cuadrado color blanco
        RectangleShape rtsBlanco;
        rtsBlanco.setPosition(Vector2f(x, y));
        rtsBlanco.setSize(Vector2f(20, 25));
        rtsBlanco.setFillColor(Color::White);
        Go->draw(rtsBlanco);
        x += 90;
    }

    posXTxt = 13;
    sheep.setString(to_string(actualNode->getData()->getVictoryPoint()));
    sheep.setFont(font);
    sheep.setFillColor(Color::Black);
    sheep.setPosition(posXTxt, posYTxt);
    sheep.setString("0");

    posXTxt += 90;
    wood.setString(to_string(actualNode->getData()->getVictoryPoint()));
    wood.setFont(font);
    wood.setFillColor(Color::Black);
    wood.setPosition(posXTxt, posYTxt);
    wood.setString("0");
    posXTxt += 90;

    mineral.setString(to_string(actualNode->getData()->getVictoryPoint()));
    mineral.setFont(font);
    mineral.setFillColor(Color::Black);
    mineral.setPosition(posXTxt, posYTxt);
    mineral.setString("0");
    posXTxt += 90;

    cereals.setString(to_string(actualNode->getData()->getVictoryPoint()));
    cereals.setFont(font);
    cereals.setFillColor(Color::Black);
    cereals.setPosition(posXTxt, posYTxt);
    cereals.setString("0");
    posXTxt += 90;

    clay.setString(to_string(actualNode->getData()->getVictoryPoint()));
    clay.setFont(font);
    clay.setFillColor(Color::Black);
    clay.setPosition(posXTxt, posYTxt);
    clay.setString("0");
    posXTxt += 90;

    development.setString(to_string(actualNode->getData()->getVictoryPoint()));
    development.setFont(font);
    development.setFillColor(Color::Black);
    development.setPosition(posXTxt, posYTxt);
    development.setString("0");

    Go->draw(sheep);
    Go->draw(wood);
    Go->draw(mineral);
    Go->draw(cereals);
    Go->draw(clay);
    Go->draw(development);


}