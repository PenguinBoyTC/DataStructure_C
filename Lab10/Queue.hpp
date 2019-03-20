/**
Name：ChongTan
File Name:Queue.hpp
Data:3/1/2016
Description: create a queue and add member to the back
*/
#include "Queue.h"
//#include "PrecondViolatedExcep.h"
#include "Node.h"
using namespace std;
template <class T>
Queue<T>::Queue()
{
	m_front = nullptr;
	m_size = 0;
}

template <class T>
Queue<T>::~Queue()
{
	Node<T>* temp=nullptr;
	while(m_front!=nullptr)
	{
        temp = m_front;
		m_front = temp->getnext();
		delete temp;
		m_size--;
	}
}

template <class T>
bool Queue<T>::isEmpty() const
{//returns true if the stack is empty, false otherwise
	if (m_front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void Queue<T>::enqueue(const T& newEntry) //throw (PrecondViolatedExcep)
{//Entry added to back of queue
	Node<T>* NewNode = new Node<T>;
	NewNode->setItem(newEntry);
	if (m_front == nullptr)
	{
		m_front = NewNode;
		m_size++;
	}
	else
	{
		Node<T>* cur = m_front;
		while(cur->getnext()!=nullptr)
        {
			cur = cur->getnext();
	    }
		cur->setnext(NewNode);
		m_size++;
	}
}

template <class T>
bool Queue<T>::dequeue() //throw(PrecondViolatedExcep)
{//throws PreconditionViolationException when a pop is attempted on an empty stack. Does not return a value in this case.
	if (m_front == nullptr)
	{
		return false;//throw(PrecondViolatedExcep("Pop attempted on an empty stack"));
	}
	else
	{
        Node<T>* temp = m_front->getnext();
		delete m_front;
		m_front = temp;
		temp = nullptr;
		m_size = m_size - 1;
		return true;
	}

}

template <class T>
T Queue<T>::getFront() //throw(PrecondViolatedExcep)
{//throws a PreconditionViolationException is attempted on an empty stack. Does not return a value in this case.
	if (m_front != nullptr)
	{
        return(m_front->getItem());
	}
	else
	{
		return nullptr;
		//throw(PrecondViolatedExcep("Peekfront attempted on an empty stack"));
	}
}

template <class T>
T Queue<T>::peekFront()
{
	if(m_front != nullptr)
	{
		T item = m_front->getItem();
		dequeue();
		return item;
	}
	else
	{
		return nullptr;
	}
}
template <class T>
int Queue<T>::getLength()
{
	return m_size;
}