#ifndef Executive_H
#define Executive_H
#include <string>
#include <fstream>
#include <iostream>
#include "MaxMin_Heap.h"
#include "MinMax_Heap.h"
#include "HeapInterface.h"
class Executive
{
public:
    Executive(char* name);//constructor
	~Executive();//distructor
    void run();//run method
    void Insert();//
    void DeleteMin();
    void DeleteMax();
    void FindMin();
    void FindMax();
    void LevelOrder();

private:
    HeapInterface <int>* Heap;
    int choose;
};
#endif
