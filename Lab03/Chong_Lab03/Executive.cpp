#include "Executive.h"
#include "QuadraticProbing.h"
#include "DoubleHashing.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

Executive::Executive()
{
    QP = new QuadraticProbing<int>();
    DH = new DoubleHashing<int>();
}
Executive::~Executive()//distructor
{
    delete QP;
    delete DH;
}
void Executive::run()//run method
{
    std::cout<<"Which data file you want to load?"<<std::endl;
    std::cout<<"1. data1.txt."<<std::endl;
    std::cout<<"2. data2.txt."<<std::endl;
    std::cout<<"3. data3.txt."<<std::endl;
    std::cout<<"4. data4.txt."<<std::endl;
    std::cout<<"5. data5.txt."<<std::endl;
    int option;
    std::string filename;
    std::cin>>option;
    if(option == 1){filename = "data1.txt";}
    else if(option == 2){filename = "data2.txt";}
    else if(option == 3){filename = "data3.txt";}
    else if(option == 4){filename = "data4.txt";}
    else {filename = "data5.txt";}

    std::ifstream inp;
    //inp.open("data.txt");//open the data.txt file
    inp.open(filename);//open the data.txt file
    int number;//use to read the number
    //int tryingnumber = 0;
    while(!inp.eof())
    {
        inp>>number;
        //tryingnumber++;
        QP->Insert(number);//add number to the Hash Table
        DH->Insert(number);
    }
    inp.close();//close the data.txt file
    //std::cout<<"Trying to insert:"<<tryingnumber<<std::endl;
    std::cout<<"Load factor of hash table with quadratic probing is "<<QP->loadFactor()<<"."<<std::endl;
    std::cout<<"Load factor of hash table with double hashing is "<<DH->loadFactor()<<"."<<std::endl;
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
    std::cout<<""<<std::endl;

    if(!QP->Insert(IN))
    {
        std::cout<<"Failed to insert "<<IN<<" into hash table with quadratic probing"<<std::endl;
    }
    if(!DH->Insert(IN))
    {
        std::cout<<"Failed to insert "<<IN<<" into hash table with double hashing"<<std::endl;
    }
    std::cout<<"Load factor of hash table with quadratic probing is "<<QP->loadFactor()<<"."<<std::endl;
    std::cout<<"Load factor of hash table with double hashing is "<<DH->loadFactor()<<"."<<std::endl;
}
//delete method to remove the number
void Executive::Delete()
{
    std::cout<<"Enter the number to be deleted:"<<std::endl;
    int IN;
    std::cin>>IN;
    std::cout<<""<<std::endl;
    if(!QP->Remove(IN))
    {
        std::cout<<"Entered number does not exist in the hash table with quadratic probing."<<std::endl;
    }
    else
    {
        std::cout<<"Successfully deleted "<<IN<<" from the hash table with quadratic probing."<<std::endl;
    }
    if(!DH->Remove(IN))
    {
        std::cout<<"Entered number does not exist in the hash table with double hashing."<<std::endl;
    }
    else
    {
        std::cout<<"Successfully deleted "<<IN<<" from the hash table with double hashing."<<std::endl;
    }
    std::cout<<""<<std::endl;
    std::cout<<"Load factor of hash table with quadratic probing is "<<QP->loadFactor()<<"."<<std::endl;
    std::cout<<"Load factor of hash table with double hashing is "<<DH->loadFactor()<<"."<<std::endl;
}
//check if the number exist
void Executive::Find()
{
    std::cout<<"Enter a number to be found:"<<std::endl;
    int IN;
    std::cin>>IN;
    std::cout<<""<<std::endl;
    if(QP->Find(IN))
    {
        std::cout<<IN<<" exists in the hash table with quadratic hashing."<<std::endl;
    }
    else
    {
        std::cout<<IN<<" does not exist in the hash table with quadratic probing."<<std::endl;
    }
    if(DH->Find(IN))
    {
        std::cout<<IN<<" exists in the hash table with double hasing."<<std::endl;
    }
    else
    {
        std::cout<<IN<<" does not exist in the hash table with double hasing."<<std::endl;
    }
}
// print out the list
void Executive::Print()
{
    std::cout<<"Hash table with quadratic probing:"<<std::endl;
    QP->Print();
    std::cout<<""<<std::endl;
    std::cout<<"Hash table with double hashing:"<<std::endl;
    DH->Print();
    std::cout<<""<<std::endl;
}

