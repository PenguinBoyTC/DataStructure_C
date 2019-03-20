#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include <cstddef>


template <typename T>
Node<T>::Node()
{
        m_next = nullptr;//Sets m_next to nullptr
}

// template<typename T>
// Node<T>::Node(const T& Item) : m_Item(Item), m_next(NULL)
// {
// } // end constructor

template <typename T>
void Node<T>::setItem(T Item)
{
        m_Item = Item;//sets m_Item to Item
}

template <typename T> 
T Node<T>::getItem()
{
        return m_Item;//returns m_Item
}

template <typename T> 
void Node<T>::setnext(Node<T>* prev)//set next 
{
        m_next = prev;
}

template <typename T> 
Node<T>* Node<T>::getnext()
{
        return m_next;//returns m_next
}

// template <typename T> 
// Node<T>::~Node() 
// {
// 	delete m_next;
// }
