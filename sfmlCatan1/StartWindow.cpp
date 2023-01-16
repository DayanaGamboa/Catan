#include "StartWindow.h"

StartWindow::StartWindow(float widht, float height) {
    if (!font.loadFromFile("Fonts/GethoFont.ttf")) {
        cout << "¡¡No Font!!";
    }
    int posY = 200;
    for (int i = 0; i < 3; i++) {
        //Start Game
        startMenu[i].setFont(font);
        startMenu[i].setFillColor(Color::White);
        startMenu[i].setCharacterSize(70);
        startMenu[i].setPosition(400, posY);

        posY += 100;

    }

    startMenu[0].setString("Go");
    startMenu[1].setString("About");
    startMenu[2].setString("Exit");

    StartWindowSelected = -1;
}

StartWindow::~StartWindow(){}

//Draw Window

void StartWindow::drawWindow(RenderWindow& window) {
	for (int i = 0; i < Max_start_window; i++) {
		window.draw(startMenu[i]);
	}
}

//MoveUp

void StartWindow::moveUp() {
	if (StartWindowSelected - 1 >= 0) {
		startMenu[StartWindowSelected].setFillColor(Color::White);

		StartWindowSelected--;
		if (StartWindowSelected == -1) {
			StartWindowSelected = 2;
		}
		startMenu[StartWindowSelected].setFillColor(Color::Cyan);
	}
}

//MoveDown

void StartWindow::moveDown() {
	if (StartWindowSelected + 1 <= Max_start_window) 
	{
		startMenu[StartWindowSelected].setFillColor(Color::White);
		StartWindowSelected++;
		if (StartWindowSelected == 3) {
			StartWindowSelected = 0;
		}
		startMenu[StartWindowSelected].setFillColor(Color::Cyan);
	
	}
}



void StartWindow::initializeWindow()
{

    //Make a Main Window
    RenderWindow windowMENU(VideoMode(900, 700), "Start Game Window", Style::Default);
    StartWindow  startMenu(windowMENU.getSize().x, windowMENU.getSize().y);

    //set background
    RectangleShape background;
    background.setSize(Vector2f(900, 700));
    Texture startWindowImage;
    startWindowImage.loadFromFile("resouceImages/startMenu.jpg");
    background.setTexture(&startWindowImage);


    //set gameArea
    RectangleShape area;
    area.setPosition(250, 150);
    area.setSize(Vector2f(400, 400));
    Texture areaImage;
    areaImage.loadFromFile("resouceImages/AreaJuego.png");
    area.setTexture(&areaImage);

    //set photoGame
    RectangleShape gBackground;
    gBackground.setSize(Vector2f(900, 700));
    Texture gameWindowImage;
    gameWindowImage.loadFromFile("resouceImages/goGame.jpg");
    gBackground.setTexture(&gameWindowImage);

    //set photoAbout
    RectangleShape aBackground;
    aBackground.setSize(Vector2f(900, 700));
    Texture aboutWindowImage;
    aboutWindowImage.loadFromFile("resouceImages/about.png");
    aBackground.setTexture(&aboutWindowImage);

    //set button
    Texture but;
    Sprite ButtonImage;
    but.loadFromFile("resouceImages/Ladron.png");
    ButtonImage.setPosition(350, 250);
    float ButtonWidth = ButtonImage.getLocalBounds().width;
    float ButtonHeight = ButtonImage.getLocalBounds().height;
    ButtonImage.setTexture(but);

    while (windowMENU.isOpen()) {
        Event event;
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
                    RenderWindow Go(VideoMode(900, 700), "CATAN");
                    RenderWindow About(VideoMode(900, 700), "About");
                    
                    
                    int pos = startMenu.StartWindowPressed();
                    
                    if (pos == 0) {
                        while (Go.isOpen()) {
                            Event event1;
                            while (Go.pollEvent(event1)) {
                                if (event1.type == Event::Closed) {
                                    Go.close();
                                }
                                if (event1.type == Event::KeyPressed) {
                                    if (event1.key.code == Keyboard::Escape) {
                                        Go.close();
                                    }
                                }
                            }
                            About.close();
                            Go.clear();
                            Go.draw(gBackground);
                            Go.draw(area);
                            Go.draw(ButtonImage);
                            Go.display();
                        }
                    }
                    if (pos == 1) {
                        while (About.isOpen()) {
                            Event event1;
                            while (About.pollEvent(event1)) {
                                if (event1.type == Event::Closed) {
                                    About.close();
                                }
                                if (event1.type == Event::KeyPressed) {
                                    if (event1.key.code == Keyboard::Escape) {
                                        About.close();
                                    }

                                }
                            }
                            Go.close();
                            About.clear();
                            About.draw(aBackground);
                            About.display();
                        }
                    }
                    if (pos == 2)
                        windowMENU.close();
                    break;
                }

            }
        }
        windowMENU.clear();
        windowMENU.draw(background);
        startMenu.drawWindow(windowMENU);
        windowMENU.display();
    }
}

void StartWindow::button()
{
    /*f::Texture exitButton;
    sf::Sprite exitButtonImage;
    if (!exitButton.loadFromFile("Exit Button.png"))
        std::cout << "Can't find the image" << std::endl;
    exitButtonImage.setPosition(50.0f, 500.0f);

    float exitButtonWidth = exitButtonImage.getLocalBounds().width;
    float exitButtonHeight = exitButtonImage.getLocalBounds().height;

    exitButtonImage.setTexture(exitButton);*/

}
