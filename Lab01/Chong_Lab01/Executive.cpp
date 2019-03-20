#include "Executive.h"
#include "LinkedList.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

Executive::Executive()
{
    choose = 1;
}
void Executive::run()//run method
{
    LinkedList<int>* L = new LinkedList<int>();
    std::ifstream inp;
    inp.open("data.txt");//open the data.txt file
    int number;//use to read the number
    while(!inp.eof())
    {
        inp>>number;
        L->addBack(number);//add number to the end of the list
    }
    inp.close();//close the data.txt file
    while(choose<5)
    {
        //User menu
        std::cout<<"......................................"<< std::endl;
        std::cout<<"Please choose one of the following commands:"<< std::endl;
        std::cout<<"1-Insert"<< std::endl;
        std::cout<<"2-Delete"<< std::endl;
        std::cout<<"3-Find"<< std::endl;
        std::cout<<"4-Print"<< std::endl;
        std::cout<<"5-Exit"<< std::endl;
        std::cin>>choose;
        if(choose==1)
        {
            Insert(L);
        }
        else if(choose==2)
        {
            Delete(L);
        }
        else if(choose==3)
        {
            Find(L);
        }
        else if(choose==4)
        {
            Print(L);
        };
    }
    delete L;
    std::cout<<"Thanks !"<<std::endl;
    std::cout<<"Bye."<<std::endl;
}
//insert method to add number.
void Executive::Insert(LinkedList<int>* List)
{
    std::cout<<"Enter a number to be inserted into the list:"<<std::endl;
    int IN;
    std::cin>>IN;
    if(!List->addBack(IN))
    {
        std::cout<<"The number already exist."<<std::endl;
    }
    else
    {
        std::cout<<"The number added into the list successfully."<<std::endl;
    }
}
//delete method to remove the number
void Executive::Delete(LinkedList<int>* List)
{
    std::cout<<"Enter a number to be deleted from the list:"<<std::endl;
    int IN;
    std::cin>>IN;
    if(!List->remove(IN))
    {
        std::cout<<"Entered number does not exist in the list."<<std::endl;
    }
    else
    {
        std::cout<<"Entered number has been deleted from the list."<<std::endl;
    }
}
//check if the number exist
void Executive::Find(LinkedList<int>* List)
{
    std::cout<<"Enter a number to be found:"<<std::endl;
    int IN;
    std::cin>>IN;
    if(List->isExist(IN))
    {
        std::cout<<"Entered number exists in the list."<<std::endl;
    }
    else
    {
        std::cout<<"Entered number doesn't exist in the list."<<std::endl;
    }
}
// print out the list
void Executive::Print(LinkedList<int>* List)
{
    List->print();
}

