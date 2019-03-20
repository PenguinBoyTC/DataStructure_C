#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include <cstddef>


template <typename T>
Bucket<T>::Bucket()
{
    m_Item = -1;
    m_flag = false;
    isempty = true;
}

template <typename T>
bool Bucket<T>::setItem(T Item)
{
    if(isempty)
    {
        m_Item = Item;//sets m_Item to Item
        isempty = false;
        return true;
    }   
    else
    {
        return false;
    } 
}

template <typename T>
void Bucket<T>::desetItem()
{
    m_Item = -1;//sets m_Item to Item
    isempty = true;
    m_flag = true;
}

template <typename T> 
T Bucket<T>::getItem()
{
    return m_Item;//returns m_Item
}

template <typename T>
void Bucket<T>::setFlag(bool flag)
{
    m_flag = flag;//sets m_flag
}

template <typename T> 
bool Bucket<T>::getFlag()
{
    return m_flag;//returns m_flag
}

template <typename T> 
bool Bucket<T>::isEmpty()
{
    return isempty;//returns true if Bucket is empty and false otherwise
}

template <typename T> 
bool Bucket<T>::AlwaysEmpty()
{
    return (isempty && !m_flag);//returns true if Bucket is empty and false otherwise
}



