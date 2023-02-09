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
    ~VertexGraph()
    {
    }
    int getData() {
        return this->data;
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
