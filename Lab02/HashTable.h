/**
*	@file HashTable.h
*	@author ChongTan
*	@date 1/30/18
*	@brief A header file for templated LinkedList class
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"

template <typename T>
class HashTable
{
	public:
		HashTable(int size);//constructor
		// HashTable();
		~HashTable();//Distructor
		bool Insert(T value);//insert value to hash table
		bool Delete(T value);//delete value from hash table
		void Print();// print all value in the hash table
		int Hash(T value);//return the index for key value
		bool Find(T value);//return true if the key value is in the hashtable and false otherwise

		//void setSize(int size);
	private:
		LinkedList<T>* m_hashtable;//create an array for hash table
		int m_size;
};
#include "HashTable.hpp"
#endif
