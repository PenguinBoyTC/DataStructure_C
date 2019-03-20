#include "Executive.h"
#include "LinkedList.h"
#include "HashTable.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

Executive::Executive()
{
    size = 0;
}
Executive::~Executive()//distructor
{
    delete HT;
}
void Executive::run()//run method
{
    std::ifstream inp;
    inp.open("data.txt");//open the data.txt file
    int number;//use to read the number
	inp>>size;//get size for hash table

    HT = new HashTable<int>(size);

    while(!inp.eof())
    {
        inp>>number;
        HT->Insert(number);//add number to the Hash Table
    }
    inp.close();//close the data.txt file
	int choose =1;
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
            Insert();
        }
        else if(choose==2)
        {
            Delete();
        }
        else if(choose==3)
        {
            Find();
        }
        else if(choose==4)
        {
            Print();
        };
    }
    std::cout<<"Thanks !"<<std::endl;
    std::cout<<"Bye."<<std::endl;
}
//insert method to add number.
void Executive::Insert()
{
    std::cout<<"Enter a number to be inserted:"<<std::endl;
    int IN;
    std::cin>>IN;
    if(!HT->Insert(IN))
    {
        std::cout<<IN<<" is duplicated, can’t be added to the hash table"<<std::endl;
    }
    else
    {
        std::cout<<IN<<" is added to the hash table"<<std::endl;
    }
}
//delete method to remove the number
void Executive::Delete()
{
    std::cout<<"Enter a number to delete:"<<std::endl;
    int IN;
    std::cin>>IN;
    if(!HT->Delete(IN))
    {
        std::cout<<"Entered number does not exist in the hash table."<<std::endl;
    }
    else
    {
        std::cout<<IN<<" is deleted from the hash table"<<std::endl;
    }
}
//check if the number exist
void Executive::Find()
{
    std::cout<<"Enter a number to be found:"<<std::endl;
    int IN;
    std::cin>>IN;
    if(HT->Find(IN))
    {
        std::cout<<IN<<" is found in the hash table."<<std::endl;
    }
    else
    {
        std::cout<<IN<<" can’t be found in the hash table."<<std::endl;
    }
}
// print out the list
void Executive::Print()
{
    HT->Print();
}

