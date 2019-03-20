#include "Executive.h"
#include "BinarySearchTree.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

Executive::Executive()
{
    bst = new BinarySearchTree<int>();
}
Executive::~Executive()//distructor
{
    delete bst;
}
void Executive::run()//run method
{
    std::cout<<"Which data file you want to load?"<<std::endl;
    std::cout<<"1. data.txt."<<std::endl;
    std::cout<<"2. complete_tree.txt."<<std::endl;
    std::cout<<"3. skew_tree.txt."<<std::endl;
    int option;
    std::string filename;
    std::cin>>option;

    if(option == 1){filename = "data.txt";}
    else if(option == 2){filename = "complete_tree.txt";}
    else{filename = "skew_tree.txt";}

    std::ifstream inp;
    inp.open(filename);//open the data.txt file
    //BinarySearchTree<int> bst;

    int number;
    while(!inp.eof())
    {
        inp>>number;
        bst->Insert(number);
    }
    inp.close();//close the data.txt file

	int choose =1;
    while(choose<10)
    {
        //User menu
        std::cout<<"......................................"<< std::endl;
        std::cout<<"Please choose one of the following commands:"<< std::endl;
        std::cout<<"1-Insert"<< std::endl;
        std::cout<<"2-DeleteMin"<< std::endl;
        std::cout<<"3-DeleteMax"<< std::endl;
        std::cout<<"4-Delete"<< std::endl;
        std::cout<<"5-FindMin"<< std::endl;
        std::cout<<"6-FindMax"<< std::endl;
        std::cout<<"7-Preorder"<< std::endl;
        std::cout<<"8-Inorder"<< std::endl;
        std::cout<<"9-Postorder"<< std::endl;
        std::cout<<"10-Exit"<< std::endl;
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
            Delete();
        }
        else if(choose==5)
        {
            FindMin();
        }
        else if(choose==6)
        {
            FindMax();
        }
        else if(choose==7)
        {
            bst->Preorder();
        }
        else if(choose==8)
        {
            bst->Inorder();
    
        }
        else if(choose==9)
        {
            bst->Postorder();
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
    bst->Insert(IN);
    std::cout<<IN<<" has been inserted."<<std::endl;
}

//delete method to remove the number
void Executive::Delete()
{
    std::cout<<"Enter the number to be deleted: "<<std::endl;
    int IN;
    std::cin>>IN;
    if(bst->Delete(IN))
    {
        std::cout<<IN<<" has been deleted."<<std::endl;
    }
    else
    {
        std::cout<<IN<<" is not found in the BST."<<std::endl;
    }
}

void Executive::DeleteMin()
{
    if(bst->isEmpty())
    {
        std::cout<<"There is no element can be deleted."<<std::endl;    
    }
    else
    {
        int Item = bst->FindMin()->getItem();
        if(bst->DeleteMin())
        {
            std::cout<<Item<<" has been deleted."<<std::endl;
        }
    }
}
void Executive::DeleteMax()
{
    if(bst->isEmpty())
    {
        std::cout<<"There is no element can be deleted."<<std::endl;    
    }
    else
    {
        int Item = bst->FindMax()->getItem();
        if(bst->DeleteMax())
        {
            std::cout<<Item<<" has been deleted."<<std::endl;
        }
    }
}
void Executive::FindMin()
{
    if(bst->isEmpty())
    {
        std::cout<<"There is no element in the tree."<<std::endl;
    }
    else
    {
        std::cout<<bst->FindMin()->getItem()<<" is the smallest element."<<std::endl;
    }
}
void Executive::FindMax()
{
    if(bst->isEmpty())
    {
        std::cout<<"There is no element in the tree."<<std::endl;
    }
    else
    {
        std::cout<<bst->FindMax()->getItem()<<" is the largest element."<<std::endl;
    }
}

