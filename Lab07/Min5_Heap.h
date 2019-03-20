#ifndef MIN5_HEAP_H
#define MIN5_HEAP_H
#include "HeapInterface.h"
#include <string>

template <typename T>
class Min5_Heap: public HeapInterface<T>
{
public:
	Min5_Heap(int initialSize);//constructor
	Min5_Heap(const Min5_Heap<T>& heap); // The copy constructor
	Min5_Heap(int initialSize, std::string filename);
	~Min5_Heap();
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
	int smallestChildIndex(int parent);
	int biggestleafIndex();
	void buildHelper(int parent, int smallestchild);//switch the parent with all its child and swap until reach the bottom
	void deletemaxbuild(int parent, int targetchild);
};
#include "Min5_Heap.hpp"
#endif
