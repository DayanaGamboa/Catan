// sfmlCatan1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "SFML/Graphics.hpp"
#include "StartWindow.h"
#include "Player.h"
#include "CircularList.h"

int main()
{
    StartWindow start(X, Y);
    start.mainWindow();
    /*CircularList<Player>* list = new CircularList<Player>;
    Player *player1 = new Player(1);
    Player *player2 = new Player(2);
    Player *player3 = new Player(3);
    Player *player4 = new Player(4);

    list->inserNode(player1);
    list->inserNode(player2);
    list->inserNode(player3);
    list->inserNode(player4);

    list->desplegarLista();
    */
}
