#include <string>

template <typename T>
Min5_Heap<T>::Min5_Heap(int initialSize)//initialize the size and create a array
{
	sizeOfArray = initialSize;
	numItemsInHeap = 0;
	theCompleteBinaryTree= new T[sizeOfArray];
}
template <typename T>
Min5_Heap<T>::Min5_Heap(int initialSize, std::string filename)//initialize the size and create a array
{
	sizeOfArray = initialSize;
	numItemsInHeap = 0;
	theCompleteBinaryTree= new T[sizeOfArray];
	std::ifstream inp;
	inp.open(filename);
	int number;
	while(!inp.eof())
	{
		inp>>number;
		theCompleteBinaryTree[numItemsInHeap] = number;
		numItemsInHeap++;
	}
	inp.close();
	buildheap();
}
template <typename T>
Min5_Heap<T>::Min5_Heap(const Min5_Heap<T>& heap)//copy the tree
{
	sizeOfArray=heap.sizeOfArray;//copy the size
	numItemsInHeap=heap.numItemsInHeap;//copy the number of Item
	theCompleteBinaryTree = new T[sizeOfArray];//create a new array
	for(int i = 0; i < numItemsInHeap; i++)
	{
		theCompleteBinaryTree[i]=heap.theCompleteBinaryTree[i];//copy the array
	}
}
template <typename T>
Min5_Heap<T>::~Min5_Heap()
{
	delete[] theCompleteBinaryTree;
}
template <typename T>
void Min5_Heap<T>::insert(T newItem)//add method
{
	if(numItemsInHeap >= sizeOfArray)//check if the Number of Item is bigger than the size of array
	{
		sizeOfArray = sizeOfArray*2;
		T* temp = new T[sizeOfArray];
		for(int i = 0; i < numItemsInHeap; i++) {
			temp[i] = theCompleteBinaryTree[i];//copy the tree to a template array
		}
		delete[] theCompleteBinaryTree;
		theCompleteBinaryTree = temp;
		delete[] temp;//?
		theCompleteBinaryTree[numItemsInHeap]=newItem;//add the new Item to the end of tree
	}
	else
	{
		theCompleteBinaryTree[numItemsInHeap]=newItem;
	}
	int newIndex = numItemsInHeap;// the index of child
	bool inPlace = false;
	int parentIndex=0;//the index of parent
	while(newIndex>0 && inPlace==false)
	{
		parentIndex = (newIndex-1)/5;
		if(newItem > theCompleteBinaryTree[parentIndex])//to check which is bigger
		{
			inPlace = true;
		}
		else
		{
			std::swap(theCompleteBinaryTree[newIndex], theCompleteBinaryTree[parentIndex]);//switch the bigger number to the top
			newIndex=parentIndex;
		}
	}
	numItemsInHeap++;
}
template <typename T>
void Min5_Heap<T>::buildheap()//recusive
{
	int LastChild = numItemsInHeap-1;
  	int LastParent = (LastChild - 1)/5;
	if(LastChild>1)
	{
		for(int i=LastParent; i >= 0; i--)
		{
			int smallestChild = smallestChildIndex(i);
			buildHelper(i, smallestChild);
		}
	}
}
template <typename T>
void Min5_Heap<T>::buildHelper(int parent, int smallestchild)//switch the parent with all its child and swap until reach the bottom
{
	if(smallestChildIndex(parent)!=-1)
	{
		if(theCompleteBinaryTree[parent] > theCompleteBinaryTree[smallestchild])
		{
			std::swap(theCompleteBinaryTree[parent], theCompleteBinaryTree[smallestchild]);
			buildHelper(smallestchild, smallestChildIndex(smallestchild));
		}
	}
}
template <typename T>
int Min5_Heap<T>::smallestChildIndex(int parent)
{
	int smallerChild = 5 * parent + 1;
	int nextChild = smallerChild + 1;
	int numOfChildren = 1;
	if(smallerChild < numItemsInHeap)
	{
		while(nextChild < numItemsInHeap && numOfChildren<5)
		{
			if(theCompleteBinaryTree[smallerChild] > theCompleteBinaryTree[nextChild])
			{
				smallerChild = nextChild;
			}	
			nextChild++;
			numOfChildren++;
		}
		return smallerChild;
	}
	else
	{
		return -1;
	}
}
template <typename T>
bool Min5_Heap<T>::isEmpty()//check if it is a empty tree
{
	if(numItemsInHeap==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
int Min5_Heap<T>::biggestleafIndex()
{
	if(!isEmpty())
	{
		int LastChild = numItemsInHeap-1;
		int biggest = (LastChild-1)/5+1;
		int next = biggest+1;
		if(LastChild!=0)
		{
			while(next<numItemsInHeap)
			{
				if(theCompleteBinaryTree[biggest] < theCompleteBinaryTree[next])
				{
					biggest = next;
				}
				next++;
			}
			return biggest;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return -1;
	}
}
template <typename T>
bool Min5_Heap<T>::deletemin()//remove method
{
	if(isEmpty()==true)
	{
		return false;
	}
	else
	{
		theCompleteBinaryTree[0] = theCompleteBinaryTree[numItemsInHeap-1];//switch the last Item to the top
		theCompleteBinaryTree[numItemsInHeap-1] = -1;
		numItemsInHeap--;
		int parentIndex=0;
		int Index = smallestChildIndex(parentIndex);
		if(Index!=-1)
		{
			buildHelper(parentIndex, Index);
		}
		return true;
	}
}
template <typename T>
bool Min5_Heap<T>::deletemax()//remove method
{
	if(isEmpty()==true)
	{
		return false;
	}
	else
	{
		int childIndex = biggestleafIndex();
		theCompleteBinaryTree[biggestleafIndex()] = theCompleteBinaryTree[numItemsInHeap-1];//switch the last Item to the top
		theCompleteBinaryTree[numItemsInHeap-1] = -1;
		numItemsInHeap--;
		int parent = (childIndex-1)/5;
		deletemaxbuild(parent, childIndex);
		return true;
	}
}
template <typename T>
void Min5_Heap<T>::deletemaxbuild(int parent, int targetchild)
{
	if(targetchild>0)
	{
		if(theCompleteBinaryTree[parent] > theCompleteBinaryTree[targetchild])
		{
			std::swap(theCompleteBinaryTree[parent], theCompleteBinaryTree[targetchild]);
			deletemaxbuild((parent-1)/5, parent);
		}
	}
}
template <typename T>
T Min5_Heap<T>::findmin()//peek method
{
	if(isEmpty()==true)
	{
		return -1;
	}
	else
	{
		return theCompleteBinaryTree[0];//return the top Item
	}
}
template <typename T>
T Min5_Heap<T>::findmax()//peek method
{
	if(isEmpty()==true)
	{
		return -1;
	}
	else
	{
		return theCompleteBinaryTree[biggestleafIndex()];//return the top Item
	}
}
template <typename T>
void Min5_Heap<T>::levelorder(int k_heap)
{
	if(!isEmpty())
	{
		int last_i = 0;
		int bounded = k_heap;
		for(int i=0; i<numItemsInHeap;i++)
		{
			std::cout<<theCompleteBinaryTree[i]<<" ";
			if(i==0)
			{
				std::cout<<""<<std::endl;
			}
			else if((i-last_i) % bounded == 0)
			{
				std::cout<<""<<std::endl;
				last_i = i;
				bounded = bounded*k_heap;
			}
			else if(last_i!=0 && (i-last_i) % k_heap == 0 && i!=(numItemsInHeap-1))
			{
				std::cout<<"- ";
			}
		}
		std::cout<<""<<std::endl;
	}
}
