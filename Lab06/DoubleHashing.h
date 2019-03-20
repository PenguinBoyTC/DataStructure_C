/**
*	@file DoubleHashing.h
*	@author ChongTan
*	@date 2/6/18
*	@brief A header file for templated DoubleHashing class
*/

#ifndef DOUBLEHASHING_H
#define DOUBLEHASHING_H
#include "Bucket.h"

template <typename T>
class DoubleHashing
{
	public:
		DoubleHashing(int m, int k, int p);//constructor
		DoubleHashing();
		~DoubleHashing();//Distructor
		bool Insert(T value);//insert value to hash table
		bool Remove(T value);//delete value from hash table
		void Print();// print all value in the hash table
		int Hash(T value);//return the index for key value
		bool Find(T value);//return true if the key value is in the hashtable and false otherwise
		float loadFactor();//return the value of loading factor

	private:
		Bucket<T>* m_hashtable;//create an array for hash table
		int m_m;
		int m_k;
		int m_p;
		int numOfEle;
};
#include "DoubleHashing.hpp"
#endif
