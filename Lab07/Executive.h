#ifndef Executive_H
#define Executive_H
#include <string>
#include <fstream>
#include <iostream>
#include "Max5_Heap.h"
#include "Min5_Heap.h"
#include "HeapInterface.h"
class Executive
{
public:
    Executive();//constructor
	~Executive();//distructor
    void run();//run method
    void Insert();//
    void DeleteMin();
    void DeleteMax();
    void FindMin();
    void FindMax();
    void LevelOrder();

private:
    //Max5_Heap <int>* Heap;
    // Max5_Heap <int>* MaxHeap;
    // Min5_Heap <int>* MinHeap;
    HeapInterface <int>* Heap;
};
#endif
