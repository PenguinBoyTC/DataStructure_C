/**
*	@file LinkedList.h
*	@author ChongTan
*	@date 1/23/18
*	@brief A header file for templated LinkedList class
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

template <typename T>
class LinkedList
{
	public:
		LinkedList();//constructor
		~LinkedList();//Distructor
		bool addBack(T value);//add a node to the end of the list if the value doesn't exist;
		Node<T>* insert(Node<T>* subList, Node<T>* NewNode);//Insert value into the end of the list
		bool isEmpty() const;//return true if the list is empty, false otherwise.
		bool remove(T value);//Remove x from List if found; else return false;
		Node<T>*  erase(Node<T>* subList, T value);//a recursively method to delete node
    	void print();//print out all the elements of the list separated by a space. 
		void printHelper(Node<T>* subList);//a recursive function to print the list.
		bool isExist(T value);//a function to call find method so that it can be used in other class.
		Node<T>* find(Node<T>* subList, T value);//Search for value in L and return the pointer pointing at the node containing x. if x not found, return a NULL pointer.

	private:
		Node<T>* m_front;
		int m_length;
};
#include "LinkedList.hpp"
#endif
