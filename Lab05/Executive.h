#ifndef Executive_H
#define Executive_H
#include <string>
#include <fstream>
#include <iostream>
#include "twothree_tree.h"
#include "twothree_Node.h"

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
    void Find();
    void LevelOrder();

private:
    twothree_tree<int>* TTtree;
};
#endif
    
