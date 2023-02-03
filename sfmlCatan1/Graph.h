#pragma once
#include <climits>
#include <iostream>
using namespace std;
class Graph
{
private:
    int** adjacencyMatrix;
    int** MM;
    int numVertex;
    bool dirigido;
    bool construction;

public:
    Graph(int, bool);
    void cleanMM();

    void addEdge(int, int, int);
    void reverseDijkstra(int);
    bool hasConstruction(Graph&);
    void imprimir();
    void imprimirMM();
    void cargarMM(int);

    ~Graph();
};