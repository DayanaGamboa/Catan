#pragma once
class VertexGraph {

public:
    int data;
    int x;
    int y;
    int idProp;
    bool town = false;
    bool city = false;

    VertexGraph()
    {
        this->data = data;
        this->x = x;
        this->y = y;
        this->idProp = idProp;
        this->town = town;
        this->city = city;
    }
    ~VertexGraph()
    {
        //falta?
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
    int getIdProp() {
        return this->idProp;
    }
    void setIdProp(int idProp) {
        this->idProp = idProp;
    }

};
