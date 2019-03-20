#ifndef MAXMIN_HEAP_H
#define MAXMIN_HEAP_H
#include "HeapInterface.h"
#include <string>
#include <math.h>

template <typename T>
class MaxMin_Heap: public HeapInterface<T>
{
public:
	MaxMin_Heap(int initialSize);//constructor
	MaxMin_Heap(const MaxMin_Heap<T>& heap); // The copy constructor
	MaxMin_Heap(int initialSize, std::string filename);
	~MaxMin_Heap();
	void buildheap();
	void insert(T newItem);//add a Item to the tree
	bool deletemin();
	bool deletemax();
	T findmin();
	T findmax();
	void levelorder(int k_heap);
	bool isEmpty();//check if the tree is empty
private:
	T* theCompleteBinaryTree;
	int sizeOfArray;
	int numItemsInHeap;
	//Helper Functions
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
#include "MaxMin_Heap.hpp"
#endif
