
template <typename T>
LinkedList<T>::LinkedList()//constructor
{
	m_front=nullptr;
    m_length=0;
}

template <typename T>
LinkedList<T>::~LinkedList()//Deletes all nodes in the list.
{
    Node<T>* temp=nullptr;
	while(m_front!=nullptr)
	{
        temp = m_front;
		m_front = temp->getnext();
		delete temp;
		m_length--;
	}
}
template <typename T>
void LinkedList<T>::RemoveAll()//Deletes all nodes in the list.
{
    Node<T>* temp=nullptr;
	while(m_front!=nullptr)
	{
        temp = m_front;
		m_front = temp->getnext();
		delete temp;
		m_length--;
	}
}

template <typename T>
bool LinkedList<T>::isEmpty()const//returns true if the list is empty, false otherwise.
{
	if(m_front==nullptr)
	{
		return (true);
	}
	else
	{
		return(false);
	}

}

template <typename T>
bool LinkedList<T>::remove(T value)//Remove x from List if found; else return false;
{
    if(!isExist(value))
    {
        return false;
    }
    else 
    {
        m_front = erase(m_front, value);//call the erase method to delete node.
        m_length--;
        return true;
    }
}

template <typename T>
Node<T>* LinkedList<T>::erase(Node<T>* subList, T value)//a recursively method to delete node
{
    if(subList==nullptr)
    {
        return nullptr;
    }
    else if(subList->getItem()!=value)
    {
        Node<T>* NextPtr = subList->getnext();
        NextPtr = erase(NextPtr, value);//call itself
        subList->setnext(NextPtr);//set to next node
        return subList;
    }
    else
    {
        Node<T>* NextPtr1 = subList->getnext();
       delete subList;
       subList = nullptr;
        return NextPtr1;
    }
}

template <typename T>
bool LinkedList<T>::addBack(T value)//add a node to the end of the list if the value doesn't exist;
{
    if(isExist(value))
    {
        return false;
    }
    else
    {
        Node<T>* n = new Node<T>;
        n->setItem(value);
        m_front = insert(m_front, n);
        m_length++;
        return true;
    }  
}

template <typename T>
Node<T>* LinkedList<T>::insert(Node<T>* subList, Node<T>* NewNode)//Insert value into the end of the list
{
    if(subList == nullptr)
    {
        return NewNode;
    }
    else
    {
        Node<T>* NextPtr = subList->getnext();
        NextPtr = insert(NextPtr, NewNode);//call itself
        subList->setnext(NextPtr);
        return subList;
    }
}

template <typename T>
Node<T>* LinkedList<T>::find(Node<T>* subList, T value)//Search for value in L and return the pointer pointing at the node containing x. if x not found, return a NULL pointer.
{
    if(subList == nullptr)
    {
        return nullptr;
    }
    else if(subList->getItem()!=value)
    {
        return find(subList->getnext(), value);//call itself
    }
    else
    {
        return subList;
    }
}

template <typename T>
bool LinkedList<T>::isExist(T value)//a function to call find method so that it can be used in other class.
{
    if(find(m_front, value) == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// template <typename T>
// void LinkedList<T>::print()
// {
//     Node<T>* cur = m_front;
//     while(cur!=nullptr)
//     {
//         std::cout<<cur->getItem()<<" ";
//         cur=cur->getnext();
//     }
//     std::cout<<""<<std::endl;
// }

template <typename T>
void LinkedList<T>::print()//print out all the elements of the list separated by a space. 
{
    printHelper(m_front);
}

template <typename T>
void LinkedList<T>::printHelper(Node<T>* subList)//a recursive function to print the list
{
    if(subList==nullptr)
    {
        std::cout<<""<<std::endl;
    }
    else
    {
        std::cout<<subList->getItem()<<" ";
        subList = subList->getnext();
        printHelper(subList);//call itself;
    }
}


template <typename T>
bool LinkedList<T>::addFront(T value)//add a node to the end of the list if the value doesn't exist;
{
    if(isExist(value))
    {
        return false;
    }
    else
    {
        Node<T>* temp = m_front;
	    m_front = new Node<T>();
        m_front->setItem(value);
	    m_front->setnext( temp );
	    m_length++;
        return true;
    }  
}