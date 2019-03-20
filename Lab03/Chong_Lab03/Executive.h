#ifndef Executive_H
#define Executive_H
#include <string>
#include <fstream>
#include <iostream>
#include "QuadraticProbing.h"
#include "DoubleHashing.h"

class Executive
{
public:
    Executive();//constructor
	~Executive();//distructor
    void run();//run method
    void Insert();//Reverse method
    void Delete();//C(n)method
    void Find();//permutation
    void Print();//ignore permutation
private:
    QuadraticProbing<int>* QP;
    DoubleHashing<int>* DH;
};
#endif
    
