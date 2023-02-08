#include "Dice.h"

Dice::Dice()
{
}

Dice::~Dice()
{
}

int Dice::diceFinalAmount(RenderWindow * Go) {

        int diceSum = 0;

        if (paintDices) {

            int numRandom = 0;
            srand(time(NULL));
            numRandom = 1 + rand() % 6;
            string path;
            path = "resouceImages/D";
            path += to_string(numRandom);
            path += ".png";
            rtsDice1.setPosition(Vector2f(900, 10));
            rtsDice1.setSize(Vector2f(100, 100));
            txtrRtsDice1.loadFromFile(path);
            rtsDice1.setTexture(&txtrRtsDice1);
            diceSum += numRandom;
            numRandom = 1 + rand() % 6;
            path = "resouceImages/D";
            path += to_string(numRandom);
            path += ".png";
            rtsDice2.setPosition(Vector2f(1020, 10));
            rtsDice2.setSize(Vector2f(100, 100));
            txtrRtsDice2.loadFromFile(path);
            rtsDice2.setTexture(&txtrRtsDice2);
            diceSum += numRandom;
            cout << "SUMA: " << diceSum << endl;
            paintDices = false;
        }
        Go->draw(rtsDice1);
        Go->draw(rtsDice2);
        

        return diceSum;
    }

