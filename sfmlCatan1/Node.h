#pragma once
#include <sstream>


template<class T>
class Node{

private:
	T* data;
	Node<T> *nextNode;
public:
	Node(T*, Node<T>*);
	~Node();

	void setData(T*);
	T* getData();
	void setNextNoden(Node<T>*);
	Node<T>* getNextNode();
};

template<class T>
Node<T> ::Node(T* dat, Node<T>* nextN) :data(dat), nextNode(nextN) {

}
template<class T>
void Node<T>::setData(T* obj) {
	data = obj;
}
template<class T>
T* Node<T>::getData() {
	return data;
}
template<class T>
void Node<T>::setNextNoden(Node<T>* nextN) {
	nextNode = nextN;
}
template<class T>
Node<T>* Node<T>::getNextNode() {
	return nextNode;
}
template<class T>
Node<T>::~Node() {

}
