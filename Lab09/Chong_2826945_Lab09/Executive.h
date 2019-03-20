#ifndef Executive_H
#define Executive_H
#include <string>
#include <fstream>
#include <iostream>
#include "Max5_Heap.h"
#include "Min5_Heap.h"
#include "BinarySearchTree.h"
#include "BinaryNode.h"
#include "Timer.cpp"

class Executive
{
public:
    Executive();//constructor
	~Executive();//distructor
    void run();//run method
    void Performance_BST();
    void Performance_Max_5();
    void Performance_Min_5();
    void Performance();
private:
    int array_size;
    int m_m;
};
#endif
    
