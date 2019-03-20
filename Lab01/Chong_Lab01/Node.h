#ifndef NODE_H
#define NODE_H
#include <string>

template <typename T>
class Node
{
public:
	Node();//constructor
  	// ~Node();
	// void setItem(T& Item);//set value
	void setItem(T Item);//set value
	T getItem();//get value
	void setnext(Node<T>* prev); //set next Node
	Node<T>* getnext();//get next Node
private:
	T m_Item;
	Node<T>* m_next;

};
#include "Node.hpp"
#endif
