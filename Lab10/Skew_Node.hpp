/** @file Skew_Node.cpp */

#include "Skew_Node.h"


template<typename T>
Skew_Node<T>::Skew_Node()
{
    m_key = -1;
    LeftChild = nullptr;
    RightChild = nullptr;
}
template<typename T>
Skew_Node<T>::Skew_Node(T key)
{
    m_key = key;
    LeftChild = nullptr;
    RightChild = nullptr;
}
template<typename T>
T Skew_Node<T>::getKeyValue() const
{
    return m_key;
}

template<typename T>
Skew_Node<T>* Skew_Node<T>::getLeftChildPtr() const
{
    return LeftChild;
}
template<typename T>
Skew_Node<T>* Skew_Node<T>::getRightChildPtr() const
{
    return RightChild;
}
template<typename T>
void Skew_Node<T>::setKeyValue(T key)
{
    m_key = key;
}
template<typename T>
void Skew_Node<T>::setLeftChildPtr(Skew_Node<T>* leftChildPtr)
{
    LeftChild = leftChildPtr;
}
template<typename T>
void Skew_Node<T>::setRightChildPtr(Skew_Node<T>* rightChildPtr)
{
    RightChild = rightChildPtr;
}