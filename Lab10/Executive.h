#ifndef Executive_H
#define Executive_H
#include <string>
#include <fstream>
#include <iostream>
#include "Leftist_Tree.h"
#include "Skew_Tree.h"
#include "LeftistOrSkewInterface.h"
class Executive
{
public:
    Executive();//constructor
	~Executive();//distructor
    void run();//run method
    void Insert();//
    void DeleteMin();//
    void Preorder();
    void Inorder();
    void Levelorder();

private:
    LeftistOrSkewInterface<int>* Tree;
    int Tree_Option;
};
#endif
    
