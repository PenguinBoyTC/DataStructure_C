#include "Executive.h"
#include "Leftist_Tree.h"
#include "Skew_Tree.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

Executive::Executive()
{
    Tree_Option = 4;
    while(Tree_Option>3)
    {
        std::cout<<"Which Tree you want to implement?"<<std::endl;
        std::cout<<"1. Leftist-Tree."<<std::endl;
        std::cout<<"2. Skew-Tree."<<std::endl;
        std::cin>>Tree_Option;
        if(Tree_Option==1)
        {
            Tree = new Leftist_Tree<int>();
        }
        else if(Tree_Option==2)
        {
            Tree = new Skew_Tree<int>();
        }
    }
}
Executive::~Executive()//distructor
{
    delete Tree;
}
void Executive::run()//run method
{
    Tree->buildheap("data.txt");
	int choose =1;
    while(choose<6)
    {
        //User menu
        std::cout<<"......................................"<< std::endl;
        std::cout<<"Please choose one of the following commands:"<< std::endl;
        std::cout<<"1-insert"<< std::endl;
        std::cout<<"2-deletemin"<< std::endl;
        std::cout<<"3-preorder"<< std::endl;
        std::cout<<"4-inorder"<< std::endl;
        std::cout<<"5-levelorder"<< std::endl;
        std::cout<<"6-end"<< std::endl;
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
            Preorder();
        }
        else if(choose==4)
        {
            Inorder();
        }
        else if(choose==5)
        {
            Levelorder();
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
    Tree->Insert(IN);
    std::cout<<IN<<" has been inserted."<<std::endl;
}

//delete method to remove the number
void Executive::DeleteMin()
{
    if(!Tree->DeleteMin())
    {
        std::cout<<"It's an empty tree. There is no element can be deleted."<<std::endl;
    }
}
void Executive::Preorder()
{
    Tree->Preorder();
}
void Executive::Inorder()
{
    Tree->Inorder();
}
void Executive::Levelorder()
{
    Tree->Levelorder();
}