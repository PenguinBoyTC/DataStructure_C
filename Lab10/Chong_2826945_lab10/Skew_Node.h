
 
#ifndef _SKEW_NODE
#define _SKEW_NODE

template<typename T>
class Skew_Node
{   
private:

   T m_key;
   Skew_Node<T>* LeftChild;   // Pointer to first child
   Skew_Node<T>* RightChild;  // Pointer to second child

public:
   Skew_Node();
   Skew_Node(T key);
   T getKeyValue() const;
   Skew_Node<T>* getLeftChildPtr() const;
   Skew_Node<T>* getRightChildPtr() const;
   
   void setKeyValue(T key);
   void setLeftChildPtr(Skew_Node<T>* leftChildPtr);
   void setRightChildPtr(Skew_Node<T>* rightChildPtr); 
         
}; // end Skew_Node

#include "Skew_Node.hpp"

#endif 
