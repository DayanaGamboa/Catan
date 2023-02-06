#pragma once
class VertexGraph {

public:
    int data;
    int x;
    int y;
    
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