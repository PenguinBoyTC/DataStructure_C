/** @file twothree_Node.cpp */

#include "twothree_Node.h"
#include <cstddef>

template<typename NodeItemType>
twothree_Node<NodeItemType>::twothree_Node()
{
    m_keyValue = -1;
    m_minSecond = -1;
    m_minThird = -1;
    flag = -1;
    FirstPtr = nullptr;
    SecondPtr = nullptr;
    ThirdPtr = nullptr;
    ParentPtr = nullptr;
}  // end default constructor

template<typename NodeItemType>
twothree_Node<NodeItemType>::twothree_Node(NodeItemType& minSecond, NodeItemType& minThird)
{
    m_keyValue = -1;
    m_minSecond = minSecond;
    m_minThird = minThird;
    flag = 0;
    FirstPtr = nullptr;
    SecondPtr = nullptr;
    ThirdPtr = nullptr;
    ParentPtr = nullptr;
}  // end constructor
template<typename NodeItemType>
twothree_Node<NodeItemType>::twothree_Node(NodeItemType& keyValue)
{
    m_keyValue = keyValue;
    m_minSecond = -1;
    m_minThird = -1;
    flag = 1;
    FirstPtr = nullptr;
    SecondPtr = nullptr;
    ThirdPtr = nullptr;
    ParentPtr = nullptr;
}  // end constructor
template<typename NodeItemType>
void twothree_Node<NodeItemType>::setKeyValue(NodeItemType keyValue)
{
   m_keyValue = keyValue;
   if(m_keyValue!=-1)
   {
       flag = 1;
   }
   else if(m_keyValue == -1 && m_minSecond == -1 && m_minThird == -1)
   {
       flag = -1;
   }
   else
   {
       flag = 0;
   }
}  // end setItem

template<typename NodeItemType>
NodeItemType twothree_Node<NodeItemType>::getKeyValue()
{
   return m_keyValue;
}  // end getItem
template<typename NodeItemType>
void twothree_Node<NodeItemType>::setminSecond(NodeItemType minSecond)
{
   m_minSecond = minSecond;
   if(m_keyValue!=-1)
   {
       flag = 1;
   }
   else if(m_keyValue == -1 && m_minSecond == -1 && m_minThird == -1)
   {
       flag = -1;
   }
   else
   {
       flag = 0;
   }
}  // end setItem

template<typename NodeItemType>
NodeItemType twothree_Node<NodeItemType>::getminSecond()
{
   return m_minSecond;
}  // end getItem
template<typename NodeItemType>
void twothree_Node<NodeItemType>::setminThird(NodeItemType minThird)
{
   m_minThird = minThird;
   if(m_keyValue!=-1)
   {
       flag = 1;
   }
   else if(m_keyValue == -1 && m_minSecond == -1 && m_minThird == -1)
   {
       flag = -1;
   }
   else
   {
       flag = 0;
   }
}  // end setItem

template<typename NodeItemType>
NodeItemType twothree_Node<NodeItemType>::getminThird()
{
   return m_minThird;
}  // end getItem

template<typename NodeItemType>
bool twothree_Node<NodeItemType>::isInteriorNode()
{
   return (flag == 0);
}  // end getItem

template<typename NodeItemType>
bool twothree_Node<NodeItemType>::isLeafNode()
{
   return (flag == 1);
}  // end getItem

template<typename NodeItemType>
twothree_Node<NodeItemType>* twothree_Node<NodeItemType>::getFirstChildPtr() const
{
   return FirstPtr;
}  
template<typename NodeItemType>
twothree_Node<NodeItemType>* twothree_Node<NodeItemType>::getSecondChildPtr() const
{
   return SecondPtr;
}  
template<typename NodeItemType>
twothree_Node<NodeItemType>* twothree_Node<NodeItemType>::getThirdChildPtr() const
{
   return ThirdPtr;
}  
template<typename NodeItemType>
void twothree_Node<NodeItemType>::setFirstChildPtr(twothree_Node<NodeItemType>* firstChildPtr)
{
    FirstPtr = firstChildPtr;
    if(firstChildPtr!=nullptr)
    {
        flag = 0;
        FirstPtr->setParentPtr(this);
    }
}
template<typename NodeItemType>
void twothree_Node<NodeItemType>::setSecondChildPtr(twothree_Node<NodeItemType>* secondChildPtr)
{
    SecondPtr = secondChildPtr;
    if(secondChildPtr!=nullptr)
    {
        SecondPtr->setParentPtr(this);
        flag = 0;
        if(SecondPtr->isLeafNode())
        {
            m_minSecond = SecondPtr->getKeyValue();
        }
    }
}
template<typename NodeItemType>
void twothree_Node<NodeItemType>::setThirdChildPtr(twothree_Node<NodeItemType>* thirdChildPtr)
{
    ThirdPtr = thirdChildPtr;
    if(thirdChildPtr!=nullptr)
    {
        ThirdPtr->setParentPtr(this);
        flag = 0;
        if(ThirdPtr->isLeafNode())
        {
            m_minThird = ThirdPtr->getKeyValue();
        }
    }
    else
    {
        m_minThird = -1;
    }
}
template<typename NodeItemType>
twothree_Node<NodeItemType>* twothree_Node<NodeItemType>::getParentPtr() const
{
   return ParentPtr;
}  
template<typename NodeItemType>
void twothree_Node<NodeItemType>::setParentPtr(twothree_Node<NodeItemType>* Parent)
{
    ParentPtr = Parent;
}