#include "StartWindow.h"
#include "windows.h"

StartWindow::StartWindow(float widht, float height) {
    if (!font.loadFromFile("Fonts/GethoFont.ttf")) {
        cout << "¡¡No Font!!";
    }
    int num = 200;
    for (int i = 0; i < 4; i++) {
        //Start Game
        startMenu[i].setFont(font);
        startMenu[i].setFillColor(Color::White);
        startMenu[i].setCharacterSize(70);
        startMenu[i].setPosition(1100, num);
        num += 100;
    }

    startMenu[0].setString("Go");
    startMenu[0].setFillColor(Color::Cyan);

    startMenu[1].setString("About");
    startMenu[2].setString("Load");
    startMenu[3].setString("Exit");

    StartWindowSelected = 0;

    //RenderWindow Go(VideoMode(X, Y), "SFML works!");
// RenderWindow Go(VideoMode(X, Y), "CATAN");


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

    if (StartWindowSelected <= 2/*optionMenu*/)
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
    Event event;
    //set background
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
                        goWindow();
                    }
                    if (pos == 1) {
                        windowMENU.close();
                        aboutWindow();
                    }
                    if (pos == 2) {

                        windowMENU.close();
                        break;
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

void StartWindow::goWindow()
{
    RenderWindow Go(VideoMode(X, Y), "Area de juego");

    //MAR
    RectangleShape rtsSea;
    rtsSea.setSize(Vector2f(X, Y));
    Texture textureRtsSea;
    textureRtsSea.loadFromFile("resouceImages/goGame.jpg");
    rtsSea.setTexture(&textureRtsSea);

    //Hexagono para los terrenos
    RectangleShape rtsLand;
    rtsLand.setPosition(Vector2f(500, 150));
    rtsLand.setSize(Vector2f(400, 400));
    Texture textureRtsLand;
    textureRtsLand.loadFromFile("resouceImages/AreaJuego.png");
    rtsLand.setTexture(&textureRtsLand);

    //Boton dados
    RectangleShape rtsBtnDice;
    rtsBtnDice.setPosition(Vector2f(615, 10));
    rtsBtnDice.setSize(Vector2f(200, 110));
    Texture textureRtsBtnDice;
    textureRtsBtnDice.loadFromFile("resouceImages/btnTirarDados.png");
    rtsBtnDice.setTexture(&textureRtsBtnDice);

    //Boton salir
    RectangleShape rtsBtnExit;
    rtsBtnExit.setPosition(Vector2f(1250, 10));
    rtsBtnExit.setSize(Vector2f(57, 30));
    Texture textureRtsBtnExit;
    textureRtsBtnExit.loadFromFile("resouceImages/exitButton.png");
    rtsBtnExit.setTexture(&textureRtsBtnExit);
    
    //Boton guardar
    RectangleShape rtsBtnSave;
    rtsBtnSave.setPosition(Vector2f(1255, 40));
    rtsBtnSave.setSize(Vector2f(50, 30));
    Texture textureRtsBtnSave;
    textureRtsBtnSave.loadFromFile("resouceImages/btnSave.png");
    rtsBtnSave.setTexture(&textureRtsBtnSave);
    
    

    int numero = 0;
    


    RectangleShape vectorTerrenosRTS[19], rts;
    for (int i = 0; i < 19; i++) {
        vectorTerrenosRTS[i] = rts;
    }
    Texture vectorTerrenosTXT[19], txtr;
    for (int i = 0; i < 19; i++) {

        vectorTerrenosTXT[i] = txtr;
    }
    int posX[19] = { 608,673,737,580,641,703,765,549,610,673,735,798,580,642,705,767,610,674,735 };
    int posY[19] = { 234,234,234,278,278,278,278,325,325,325,325,325,370,370,370,370,415,415,415 };
    string ruta = "";
    srand(time(NULL));
    for (int i = 0; i < 19; i++) {
        vectorTerrenosRTS[i].setPosition(Vector2f(posX[i], posY[i]));
        vectorTerrenosRTS[i].setSize(Vector2f(55, 55));

        numero = 0 + rand() % 5;
        
        ruta = "resouceImages/T";
        ruta += to_string(numero);
        ruta += ".png";
        vectorTerrenosTXT[i].loadFromFile(ruta);
       
        Texture* txt;
        txt = &vectorTerrenosTXT[i];
        vectorTerrenosRTS[i].setTexture(txt);
       
        Go.draw(vectorTerrenosRTS[i]);
    }

    //----------------------------------------------------------------------------------------------------
    string letra;
    RectangleShape vectorTerrenosRTS2[19];
    for (int i = 0; i < 19; i++) {
        RectangleShape rts;
        vectorTerrenosRTS2[i] = rts;
    }
    Texture vectorTerrenosTXT2[19];
    for (int i = 0; i < 19; i++) {
        Texture txtr;
        vectorTerrenosTXT2[i] = txtr;
    }
    
    srand(time(NULL));
    for (int i = 0; i < 19; i++) {
        vectorTerrenosRTS2[i].setPosition(Vector2f(posX[i]+8, posY[i]+8));
        vectorTerrenosRTS2[i].setSize(Vector2f(40, 40));

        /*letra = "A" + rand() ;

        ruta = "resouceImages/";
        ruta += to_string(numero);
        ruta += ".png";*/

        vectorTerrenosTXT2[i].loadFromFile("resouceImages/A.png");

        Texture* txt;
        txt = &vectorTerrenosTXT2[i];
        vectorTerrenosRTS2[i].setTexture(txt);

        Go.draw(vectorTerrenosRTS2[i]);
    }

    Vector2i v2i = mouse.getPosition(Go);

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

                    paintDice(&Go);
                    /* pintaTerrenos(&Go); */

                }
                
                if (rtsBtnExit.getGlobalBounds().contains(Vector2<float>(v2i))) {

                    exitButton(&Go);

                    // Go.close();

                    // mainWindow();
                } 
                
            }

        }
        Go.draw(rtsSea);
        Go.draw(rtsLand);
        Go.draw(rtsDice1);
        Go.draw(rtsDice2);
        Go.draw(rtsLand);
        Go.draw(rtsBtnDice);
        Go.draw(rtsBtnExit);
        Go.draw(rtsBtnSave);
        

        //TERRENOS
        for (int i = 0; i < 19; i++) {
            Go.draw(vectorTerrenosRTS[i]);
        }
        //este para fichas A,B,C,D
        for (int i = 0; i < 19; i++) {
            Go.draw(vectorTerrenosRTS2[i]);
        }
        paintResource(&Go, 660);
        paintResource(&Go, 10);
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

void StartWindow::paintResource(RenderWindow* Go, int y)
{
    int pos = 10;
    string ruta = "";
    RectangleShape rectangleShape;
    Texture texture1;
    for (int i = 0; i < 6; i++) {
        ruta = "resouceImages/MP";

        rectangleShape.setPosition(Vector2f(pos, y));
        rectangleShape.setSize(Vector2f(80, 110));
        ruta += to_string(i + 1);
        ruta += ".png";
        texture1.loadFromFile(ruta);
        rectangleShape.setTexture(&texture1);
        Go->draw(rectangleShape);
        pos += 100;

    }
}

void StartWindow::paintDice(RenderWindow* Go)
{
    int numRandom = 0, sumaDados = 0;
    srand(time(NULL));
    numRandom = 1 + rand() % 6;
    string ruta;
    ruta = "resouceImages/D";
    ruta += to_string(numRandom);
    ruta += ".png";
    rtsDice1.setPosition(Vector2f(850, 10));
    rtsDice1.setSize(Vector2f(110, 110));

    txtrRtsDice1.loadFromFile(ruta);
    rtsDice1.setTexture(&txtrRtsDice1);

    sumaDados += numRandom;

    numRandom = 1 + rand() % 6;

    ruta = "resouceImages/D";
    ruta += to_string(numRandom);
    ruta += ".png";
    rtsDice2.setPosition(Vector2f(1000, 10));
    rtsDice2.setSize(Vector2f(110, 110));

    txtrRtsDice2.loadFromFile(ruta);
    rtsDice2.setTexture(&txtrRtsDice2);
    sumaDados += numRandom;
    cout << "SUMA: " << sumaDados << endl;

    Go->draw(rtsDice2);
}

void StartWindow::paintOpponentDeck(RenderWindow* Go, int posY)
{

    RectangleShape rts1, rts2;
    Texture txtr1, txtr2;
    string ruta1 = "resouceImages/MP6.png", ruta2 = "resouceImages/MP7.png";

    rts1.setPosition(Vector2f(10, posY));
    rts1.setSize(Vector2f(40, 70));
    txtr1.loadFromFile(ruta1);
    rts1.setTexture(&txtr1);
    Go->draw(rts1);

    //posY += 100;
    rts2.setPosition(Vector2f(60, posY));
    rts2.setSize(Vector2f(40, 70));
    txtr2.loadFromFile(ruta2);
    rts2.setTexture(&txtr2);
    Go->draw(rts2);

}

void StartWindow::paintSpecialCards(RenderWindow* Go)
{
    RectangleShape rts;
    Texture txtr;
    int pos = 615;
    string ruta = "";

    for (int i = 1; i < 4; i++) {
        ruta = "resouceImages/E";

        rts.setPosition(Vector2f(pos, 590));
        rts.setSize(Vector2f(150, 180));
        ruta += to_string(i);
        ruta += ".png";
        txtr.loadFromFile(ruta);
        rts.setTexture(&txtr);
        Go->draw(rts);
        pos += 170;
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

//void StartWindow::paintLand(RenderWindow* Go)
//{
//    int terrenos[6] = { 4,4,4,3,3,1 };
//    int posX[19] = { 608,673,737,580,641,703,765,549,610,673,735,798,580,642,705,767,610,674,735, };
//    int posY[19] = { 234,234,234,278,278,278,278,325,325,325,325,325,370,370,370,370,415,415,415 };
//    string ruta = "";
//  
//
//
//        if (terrenos[numero] > 0) {
//            terrenos[numero] --;
//
//            rtsLands.setPosition(Vector2f(posX[cont], posY[cont]));
//            rtsLands.setSize(Vector2f(60, 60));
//            ruta = "resouceImages/T";
//            ruta += to_string(numero);
//            ruta += ".png";
//            txtrLands.loadFromFile(ruta);
//            rtsLands.setTexture(&txtrLands);
//            Go->draw(rtsLands);
//
//
//
//            cont++;
//        }
//
//
//    }
//}

