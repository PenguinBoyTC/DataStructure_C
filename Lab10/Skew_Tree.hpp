/** @file Skew_Tree.hpp */

//Start Private Functions//

//End Private Functions//

//Start Public Functions//
template <typename T>
Skew_Tree<T>::Skew_Tree()
{
    rootPtr = nullptr;
}
template <typename T>
Skew_Tree<T>::~Skew_Tree()
{
    while(rootPtr!=nullptr)
    {
        DeleteMin();
    }
}
template <typename T>
void Skew_Tree<T>::buildheap(std::string filename)
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
void Skew_Tree<T>::Insert(T value)
{    
    Skew_Node<T>* newNode = new Skew_Node<T>(value);
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
bool Skew_Tree<T>::DeleteMin()
{
    if(rootPtr==nullptr)
    {
        return false;
    }
    else
    {
        Skew_Node<T>* temp = rootPtr;
        rootPtr = Concate(rootPtr->getLeftChildPtr(),rootPtr->getRightChildPtr());
        delete temp;
        temp = nullptr;
        return true;
    }
}


template <typename T>
T Skew_Tree<T>::FindMin()
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
Skew_Node<T>* Skew_Tree<T>::Concate(Skew_Node<T>* H1, Skew_Node<T>* H2)
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
            std::swap(H1,H2);
        }
        Skew_Node<T>* rightchild = H1->getRightChildPtr();
        Skew_Node<T>* leftchild = H1->getLeftChildPtr();
        H1->setRightChildPtr(leftchild);
        H1->setLeftChildPtr(Concate(rightchild, H2));
        return H1;
    }
}
template <typename T>
void Skew_Tree<T>::Preorder()
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
void Skew_Tree<T>::preorderTraverse(Skew_Node<T>* treePtr)
{
    if (treePtr != nullptr)
    {
        std::cout<<treePtr->getKeyValue()<<" ";
        preorderTraverse(treePtr->getLeftChildPtr());
        preorderTraverse(treePtr->getRightChildPtr());
    }  // end if
}
template <typename T>
void Skew_Tree<T>::Inorder()
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
void Skew_Tree<T>::inorderTraverse(Skew_Node<T>* treePtr)
{
    if (treePtr != nullptr)
    {
        inorderTraverse(treePtr->getLeftChildPtr());
        std::cout<<treePtr->getKeyValue()<<" ";
        inorderTraverse(treePtr->getRightChildPtr());
    }  // end if
}
template <typename T>
void Skew_Tree<T>::Levelorder() 
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
void Skew_Tree<T>::levelorderTraverse(Skew_Node<T>* treePtr) 
{
    Queue<Skew_Node<T>*> q1, q2;
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