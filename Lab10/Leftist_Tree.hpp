/** @file Leftist_Tree.hpp */

//Start Private Functions//

//End Private Functions//

//Start Public Functions//
template <typename T>
Leftist_Tree<T>::Leftist_Tree()
{
    rootPtr = nullptr;
}
template <typename T>
Leftist_Tree<T>::~Leftist_Tree()
{
    while(rootPtr!=nullptr)
    {
        DeleteMin();
    }
}
template <typename T>
void Leftist_Tree<T>::buildheap(std::string filename)
{    
    std::ifstream inp;
    inp.open(filename);//open the data.txt file
    int number;
    while(!inp.eof())
    {
        inp>>number;
        Insert(number);
    }
    inp.close();//close the data.txt file
}
template <typename T>
void Leftist_Tree<T>::Insert(T value)
{    
    Leftist_Node<T>* newNode = new Leftist_Node<T>(value);
    if(rootPtr == nullptr)
    {
        rootPtr = newNode;
    }
    else
    {
        rootPtr = Concate(rootPtr, newNode);
    }
}

template <typename T>
bool Leftist_Tree<T>::DeleteMin()
{
    if(rootPtr==nullptr)
    {
        return false;
    }
    else
    {
        Leftist_Node<T>* temp = rootPtr;
        rootPtr = Concate(rootPtr->getLeftChildPtr(),rootPtr->getRightChildPtr());
        delete temp;
        temp = nullptr;
        return true;
    }
}


template <typename T>
T Leftist_Tree<T>::FindMin()
{
    if(rootPtr==nullptr)
    {
        return -1;
    }
    else
    {
        return rootPtr->getKeyValue();
    }
}
template <typename T>
Leftist_Node<T>* Leftist_Tree<T>::Concate(Leftist_Node<T>* H1, Leftist_Node<T>* H2)
{
    if(H1 == nullptr)
    {
        return H2;
    }
    else if(H2 == nullptr)
    {
        return H1;
    }
    else
    {
        if(H1->getKeyValue()>H2->getKeyValue())
        {
            std::swap(H1,H2);///can I???????????
        }
        
        Leftist_Node<T>* rightchild = Concate(H1->getRightChildPtr(), H2);
        H1->setRightChildPtr(rightchild);
        adjustRank(H1);
        Leftist_Node<T>* leftchild = H1->getLeftChildPtr();
        if(GetRank(leftchild)<GetRank(rightchild))
        {
            //std::swap(leftchild, rightchild);//can I ????????????
            H1->setLeftChildPtr(rightchild);
            H1->setRightChildPtr(leftchild);
        }
        return H1;
    }
}
template <typename T>
int Leftist_Tree<T>::GetRank(Leftist_Node<T>* H)
{
    if(H == nullptr)
    {
        return 0;
    }
    else
    {
        return H->getRank();
    }
}
template <typename T>
void Leftist_Tree<T>::adjustRank(Leftist_Node<T>* H1)
{
    if(H1->getLeftChildPtr()==nullptr || H1->getRightChildPtr()==nullptr)
    {
        H1->setRank(1);
    }
    else
    {
        Leftist_Node<T>* lchild = H1->getLeftChildPtr();
        Leftist_Node<T>* rchild = H1->getRightChildPtr();
        int smallerRank = lchild->getRank();
        if(smallerRank > rchild->getRank())
        {
            smallerRank = rchild->getRank();
        }
        smallerRank++;
        H1->setRank(smallerRank);
    }
}
template <typename T>
void Leftist_Tree<T>::Preorder()
{
    if(rootPtr!=nullptr)
    {
        std::cout<<"preorder: ";
        preorderTraverse(rootPtr);
        std::cout<<""<<std::endl;
    }
    else
    {
        std::cout<<"The tree is empty"<<std::endl;
    }
}
template <typename T>
void Leftist_Tree<T>::preorderTraverse(Leftist_Node<T>* treePtr)
{
    if (treePtr != nullptr)
    {
        std::cout<<treePtr->getKeyValue()<<" ";
        preorderTraverse(treePtr->getLeftChildPtr());
        preorderTraverse(treePtr->getRightChildPtr());
    }  // end if
}
template <typename T>
void Leftist_Tree<T>::Inorder()
{
    if(rootPtr!=nullptr)
    {
        std::cout<<"inorder: ";
        inorderTraverse(rootPtr);
        std::cout<<""<<std::endl;
    }
    else
    {
        std::cout<<"The tree is empty"<<std::endl;
    }
}
template <typename T>
void Leftist_Tree<T>::inorderTraverse(Leftist_Node<T>* treePtr)
{
    if (treePtr != nullptr)
    {
        inorderTraverse(treePtr->getLeftChildPtr());
        std::cout<<treePtr->getKeyValue()<<" ";
        inorderTraverse(treePtr->getRightChildPtr());
    }  // end if
}
template <typename T>
void Leftist_Tree<T>::Levelorder() //use queue class insert same level node first, then print the same level node in order.when print a node then insert his children to the back of queue and so on.
{
    if(rootPtr!=nullptr)
    {
        std::cout<<"Level order: "<<std::endl;
        levelorderTraverse(rootPtr);
    }
    else
    {
        std::cout<<"The tree is empty"<<std::endl;
    }
}
template <typename T>
void Leftist_Tree<T>::levelorderTraverse(Leftist_Node<T>* treePtr) 
{
    Queue<Leftist_Node<T>*> q1, q2;
    if(treePtr!=nullptr)
    {
        q1.enqueue(treePtr);
        while(!q1.isEmpty()||!q2.isEmpty())
        {
            while(!q1.isEmpty())
            {
                if(q1.getFront()->getLeftChildPtr() != nullptr)
                {
                    q2.enqueue(q1.getFront()->getLeftChildPtr());
                }
                if(q1.getFront()->getRightChildPtr() != nullptr)
                {
                    q2.enqueue(q1.getFront()->getRightChildPtr());
                }
                std::cout<<q1.peekFront()->getKeyValue()<<" ";
            }
            std::cout<<""<<std::endl;
            while(!q2.isEmpty())
            {
                if(q2.getFront()->getLeftChildPtr() != nullptr)
                {
                    q1.enqueue(q2.getFront()->getLeftChildPtr());
                }
                if(q2.getFront()->getRightChildPtr() != nullptr)
                {
                    q1.enqueue(q2.getFront()->getRightChildPtr());
                }
                std::cout<<q2.peekFront()->getKeyValue()<<" ";
            }
            std::cout<<""<<std::endl;
        }
    }
}