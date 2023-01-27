#include "StartWindow.h"


StartWindow::StartWindow(float widht, float height) {
    if (!font.loadFromFile("Fonts/GethoFont.ttf")) {
        cout << "¡¡No Font!!";
    }
    int num = 200;
    for (int i = 0; i < 3; i++) {
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
    startMenu[2].setString("Exit");

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
            StartWindowSelected = 3;
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
        if (StartWindowSelected == 3) {
            StartWindowSelected = 0;
        }
        startMenu[StartWindowSelected].setFillColor(Color::Cyan);

    }
}

void StartWindow::ventanaPrincipal()
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
                        ventanaGo();
                    }
                    if (pos == 1) {
                        windowMENU.close();
                        ventanaAbout();
                    }
                    if (pos == 2) {

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

void StartWindow::ventanaGo()
{
    RenderWindow Go(VideoMode(X, Y), "Area de juego");

    //MAR
    RectangleShape rtsMar;
    rtsMar.setSize(Vector2f(X, Y));
    Texture textureRtsMar;
    textureRtsMar.loadFromFile("resouceImages/goGame.jpg");
    rtsMar.setTexture(&textureRtsMar);

    //Hexagono para los terrenos
    RectangleShape rtsTerreno;
    rtsTerreno.setPosition(Vector2f(500, 150));
    rtsTerreno.setSize(Vector2f(400, 400));
    Texture textureRtsTerreno;
    textureRtsTerreno.loadFromFile("resouceImages/AreaJuego.png");
    rtsTerreno.setTexture(&textureRtsTerreno);

    //Boton dados
    RectangleShape rtsBtnDados;
    rtsBtnDados.setPosition(Vector2f(615, 10));
    rtsBtnDados.setSize(Vector2f(200, 110));
    Texture textureRtsBtnDados;
    textureRtsBtnDados.loadFromFile("resouceImages/btnTirarDados.png");
    rtsBtnDados.setTexture(&textureRtsBtnDados);

    Mouse mouse;
    Event event;

    Vector2i v2i = mouse.getPosition(Go);


    while (Go.isOpen()) {

        while (Go.pollEvent(event)) {
            if (event.type == Event::Closed) {
                Go.close();

                ventanaPrincipal();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {

                    Go.close();
                    ventanaPrincipal();
                }
            }
            if (event.type == Event::MouseButtonPressed) {

                Vector2i v2i = mouse.getPosition(Go);

                if (rtsBtnDados.getGlobalBounds().contains(Vector2<float>(v2i))) {

                    pintaDados(&Go);
                    /* pintaTerrenos(&Go); */

                }
            }

        }
        Go.draw(rtsMar);
        Go.draw(rtsTerreno);
        Go.draw(rtsDado1);
        Go.draw(rtsDado2);
        Go.draw(rtsTerrenos);
        Go.draw(rtsBtnDados);

        pintaMateriasPrimas(&Go, 660);
        pintaMateriasPrimas(&Go, 10);
        pintaMazosContrincantes(&Go, 170);
        pintaMazosContrincantes(&Go, 320);
        pintaMazosContrincantes(&Go, 470);
        pintaCartasEspeciales(&Go);


        Go.display();

    }
}

void StartWindow::ventanaAbout()
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
                ventanaPrincipal();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    About.close();
                    ventanaPrincipal();
                }
            }
        }
        About.clear();
        About.draw(aBackground);
        About.display();
    }
}

void StartWindow::pintaMateriasPrimas(RenderWindow* Go, int y)
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

void StartWindow::pintaDados(RenderWindow* Go)
{
    int numRandom = 0, sumaDados = 0;
    srand(time(NULL));
    numRandom = 1 + rand() % 6;
    string ruta;
    ruta = "resouceImages/D";
    ruta += to_string(numRandom);
    ruta += ".png";
    rtsDado1.setPosition(Vector2f(850, 10));
    rtsDado1.setSize(Vector2f(110, 110));

    txtrRtsDado1.loadFromFile(ruta);
    rtsDado1.setTexture(&txtrRtsDado1);

    sumaDados += numRandom;

    numRandom = 1 + rand() % 6;

    ruta = "resouceImages/D";
    ruta += to_string(numRandom);
    ruta += ".png";
    rtsDado2.setPosition(Vector2f(1000, 10));
    rtsDado2.setSize(Vector2f(110, 110));

    txtrRtsDado2.loadFromFile(ruta);
    rtsDado2.setTexture(&txtrRtsDado2);
    sumaDados += numRandom;
    cout << "SUMA: " << sumaDados << endl;

    Go->draw(rtsDado2);
}

void StartWindow::pintaMazosContrincantes(RenderWindow* Go, int posY)
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

void StartWindow::pintaCartasEspeciales(RenderWindow* Go)
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

void StartWindow::pintaTerrenos(RenderWindow* Go)
{
    int terrenos[6] = { 4,4,4,3,3,1 };
    int posX[19] = { 0,0,623,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    int posY[19] = { 0,0,295,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    string ruta = "";

    int numero = 0 + rand() % 5;







    int cont = 0;
    while (cont <= 19) {
        srand(time(NULL));
        int numero = 0 + rand() % 5;


        if (terrenos[numero] > 0) {
            terrenos[numero] --;

            rtsTerrenos.setPosition(Vector2f(posX[cont], posY[cont]));
            rtsTerrenos.setSize(Vector2f(60, 60));
            ruta = "resouceImages/T";
            ruta += to_string(numero);
            ruta += ".png";
            txtrTerrenos.loadFromFile(ruta);
            rtsTerrenos.setTexture(&txtrTerrenos);
            Go->draw(rtsTerrenos);



            cont++;
        }


    }
}

