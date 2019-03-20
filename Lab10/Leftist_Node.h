//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file 2_3Node.h */
 
#ifndef _LEFTIST_NODE
#define _LEFTIST_NODE

template<typename T>
class Leftist_Node
{   
private:

   T m_key;
   int m_rank;
   Leftist_Node<T>* LeftChild;   // Pointer to first child
   Leftist_Node<T>* RightChild;  // Pointer to second child

public:
   Leftist_Node();
   Leftist_Node(T key);
   T getKeyValue() const;
   int getRank() const;
   Leftist_Node<T>* getLeftChildPtr() const;
   Leftist_Node<T>* getRightChildPtr() const;
   
   void setKeyValue(T key);
   void setRank(int rank);
   void setLeftChildPtr(Leftist_Node<T>* leftChildPtr);
   void setRightChildPtr(Leftist_Node<T>* rightChildPtr); 
//    bool isLeafNode();
}; // end Leftist_Node

#include "Leftist_Node.hpp"

#endif 
