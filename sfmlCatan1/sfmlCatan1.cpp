// sfmlCatan1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "SFML/Graphics.hpp"
#include "StartWindow.h"
#include "Player.h"
#include "CircularList.h"
#include "Graph.h"



int main()
{
    //StartWindow start(X, Y);
    //start.mainWindow();

    Graph graph(6, true);

    graph.addEdge(0, 2, 9);
    graph.addEdge(0, 1, 7);
    graph.addEdge(0, 5, 14);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 5, 2);
    graph.addEdge(2, 3, 11);
    graph.addEdge(4, 3, 6);
    graph.addEdge(5, 4, 9);
    graph.imprimir();

    graph.cargarMM(2);
    cout << "Dijkstra" << endl;
    graph.imprimirMM();

    //CircularList<Player>* list = new CircularList<Player>;
    //Player* player1 = new Player(1, "maria", 20, 40, 1);
    ///*Player *player2 = new Player(2,"Dayana", 20,20,2);
    //Player *player3 = new Player(3, "Arianna", 20, 50,3);
    //Player *player4 = new Player(4, "Kira", 25, 70,4);*/
    //player1->insertResourceCard("madera", 1, 2, 7, 4);
    //player1->insertResourceCard("Piedra", 1, 2, 7, 4);
    //player1->insertDevelopmentCard("Caballero", 2, 7, 1, 2);
    //player1->insertSpecialCard("Mayor Ruta", 2, 5, 7);

    //list->inserNode(player1);
    ///*list->inserNode(player2);
    //list->inserNode(player3);
    //list->inserNode(player4);*/
    //list->dropDownList();
    //player1->insertResourceCard("madera", 1, 2, 3, 4);
    //list->dropDownList();
    
}
