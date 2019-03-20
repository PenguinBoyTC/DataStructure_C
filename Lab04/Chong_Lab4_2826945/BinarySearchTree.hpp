/** @file BinarySearchTree.hpp */

//Start Private Functions//
template<typename T>
void BinarySearchTree<T>::destroyTree(BinaryNode<T>* subTreePtr)
{
    if (subTreePtr != nullptr)
       {
          destroyTree(subTreePtr->getLeftChildPtr());//destroy the left subtree
          destroyTree(subTreePtr->getRightChildPtr());//destroy the right subtree
          delete subTreePtr;
       }
}
template<typename T>
BinaryNode<T>* BinarySearchTree<T>::insertInorder(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr)
{
    if(subTreePtr == nullptr)
    {
        return newNodePtr;
    }
    else 
    {
        BinaryNode<T>* leftPtr = subTreePtr->getLeftChildPtr();
        BinaryNode<T>* rightPtr = subTreePtr->getRightChildPtr();
        if((subTreePtr->getItem())>(newNodePtr->getItem()))
        {
            leftPtr=insertInorder(leftPtr,newNodePtr);
            subTreePtr->setLeftChildPtr(leftPtr);
        }
        else
        {
            rightPtr=insertInorder(rightPtr,newNodePtr);
            subTreePtr->setRightChildPtr(rightPtr);
        }
        return subTreePtr;
    }
}
template<typename T>
bool BinarySearchTree<T>::RemoveNode(BinaryNode<T>* subTreePtr, T value)
{
    BinaryNode<T>* Left = subTreePtr->getLeftChildPtr();
    BinaryNode<T>* Right = subTreePtr->getRightChildPtr();
    if(subTreePtr->getItem()>value && Left!=nullptr)
    {
        if(Left->getItem()==value)
        {
            if(Left->isLeaf())
            {
                subTreePtr->setLeftChildPtr(nullptr);
                delete Left;
                Left = nullptr;
            }
            else if(Left->getLeftChildPtr()==nullptr)
            {
                subTreePtr->setLeftChildPtr(Left->getRightChildPtr());
                delete Left;
                Left = nullptr;
            }
            else if(Left->getRightChildPtr()==nullptr)
            {
                subTreePtr->setLeftChildPtr(Left->getLeftChildPtr());
                delete Left;
                Left = nullptr;
            }
            else
            {
                T Rsmallest = LookforMin(Left->getRightChildPtr())->getItem();
                Left->setItem(Rsmallest);
                //std::cout<<"Lreplace:"<<Rsmallest<<std::endl;
                if(Rsmallest==Left->getRightChildPtr()->getItem())
                {
                    BinaryNode<T>* LR = Left->getRightChildPtr();
                    Left->setRightChildPtr(LR->getRightChildPtr());
                    delete LR;
                    LR = nullptr;
                }
                else
                {
                    RemoveMin(Left->getRightChildPtr());
                    isDelete = false;
                } 
            }
            return true;
        }
        else
        {
            return RemoveNode(Left, value);
        }
    }
    else if(subTreePtr->getItem()<value && Right!=nullptr)
    {
        if(Right->getItem()==value)
        {
            if(Right->isLeaf())
            {
                subTreePtr->setRightChildPtr(nullptr);
                delete Right;
                Right = nullptr;
            }
            else if(Right->getLeftChildPtr()==nullptr)
            {
                subTreePtr->setRightChildPtr(Right->getRightChildPtr());
                delete Right;
                Right = nullptr;
            }
            else if(Right->getRightChildPtr()==nullptr)
            {
                subTreePtr->setRightChildPtr(Right->getLeftChildPtr());
                delete Right;
                Right = nullptr;
            }
            else
            {
                T Rsmallest = LookforMin(Right->getRightChildPtr())->getItem();
                //std::cout<<"Rreplace:"<<Rsmallest<<std::endl;
                Right->setItem(Rsmallest);
                if(Rsmallest==Right->getRightChildPtr()->getItem())
                {
                    BinaryNode<T>* RR = Right->getRightChildPtr();
                    Right->setRightChildPtr(RR->getRightChildPtr());
                    delete RR;
                    RR = nullptr;
                }
                else
                {
                    RemoveMin(Right->getRightChildPtr());
                    isDelete = false;
                } 
            }
            return true;
        }
        else
        {
            return RemoveNode(Right, value);
        }
    }
    else 
    {
        return false;
    }
}
template <typename T>
void BinarySearchTree<T>::RemoveMin(BinaryNode<T>* subTreePtr)
{
    if(subTreePtr!=nullptr)
    {
        BinaryNode<T>* Left = subTreePtr->getLeftChildPtr();
        if(Left!=nullptr)
        {
            RemoveMin(Left);
            if(!isDelete)
            {
                if(Left->getLeftChildPtr()==nullptr && Left->getRightChildPtr()!=nullptr)
                {
                    subTreePtr->setLeftChildPtr(Left->getRightChildPtr());
                    delete Left;
                    Left = nullptr;
                    isDelete = true;
                }
                else if(Left->isLeaf())
                {
                    subTreePtr->setLeftChildPtr(nullptr);
                    delete Left;
                    Left = nullptr;
                    isDelete = true;
                }
            }
        }
    }
    else if(subTreePtr->isLeaf())
    {
        delete subTreePtr;
        subTreePtr = nullptr;
    }
}
template <typename T>
void BinarySearchTree<T>::RemoveMax(BinaryNode<T>* subTreePtr)
{
    if(subTreePtr!=nullptr)
    {
        BinaryNode<T>* Right = subTreePtr->getRightChildPtr();
        if(Right!=nullptr)
        {
            RemoveMax(Right);
            if(!isDelete)
            {
                if(Right->getRightChildPtr()==nullptr && Right->getLeftChildPtr()!=nullptr)
                {
                    subTreePtr->setRightChildPtr(Right->getLeftChildPtr());
                    delete Right;
                    Right = nullptr;
                    isDelete = true;
                }
                else if(Right->isLeaf())
                {
                    subTreePtr->setRightChildPtr(nullptr);
                    delete Right;
                    Right = nullptr;
                    isDelete = true;
                }
            }
        }
    }
}
template <typename T>
BinaryNode<T>* BinarySearchTree<T>::LookforMin(BinaryNode<T>* subTreePtr)
{
    if(subTreePtr->isLeaf()||subTreePtr->getLeftChildPtr()==nullptr)
    {
        return subTreePtr;
    }
    else
    {
        BinaryNode<T>* Left = subTreePtr->getLeftChildPtr();
        if(Left!=nullptr)
        {
            return LookforMin(Left);
        }
        else
        {
            return subTreePtr;
        }
    }
}
template <typename T>
BinaryNode<T>* BinarySearchTree<T>::LookforMax(BinaryNode<T>* subTreePtr)
{
    if(subTreePtr->isLeaf())
    {
        return subTreePtr;
    }
    else
    {
        BinaryNode<T>* Right = subTreePtr->getRightChildPtr();
        if(Right!=nullptr)
        {
            return LookforMax(Right);
        }
        else
        {
            return subTreePtr;
        }
    }
}
//End Private Functions//

//Start Public Functions//
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    rootPtr = nullptr;
    isDelete = false;
}
template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    this->destroyTree(rootPtr); // Call inherited method
}
template <typename T>
bool BinarySearchTree<T>::isEmpty()
{
    if(rootPtr==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename T>
void BinarySearchTree<T>::Insert(T value)
{
    BinaryNode<T>* newNodePtr = new BinaryNode<T>(value);
    rootPtr = insertInorder(rootPtr, newNodePtr);
}
template <typename T>
bool BinarySearchTree<T>::Delete(T value)
{
    if(rootPtr==nullptr)
    {
        return false;
    }
    else if(rootPtr->getItem() == value)
    {
        if(rootPtr->isLeaf())
        {
            delete rootPtr;
            rootPtr = nullptr;
            return true;
        }
        else if(rootPtr->getLeftChildPtr()==nullptr)
        {
            BinaryNode<T>* temp = rootPtr;
            rootPtr = rootPtr->getRightChildPtr();
            delete temp;
            temp = nullptr;
            return true;
        }
        else if(rootPtr->getRightChildPtr()==nullptr)
        {
            BinaryNode<T>* temp = rootPtr;
            rootPtr = rootPtr->getLeftChildPtr();
            delete temp;
            temp = nullptr;
            return true;
        }
        else
        {
            T Rsmallest = LookforMin(rootPtr->getRightChildPtr())->getItem();
            rootPtr->setItem(Rsmallest);
            RemoveMin(rootPtr->getRightChildPtr());
            isDelete = false;
            return true;
        }
    }
    else
    {
        return RemoveNode(rootPtr, value); 
    }
}
template <typename T>
bool BinarySearchTree<T>::DeleteMin()
{
    if(rootPtr==nullptr)
    {
        return false;
    }
    else if(rootPtr->getLeftChildPtr()==nullptr)
    {
        BinaryNode<T>* temp = rootPtr;
        rootPtr = rootPtr->getRightChildPtr();
        delete temp;
        temp = nullptr;
        return true;
    }
    else
    {
        RemoveMin(rootPtr);
        isDelete = false;
        return true;
    }
}

template <typename T>
bool BinarySearchTree<T>::DeleteMax()
{
    if(rootPtr==nullptr)
    {
        return false;
    }
    else if(rootPtr->getRightChildPtr()==nullptr)
    {
        BinaryNode<T>* temp = rootPtr;
        rootPtr = rootPtr->getLeftChildPtr();
        delete temp;
        temp = nullptr;
        return true;
    }
    else
    {
        RemoveMax(rootPtr);
        isDelete = false;
        return true;
    }
}

template <typename T>
BinaryNode<T>* BinarySearchTree<T>::FindMin()
{
    if(rootPtr==nullptr)
    {
        return nullptr;
    }
    else if(rootPtr->getLeftChildPtr()==nullptr)
    {
        return rootPtr;
    }
    else
    {
        return LookforMin(rootPtr);
    }
}

template <typename T>
BinaryNode<T>* BinarySearchTree<T>::FindMax()
{
    if(rootPtr==nullptr)
    {
        return nullptr;
    }
    else if(rootPtr->getRightChildPtr()==nullptr)
    {
        return rootPtr;
    }
    else
    {
        return LookforMax(rootPtr);
    }
}

template <typename T>
void BinarySearchTree<T>::Preorder()
{
    preorderTraverse(rootPtr);
    std::cout<<""<<std::endl;
}
template <typename T>
void BinarySearchTree<T>::preorderTraverse(BinaryNode<T>* treePtr)
{
    if (treePtr != nullptr)
    {
        std::cout<<treePtr->getItem()<<" ";
        preorderTraverse(treePtr->getLeftChildPtr());
        preorderTraverse(treePtr->getRightChildPtr());
    }  // end if
}

template<typename T>
void BinarySearchTree<T>::Inorder()
{
    inorderTraverse(rootPtr);
    std::cout<<""<<std::endl;
}
template <typename T>
void BinarySearchTree<T>::inorderTraverse(BinaryNode<T>* treePtr)
{
    if (treePtr != nullptr)
    {
        inorderTraverse(treePtr->getLeftChildPtr());
        std::cout<<treePtr->getItem()<<" ";
        inorderTraverse(treePtr->getRightChildPtr());
    }  // end if
}

template <typename T>
void BinarySearchTree<T>::Postorder()
{
    postorderTraverse(rootPtr);
    std::cout<<""<<std::endl;
}
template <typename T>
void BinarySearchTree<T>::postorderTraverse(BinaryNode<T>* treePtr)
{
    if (treePtr->getLeftChildPtr()!= nullptr)
    {
        postorderTraverse(treePtr->getLeftChildPtr());
        
    }  // end if
    if(treePtr->getRightChildPtr()!= nullptr)
    {
        postorderTraverse(treePtr->getRightChildPtr());
    }
    std::cout<<treePtr->getItem()<<" ";
}
