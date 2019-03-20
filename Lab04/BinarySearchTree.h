/**@file BinarySearchTree.h */
 
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"


template<typename T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool isEmpty();
    void Insert(T value);
    bool Delete(T value);
    bool DeleteMin();
    bool DeleteMax();
    BinaryNode<T>* FindMin();
    BinaryNode<T>* FindMax();
    void Preorder();
    void Inorder();
    void Postorder();
private:

    BinaryNode<T>* rootPtr;

    void destroyTree(BinaryNode<T>* subTreePtr);// Recursively deletes all nodes from the tree.
    BinaryNode<T>* insertInorder(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr);
    bool RemoveNode(BinaryNode<T>* subTreePtr, T value);

    void RemoveMin(BinaryNode<T>* subTreePtr);
    void RemoveMax(BinaryNode<T>* subTreePtr);
    BinaryNode<T>* LookforMin(BinaryNode<T>* subTreePtr);
    BinaryNode<T>* LookforMax(BinaryNode<T>* subTreePtr);

    void preorderTraverse(BinaryNode<T>* treePtr);
    void inorderTraverse(BinaryNode<T>* treePtr);
    void postorderTraverse(BinaryNode<T>* treePtr);
    bool isDelete;
}; // end BinarySearchTree

#include "BinarySearchTree.hpp"

#endif
