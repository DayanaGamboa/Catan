#pragma once


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

