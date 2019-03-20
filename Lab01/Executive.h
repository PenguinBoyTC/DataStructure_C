#ifndef Executive_H
#define Executive_H
#include <string>
#include <fstream>
#include <iostream>
#include "LinkedList.h"

class Executive
{
public:
    Executive();//constructor
    void run();//run method
    void Insert(LinkedList<int>* List);//Reverse method
    void Delete(LinkedList<int>* List);//C(n)method
    void Find(LinkedList<int>* List);//permutation
    void Print(LinkedList<int>* List);//ignore permutation
private:
    int choose;
};
#endif
    
