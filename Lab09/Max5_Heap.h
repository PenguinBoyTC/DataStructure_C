#ifndef MAX5_HEAP_H
#define MAX5_HEAP_H
#include "HeapInterface.h"
#include <string>

template <typename T>
class Max5_Heap: public HeapInterface<T>
{
public:
	Max5_Heap(int initialSize);//constructor
	Max5_Heap(const Max5_Heap<T>& heap); // The copy constructor
	Max5_Heap(int initialSize, std::string filename);
	~Max5_Heap();
	void buildheap();
	void insert(T newItem);//add a Item to the tree
	bool deletemin();
	bool deletemax();
	T findmin();
	T findmax();
	void levelorder(int k_heap);
	bool isEmpty();//check if the tree is empty
	void insertWithoutsorted(T newItem);
private:
	T* theCompleteBinaryTree;
	int sizeOfArray;
	int numItemsInHeap;
	//Helper Functions
	int biggestChildIndex(int parent);
	int smallestleafIndex();
	void buildHelper(int parent, int biggestchild);
	void deleteminbuild(int parent, int targetchild);
};
#include "Max5_Heap.hpp"
#endif
