#include <iostream>
#include "SFML/Graphics.hpp"
#include "StartWindow.h"
#include "Player.h"
#include "CircularList.h"
#include "Graph.h"
#include"Bank.h"



int main()
{
    StartWindow start(X, Y);
    start.mainWindow();

    //Graph graph(54);

    //    // Imprime el grafo
    //    cout << "Grafo:" << endl;
    //graph.imprimirGrafo();

    // //Ejecuta el algoritmo de Dijkstra invertido
    //graph.reverseDijkstra(25);
    //// Verifica los resultados de la ejecución de Dijkstra

    //    return 0;

    //CircularList<Player>* list = new CircularList<Player>;
    //Player* player1 = new Player(1, "maria", 20, 40, 1);
    ///*Player *player2 = new Player(2,"Dayana", 20,20,2);
    //Player *player3 = new Player(3, "Arianna", 20, 50,3);
    //Player *player4 = new Player(4, "Kira", 25, 70,4);*/
    //player1->insertResourceCard("madera", 1, 2, 7, 4);
    //player1->insertResourceCard("Piedra", 1, 2, 7, 4);
    //player1->insertDevelopmentCard("caballero", 2, 7, 1, 2);
    //player1->insertSpecialCard("Mayor Ruta", 2, 5, 7);

    //list->inserNode(player1);
    ///*list->inserNode(player2);
    //list->inserNode(player3);
    //list->inserNode(player4);*/
    //list->dropDownList();
    //player1->insertResourceCard("madera", 1, 2, 3, 4);
    //list->dropDownList();
    //Bank bank;
    //bank.loadLists();
    ////bank.addUpCards("madera", 2);
    ////bank.substtractCards("caballero", 2, 2);
    //bank.substtractCards("madera", 1, 2);
    //bank.substtractCards("caballero", 2, 2);
    return 0;
}
