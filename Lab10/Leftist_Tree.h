/**@file Leftist_tree.h */
 
#ifndef _LEFTIST_TREE
#define _LEFTIST_TREE

#include <string>
#include <fstream>
#include <iostream>

#include "Leftist_Tree.h"
#include "Leftist_Node.h"
#include "Queue.h"
#include "LeftistOrSkewInterface.h"
template<typename T>
class Leftist_Tree: public LeftistOrSkewInterface<T>
{
public:
    Leftist_Tree();//constructor
    ~Leftist_Tree();//destructor
    void buildheap(std::string filename);
    void Insert(T value);//return true if insert successfully
    bool DeleteMin();//return true after delete min element successfully
    T FindMin();//return the min element if min element exist, otherwise return -1
    Leftist_Node<T>* Concate(Leftist_Node<T>* H1, Leftist_Node<T>* H2);
    void Preorder();
    void Inorder();
    void Levelorder();//print the tree by level order
    
private:

    Leftist_Node<T>* rootPtr;
    //helper functions below:
    void preorderTraverse(Leftist_Node<T>* treePtr);
    void inorderTraverse(Leftist_Node<T>* treePtr);
    void levelorderTraverse(Leftist_Node<T>* treePtr);
    void adjustRank(Leftist_Node<T>* H1);
    int GetRank(Leftist_Node<T>* H);
}; // end Leftist_tree

#include "Leftist_Tree.hpp"

#endif
