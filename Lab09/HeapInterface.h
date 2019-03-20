#ifndef _HEAP_INTERFACE
#define _HEAP_INTERFACE
#include <string>
template<typename T>
class HeapInterface
{
public:
	// HeapInterface(){};//constructor
	virtual ~HeapInterface(){};
	virtual void insert(T newItem)=0;//add a Item to the tree
	virtual bool deletemin()=0;
	virtual bool deletemax()=0;
	virtual T findmin()=0;//return the top Item from the tree
	virtual T findmax()=0;//return the top Item from the tree
	virtual void levelorder(int k_heap)=0;
	virtual bool isEmpty()=0;//check if the tree is empty
};
#endif