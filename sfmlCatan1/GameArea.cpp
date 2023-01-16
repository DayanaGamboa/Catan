#include "GameArea.h"

GameArea::GameArea(float width, float height)
{
    if (!font.loadFromFile("Fonts/GethoFont.ttf")) {
        cout << "¡¡No Font!!";
    }
}

void GameArea::generateGameArea()
{

    //set photoGame
    RectangleShape gBackground;
    gBackground.setSize(Vector2f(960, 720));
    Texture gameWindowImage;
    gameWindowImage.loadFromFile("resouceImages/goGame.jpg");
    gBackground.setTexture(&gameWindowImage);




}

void GameArea::putThief()
{
}

void GameArea::putConstructionCosts()
{
}

void GameArea::putCardsCradle()
{
}

void GameArea::putSpecialCards()
{
}

void GameArea::assignPlayerColor()
{
}

void GameArea::assignPlayerShift()
{
}

void GameArea::button()
{
    
}
