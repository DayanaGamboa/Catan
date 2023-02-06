#include "StartWindow.h"
#include "windows.h"
#include "Player.h"
#include "Dice.h"
#include "Thief.h"
#include <string>
#include "Graph.h"

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
    Player player(0, "", 0,0,0);
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

    
    Dice dice1;
    //Player player(0, "", 0, 0, 0);
    cout << "hola" << endl;
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
                    dice1.pintaDados = false;
                    dice1.diceFinalAmount(&Go);
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
                       
                        txtTown.loadFromFile("resouceImages/casa.png");
                        
                        
                        //vectorTown[i].setTexture(&txtTown);
                        vectorTown[i].setFillColor(Color::Black);
                        Go.draw(vectorTown[i]);
                        //Go.display();
                        //player.buildTown(&Go, mouse.getPosition(Go).x, mouse.getPosition(Go).y);

                        cout << "pintado" << endl;
                        break;
                    }
                }
            }

        }

        generateGameArea(&Go);
        paintLands(&Go);
        paintNumberPieces(&Go);
        dice1.diceFinalAmount(&Go); 
        graph.drawVertex(&Go);
        graph.drawEdges(&Go);
        paintTowns(&Go);
        paintResource(&Go, 10, 10);
        paintResource(&Go, 10, 670);
        paintOpponentDeck(&Go, 170);
        paintOpponentDeck(&Go, 280);
        paintOpponentDeck(&Go, 390);
        paintOpponentDeck(&Go, 500);
        paintSpecialCards(&Go);
        PlayerInTurn(&Go);

        Go.display();
    }
}

void StartWindow::aboutWindow()
{
    RectangleShape aBackground;
    Event event;
    aBackground.setSize(Vector2f(X, Y));
    Texture aboutWindowImage;
    aboutWindowImage.loadFromFile("resouceImages/About.png");
    aBackground.setTexture(&aboutWindowImage);

    //Boton de atras    
    RectangleShape rtsBtnAtras;
    rtsBtnAtras.setPosition(Vector2f(100, 720));
    rtsBtnAtras.setSize(Vector2f(150, 80));
    Texture txtrBtnAtras;
    txtrBtnAtras.loadFromFile("resouceImages/btnAtras.png");
    rtsBtnAtras.setTexture(&txtrBtnAtras);

    RenderWindow About(VideoMode(X, Y), "About");
    Vector2i coordenadasMouse;

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

                coordenadasMouse = mouse.getPosition(About);
                if (rtsBtnAtras.getGlobalBounds().contains(Vector2<float>(coordenadasMouse))) {
                    About.close();
                    mainWindow();
                }
            }
        }
        About.clear();
        About.draw(aBackground);
        About.draw(rtsBtnAtras);
        About.display();
    }
}

void StartWindow::paintResource(RenderWindow* Go, int x, int y)
{

    string ruta = "";
    RectangleShape rectangleShape;
    Texture texture1;
    for (int i = 0; i < 6; i++) {
        ruta = "resouceImages/MP";

        rectangleShape.setPosition(Vector2f(x, y));
        rectangleShape.setSize(Vector2f(70, 100));
        ruta += to_string(i + 1);
        ruta += ".png";
        texture1.loadFromFile(ruta);
        rectangleShape.setTexture(&texture1);
        Go->draw(rectangleShape);
        x += 90;

    }
}


void StartWindow::paintOpponentDeck(RenderWindow* Go, int posY)
{

    RectangleShape rts1, rts2;
    Texture txtr1, txtr2;
    string ruta1 = "resouceImages/MP6.png", ruta2 = "resouceImages/MP7.png";

    rts1.setPosition(Vector2f(10, posY));
    rts1.setSize(Vector2f(70, 100));
    txtr1.loadFromFile(ruta1);
    rts1.setTexture(&txtr1);
    Go->draw(rts1);

    rts2.setPosition(Vector2f(90, posY));
    rts2.setSize(Vector2f(70, 100));
    txtr2.loadFromFile(ruta2);
    rts2.setTexture(&txtr2);
    Go->draw(rts2);

}

void StartWindow::paintSpecialCards(RenderWindow* Go)
{
    RectangleShape rts;
    Texture txtr;
    int pos = 550;
    string ruta = "";

    for (int i = 1; i < 4; i++) {
        ruta = "resouceImages/E";

        rts.setPosition(Vector2f(pos, 640));
        rts.setSize(Vector2f(110, 130));
        ruta += to_string(i);
        ruta += ".png";
        txtr.loadFromFile(ruta);
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

    //Jugador azul
    rtsPlayerBlue.setPosition(Vector2f(180, 190));
    rtsPlayerBlue.setSize(Vector2f(50, 50));
    txtrPlayerBlue.loadFromFile("resouceImages/jugadorAzul.png");
    rtsPlayerBlue.setTexture(&txtrPlayerBlue);
    Go->draw(rtsPlayerBlue);

    //Jugador rojo
    rtsPlayerRed.setPosition(Vector2f(180, 300));
    rtsPlayerRed.setSize(Vector2f(50, 50));
    txtrPlayerRed.loadFromFile("resouceImages/jugadorRojo.png");
    rtsPlayerRed.setTexture(&txtrPlayerRed);
    Go->draw(rtsPlayerRed);

    //Jugador amarillo
    rtsPlayerYellow.setPosition(Vector2f(180, 410));
    rtsPlayerYellow.setSize(Vector2f(50, 50));
    txtrPlayerYellow.loadFromFile("resouceImages/jugadorAmarillo.png");
    rtsPlayerYellow.setTexture(&txtrPlayerYellow);
    Go->draw(rtsPlayerYellow);

    //Jugador verde
    rtsPlayerGreen.setPosition(Vector2f(180, 520));
    rtsPlayerGreen.setSize(Vector2f(50, 50));
    txtrPlayerGreen.loadFromFile("resouceImages/jugadorVerde.png");
    rtsPlayerGreen.setTexture(&txtrPlayerGreen);
    Go->draw(rtsPlayerGreen);
}
void StartWindow::paintLands(RenderWindow* Go) {

    
    string ruta = "";
    Thief thief;
    //Terrenos
    if (terrenos == false) {

        RectangleShape rts;
        Texture txtr;
        for (int i = 0; i < 19; i++) {
            vectorTerrenosRTS[i] = rts;
            vectorTerrenosTXT[i] = txtr;
        }


        int vectorTerrenos[6] = { 4, 4, 4, 3, 3, 1 };//para saber cuantos terrenos de cada uno
        int numero = 0, contTerrenos = 0;


        srand(time(NULL));
        while (contTerrenos <= 18) {
            numero = 0 + rand() % 6;

            if (vectorTerrenos[numero] != 0) {
                if (numero == 5) {

                   /* thief.positionX = TerrenosPosX[contTerrenos];
                    thief.positionY = TerrenosPosY[contTerrenos];*/
                    posXTerrenoDesierto = TerrenosPosX[contTerrenos];
                    posYTerrenoDesierto = TerrenosPosY[contTerrenos];
                }
                vectorTerrenosRTS[contTerrenos].setPosition(Vector2f(TerrenosPosX[contTerrenos], TerrenosPosY[contTerrenos]));
                vectorTerrenosRTS[contTerrenos].setSize(Vector2f(68.5, 68.5));

                ruta = "resouceImages/T";
                ruta += to_string(numero);
                ruta += ".png";
                vectorTerrenosTXT[contTerrenos].loadFromFile(ruta);

                Texture* txt;
                txt = &vectorTerrenosTXT[contTerrenos];
                vectorTerrenosRTS[contTerrenos].setTexture(txt);

                //Go->draw(vectorTerrenosRTS[contTerrenos]);

                vectorTerrenos[numero] = vectorTerrenos[numero] - 1;
                contTerrenos++;
            }

        }
        terrenos = true;
    }

    for (int i = 0; i < 19; i++) {
        Go->draw(vectorTerrenosRTS[i]);
    }

}
void StartWindow::paintNumberPieces(RenderWindow* Go) {

    RectangleShape fichasNumeradasRts[19], fichaNumeradaRts;
    Texture fichasNumeradasTxtr[19], fichaNumerasaTxtr;
    Texture* txt;
    string ruta = "";

    for (int i = 0; i < 19; i++) {

        fichasNumeradasRts[i] = fichaNumeradaRts;
        fichasNumeradasTxtr[i] = fichaNumerasaTxtr;
    }

    int numeroFichaNumerada[18] = { 5, 2, 6, 3, 8, 10, 9, 12, 11, 4, 8, 10, 9, 4, 5, 6, 3, 11 };
    int posnumeroFichaNumerada = 0;
    for (int i = 0; i < 19; i++) {
        if ((TerrenosPosX[i] == posXTerrenoDesierto) && (TerrenosPosY[i] == posYTerrenoDesierto)) { //poner las del ladron
            fichasNumeradasRts[i].setPosition(Vector2f(posXTerrenoDesierto, posYTerrenoDesierto));  //poner las del ladron
            fichasNumeradasRts[i].setSize(Vector2f(70, 70));
            fichasNumeradasTxtr[i].loadFromFile("resouceImages/Ladron.png");
            txt = &fichasNumeradasTxtr[i];
            fichasNumeradasRts[i].setTexture(txt);
            Go->draw(fichasNumeradasRts[i]);
            i++;
        }
        fichasNumeradasRts[i].setPosition(Vector2f(TerrenosPosX[i], TerrenosPosY[i]));
        fichasNumeradasRts[i].setSize(Vector2f(70, 70));

        ruta = "resouceImages/N";
        ruta += to_string(numeroFichaNumerada[posnumeroFichaNumerada]);
        ruta += ".png";

        fichasNumeradasTxtr[i].loadFromFile(ruta);

        txt = &fichasNumeradasTxtr[i];
        fichasNumeradasRts[i].setTexture(txt);
        Go->draw(fichasNumeradasRts[i]);
        posnumeroFichaNumerada++;

    }

    for (int i = 0; i < 19; i++) {
        Go->draw(fichasNumeradasRts[i]);
    }
}
void StartWindow::PlayerInTurn(RenderWindow* Go) {

    string playerID = to_string(actualNode->getData()->getId()), playerName = actualNode->getData()->getName();
    int playerColor = actualNode->getData()->getColor(), puntosVictoria = actualNode->getData()->getVictoryPoint();

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

    /* rtsPlayerColor.setFillColor(Color::Blue);*/
    if (playerColor == 1) {
        rtsPlayerColor.setFillColor(Color::Blue);
    }
    if (playerColor == 2) {
        rtsPlayerColor.setFillColor(Color::Red);
    }
    if (playerColor == 3) {
        rtsPlayerColor.setFillColor(Color::Yellow);
    }
    if (playerColor == 4) {
        rtsPlayerColor.setFillColor(Color::Green);
    }
    Go->draw(rtsPlayerColor);
}

void  StartWindow::paintPlayerRegister(RenderWindow* playerData) {
    //MENU
    fondo.setSize(Vector2f(700, 700));
    fondo.setFillColor(Color(220, 245, 255));

    titulo1.setFont(font);
    titulo1.setString("Registro de jugadores: (3-4)");
    titulo1.setFillColor(Color::Black);
    titulo1.setPosition(200, 10);
    titulo1.setCharacterSize(50);

    //Boton de aceptar    
    rtsBtnGuardar.setPosition(Vector2f(150, 580));
    rtsBtnGuardar.setSize(Vector2f(150, 50));
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
void  StartWindow::playerRegister(RenderWindow*) {

    RenderWindow playerData(VideoMode(700, 700), "Registro de jugadores");
    //Player* player = new Player();

    rtsColor.setFillColor(Color::Blue);

    string nombre = "", edadString = "";
    Vector2i coordenadasMouse;
    int color = 0, edad = 0, puntosVictoria = 0;

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
                    mainWindow();
                }
                if (rtsBtnJugar.getGlobalBounds().contains(Vector2<float>(coordenadasMouse))) {
                    playerData.close();
                    playerList->sortPlayerListDescending();

                    actualNode = playerList->first;
                    goWindow();
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

            rtsBtnJugar.setPosition(Vector2f(300, 580));
            rtsBtnJugar.setSize(Vector2f(150, 50));
            txtrBtnJugar.loadFromFile("resouceImages/btnJugar.png");
            rtsBtnJugar.setTexture(&txtrBtnJugar);
            playerData.draw(rtsBtnJugar);
        }
        playerData.display();
    }
}

void StartWindow::paintTowns(RenderWindow* Go)
{

    Graph graph;
    RectangleShape rts;
    
    //txtTown.create(00001,00001);

    if (townStatus == false) {
        for (int i = 0; i < graph.vertices.size(); i++) {
            //vectorTown[i]
            vectorTown[i].setPosition(graph.vertices[i].x, graph.vertices[i].y);
            vectorTown[i].setSize(Vector2f(20, 20));
            //vectorTown->setTexture(&txtTown);
            vectorTown[i].setFillColor(Color::White);
            
        } 
        
        townStatus = true;
    }

    for (int i = 0; i < graph.vertices.size(); i++) {
        
        Go->draw(vectorTown[i]);
    }
}

