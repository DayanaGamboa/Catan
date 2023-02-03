#include "StartWindow.h"
#include "windows.h"
#include "Player.h"
#include "Dice.h"
#include "Thief.h"
#include <string>

StartWindow::StartWindow(float widht, float height) {
    if (!font.loadFromFile("Fonts/Wintertime.ttf")) {
        cout << "¡¡No Font!!";
    }
    int num = 200;
    for (int i = 0; i < 5; i++) {
        //Start Game
        startMenu[i].setFont(font);
        startMenu[i].setFillColor(Color::White);
        startMenu[i].setCharacterSize(70);
        startMenu[i].setPosition(800, num);
        num += 100;
    }

    startMenu[0].setString("Registrar jugadores");
    startMenu[0].setFillColor(Color::Cyan);

    startMenu[1].setString("Jugar");
    startMenu[2].setString("Cargar partida");
    startMenu[3].setString("Acerca de");
    startMenu[4].setString("Salir");

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
            StartWindowSelected = 5;
        }
        StartWindowSelected--;

        startMenu[StartWindowSelected].setFillColor(Color::Cyan);
    }

}

void StartWindow::moveDown() {

    if (StartWindowSelected <= 4)
    {
        startMenu[StartWindowSelected].setFillColor(Color::White);
        StartWindowSelected++;
        if (StartWindowSelected == 5) {
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

                        windowMENU.close();
                        goWindow();
                       
                    }
                    if (pos == 2) {


                    }

                    if (pos == 3) {

                        windowMENU.close();
                        aboutWindow();
                      
                    }
                    if (pos == 4) {

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

    Dice dice1;

    while (Go.isOpen()) {

        while (Go.pollEvent(event)) {
            if (event.type == Event::Closed) {
                Go.close();
                mainWindow();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {

                    Go.close();
                    mainWindow();
                }
            }
            if (event.type == Event::MouseButtonPressed) {

                Vector2i v2i = mouse.getPosition(Go);

                if (rtsBtnDice.getGlobalBounds().contains(Vector2<float>(v2i))) {
                    dice1.pintaDados = false;
                    dice1.diceFinalAmount(&Go);

                }
                if (rtsBtnExit.getGlobalBounds().contains(Vector2<float>(v2i))) {
                    exitButton(&Go);

                }
            }

        }

        generateGameArea(&Go);
        paintLands(&Go);
        paintNumberPieces(&Go);
        dice1.diceFinalAmount(&Go);

       

        paintResource(&Go, 10, 10);
        paintResource(&Go, 10, 670);
        paintOpponentDeck(&Go, 170);
        paintOpponentDeck(&Go, 320);
        paintOpponentDeck(&Go, 470);
        paintSpecialCards(&Go);

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

    RenderWindow About(VideoMode(X, Y), "About");


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
        }
        About.clear();
        About.draw(aBackground);
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

void StartWindow::exitButton(RenderWindow* Go){
   
    RenderWindow windowExit(VideoMode(200, 130), "Salir?");
    //set background
    RectangleShape backExit;
    backExit.setSize(Vector2f(200, 130));
    backExit.setFillColor(Color::White);

    Text text("Seguro que deseas salir?",font,15);
    text.setFillColor(Color::Black);
    text.setPosition(Vector2f(0,20));
    

    //Yes
    CircleShape rtsBtnYes;
    rtsBtnYes.setPosition(Vector2f(30, 65));
    rtsBtnYes.setRadius(20);
    Texture textureRtsBtnYes;
    textureRtsBtnYes.loadFromFile("resouceImages/btnYes.png");
    rtsBtnYes.setTexture(&textureRtsBtnYes);
    //No
    CircleShape rtsBtnNo;
    rtsBtnNo.setPosition(Vector2f(130, 65));
    rtsBtnNo.setRadius(20);
    Texture textureRtsBtnNo;
    textureRtsBtnNo.loadFromFile("resouceImages/btnNo.png");
    rtsBtnNo.setTexture(&textureRtsBtnNo);



    while (windowExit.isOpen()) {

        while (windowExit.pollEvent(event)) {
            if (event.type == Event::Closed) {
                windowExit.close();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    windowExit.close();
                    
                }
            }
            if (event.type == Event::MouseButtonPressed) {

                Vector2i v2i = mouse.getPosition(windowExit);

                if (rtsBtnYes.getGlobalBounds().contains(Vector2<float>(v2i))) {
                    windowExit.close();
                    Go->close();
                    mainWindow();
                } 
                windowExit.close();
               
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

    //btnExit
    
    rtsBtnExit.setPosition(Vector2f(1250, 10));
    rtsBtnExit.setSize(Vector2f(57, 30));
    Texture textureRtsBtnExit;
    textureRtsBtnExit.loadFromFile("resouceImages/exitButton.png");
    rtsBtnExit.setTexture(&textureRtsBtnExit);
    Go->draw(rtsBtnExit);
    
    //btnSave
    
    rtsBtnSave.setPosition(Vector2f(1255, 40));
    rtsBtnSave.setSize(Vector2f(50, 30));
    Texture textureRtsBtnSave;
    textureRtsBtnSave.loadFromFile("resouceImages/btnSave.png");
    rtsBtnSave.setTexture(&textureRtsBtnSave);
    Go->draw(rtsBtnSave);
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

