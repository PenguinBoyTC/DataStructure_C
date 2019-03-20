#include "Executive.h"
#include "Max5_Heap.h"
#include "Min5_Heap.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

Executive::Executive()
{
    //Heap = new Max5_Heap<int>(500, "data.txt");
    // MaxHeap = new Max5_Heap<int>(500);
    // MinHeap = new Min5_Heap<int>(500);
    std::cout<<"Which heap you want to implement?"<< std::endl;
    std::cout<<"1. Max 5-Heap."<< std::endl;
    std::cout<<"2. Min 5-Heap."<< std::endl;
    int option;
    std::cin>>option;
    if(option==1)
    {
        Heap = new Max5_Heap<int>(500, "data.txt");
    }
    else
    {
        Heap = new Min5_Heap<int>(500, "data.txt");
    }
}
Executive::~Executive()//distructor
{
    delete Heap;
}
void Executive::run()//run method
{
	int choose =1;
    while(choose<7)
    {
        //User menu
        std::cout<<"......................................"<< std::endl;
        std::cout<<"Please choose one of the following commands:"<< std::endl;
        std::cout<<"1-Insert"<< std::endl;
        std::cout<<"2-DeleteMin"<< std::endl;
        std::cout<<"3-FindMin"<< std::endl;
        std::cout<<"4-FindMax"<< std::endl;
        std::cout<<"5-DeleteMax"<< std::endl;
        std::cout<<"6-LevelOrder"<< std::endl;
        std::cout<<"7-Exit"<< std::endl;
        std::cin>>choose;
        if(choose==1)
        {
            Insert();
        }
        else if(choose==2)
        {
            DeleteMin();
        }
        else if(choose==3)
        {
            FindMin();
        }
        else if(choose==4)
        {
            FindMax();
        }
        else if(choose==5)
        {
            DeleteMax();
        }
        else if(choose==6)
        {
            LevelOrder();
        }
    }
    std::cout<<"Thanks !"<<std::endl;
    std::cout<<"Bye."<<std::endl;
}
//insert method to add number.
void Executive::Insert()
{
    std::cout<<"Enter the number to be inserted: "<<std::endl;
    int IN;
    std::cin>>IN;
    Heap->insert(IN);
    LevelOrder();
}

void Executive::DeleteMin()
{
    if(Heap->deletemin())
    {
        LevelOrder();
    }
    else
    {
        std::cout<<"There is no element in the heap."<<std::endl;
    }
}
void Executive::DeleteMax()
{
    if(Heap->deletemax())
    {
        LevelOrder();
    }
    else
    {
        std::cout<<"There is no element in the heap."<<std::endl;
    }
}
void Executive::FindMin()
{
    if(Heap->findmin()!=-1)
    {
        std::cout<<"Min value is: "<<Heap->findmin()<<std::endl;
    }
    else
    {
        std::cout<<"There is no element in the heap."<<std::endl;
    }
}
void Executive::FindMax()
{
    if(Heap->findmax()!=-1)
    {
        std::cout<<"Max value is: "<<Heap->findmax()<<std::endl;
    }
    else
    {
        std::cout<<"There is no element in the heap."<<std::endl;
    }
}
void Executive::LevelOrder()
{
    Heap->levelorder(5);
}
