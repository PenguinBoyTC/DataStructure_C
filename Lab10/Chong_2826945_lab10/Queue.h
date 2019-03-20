//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified (JRM): Use Exceptions

/** Listing 13-1.
@file Queue.h */

#ifndef QUEUE_H
#define QUEUE_H
//#include "PrecondViolatedExcep.h"
//#include "QueueInterface.h"
#include "Node.h"
#include <string>

template<class T>
class Queue//: public QueueInterface<T>
{
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	void enqueue(const T& newEntry);// throw (PrecondViolatedExcep);
	bool dequeue();// throw (PrecondViolatedExcep);
	T peekFront();//throw (PrecondViolatedExcep);
	T getFront();
	int getLength();
private:
	Node<T>* m_front;
	int m_size;

}; // end Queue
#include "Queue.hpp"
#endif
