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
    int** cost, * distance, * pred;
    int* visited, count, maxdistance, nextnode = -1, i, j;
    cost = new int* [numVertex];
    distance = new int[numVertex] {0};
    pred = new int[numVertex] {false};
    visited = new int[numVertex] { -1 };
    for (int i = 0; i < numVertex; i++) {
        cost[i] = new int[numVertex];
        for (int j = 0; j < numVertex; j++) {
            if (adjacencyMatrix[i][j] == 0)
                cost[i][j] = INT_MIN;
            else
                cost[i][j] = 1 / adjacencyMatrix[i][j];
        }

    }
    for (i = 0; i < numVertex; i++) {
        distance[i] = cost[src][i];
        pred[i] = src;
        visited[i] = 0;
    }
    distance[src] = 0;
    visited[src] = 1;
    count = 1;
    while (count < numVertex - 1) {
        maxdistance = INT_MIN;
        for (i = 0; i < numVertex; i++)
            if (distance[i] > maxdistance && !visited[i]) {
                maxdistance = distance[i];
                nextnode = i;
            }
        if (nextnode == -1) { break; }
        visited[nextnode] = 1;
        for (i = 0; i < numVertex; i++)
            if (!visited[i])
                if (maxdistance + cost[nextnode][i] > distance[i]) { //BUSCA CAMINO MAS LARGO
                    distance[i] = maxdistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }
    int counter = 0;
    for (i = 0; i < numVertex; i++) {
        if (i != src) {
            counter = 0;
            MM[i][counter] = i;
            counter += 1;
            j = i;
            do {
                j = pred[j];
                MM[i][counter] = j;
                counter += 1;

            } while (j != src);
        }
    }
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