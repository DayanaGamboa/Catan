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
    for (int i = 0; i < numVertex; i++) {
        for (int j = 0; j < numVertex; j++) {
            MM[i][j] = 0;
        }
    }
}

void Graph::addEdge(int i, int j, int cost)
{
    if (dirigido) {
        adjacencyMatrix[i][j] = cost;
    }
    else {
        adjacencyMatrix[i][j] = cost;
        adjacencyMatrix[j][i] = cost;
    }
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

    for (int i = 0; i < numVertex; i++) {
        cout << i << " : ";
        for (int j = 0; j < numVertex; j++)
            cout << adjacencyMatrix[i][j] << ",";
        cout << "\n";
    }

}

void Graph::imprimirMM()
{
    if (dirigido) {
        for (int i = 0; i < numVertex; i++) {
            cout << i << " : ";
            for (int j = 0; j < numVertex; j++)
                cout << MM[i][j] << " ";
            cout << "\n";
        }
    }
}

void Graph::cargarMM(int src)
{
    if (dirigido) {
        cleanMM();
        reverseDijkstra(src);
    }
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