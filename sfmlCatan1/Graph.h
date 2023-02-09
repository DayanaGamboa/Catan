#pragma once
#include <climits>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <list>
#include "VertexGraph.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Graph {
public:
    vector<CircleShape> circlesV;
    vector<list<int>> adjacencyMatrix;
    vector<VertexGraph> vertices;
    bool verticesConstructed[54];
    int numVertices = 54;
    int positions[54][2] = { {819,241},{783,226},{742,245},{701,225},{659,242},{620,226},{587,243},{585,276},{550,302},{550,338},
        {512,357},{509,396},{545,414},{548,452},{585,470},{586,508},{619,524},{660,507},{701,524},{740,508},{781,525},{819,508},
        {821,472},{858,452},{862,416},{898,395},{900,358},{860,336},{857,298},{821,279},{780,300},{737,275},{703,301},{660,282},
        {625,303},{623,335},{585,358},{587,395},{623,415},{622,449},{663,473},{703,450},{742,472},{783,451},{783,415},{820,397},
        {822,361},{780,333},{740,359},{700,335},{663,361},{660,390},{703,413},{740, 390}};

    Graph() {
        adjacencyMatrix.resize(numVertices);
        vertices.resize(numVertices);

        loadEdgeFromFile();

        for (int i = 0; i < numVertices; i++) {
            vertices[i].setData(i);
            vertices[i].x = positions[i][0];
            vertices[i].y = positions[i][1];
        }
    }
    void loadEdgeFromFile() {
        ifstream file("edges.txt");


        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                istringstream iss(line);
                string ori, dest;
                getline(iss, ori, ',');
                getline(iss, dest, ',');
                int origin = stoi(ori);
                int destin = stoi(dest);
                addEdge(origin, destin);
            }
            file.close();
        }

    }
    void addEdge(int origen, int destino) {
        adjacencyMatrix[origen].push_back(destino);
    }
    void drawEdges(RenderWindow* Go) {

        for (int i = 0; i < vertices.size(); i++) {
            for (auto j = adjacencyMatrix[i].begin(); j != adjacencyMatrix[i].end(); j++) {
                int indiceAdyacente = *j;
                VertexGraph vertex1 = vertices[i];
                VertexGraph vertex2 = vertices[indiceAdyacente];
                Vector2f p1(vertex1.x, vertex1.y);
                Vector2f p2(vertex2.x, vertex2.y);
                VertexArray edge(Lines, 2);
                edge[0].position = p1;
                edge[1].position = p2;
                edge[0].color = Color::Black;
                edge[1].color = Color::Black;
                Go->draw(edge);
            }
        }
    }
    void drawVertex(RenderWindow* Go) {
        CircleShape circle(10);
        circle.setFillColor(Color(135, 135, 135));
        list<Vector2f> positions = {
            {819,241},{783,226},{742,245}, {701,225},{659,242},{620,226},{587,243},{585,276},{ 550,302},{ 550,338},{512,357},{509,396},{545,414},{548,452},{585,470},{586,508},{619,524},{660,507},{701,524},{740,508},{781,525},{819,508},{821,472},{858,452},{862,416},{898,395},{900,358},{860,336},{857,298},{821,279},
            {780,300},{737,275},{703,301},{660,282},{625,303},{623,335},{585,358},{587,395},{623,415},{622,449},{663,473},{703,450},{742,472},{783,451},{783,415},{820,397},{822,361},{780,333},
            {740, 359} ,{700,335},{663,361},{660,390},{703,413},{740, 390}
        };
        for (auto& pos : positions)
        {
            circle.setPosition(pos);
            circlesV.push_back(circle);
        }
        for (auto& circle : circlesV)
            Go->draw(circle);
    }
    /*void imprimirGrafo() {
        for (int i = 0; i < adjacencyMatrix.size(); i++) {
            cout << i << " : ";
            for (auto j : adjacencyMatrix[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }*/
    void reverseDijkstra(int route) {
        vector<int> distance(vertices.size(), INT_MIN), pred(vertices.size(), -1);
        vector<bool> visited(vertices.size(), false);
        distance[route] = 0;
        for (int count = 0; count < vertices.size() - 1; count++) {
            int u = maxDistance(distance, visited);
            visited[u] = true;
            for (int v : adjacencyMatrix[u]) {
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