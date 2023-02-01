#include "Dice.h"

Dice::Dice()
{
}

Dice::~Dice()
{
}

int Dice::diceFinalAmount(RenderWindow * Go) {

        int sumaDados = 0;

        if (pintaDados == false) {

            int numRandom = 0;
            srand(time(NULL));
            numRandom = 1 + rand() % 6;
            string ruta;
            ruta = "resouceImages/D";
            ruta += to_string(numRandom);
            ruta += ".png";
            rtsDice1.setPosition(Vector2f(900, 10));
            rtsDice1.setSize(Vector2f(100, 100));
            txtrRtsDice1.loadFromFile(ruta);
            rtsDice1.setTexture(&txtrRtsDice1);


            sumaDados += numRandom;
            numRandom = 1 + rand() % 6;
            ruta = "resouceImages/D";
            ruta += to_string(numRandom);
            ruta += ".png";
            rtsDice2.setPosition(Vector2f(1020, 10));
            rtsDice2.setSize(Vector2f(100, 100));
            txtrRtsDice2.loadFromFile(ruta);
            rtsDice2.setTexture(&txtrRtsDice2);
            sumaDados += numRandom;
            cout << "SUMA: " << sumaDados << endl;
            pintaDados = true;
        }



        Go->draw(rtsDice1);
        Go->draw(rtsDice2);

        return sumaDados;

    }

