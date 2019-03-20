#ifndef Executive_H
#define Executive_H
#include <string>
#include <fstream>
#include <iostream>
#include "QuadraticProbing.h"
#include "DoubleHashing.h"
#include "HashTable.h"
#include "Timer.cpp"

class Executive
{
public:
    Executive();//constructor
	~Executive();//distructor
    void run();//run method
    void Test_HashTable();
    void Performance_Comparison(int size);
private:
    int m;
    int k;
    int p;
};
#endif
    
