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

	Node<T>* createNode(T*);
	void inserNode(T*);
	void findNode(string);
	void dropDownList();
	/*void showCards();*/
	void saveFile(string);
	void loadFromFile(const string&);
	bool existenceOfCard(string);
	void increaseQuantity(string, int);
	void decrementQuantity(string, int);
	void sortPlayerListDescending();
	/*void PlayerInformation();*/

};
template<class T>
CircularList<T> ::CircularList() {

}
template<class T>
Node<T>* CircularList<T>::createNode(T* obj) {
	Node<T>* node = (Node<T>*)malloc(sizeof(Node<T>));
	node->setData(obj);
	node->setNextNoden(nullptr);

	return node;

}
template<class T>
void CircularList<T>::inserNode(T* obj) {
	Node<T>* node = createNode(obj);

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
void CircularList<T>::dropDownList() {

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

template<class T>
bool CircularList<T>::existenceOfCard(string name) {

	if (first) {
		Node<T>* node = first;
		if (node->getData()->getCardName() == name) { return true; }
		else { return false; }
		node = node->getNextNode();
	}
	else {
		return false;
	}

}

template<class T>
void CircularList<T>::increaseQuantity(string name, int quantity) {

	if (first) {
		Node<T>* node = first;
		int increase = 0;
		do {
			if (node->getData()->getCardName() == name) {
				increase = node->getData()->getQuantity();
				node->getData()->setQuantity(increase + quantity);
				node = nullptr;
			}
			else {
				node = node->getNextNode();
			}
		} while (node != nullptr);
	}
}

template<class T>
void CircularList<T>::decrementQuantity(string name, int quantity) {

	if (first) {
		Node<T>* node = first;
		int increase = 0;
		do {
			if (node->getData()->getCardName() == name) {
				increase = node->getData()->getQuantity();
				node->getData()->setQuantity(increase - quantity);
				node = nullptr;
			}
			else {
				node = node->getNextNode();
			}
		} while (node != nullptr);
	}
}

template<class T>
void CircularList<T>::sortPlayerListDescending() {
	Node<T>* node = first;
	Node<T>* next = nullptr;
	T* tem = nullptr;

	while (node->getNextNode() != first) {
		next = node->getNextNode();
		while (next != first) {
			if (node->getData()->getAge() < next->getData()->getAge()){
				tem = next->getData();
				next->setData(node->getData());
				node->setData(tem);
			}
			next = next->getNextNode();

		}
		node = node->getNextNode();
		next = node->getNextNode();
	} 
}

//template<class T>
//void CircularList<T>::showCards() {
//
//	if (first) {
//		Node<T>* node = first;
//		do {
//			cout << node->getData()->showCard() << endl;
//			node = node->getNextNode();
//		} while (node != first);
//	}
//	else {
//		cout << "Lista vacia...!" << endl;
//	}
//
//}


