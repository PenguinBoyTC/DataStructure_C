/** @file twothree_tree.hpp */

//Start Private Functions//
template <typename T>
bool twothree_tree<T>::search(T value, twothree_Node<T>* tree)
{
    if(tree->isLeafNode())
    {
        return(value == tree->getKeyValue());
    }
    else
    {
        if(value == tree->getminSecond() || value == tree->getminThird())
        {
            return true;
        }
        else if(value < tree->getminSecond())
        {
            return search(value, tree->getFirstChildPtr());
        }
        else if(tree->getminThird()!=-1 && value > tree->getminThird())
        {
            return search(value, tree->getThirdChildPtr());
        }
        else
        {
            return search(value, tree->getSecondChildPtr());
        }
    }
}
template <typename T>
void twothree_tree<T>::resetMinValue(twothree_Node<T>* intNode)
{
    twothree_Node<T>* Schild = intNode->getSecondChildPtr();
    twothree_Node<T>* Tchild = intNode->getThirdChildPtr();
    if(Schild->isLeafNode())
    {
        intNode->setminSecond(Schild->getKeyValue());
        if(Tchild!=nullptr)
        {
            intNode->setminThird(Tchild->getKeyValue());
        }
    }
    else
    {
        twothree_Node<T>* Min = FindMinHelper(Schild);
        intNode->setminSecond(Min->getKeyValue());
        if(Tchild!=nullptr)
        {
            Min = FindMinHelper(Tchild);
            intNode->setminThird(Min->getKeyValue());
        }
    }
}
template <typename T>
void twothree_tree<T>::resetAllminValue(twothree_Node<T>* subTreePtr)
{
    if(subTreePtr->isInteriorNode())
    {
        twothree_Node<T>* FirstChild = subTreePtr->getFirstChildPtr();
        twothree_Node<T>* SecondChild = subTreePtr->getSecondChildPtr();
        twothree_Node<T>* ThirdChild = subTreePtr->getThirdChildPtr();
        resetMinValue(subTreePtr);
        if(FirstChild->isInteriorNode())
        {
            resetAllminValue(FirstChild);
            resetAllminValue(SecondChild);
            if(ThirdChild!=nullptr)
            {
                resetAllminValue(ThirdChild);
            }
        }
    }
}
template <typename T>
twothree_Node<T>* twothree_tree<T>::FindMinHelper(twothree_Node<T>* subTreePtr)
{
    if(subTreePtr->isInteriorNode())
    {
        return FindMinHelper(subTreePtr->getFirstChildPtr());
    }
    else
    {
        return subTreePtr;
    }
}
template <typename T>
twothree_Node<T>* twothree_tree<T>::FindMaxHelper(twothree_Node<T>* subTreePtr)
{
    if(subTreePtr->isInteriorNode())
    {
        if(subTreePtr->getThirdChildPtr()!=nullptr)
        {
            return FindMaxHelper(subTreePtr->getThirdChildPtr());
        }
        else
        {
            return FindMaxHelper(subTreePtr->getSecondChildPtr());
        }
    }
    else
    {
        return subTreePtr;
    }
}
template <typename T>
void twothree_tree<T>::levelorderTraverse(twothree_Node<T>* treePtr)
{
    if (treePtr != nullptr)
    {
        if(treePtr->isInteriorNode())
        {
            levelorderTraverse(treePtr->getFirstChildPtr());
            levelorderTraverse(treePtr->getSecondChildPtr());
            levelorderTraverse(treePtr->getThirdChildPtr());
        }
        else if(treePtr->isLeafNode())
        {
            std::cout<<treePtr->getKeyValue()<<" ";
        }
    }  // end if
}
//End Private Functions//

//Start Public Functions//
template <typename T>
twothree_tree<T>::twothree_tree()
{
    rootPtr = nullptr;
}
template <typename T>
twothree_tree<T>::~twothree_tree()
{
    if(rootPtr!=nullptr)
    {
        DeleteMax();
    }
}

template <typename T>
bool twothree_tree<T>::Insert(T value)
{    
    twothree_Node<T>* newNode = new twothree_Node<T>(value);
    return insertHelper(rootPtr, newNode);
}
template <typename T>
bool twothree_tree<T>::insertHelper(twothree_Node<T>* subTreePtr, twothree_Node<T>* newNodePtr)
{
    if(rootPtr == nullptr)//empty tree
    {
        rootPtr = newNodePtr;
        return true;
    }
    else if(rootPtr->isLeafNode())//one node tree
    {
        twothree_Node<T>* intNode = new twothree_Node<T>();
        if(rootPtr->getKeyValue() <  newNodePtr->getKeyValue())
        {
            int minSecond = newNodePtr->getKeyValue();
            intNode->setFirstChildPtr(rootPtr);
            intNode->setSecondChildPtr(newNodePtr);
            rootPtr = intNode;
            return true;
        }
        else if(rootPtr->getKeyValue() >  newNodePtr->getKeyValue())
        {
            int minSecond = rootPtr->getKeyValue();
            intNode->setFirstChildPtr(newNodePtr);
            intNode->setSecondChildPtr(rootPtr);
            rootPtr = intNode;
            return true;
        }
        else 
        {
            return false;
        }
    }
    else if(subTreePtr->isInteriorNode())
    {
        if(subTreePtr->getminSecond() == newNodePtr->getKeyValue() || subTreePtr->getminThird() == newNodePtr->getKeyValue())
        {
            return false;
        }
        twothree_Node<T>* Fchild = subTreePtr->getFirstChildPtr();
        twothree_Node<T>* Schild = subTreePtr->getSecondChildPtr();
        if(subTreePtr->getminThird() == -1 && Fchild->isInteriorNode())//at least 3 level tree has two children
        {
            if(newNodePtr->getKeyValue() < subTreePtr->getminSecond())
            {
                return insertHelper(Fchild, newNodePtr);
            }
            else
            {
                return insertHelper(Schild, newNodePtr);
            }
        }
        else if(subTreePtr->getminThird() != -1 && Fchild->isInteriorNode())//at least 3 level tree has three children
        {//test
            twothree_Node<T>* Tchild = subTreePtr->getThirdChildPtr();
            if(newNodePtr->getKeyValue() < subTreePtr->getminSecond())
            {
                return insertHelper(Fchild, newNodePtr);
            }
            else if(subTreePtr->getminSecond() < newNodePtr->getKeyValue() && newNodePtr->getKeyValue() < subTreePtr->getminThird())
            {
                return insertHelper(Schild, newNodePtr);
            }
            else
            {
                return insertHelper(Tchild, newNodePtr);
            }
            //test
        }
        else if(subTreePtr->getminThird() != -1 && Fchild->isLeafNode())//the last interior node has 3 children
        {
            twothree_Node<T>* Tchild = subTreePtr->getThirdChildPtr();
            twothree_Node<T>* sibling = new twothree_Node<T>();
            if(newNodePtr->getKeyValue() > subTreePtr->getminThird())// target at third child
            {//**set new right interior child
                sibling->setminSecond(newNodePtr->getKeyValue());
                sibling->setFirstChildPtr(Tchild);
                sibling->setSecondChildPtr(newNodePtr);
                //**
                subTreePtr->setThirdChildPtr(nullptr);
                if(subTreePtr == rootPtr)// The tree is 2 level tree
                {//**set a new root
                    twothree_Node<T>* NewRoot = new twothree_Node<T>();
                    NewRoot->setminSecond(subTreePtr->getminThird());
                    NewRoot->setFirstChildPtr(subTreePtr);
                    NewRoot->setSecondChildPtr(sibling);
                    subTreePtr->setThirdChildPtr(nullptr);
                    rootPtr = NewRoot;
                    resetMinValue(rootPtr);
                    // std::cout<<"Change root1"<<std::endl;
                    // std::cout<<"root minSecond: "<<rootPtr->getminSecond()<<std::endl;
                    // std::cout<<"root minThird: "<<rootPtr->getminThird()<<std::endl;
                }
                else//the tree at least has 3 level
                {
                    twothree_Node<T>* parent = subTreePtr->getParentPtr();
                    twothree_Node<T>* lastFchild = parent->getFirstChildPtr();
                    twothree_Node<T>* lastSchild = parent->getSecondChildPtr();
                    if(parent->getThirdChildPtr()==nullptr)//parent has 2 children sub-node has 3 children
                    {
                        if(sibling->getminSecond() > lastSchild->getminSecond())
                        {
                            parent->setThirdChildPtr(sibling);
                            
                        }
                        else if(sibling->getminSecond() > lastFchild->getminSecond())
                        {
                            parent->setThirdChildPtr(lastSchild);
                            parent->setSecondChildPtr(sibling);
                        }
                        resetMinValue(parent);
                        //std::cout<<"single Fen lie zhi hou P de minSecond:"<<parent->getminSecond()<<std::endl;
                        //std::cout<<"single Fen lie zhi hou P de minThird:"<<parent->getminThird()<<std::endl;
                    }
                    else//parent has 3 children sub-node has 3 children
                    {
                        twothree_Node<T>* lastTchild = parent->getThirdChildPtr();
                        if(parent->getThirdChildPtr()!=nullptr)//change to while if necessary
                        {
                            twothree_Node<T>* NewLeftsubParent = new twothree_Node<T>();
                            twothree_Node<T>* NewRightsubParent = new twothree_Node<T>();
                            if(sibling->getminSecond() > lastTchild->getminSecond())
                            {
                                NewLeftsubParent->setFirstChildPtr(lastFchild);
                                NewLeftsubParent->setSecondChildPtr(lastSchild);
                                resetMinValue(NewLeftsubParent);
                                //std::cout<<"Double Fen lie zhi hou zuo P de minSecond:"<<NewLeftsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou zuo P de minThird:"<<NewLeftsubParent->getminThird()<<std::endl;
                                NewRightsubParent->setFirstChildPtr(lastTchild);
                                NewRightsubParent->setSecondChildPtr(sibling);
                                resetMinValue(NewRightsubParent);
                                //std::cout<<"Double Fen lie zhi hou you P de minSecond:"<<NewRightsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou you P de minThird:"<<NewRightsubParent->getminThird()<<std::endl;
                            }
                            else if(sibling->getminSecond() > lastSchild->getminSecond())
                            {
                                NewLeftsubParent->setFirstChildPtr(lastFchild);
                                NewLeftsubParent->setSecondChildPtr(lastSchild);
                                resetMinValue(NewLeftsubParent);
                                //std::cout<<"Double Fen lie zhi hou zuo P de minSecond:"<<NewLeftsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou zuo P de minThird:"<<NewLeftsubParent->getminThird()<<std::endl;
                                NewRightsubParent->setFirstChildPtr(sibling);
                                NewRightsubParent->setSecondChildPtr(lastTchild);
                                resetMinValue(NewRightsubParent);
                                //std::cout<<"Double Fen lie zhi hou you P de minSecond:"<<NewRightsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou you P de minThird:"<<NewRightsubParent->getminThird()<<std::endl;
                            }
                            else
                            {
                                NewLeftsubParent->setFirstChildPtr(lastFchild);
                                NewLeftsubParent->setSecondChildPtr(sibling);
                                resetMinValue(NewLeftsubParent);
                                //std::cout<<"Double Fen lie zhi hou zuo P de minSecond:"<<NewLeftsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou zuo P de minThird:"<<NewLeftsubParent->getminThird()<<std::endl;
                                NewRightsubParent->setFirstChildPtr(lastSchild);
                                NewRightsubParent->setSecondChildPtr(lastTchild);
                                resetMinValue(NewRightsubParent);
                                //std::cout<<"Double Fen lie zhi hou you P de minSecond:"<<NewRightsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou you P de minThird:"<<NewRightsubParent->getminThird()<<std::endl;
                            }
                            parent->setFirstChildPtr(NewLeftsubParent);
                            parent->setSecondChildPtr(NewRightsubParent);
                            parent->setThirdChildPtr(nullptr);
                            resetMinValue(parent);
                            //std::cout<<"Double Fen lie zhi hou root P de minSecond:"<<parent->getminSecond()<<std::endl;
                            //std::cout<<"Double Fen lie zhi hou root P de minThird:"<<parent->getminThird()<<std::endl;
                        }
                        //parent = parent->getParentPtr();!!!!!!!
                    }
                }
            }
            else if(subTreePtr->getminSecond() < newNodePtr->getKeyValue() && newNodePtr->getKeyValue() < subTreePtr->getminThird())
            {//**set new right interior child
                sibling->setminSecond(subTreePtr->getminThird());
                sibling->setFirstChildPtr(newNodePtr);
                sibling->setSecondChildPtr(Tchild);
                //**
                subTreePtr->setThirdChildPtr(nullptr);
                if(subTreePtr == rootPtr)
                {//**set a new root
                    twothree_Node<T>* NewRoot = new twothree_Node<T>();
                    NewRoot->setminSecond(newNodePtr->getKeyValue());
                    NewRoot->setFirstChildPtr(subTreePtr);
                    NewRoot->setSecondChildPtr(sibling);
                    rootPtr = NewRoot;
                    resetMinValue(rootPtr);
                }
                else
                {
                    twothree_Node<T>* parent = subTreePtr->getParentPtr();
                    twothree_Node<T>* lastFchild = parent->getFirstChildPtr();
                    twothree_Node<T>* lastSchild = parent->getSecondChildPtr();
                    if(parent->getThirdChildPtr()==nullptr)
                    {
                        if(sibling->getminSecond() > lastSchild->getminSecond())
                        {
                            parent->setThirdChildPtr(sibling);
                        }
                        else if(sibling->getminSecond() > lastFchild->getminSecond())
                        {
                            parent->setThirdChildPtr(lastSchild);
                            parent->setSecondChildPtr(sibling);
                        }
                        resetMinValue(parent);
                        //std::cout<<"single Fen lie zhi hou P de minSecond:"<<parent->getminSecond()<<std::endl;
                        //std::cout<<"single Fen lie zhi hou P de minThird:"<<parent->getminThird()<<std::endl;
                    }
                    else
                    {
                        twothree_Node<T>* lastTchild = parent->getThirdChildPtr();
                        if(parent->getThirdChildPtr()!=nullptr)//change to while if necessary
                        {
                            twothree_Node<T>* NewLeftsubParent = new twothree_Node<T>();
                            twothree_Node<T>* NewRightsubParent = new twothree_Node<T>();
                            if(sibling->getminSecond() > lastTchild->getminSecond())
                            {
                                NewLeftsubParent->setFirstChildPtr(lastFchild);
                                NewLeftsubParent->setSecondChildPtr(lastSchild);
                                resetMinValue(NewLeftsubParent);
                                //std::cout<<"Double Fen lie zhi hou zuo P de minSecond:"<<NewLeftsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou zuo P de minThird:"<<NewLeftsubParent->getminThird()<<std::endl;
                                NewRightsubParent->setFirstChildPtr(lastTchild);
                                NewRightsubParent->setSecondChildPtr(sibling);
                                resetMinValue(NewRightsubParent);
                                //std::cout<<"Double Fen lie zhi hou you P de minSecond:"<<NewRightsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou you P de minThird:"<<NewRightsubParent->getminThird()<<std::endl;
                            }
                            else if(sibling->getminSecond() > lastSchild->getminSecond())
                            {
                                NewLeftsubParent->setFirstChildPtr(lastFchild);
                                NewLeftsubParent->setSecondChildPtr(lastSchild);
                                resetMinValue(NewLeftsubParent);
                                //std::cout<<"Double Fen lie zhi hou zuo P de minSecond:"<<NewLeftsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou zuo P de minThird:"<<NewLeftsubParent->getminThird()<<std::endl;
                                NewRightsubParent->setFirstChildPtr(sibling);
                                NewRightsubParent->setSecondChildPtr(lastTchild);
                                resetMinValue(NewRightsubParent);
                                //std::cout<<"Double Fen lie zhi hou you P de minSecond:"<<NewRightsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou you P de minThird:"<<NewRightsubParent->getminThird()<<std::endl;
                            }
                            else
                            {
                                NewLeftsubParent->setFirstChildPtr(lastFchild);
                                NewLeftsubParent->setSecondChildPtr(sibling);
                                resetMinValue(NewLeftsubParent);
                                //std::cout<<"Double Fen lie zhi hou zuo P de minSecond:"<<NewLeftsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou zuo P de minThird:"<<NewLeftsubParent->getminThird()<<std::endl;
                                NewRightsubParent->setFirstChildPtr(lastSchild);
                                NewRightsubParent->setSecondChildPtr(lastTchild);
                                resetMinValue(NewRightsubParent);
                                //std::cout<<"Double Fen lie zhi hou you P de minSecond:"<<NewRightsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou you P de minThird:"<<NewRightsubParent->getminThird()<<std::endl;
                            }
                            parent->setFirstChildPtr(NewLeftsubParent);
                            parent->setSecondChildPtr(NewRightsubParent);
                            parent->setThirdChildPtr(nullptr);
                            resetMinValue(parent);
                            //std::cout<<"Double Fen lie zhi hou root P de minSecond:"<<parent->getminSecond()<<std::endl;
                            //std::cout<<"Double Fen lie zhi hou root P de minThird:"<<parent->getminThird()<<std::endl;
                        }
                    }
                }
            }
            else
            {//**set new left interior child
                if(newNodePtr->getKeyValue() == Fchild->getKeyValue())
                {
                    return false;
                }
                else if(newNodePtr->getKeyValue() < Fchild->getKeyValue())
                {
                    sibling->setminSecond(Fchild->getKeyValue());
                    sibling->setFirstChildPtr(newNodePtr);
                    sibling->setSecondChildPtr(Fchild);
                    subTreePtr->setFirstChildPtr(Schild);
                    subTreePtr->setSecondChildPtr(Tchild);
                    subTreePtr->setThirdChildPtr(nullptr);

                }
                else
                {
                    sibling->setminSecond(newNodePtr->getKeyValue());
                    sibling->setFirstChildPtr(Fchild);
                    sibling->setSecondChildPtr(newNodePtr);
                    subTreePtr->setFirstChildPtr(Schild);
                    subTreePtr->setSecondChildPtr(Tchild);
                    subTreePtr->setThirdChildPtr(nullptr);
                }
                //**
                if(subTreePtr == rootPtr)
                {//**set a new root
                    twothree_Node<T>* NewRoot = new twothree_Node<T>();
                    NewRoot->setminSecond(subTreePtr->getminSecond());
                    NewRoot->setFirstChildPtr(sibling);
                    NewRoot->setSecondChildPtr(subTreePtr);
                    rootPtr = NewRoot;
                    resetMinValue(rootPtr);
                    //std::cout<<"Change root"<<std::endl;
                }
                else
                {
                    twothree_Node<T>* parent = subTreePtr->getParentPtr();
                    twothree_Node<T>* lastFchild = parent->getFirstChildPtr();
                    twothree_Node<T>* lastSchild = parent->getSecondChildPtr();
                    if(parent->getThirdChildPtr()==nullptr)
                    {   
                        if(sibling->getminSecond() < lastFchild->getminSecond())
                        {
                            parent->setFirstChildPtr(sibling);
                            parent->setSecondChildPtr(lastFchild);
                            parent->setThirdChildPtr(lastSchild);
                        }
                        else if(sibling->getminSecond() < lastSchild->getminSecond())
                        {
                            parent->setSecondChildPtr(sibling);
                            parent->setThirdChildPtr(lastSchild);
                        }
                        resetMinValue(parent);
                        //std::cout<<"single Fen lie zhi hou P de minSecond:"<<parent->getminSecond()<<std::endl;
                        //std::cout<<"single Fen lie zhi hou P de minThird:"<<parent->getminThird()<<std::endl;
                    }
                    else
                    {
                        twothree_Node<T>* lastTchild = parent->getThirdChildPtr();
                        if(parent->getThirdChildPtr()!=nullptr)//change to while if necessary
                        {
                            twothree_Node<T>* NewLeftsubParent = new twothree_Node<T>();
                            twothree_Node<T>* NewRightsubParent = new twothree_Node<T>();
                            if(sibling->getminSecond() < lastFchild->getminSecond())
                            {
                                NewLeftsubParent->setFirstChildPtr(sibling);
                                NewLeftsubParent->setSecondChildPtr(lastFchild);
                                resetMinValue(NewLeftsubParent);
                                //std::cout<<"Double Fen lie zhi hou zuo P de minSecond:"<<NewLeftsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou zuo P de minThird:"<<NewLeftsubParent->getminThird()<<std::endl;
                                NewRightsubParent->setFirstChildPtr(lastSchild);
                                NewRightsubParent->setSecondChildPtr(lastTchild);
                                resetMinValue(NewRightsubParent);
                                //std::cout<<"Double Fen lie zhi hou you P de minSecond:"<<NewRightsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou you P de minThird:"<<NewRightsubParent->getminThird()<<std::endl;
                            }
                            else if(sibling->getminSecond() < lastSchild->getminSecond())
                            {
                                NewLeftsubParent->setFirstChildPtr(lastFchild);
                                NewLeftsubParent->setSecondChildPtr(sibling);
                                resetMinValue(NewLeftsubParent);
                                //std::cout<<"Double Fen lie zhi hou zuo P de minSecond:"<<NewLeftsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou zuo P de minThird:"<<NewLeftsubParent->getminThird()<<std::endl;
                                NewRightsubParent->setFirstChildPtr(lastSchild);
                                NewRightsubParent->setSecondChildPtr(lastTchild);
                                resetMinValue(NewRightsubParent);
                                //std::cout<<"Double Fen lie zhi hou you P de minSecond:"<<NewRightsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou you P de minThird:"<<NewRightsubParent->getminThird()<<std::endl;
                            }
                            else
                            {
                                NewLeftsubParent->setFirstChildPtr(lastFchild);
                                NewLeftsubParent->setSecondChildPtr(lastSchild);
                                resetMinValue(NewLeftsubParent);
                                //std::cout<<"Double Fen lie zhi hou zuo P de minSecond:"<<NewLeftsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou zuo P de minThird:"<<NewLeftsubParent->getminThird()<<std::endl;
                                NewRightsubParent->setFirstChildPtr(sibling);
                                NewRightsubParent->setSecondChildPtr(lastTchild);
                                resetMinValue(NewRightsubParent);
                                //std::cout<<"Double Fen lie zhi hou you P de minSecond:"<<NewRightsubParent->getminSecond()<<std::endl;
                                //std::cout<<"Double Fen lie zhi hou you P de minThird:"<<NewRightsubParent->getminThird()<<std::endl;
                            }
                            parent->setFirstChildPtr(NewLeftsubParent);
                            parent->setSecondChildPtr(NewRightsubParent);
                            parent->setThirdChildPtr(nullptr);
                            resetMinValue(parent);
                            //std::cout<<"Double Fen lie zhi hou root P de minSecond:"<<parent->getminSecond()<<std::endl;
                            //std::cout<<"Double Fen lie zhi hou root P de minThird:"<<parent->getminThird()<<std::endl;
                        }
                    }
                }
            }
            resetAllminValue(rootPtr);
            return true;
        }
        else if(subTreePtr->getminThird() == -1 && Fchild->isLeafNode())
        {
            if(newNodePtr->getKeyValue() < subTreePtr->getminSecond())
            {
                if(Fchild->getKeyValue() == newNodePtr->getKeyValue())
                {
                    return false;
                }
                else
                {
                    if(newNodePtr->getKeyValue() < Fchild->getKeyValue())
                    {
                        subTreePtr->setThirdChildPtr(Schild);
                        subTreePtr->setSecondChildPtr(Fchild);
                        subTreePtr->setFirstChildPtr(newNodePtr);
                        subTreePtr->setminSecond(Schild->getKeyValue());
                    }
                    else if(Fchild->getKeyValue() < newNodePtr->getKeyValue())
                    {
                        subTreePtr->setThirdChildPtr(Schild);
                        subTreePtr->setSecondChildPtr(newNodePtr);
                        subTreePtr->setminSecond(newNodePtr->getKeyValue());
                    }
                    twothree_Node<T>* Tchild = subTreePtr->getThirdChildPtr();
                    return true;
                }
            }
            else if(newNodePtr->getKeyValue() > subTreePtr->getminSecond())
            {
                subTreePtr->setThirdChildPtr(newNodePtr);
                twothree_Node<T>* Tchild = subTreePtr->getThirdChildPtr();
                return true;
            }
        }
    }
}
template <typename T>
bool twothree_tree<T>::Delete(T value)
{
    if(rootPtr == nullptr)
    {
        return false;
    }
    else if(rootPtr->isLeafNode())
    {
        if(rootPtr->getKeyValue()!=value)
        {
            return false;
        }
        else
        {
            delete rootPtr;
            rootPtr = nullptr;
            return true;
        }
    }
    else
    {
        return deleteHelper(value, rootPtr);
    }
}

template <typename T>
bool twothree_tree<T>::deleteHelper(T value, twothree_Node<T>* subTreePtr)
{
    if(subTreePtr->isLeafNode())
    {
        if(value == subTreePtr->getKeyValue())
        {
            twothree_Node<T>* parent = subTreePtr->getParentPtr();
            twothree_Node<T>* FirstChild = parent->getFirstChildPtr();
            twothree_Node<T>* SecondChild = parent->getSecondChildPtr();
            twothree_Node<T>* ThirdChild = parent->getThirdChildPtr();
            if(ThirdChild!=nullptr)//delete a node from a Interior node that has three child
            {
                if(subTreePtr == FirstChild)
                {
                    parent->setFirstChildPtr(SecondChild);
                    parent->setSecondChildPtr(ThirdChild);
                    parent->setThirdChildPtr(nullptr);
                    delete FirstChild;
                    FirstChild = nullptr;
                }
                else if(subTreePtr == SecondChild)
                {
                    parent->setSecondChildPtr(ThirdChild);
                    parent->setThirdChildPtr(nullptr);
                    delete SecondChild;
                    SecondChild = nullptr;
                }
                else
                {
                    parent->setThirdChildPtr(nullptr);
                    delete ThirdChild;
                    ThirdChild = nullptr;
                }
            }
            else//delet a node from a Interior node has two children
            {
                if(parent==rootPtr)//only has one interior level
                {
                    if(subTreePtr == FirstChild)
                    {
                        SecondChild->setParentPtr(nullptr);
                        rootPtr = SecondChild;
                        delete FirstChild;
                        FirstChild = nullptr;
                        delete parent;
                        parent = nullptr;
                    }
                    else
                    {
                        FirstChild->setParentPtr(nullptr);
                        rootPtr = FirstChild;
                        delete SecondChild;
                        SecondChild = nullptr;
                        delete parent;
                        parent = nullptr;
                    }
                }
                else//have at least two interior level
                {  
                    twothree_Node<T>* PParent = parent->getParentPtr();
                    twothree_Node<T>* PFirst = PParent->getFirstChildPtr();
                    twothree_Node<T>* PSecond = PParent->getSecondChildPtr();
                    twothree_Node<T>* PThird = PParent->getThirdChildPtr();  
                    if(parent==PFirst)
                    {   
                        if(PSecond->getminThird()==-1)
                        {   
                            PSecond->setThirdChildPtr(PSecond->getSecondChildPtr());
                            PSecond->setSecondChildPtr(PSecond->getFirstChildPtr());
                            if(subTreePtr == FirstChild)
                            {
                                PSecond->setFirstChildPtr(SecondChild);
                            }
                            else
                            {
                                PSecond->setFirstChildPtr(FirstChild);
                            }
                            PParent->setFirstChildPtr(PSecond);
                            PParent->setSecondChildPtr(PThird);
                            PParent->setThirdChildPtr(nullptr);
                            delete subTreePtr;
                            subTreePtr = nullptr;
                            delete PFirst;
                            PFirst = nullptr;
                        }
                        else
                        {
                            if(subTreePtr == FirstChild)
                            {
                                PFirst->setFirstChildPtr(SecondChild);
                            }
                            PFirst->setSecondChildPtr(PSecond->getFirstChildPtr());
                            PSecond->setFirstChildPtr(PSecond->getSecondChildPtr());
                            PSecond->setSecondChildPtr(PSecond->getThirdChildPtr());
                            PSecond->setThirdChildPtr(nullptr);
                            delete subTreePtr;
                            subTreePtr=nullptr;
                        }
                    }
                    else if(parent==PSecond)
                    {
                        if(PFirst->getminThird()==-1)
                        {
                            if(subTreePtr == FirstChild)
                            {
                                PFirst->setThirdChildPtr(SecondChild);
                            }
                            else
                            {
                                PFirst->setThirdChildPtr(FirstChild);
                            }
                            PParent->setSecondChildPtr(PThird);
                            PParent->setThirdChildPtr(nullptr);
                            delete subTreePtr;
                            subTreePtr=nullptr;
                            delete parent;
                            parent = nullptr;
                        }
                        else
                        {
                            if(subTreePtr == SecondChild)
                            {
                                PSecond->setSecondChildPtr(FirstChild);
                            }
                            PSecond->setFirstChildPtr(PFirst->getThirdChildPtr());
                            PFirst->setThirdChildPtr(nullptr);
                            delete subTreePtr;
                            subTreePtr=nullptr;
                        }
                    }
                    else//delete Third Child from PParent
                    {
                        if(PSecond->getminThird()==-1)//left sibling has 2 children
                        {
                            if(subTreePtr == FirstChild)
                            {
                                PSecond->setThirdChildPtr(SecondChild);
                            }
                            else
                            {
                                PSecond->setThirdChildPtr(FirstChild);
                            }
                            PParent->setThirdChildPtr(nullptr);
                            delete subTreePtr;
                            subTreePtr=nullptr;
                            delete parent;
                            parent = nullptr;
                        }
                        else// left sibling has 3 children
                        {
                            if(subTreePtr == SecondChild)
                            {
                                PThird->setSecondChildPtr(FirstChild);
                            }
                            PThird->setFirstChildPtr(PSecond->getThirdChildPtr());
                            PSecond->setThirdChildPtr(nullptr);
                            delete subTreePtr;
                            subTreePtr=nullptr;
                        }
                    }
                    //if(PParent->getSecondChildPtr()==nullptr)
                    bool DoneCase1 = false;
                    while(PParent->getSecondChildPtr()==nullptr && DoneCase1 == false)
                    {
                        if(PParent == rootPtr)//case 1: 3 level tree merge delete
                        {
                            rootPtr = PParent->getFirstChildPtr();
                            delete PParent;
                            PParent = rootPtr;
                            DoneCase1 = true;
                        }
                        else// case 2: 4 or more level tree merge delete
                        {
                            parent = PParent;
                            PParent = PParent->getParentPtr();
                            subTreePtr = parent->getFirstChildPtr();
                            PFirst = PParent->getFirstChildPtr();
                            PSecond = PParent->getSecondChildPtr();
                            PThird = PParent->getThirdChildPtr(); 
                            if(parent == PFirst)
                            {
                                if(PSecond->getminThird()==-1)//left sibling has 2 children
                                {
                                    PParent->setFirstChildPtr(nullptr);
                                    delete parent;
                                    parent = nullptr;
                                    PSecond->setThirdChildPtr(PSecond->getSecondChildPtr());
                                    PSecond->setSecondChildPtr(PSecond->getFirstChildPtr());
                                    PSecond->setFirstChildPtr(subTreePtr);
                                    PParent->setFirstChildPtr(PParent->getSecondChildPtr());
                                    PParent->setSecondChildPtr(PParent->getThirdChildPtr());
                                    PParent->setThirdChildPtr(nullptr);
                                }
                                else// left sibling has 3 children
                                {
                                    PFirst->setSecondChildPtr(PSecond->getFirstChildPtr());
                                    PSecond->setFirstChildPtr(PSecond->getSecondChildPtr());
                                    PSecond->setSecondChildPtr(PSecond->getThirdChildPtr());
                                    PSecond->setThirdChildPtr(nullptr);
                                }
                            }
                            else if(parent == PSecond)
                            {
                                if(PFirst->getminThird()==-1)//left sibling has 2 children
                                {
                                    PParent->setSecondChildPtr(PThird);
                                    PParent->setThirdChildPtr(nullptr);
                                    delete parent;
                                    parent = nullptr;
                                    PFirst->setThirdChildPtr(subTreePtr);
                                }
                                else// left sibling has 3 children
                                {
                                    PSecond->setSecondChildPtr(subTreePtr);
                                    PSecond->setFirstChildPtr(PFirst->getThirdChildPtr());
                                    PFirst->setThirdChildPtr(nullptr);
                                }
                            }
                            else
                            {
                                if(PSecond->getminThird()==-1)//left sibling has 2 children
                                {
                                    PParent->setThirdChildPtr(nullptr);
                                    delete parent;
                                    parent = nullptr;
                                    PSecond->setThirdChildPtr(subTreePtr);
                                }
                                else// left sibling has 3 children
                                {
                                    PThird->setSecondChildPtr(subTreePtr);
                                    PThird->setFirstChildPtr(PSecond->getThirdChildPtr());
                                    PSecond->setThirdChildPtr(nullptr);
                                }
                            }
                        }
                    }
                    PParent = nullptr;
                }
            }
            resetAllminValue(rootPtr);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(value < subTreePtr->getminSecond())
        {
            return deleteHelper(value, subTreePtr->getFirstChildPtr());
        }
        else if(subTreePtr->getminThird()!=-1 && value >= subTreePtr->getminThird())
        {
            return deleteHelper(value, subTreePtr->getThirdChildPtr());
        }
        else
        {
            return deleteHelper(value, subTreePtr->getSecondChildPtr());
        }
    }
}
template <typename T>
T twothree_tree<T>::FindMin()
{
    if(rootPtr==nullptr)
    {
        return -1;
    }
    else
    {
        return FindMinHelper(rootPtr)->getKeyValue();
    }
}
template <typename T>
T twothree_tree<T>::FindMax()
{
    if(rootPtr==nullptr)
    {
        return -1;
    }
    else
    {
        return FindMaxHelper(rootPtr)->getKeyValue();
    }
}

template <typename T>
bool twothree_tree<T>::Find(T value)
{
    return search(value, rootPtr);
}

template <typename T>
void twothree_tree<T>::Levelorder() 
{
    if(rootPtr!=nullptr)
    {
        std::cout<<"Level order: ";
        levelorderTraverse(rootPtr);
        std::cout<<""<<std::endl;
        /////////
        // std::cout<<"root minSecond: "<<rootPtr->getminSecond()<<std::endl;
        // std::cout<<"root minThird: "<<rootPtr->getminThird()<<std::endl;
        // std::cout<<"First Child MS: "<<rootPtr->getFirstChildPtr()->getminSecond()<<std::endl;
        // std::cout<<"First Child MT: "<<rootPtr->getFirstChildPtr()->getminThird()<<std::endl;
        // std::cout<<"Second Child MS: "<<rootPtr->getSecondChildPtr()->getminSecond()<<std::endl;
        // std::cout<<"Second Child MT: "<<rootPtr->getSecondChildPtr()->getminThird()<<std::endl;
        //std::cout<<"Third Child MS: "<<rootPtr->getThirdChildPtr()->getminSecond()<<std::endl;
        //std::cout<<"Third Child MT: "<<rootPtr->getThirdChildPtr()->getminThird()<<std::endl;
    }
    else
    {
        std::cout<<"The tree is empty"<<std::endl;
    }
}
template <typename T>
bool twothree_tree<T>::DeleteMin()
{
    if(rootPtr==nullptr)
    {
        return false;
    }
    else
    {
        Delete(FindMin());
        return true;
    }
}
template <typename T>
bool twothree_tree<T>::DeleteMax()
{
    if(rootPtr==nullptr)
    {
        return false;
    }
    else
    {
        Delete(FindMax());
        return true;
    }
}