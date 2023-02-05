#pragma once
class VertexGraph {

public:
    int data;
    int x;
    int y;
    /*VertexGraph(int,int,int);
    ~VertexGraph();
    void setData(int);
    int getData();
    int getX();
    int getY();
    bool isConstruido();
    void construir();*/


    VertexGraph()
    {
        this->data = data;
        this->x = x;
        this->y = y;

    }
    int getData() {
        return this->data;
    }


    ~VertexGraph()
    {
        //falta?
    }
    void setData(int data) {
        this->data = data;
    }

    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }
};