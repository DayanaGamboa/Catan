#include "CircularList.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace::std;

template<class T>
CircularList<T> ::CircularList() {

}
template<class T>
Node<T>* CircularList<T>::crearNode(T* obj) {
	Node<T>* node = (Node<T>*)malloc(sizeof(Node<T>));
	node->getData() = obj;
	node->getNextNode = 0;

	return node;

}
template<class T>
void CircularList<T>::inserNode(T* obj){
	Node<T>* node = crearNode(obj);

	if (!first) {
		first = node;
		first->getNextNode = first;
		last = first;

	}
	else {
		last->getNextNode = node;
		node->getNextNode = first;
		last = node;
	}

}
template<class T>
void CircularList<T>::findNode(string ide){



}
template<class T>
void CircularList<T>::desplegarLista( ) {



}
