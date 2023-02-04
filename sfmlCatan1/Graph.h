#pragma once
#include <climits>
#include <iostream>
#include "VertexGraph.h"
using namespace std;

class Graph {
public:

    vector<list<int>> matrizAdyacencia;
    vector<VertexGraph> vertices;

    Graph(int numVertices) {
        matrizAdyacencia.resize(numVertices);
        vertices.resize(numVertices);
        int posiciones[54][2] = { {819,241},{783,226},{742,245}, {701,225},{659,242},{620,226},{587,243},{585,276},{ 550,302},{ 550,338},{512,357},{509,396},{545,414},{548,452},{585,470},{586,508},{619,524},{660,507},{701,524},{740,508},{781,525},{819,508},{821,472},{858,452},{862,416},{898,395},{900,358},{860,336},{857,298},{821,279},
        {737,275},{703,301},{660,282},{625,303},{623,335},{585,358},{587,395},{623,415},{622,449},{663,473},{703,450},{742,472},{783,451},{783,415},{820,397},{822,361},{780,333},{780,300},
        {700,335},{663,361},{660,390},{703,413},{740, 390},{740, 359} };
        
        includeEdge();

        for (int i = 0; i < numVertices; i++) {
            vertices[i].setData(i);
            vertices[i].x = posiciones[i][0];
            vertices[i].y = posiciones[i][1];
        }
    }
    void includeEdge() {
        addEdge(0, 1);
        addEdge(0, 29);
        addEdge(1, 2);
        addEdge(2, 3);
        addEdge(3, 4);
        addEdge(4, 5);
        addEdge(5, 6);
        addEdge(6, 7);
        addEdge(7, 8);
        addEdge(8, 9);
        addEdge(9, 10);
        addEdge(10, 11);
        addEdge(11, 12);
        addEdge(12, 13);
        addEdge(13, 14);
        addEdge(14, 15);
        addEdge(15, 16);
        addEdge(16, 17);
        addEdge(17, 18);
        addEdge(18, 19);
        addEdge(19, 20);
        addEdge(20, 21);
        addEdge(21, 22);
        addEdge(22, 23);
        addEdge(23, 24);
        addEdge(24, 25);
        addEdge(25, 26);
        addEdge(26, 27);
        addEdge(27, 28);
        addEdge(28, 29);
        addEdge(29, 30);
        addEdge(30, 31);
        addEdge(31, 2);
        addEdge(31, 32);
        addEdge(32, 33);
        addEdge(33, 4);
        addEdge(33, 34);
        addEdge(34, 7);
        addEdge(34, 35);
        addEdge(35, 36);
        addEdge(36, 9);
        addEdge(36, 37);
        addEdge(37, 12);
        addEdge(37, 38);
        addEdge(38, 39);
        addEdge(39, 14);
        addEdge(39, 40);
        addEdge(40, 17);
        addEdge(40, 41);
        addEdge(41, 42);
        addEdge(42, 19);
        addEdge(42, 43);
        addEdge(43, 22);
        addEdge(43, 44);
        addEdge(44, 45);
        addEdge(45, 24);
        addEdge(45, 46);
        addEdge(46, 27);
        addEdge(46, 47);
        addEdge(47, 30);
        addEdge(47, 48);
        addEdge(48, 49);
        addEdge(49, 32);
        addEdge(49, 50);
        addEdge(50, 35);
        addEdge(50, 51);
        addEdge(51, 38);
        addEdge(51, 52);
        addEdge(52, 41);
        addEdge(52, 53);
        addEdge(53, 44);
        addEdge(53, 48);
    }
    void addEdge(int origen, int destino) {
        matrizAdyacencia[origen].push_back(destino);
    }

    void imprimirGrafo() {

        for (int i = 0; i < matrizAdyacencia.size(); i++) {
            cout << i << " : ";
            for (auto j : matrizAdyacencia[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    void reverseDijkstra(int src) {
        vector<int> distance(vertices.size(), INT_MIN), pred(vertices.size(), -1);
        vector<bool> visited(vertices.size(), false);
        distance[src] = 0;
        for (int count = 0; count < vertices.size() - 1; count++) {
            int u = maxDistance(distance, visited);
            visited[u] = true;
            for (int v : matrizAdyacencia[u]) {
                if (!visited[v] && distance[u] + 1 > distance[v]) {
                    distance[v] = distance[u] + 1;
                    pred[v] = u;
                }
            }
        }
    }
    int maxDistance(vector<int>& distance, vector<bool>& visited) {
        int max = INT_MIN, maxIndex=0;
        for (int v = 0; v < vertices.size(); v++) {
            if (!visited[v] && distance[v] > max) {
                max = distance[v];
                maxIndex = v;
                cout << "La ruta mas larga: " + to_string(maxIndex)<<endl;
            }
        }
        
        return maxIndex;
    }
};