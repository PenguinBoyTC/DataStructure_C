//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file 2_3Node.h */
 
#ifndef _TWO_THREE_NODE
#define _TWO_THREE_NODE

template<typename NodeItemType>
class twothree_Node
{   
private:

   NodeItemType m_keyValue;
   NodeItemType m_minSecond;           // Data portion
   NodeItemType m_minThird; 
   int flag;
   twothree_Node<NodeItemType>* FirstPtr;   // Pointer to first child
   twothree_Node<NodeItemType>* SecondPtr;  // Pointer to second child
   twothree_Node<NodeItemType>* ThirdPtr;   // Pointer to third child
   twothree_Node<NodeItemType>* ParentPtr;
   

public:
   twothree_Node();
   twothree_Node(NodeItemType& minSecond, NodeItemType& minThird);
   twothree_Node(NodeItemType& keyValue);

   void setKeyValue(NodeItemType keyValue);
   NodeItemType getKeyValue();
   void setminSecond(NodeItemType minSecond);
   NodeItemType getminSecond();
   void setminThird(NodeItemType minThird);
   NodeItemType getminThird();
   bool isInteriorNode();
   bool isLeafNode();
   twothree_Node<NodeItemType>* getFirstChildPtr() const;
   twothree_Node<NodeItemType>* getSecondChildPtr() const;
   twothree_Node<NodeItemType>* getThirdChildPtr() const;
   twothree_Node<NodeItemType>* getParentPtr() const;
   
   void setFirstChildPtr(twothree_Node<NodeItemType>* firstChildPtr);
   void setSecondChildPtr(twothree_Node<NodeItemType>* secondChildPtr); 
   void setThirdChildPtr(twothree_Node<NodeItemType>* thirdChildPtr);    
   void setParentPtr(twothree_Node<NodeItemType>* Parent);        
}; // end twothree_Node

#include "twothree_Node.hpp"

#endif 
