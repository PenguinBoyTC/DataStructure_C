#ifndef _LEFTIST_OR_SKEW_INTERFACE
#define _LEFTIST_OR_SKEW_INTERFACE
#include <string> 
template<typename T>
class LeftistOrSkewInterface
{
public:
	// LeftistOrSkewInterface(){};//constructor
	virtual ~LeftistOrSkewInterface(){};
	virtual void buildheap(std::string filename)=0;
	virtual void Insert(T value)=0;//add a Item to the tree
	virtual bool DeleteMin()=0;
	//virtual bool deletemax()=0;
	virtual T FindMin()=0;//return the top Item from the tree
	//virtual T findmax()=0;//return the top Item from the tree
	//virtual void Concate()=0;
	
	virtual void Preorder()=0;
    virtual void Inorder()=0;
    virtual void Levelorder()=0;//print the tree by level order
};
#endif