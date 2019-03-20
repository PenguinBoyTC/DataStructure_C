/**@file twothree_tree.h */
 
#ifndef _TWO_THREE_TREE
#define _TWO_THREE_TREE

#include "twothree_tree.h"
#include "twothree_Node.h"

template<typename T>
class twothree_tree
{
public:
    twothree_tree();//constructor
    ~twothree_tree();//destructor
    bool Find(T value);//return true if value exist in the tree, otherwise false.
    void Levelorder();//print the tree by level order
    bool Insert(T value);//return true if insert successfully
    bool Delete(T value);//return true if delete successfully
    bool DeleteMin();//return true after delete min element successfully
    bool DeleteMax();//return true after delete max element successfully
    T FindMin();//return the min element if min element exist, otherwise return -1
    T FindMax();//return the max element if max element exist, otherwise return -1
private:

    twothree_Node<T>* rootPtr;
    //helper functions below:
    bool search(T value, twothree_Node<T>* tree);//search the value from the tree
    bool insertHelper(twothree_Node<T>* subTreePtr, twothree_Node<T>* newNodePtr);
    bool deleteHelper(T value, twothree_Node<T>* subTreePtr);
    void levelorderTraverse(twothree_Node<T>* treePtr);
    void resetMinValue(twothree_Node<T>* intNode);//a helper for insert
    void resetAllminValue(twothree_Node<T>* subTreePtr);// a helper for delete
    twothree_Node<T>* FindMinHelper(twothree_Node<T>* subTreePtr);
    twothree_Node<T>* FindMaxHelper(twothree_Node<T>* subTreePtr);
}; // end twothree_tree

#include "twothree_tree.hpp"

#endif
