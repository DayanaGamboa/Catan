#include "StartWindow.h"
#include "windows.h"
#include "Player.h"
#include "Dice.h"
#include "Thief.h"
#include <string>

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
                        player.playerRegister(&windowMENU);

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
    //----------------------------------------
    //pintar circulos del grafo
    list<CircleShape> circlesV;
    CircleShape circle(10);
    circle.setFillColor(Color(135, 135, 135));


    list<Vector2f> positions = {
        {819,241},{783,226},{742,245}, {701,225},{659,242},{620,226},{587,243},{585,276},{550,302},{550,338},{512,357},{509,396},{545,414},{548,452},{585,470},{586,508},{619,524},{660,507},{701,524},{740,508},{781,525},{819,508},{821,472},{858,452},{862,416},{898,395},{900,358},{860,336},{857,298},{821,279},
        {737,275},{703,301},{660,282},{625,303},{623,335},{585,358},{587,395},{623,415},{622,449},{663,473},{703,450},{742,472},{783,451},{783,415},{820,397},{822,361},{780,333},{780,300},
        {700,335},{663,361},{660,390},{703,413},{740, 390},{740, 359}
    };


    for (auto& pos : positions)
    {
        circle.setPosition(pos);
        circlesV.push_back(circle);
    }
    //----------------------------------------
    Dice dice1;

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
                }
            }

        }

        generateGameArea(&Go);
        paintLands(&Go);
        paintNumberPieces(&Go);
        dice1.diceFinalAmount(&Go);     
        for (auto& circle : circlesV)
            Go.draw(circle);
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

                Go->draw(vectorTerrenosRTS[contTerrenos]);

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
    Go->draw(ID);

    //titulo PV 
    Text PV;
    PV.setFont(font);
    PV.setString("PV:  ");
    PV.setFillColor(Color::Black);
    PV.setPosition(1150, 670);
    Go->draw(PV);

    //titulo nombre   
    Text name;
    name.setFont(font);
    name.setString("Nombre:  ");
    name.setFillColor(Color::Black);
    name.setPosition(955, 700);
    Go->draw(name);

    //titulo color  
    Text color;
    color.setFont(font);
    color.setString("Color:  ");
    color.setFillColor(Color::Black);
    color.setPosition(955, 730);
    Go->draw(color);

    string playerID = "", playerName = "";
    int playerColor = 0, puntosVictoria = 0;

    ID.setString(ID.getString() + playerID);
    name.setString(ID.getString() + playerID);
    PV.setString(PV.getString() + to_string(puntosVictoria));

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

