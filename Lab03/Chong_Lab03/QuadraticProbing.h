/**
*	@file QuadraticProbing.h
*	@author ChongTan
*	@date 2/6/18
*	@brief A header file for templated QuadraticProbing class
*/

#ifndef QUADRATICPROBING_H
#define QUADRATICPROBING_H
#include "Bucket.h"

template <typename T>
class QuadraticProbing
{
	public:
		QuadraticProbing(int m, int k);//constructor
		QuadraticProbing();
		~QuadraticProbing();//Distructor
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
		int numOfEle;
};
#include "QuadraticProbing.hpp"
#endif
