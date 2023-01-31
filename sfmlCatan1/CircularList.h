#pragma once
#include <string.h>
#include <iostream>
#include <fstream>
#include "Node.h"
using namespace::std;

template<class T>
class CircularList {
public:
	Node<T>* first;
	Node<T>* last;

	CircularList();
	~CircularList();

	Node<T>* crearNode(T*);
	void inserNode(T*);
	void findNode(string);
	void desplegarLista();
	void saveFile(string);
	void loadFromFile(const string&);

};
template<class T>
CircularList<T> ::CircularList() {

}
template<class T>
Node<T>* CircularList<T>::crearNode(T* obj) {
	Node<T>* node = (Node<T>*)malloc(sizeof(Node<T>));
	node->setData(obj);
	node->setNextNoden(nullptr);

	return node;

}
template<class T>
void CircularList<T>::inserNode(T* obj) {
	Node<T>* node = crearNode(obj);

	if (!first) {
		first = node;
		first->setNextNoden(first);
		last = first;

	}
	else {
		last->setNextNoden(node); 
		node->setNextNoden(first);
		last = node;
	}

}
template<class T>
void CircularList<T>::findNode(string ide) {



}
template<class T>
void CircularList<T>::desplegarLista() {

	if (first) {
		Node<T>* node = first;
		do {
			cout << "Dato: " << node->getData()->toString() << endl;
			node = node->getNextNode();
		} while (node != first);
	}
	else {
		cout << "Lista vacia...!" << endl;
	}

}
template <class T>
void CircularList<T>::saveFile(string filename) {
	
	ofstream file(filename);
	if (file) {
		Node<T>* node = first;
		do {
			file << node->getData()->toString() << endl;
			node = node->getNextNode();
		} while (node != first);
		
		file.close();
	}


}
template <class T>
void CircularList<T>::loadFromFile(const string& filename) {
	
}

template<class T>
CircularList<T> ::~CircularList() {
	CircularList<T>* p;
	while (first != NULL) {
		p = first;
		first = first->getNextNode();
		delete p;
	}
}

