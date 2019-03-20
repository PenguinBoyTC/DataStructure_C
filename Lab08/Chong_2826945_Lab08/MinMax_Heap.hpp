#include <string>

template <typename T>
MinMax_Heap<T>::MinMax_Heap(int initialSize)//initialize the size and create a array
{
	sizeOfArray = initialSize;
	numItemsInHeap = 0;
	theCompleteBinaryTree= new T[sizeOfArray];
}
template <typename T>
MinMax_Heap<T>::MinMax_Heap(int initialSize, std::string filename)//initialize the size and create a array
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
		theCompleteBinaryTree[numItemsInHeap+1] = number;
		numItemsInHeap++;
	}
	inp.close();
	buildheap();
}
template <typename T>
MinMax_Heap<T>::MinMax_Heap(const MinMax_Heap<T>& heap)//copy the tree
{
	sizeOfArray=heap.sizeOfArray;//copy the size
	numItemsInHeap=heap.numItemsInHeap;//copy the number of Item
	theCompleteBinaryTree = new T[sizeOfArray];//create a new array
	for(int i = 0; i <= numItemsInHeap; i++)
	{
		theCompleteBinaryTree[i]=heap.theCompleteBinaryTree[i];//copy the array
	}
}
template <typename T>
MinMax_Heap<T>::~MinMax_Heap()
{
	delete[] theCompleteBinaryTree;
}
template <typename T>
void MinMax_Heap<T>::insert(T newItem)//add method
{
	if(numItemsInHeap > sizeOfArray)//check if the Number of Item is bigger than the size of array
	{
		sizeOfArray = sizeOfArray*2;
		T* temp = new T[sizeOfArray];
		for(int i = 0; i <= numItemsInHeap; i++) {
			temp[i] = theCompleteBinaryTree[i];//copy the tree to a template array
		}
		delete[] theCompleteBinaryTree;
		theCompleteBinaryTree = temp;
		delete[] temp;//?
		theCompleteBinaryTree[numItemsInHeap+1] = newItem;//add the new Item to the end of tree
	}
	else
	{
		theCompleteBinaryTree[numItemsInHeap+1] = newItem;
	}
	
	// int newIndex = numItemsInHeap+1;// the index of child
	// bool inPlace = false;
	// int parentIndex=0;//the index of parent
	// while(newIndex>0 && inPlace==false)
	// {
	// 	parentIndex = newIndex/4;
	// 	if()
	// 	{

	// 	}
	// 	if(newItem > theCompleteBinaryTree[parentIndex])//to check which is bigger
	// 	{
	// 		inPlace = true;
	// 	}
	// 	else
	// 	{
	// 		std::swap(theCompleteBinaryTree[newIndex], theCompleteBinaryTree[parentIndex]);//switch the bigger number to the top
	// 		newIndex=parentIndex;
	// 	}
	// }
	numItemsInHeap++;
	if(numItemsInHeap>1)
	{
		insertbuild(numItemsInHeap);
	}
}
template <typename T>
void MinMax_Heap<T>::insertbuild(int newIndex)
{
	int parent = newIndex/2;
	if(isMinLevel(parent))
	{
		if(theCompleteBinaryTree[parent] > theCompleteBinaryTree[newIndex])
		{
			std::swap(theCompleteBinaryTree[parent], theCompleteBinaryTree[newIndex]);
			newIndex = parent;	
			swapbyMinLevel(newIndex);
		}
		else
		{
			swapbyMaxLevel(newIndex);
		}
	}
	else if(isMaxLevel(parent))
	{
		if(theCompleteBinaryTree[parent] < theCompleteBinaryTree[newIndex])
		{
			std::swap(theCompleteBinaryTree[parent], theCompleteBinaryTree[newIndex]);
			newIndex = parent;
			swapbyMaxLevel(newIndex);
		}
		else
		{
			swapbyMinLevel(newIndex);
		}
	}
}
template <typename T>
void MinMax_Heap<T>::swapbyMinLevel(int newIndex)
{
	int grandparent = newIndex/4;
	if(grandparent!=0)
	{
		if(theCompleteBinaryTree[grandparent] > theCompleteBinaryTree[newIndex])
		{
			std::swap(theCompleteBinaryTree[grandparent], theCompleteBinaryTree[newIndex]);
			newIndex = grandparent;
			swapbyMinLevel(newIndex);
		}
	}
}
template <typename T>
void MinMax_Heap<T>::swapbyMaxLevel(int newIndex)
{
	int grandparent = newIndex/4;
	if(grandparent!=0)
	{
		if(theCompleteBinaryTree[grandparent] < theCompleteBinaryTree[newIndex])
		{
			std::swap(theCompleteBinaryTree[grandparent], theCompleteBinaryTree[newIndex]);
			newIndex = grandparent;
			swapbyMaxLevel(newIndex);
		}
	}
}
template <typename T>
void MinMax_Heap<T>::buildheap()//recusive
{
	int LastChild = numItemsInHeap;
  	int LastParent = LastChild/2;
	if(LastChild>1)
	{
		for(int i=LastParent; i >= 1; i--)
		{
			buildHelper(i);
		}
	}
}
template <typename T>
bool MinMax_Heap<T>::isMaxLevel(int index)
{
	if(index==0)
	{
		return false;
	}
	else
	{
		return(!isMinLevel(index));
	}
}
template <typename T>
bool MinMax_Heap<T>::isMinLevel(int index)
{
	if(index==0)
	{
		return false;
	}
	else
	{
		int flr = log2(index);
		if(flr%2==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
template <typename T>
void MinMax_Heap<T>::buildHelper(int parent)//switch the parent with all its child and swap until reach the bottom
{
	int target = targetgrandChildIndex(parent);
	if(target!=-1)
	{
		if(isMaxLevel(parent))
		{
			if(theCompleteBinaryTree[parent] < theCompleteBinaryTree[target])
			{
				std::swap(theCompleteBinaryTree[parent], theCompleteBinaryTree[target]);
				if(theCompleteBinaryTree[target] < theCompleteBinaryTree[target/2])
				{
					std::swap(theCompleteBinaryTree[target], theCompleteBinaryTree[target/2]);
				}
				buildHelper(target);
				if(targetChildIndex(target)!=-1)
				{
					if(theCompleteBinaryTree[target] < theCompleteBinaryTree[targetChildIndex(target)])
					{
						std::swap(theCompleteBinaryTree[target], theCompleteBinaryTree[targetChildIndex(target)]);
					}
				}
			}
		}
		else if(isMinLevel(parent))
		{
			if(theCompleteBinaryTree[parent] > theCompleteBinaryTree[target])
			{
				std::swap(theCompleteBinaryTree[parent], theCompleteBinaryTree[target]);
				if(theCompleteBinaryTree[target] > theCompleteBinaryTree[target/2])
				{
					std::swap(theCompleteBinaryTree[target], theCompleteBinaryTree[target/2]);
				}
				buildHelper(target);
				if(targetChildIndex(target)!=-1)
				{
					if(theCompleteBinaryTree[target] > theCompleteBinaryTree[targetChildIndex(target)])
					{
						std::swap(theCompleteBinaryTree[target], theCompleteBinaryTree[targetChildIndex(target)]);
					}
				}
			}
		}
	}
	else
	{
		target = targetChildIndex(parent);
		if(target!=-1)
		{
			if(isMaxLevel(parent))
			{
				if(theCompleteBinaryTree[parent] < theCompleteBinaryTree[target])
				{
					std::swap(theCompleteBinaryTree[parent], theCompleteBinaryTree[target]);
				}
			}
			else if(isMinLevel(parent))
			{
				if(theCompleteBinaryTree[parent] > theCompleteBinaryTree[target])
				{
					std::swap(theCompleteBinaryTree[parent], theCompleteBinaryTree[target]);
				}
			}
		}
	}
}
template <typename T>
int MinMax_Heap<T>::targetgrandChildIndex(int parent)
{
	int targetGrandchild = 4*parent;
	if(targetGrandchild>numItemsInHeap)
	{
		return -1;
	}
	else
	{	
		int nextChild = targetGrandchild+1;
		for(int i=1;i<4 && nextChild<=numItemsInHeap;i++)
		{
			if(isMinLevel(parent))
			{
				if(theCompleteBinaryTree[targetGrandchild]>theCompleteBinaryTree[nextChild])
				{
					targetGrandchild=nextChild;
				}
			}
			else
			{
				if(theCompleteBinaryTree[targetGrandchild]<theCompleteBinaryTree[nextChild])
				{
					targetGrandchild=nextChild;
				}
			}
			nextChild++;
		}
		return targetGrandchild;
	}
}
template <typename T>
int MinMax_Heap<T>::targetChildIndex(int parent)
{
	if(isMinLevel(parent))
	{
		return Minchild(parent);
	}
	else
	{
		return Maxchild(parent);
	}
}
template <typename T>
int MinMax_Heap<T>::Maxchild(int parent)
{
	int biggerChild = 2 * parent;
	int nextChild = biggerChild + 1;
	if(biggerChild > numItemsInHeap)
	{
		return -1;
	}
	else if(nextChild>numItemsInHeap)
	{
		return biggerChild;
	}
	else if(theCompleteBinaryTree[biggerChild] < theCompleteBinaryTree[nextChild])
	{
		biggerChild = nextChild;
		return biggerChild;
	}
	else
	{
		return biggerChild;
	}
}
template <typename T>
int MinMax_Heap<T>::Minchild(int parent)
{
	int smallerChild = 2 * parent;
	int nextChild = smallerChild + 1;
	if(smallerChild > numItemsInHeap)
	{
		return -1;
	}
	else if(nextChild > numItemsInHeap)
	{
		return smallerChild;
	}
	else if(theCompleteBinaryTree[smallerChild] > theCompleteBinaryTree[nextChild])
	{
		smallerChild = nextChild;
		return smallerChild;
	}
	else
	{
		return smallerChild;
	}
}
template <typename T>
bool MinMax_Heap<T>::isEmpty()//check if it is a empty tree
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
bool MinMax_Heap<T>::deletemin()//remove method
{
	if(isEmpty()==true)
	{
		return false;
	}
	else
	{
		theCompleteBinaryTree[1] = theCompleteBinaryTree[numItemsInHeap];//switch the last Item to the top
		theCompleteBinaryTree[numItemsInHeap] = -1;
		numItemsInHeap--;
		if(numItemsInHeap>1)
		{
			buildHelper(1);
		}
		return true;
	}
}
template <typename T>
bool MinMax_Heap<T>::deletemax()//remove method
{
	if(isEmpty()==true)
	{
		return false;
	}
	else if(numItemsInHeap==1)
	{
		theCompleteBinaryTree[1] = -1;
		numItemsInHeap--;
		return true;
	}
	else
	{
		int MaxIndex = Maxchild(1);
		theCompleteBinaryTree[MaxIndex] = theCompleteBinaryTree[numItemsInHeap];//switch the last Item to the top
		theCompleteBinaryTree[numItemsInHeap] = -1;
		numItemsInHeap--;
		buildHelper(MaxIndex);
		return true;
	}
}
template <typename T>
T MinMax_Heap<T>::findmin()//peek method
{
	if(isEmpty()==true)
	{
		return -1;
	}
	else
	{
		return theCompleteBinaryTree[1];//return the top Item
	}
}
template <typename T>
T MinMax_Heap<T>::findmax()//peek method
{
	if(isEmpty()==true)
	{
		return -1;
	}
	else if(numItemsInHeap==1)
	{
		return theCompleteBinaryTree[1];//return the top Item
	}
	else
	{
		int maxchild = Maxchild(1);
		return theCompleteBinaryTree[maxchild];
	}
}
template <typename T>
void MinMax_Heap<T>::levelorder(int k_heap)
{
	if(!isEmpty())
	{
		int last_i = 1;
		int bounded = k_heap;
		for(int i=1; i<=numItemsInHeap;i++)
		{
			std::cout<<theCompleteBinaryTree[i]<<" ";
			if(i==1)
			{
				std::cout<<""<<std::endl;
			}
			else if((i-last_i) % bounded == 0)
			{
				std::cout<<""<<std::endl;
				last_i = i;
				bounded = bounded*k_heap;
			}
			else if(last_i!=1 && (i-last_i) % k_heap == 0 && i!=numItemsInHeap)
			{
				std::cout<<"- ";
			}
		}
		std::cout<<""<<std::endl;
	}
}
