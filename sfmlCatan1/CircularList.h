#pragma once
#include <string.h>
#include <iostream>
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

};
