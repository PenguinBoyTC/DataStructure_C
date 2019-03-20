#include "Executive.h"
#include "twothree_tree.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

Executive::Executive()
{
    TTtree = new twothree_tree<int>();
}
Executive::~Executive()//distructor
{
    delete TTtree;
}
void Executive::run()//run method
{
    // std::cout<<"Which data file you want to load?"<<std::endl;
    // std::cout<<"1. data.txt."<<std::endl;
    // std::cout<<"2. complete_tree.txt."<<std::endl;
    // std::cout<<"3. skew_tree.txt."<<std::endl;
    //int option;
    std::string filename = "data.txt";
    //std::cin>>option;

    // if(option == 1){filename = "data.txt";}
    // else if(option == 2){filename = "complete_tree.txt";}
    // else{filename = "skew_tree.txt";}

    std::ifstream inp;
    inp.open(filename);//open the data.txt file

    int number;
    while(!inp.eof())
    {
        inp>>number;
        TTtree->Insert(number);
    }
    inp.close();//close the data.txt file

	int choose =1;
    while(choose<9)
    {
        //User menu
        std::cout<<"......................................"<< std::endl;
        std::cout<<"Please choose one of the following commands:"<< std::endl;
        std::cout<<"1-Insert"<< std::endl;//c
        std::cout<<"2-DeleteMin"<< std::endl;
        std::cout<<"3-DeleteMax"<< std::endl;
        std::cout<<"4-FindMin"<< std::endl;//c
        std::cout<<"5-FindMax"<< std::endl;//c
        std::cout<<"6-Find"<< std::endl;//c
        std::cout<<"7-Delete"<< std::endl;
        std::cout<<"8-Level order"<< std::endl;//c
        std::cout<<"9-Exit"<< std::endl;//c
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
            DeleteMax();
        }
        else if(choose==4)
        {
            FindMin();
        }
        else if(choose==5)
        {
            FindMax();
        }
        else if(choose==6)
        {
            Find();
        }
        else if(choose==7)
        {
            Delete();
        }
        else if(choose==8)
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
    if(TTtree->Insert(IN))
    {
        std::cout<<IN<<" has been inserted."<<std::endl;
    }
    else
    {
        std::cout<<IN<<" already exist."<<std::endl;
    }
}

//delete method to remove the number
void Executive::Delete()
{
    std::cout<<"Enter the number to be deleted: "<<std::endl;
    int IN;
    std::cin>>IN;
    if(TTtree->Delete(IN))
    {
        std::cout<<IN<<" has been deleted."<<std::endl;
    }
    else
    {
        std::cout<<IN<<" do not exist in the tree."<<std::endl;
    }
}

void Executive::DeleteMin()
{
    if(TTtree->FindMin()!=-1)
    {
        int IN = TTtree->FindMin();
        TTtree->DeleteMin();
        std::cout<<IN<<" have been deleted from the tree."<<std::endl;
    }
    else
    {
        std::cout<<"There is no element can be deleted."<<std::endl;    
    }
}
void Executive::DeleteMax()
{
    if(TTtree->FindMax()!=-1)
    {
        int IN = TTtree->FindMax();
        TTtree->DeleteMax();
        std::cout<<IN<<" have been deleted from the tree."<<std::endl;
    }
    else
    {
        std::cout<<"There is no element can be deleted."<<std::endl;    
    }
}
void Executive::FindMin()
{
    if(TTtree->FindMin()==-1)
    {
        std::cout<<"There is no element in the tree."<<std::endl;
    }
    else
    {
        std::cout<<TTtree->FindMin()<<" is the smallest element."<<std::endl;
    }
}
void Executive::FindMax()
{
    if(TTtree->FindMax()==-1)
    {
        std::cout<<"There is no element in the tree."<<std::endl;
    }
    else
    {
        std::cout<<TTtree->FindMax()<<" is the biggest element."<<std::endl;
    }
}
void Executive::Find()
{
    std::cout<<"Enter a number to be found: "<<std::endl;
    int IN;
    std::cin>>IN;
    if(TTtree->Find(IN))
    {
        std::cout<<IN<<" exist in the tree."<<std::endl;
    }
    else
    {
        std::cout<<IN<<" do not exist in the tree."<<std::endl;
    }
}
void Executive::LevelOrder()
{
    TTtree->Levelorder();
}