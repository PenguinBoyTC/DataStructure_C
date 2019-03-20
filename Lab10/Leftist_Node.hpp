/** @file Leftist_Node.cpp */

#include "Leftist_Node.h"


template<typename T>
Leftist_Node<T>::Leftist_Node()
{
    m_key = -1;
    m_rank = 1;
    LeftChild = nullptr;
    RightChild = nullptr;
}
template<typename T>
Leftist_Node<T>::Leftist_Node(T key)
{
    m_key = key;
    m_rank = 1;
    LeftChild = nullptr;
    RightChild = nullptr;
}
template<typename T>
T Leftist_Node<T>::getKeyValue() const
{
    return m_key;
}
template<typename T>
int Leftist_Node<T>::getRank() const
{
    return m_rank;
}
template<typename T>
Leftist_Node<T>* Leftist_Node<T>::getLeftChildPtr() const
{
    return LeftChild;
}
template<typename T>
Leftist_Node<T>* Leftist_Node<T>::getRightChildPtr() const
{
    return RightChild;
}
template<typename T>
void Leftist_Node<T>::setKeyValue(T key)
{
    m_key = key;
}
template<typename T>
void Leftist_Node<T>::setRank(int rank)
{
    m_rank = rank;
}
template<typename T>
void Leftist_Node<T>::setLeftChildPtr(Leftist_Node<T>* leftChildPtr)
{
    LeftChild = leftChildPtr;
}
template<typename T>
void Leftist_Node<T>::setRightChildPtr(Leftist_Node<T>* rightChildPtr)
{
    RightChild = rightChildPtr;
}
// template<typename T>
// bool Leftist_Node<T>::isLeafNode()
// {
//     if(LeftChild == nullptr && RightChild == nullptr)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }