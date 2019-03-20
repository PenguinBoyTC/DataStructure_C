#ifndef Executive_H
#define Executive_H
#include <string>
#include <fstream>
#include <iostream>
#include "BinarySearchTree.h"
#include "BinaryNode.h"

class Executive
{
public:
    Executive();//constructor
	~Executive();//distructor
    void run();//run method
    void Insert();//
    void Delete();//
    void DeleteMin();
    void DeleteMax();
    void FindMin();
    void FindMax();

private:
    BinarySearchTree<int>* bst;
};
#endif
    
