#include "Graph.h"

Graph::Graph(int numVertex, bool dirigido)
{
    this->dirigido = dirigido;
    this->numVertex = numVertex;
    adjacencyMatrix = new int* [numVertex];

    if (dirigido) {
        MM = new int* [numVertex];
    }
    for (int i = 0; i < numVertex; i++) {
        adjacencyMatrix[i] = new int[numVertex];
        if (dirigido) {
            MM[i] = new int[numVertex];
        }
        for (int j = 0; j < numVertex; j++) {
            if (dirigido) {
                MM[i][j] = 0;
            }
            adjacencyMatrix[i][j] = 0;
        }

    }

}

void Graph::cleanMM()
{
   
}

void Graph::addEdge(int i, int j, int cost)
{
   
}

void Graph::reverseDijkstra(int src)
{
    
}

bool Graph::hasConstruction(Graph&)
{
    return false;
}

void Graph::imprimir()
{

    

}

void Graph::imprimirMM()
{
    
}

void Graph::cargarMM(int src)
{
    
}

Graph::~Graph()
{
    for (int i = 0; i < numVertex; i++)
    {
        if (dirigido) {
            delete[] MM[i];
        }
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
    if (dirigido) {
        delete[] MM;
    }
}