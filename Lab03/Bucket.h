#ifndef BUCKET_H
#define BUCKET_H
#include <string>

template <typename T>
class Bucket
{
public:
	Bucket();//constructor
	bool setItem(T Item);//set value
	void desetItem();
	T getItem();//get value
	void setFlag(bool flag);
	bool getFlag();
	bool isEmpty();
	bool AlwaysEmpty();

private:
	T m_Item;
	bool m_flag;
	bool isempty;
};
#include "Bucket.hpp"
#endif
