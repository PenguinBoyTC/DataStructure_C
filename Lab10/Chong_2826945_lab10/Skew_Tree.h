/**@file Skew_Tree.h */
 
#ifndef _SKEW_TREE
#define _SKEW_TREE

#include <string>
#include <fstream>
#include <iostream>

#include "Skew_Tree.h"
#include "Skew_Node.h"
#include "Queue.h"
#include "LeftistOrSkewInterface.h"

template<typename T>
class Skew_Tree: public LeftistOrSkewInterface<T>
{
public:
    Skew_Tree();//constructor
    ~Skew_Tree();//destructor
    void buildheap(std::string filename);
    void Insert(T value);//return true if insert successfully
    bool DeleteMin();//return true after delete min element successfully
    T FindMin();//return the min element if min element exist, otherwise return -1
    Skew_Node<T>* Concate(Skew_Node<T>* H1, Skew_Node<T>* H2);
    void Preorder();
    void Inorder();
    void Levelorder();//print the tree by level order
private:

    Skew_Node<T>* rootPtr;
    //helper functions below:
    void preorderTraverse(Skew_Node<T>* treePtr);
    void inorderTraverse(Skew_Node<T>* treePtr);
    void levelorderTraverse(Skew_Node<T>* treePtr);
}; // end Skew_Tree

#include "Skew_Tree.hpp"

#endif
