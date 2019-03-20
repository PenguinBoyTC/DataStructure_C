#ifndef MINMAX_HEAP_H
#define MINMAX_HEAP_H
#include "HeapInterface.h"
#include <string>
#include <math.h>
//#include <algorithm>
template <typename T>
class MinMax_Heap: public HeapInterface<T>
{
public:
	MinMax_Heap(int initialSize);//constructor
	MinMax_Heap(const MinMax_Heap<T>& heap); // The copy constructor
	MinMax_Heap(int initialSize, std::string filename);
	~MinMax_Heap();
	void buildheap();
	void insert(T newItem);//add a Item to the tree
	bool deletemin();
	bool deletemax();
	T findmin();//return the top Item from the tree
	T findmax();
	void levelorder(int k_heap);
	bool isEmpty();//check if the tree is empty
private:
	T* theCompleteBinaryTree;
	int sizeOfArray;
	int numItemsInHeap;
	//helper functions
	void insertbuild(int newIndex);
	void swapbyMinLevel(int newIndex);
	void swapbyMaxLevel(int newIndex);
	bool isMaxLevel(int index);
	bool isMinLevel(int index);
	int Maxchild(int parent);
	int Minchild(int parent);
	void buildHelper(int parent);//switch the parent with all its child and swap until reach the bottom
	int targetgrandChildIndex(int parent);
	int targetChildIndex(int parent);
};
#include "MinMax_Heap.hpp"
#endif
