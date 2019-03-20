#include "Executive.h"
#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include "Min5_Heap.h"
#include "Max5_Heap.h"
#include "Timer.cpp"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

Executive::Executive()
{
    array_size = 10000000;
    m_m = 1000000;
}
Executive::~Executive()//distructor
{
}
void Executive::run()//run method
{
	int choose =1;
    while(choose<5)
    {
        //User menu
        std::cout<<"............................................................................"<< std::endl;
        std::cout<<"Please choose one of the following commands:"<< std::endl;
        std::cout<<"1-Performance BST"<< std::endl;
        std::cout<<"2-Performance Min_5_heap"<< std::endl;
        std::cout<<"3-Performance Max_5_heap"<< std::endl;
        std::cout<<"4-Performance Comparison"<< std::endl;
        std::cout<<"5-Exit"<< std::endl;
        std::cin>>choose;
        if(choose==1)
        {
            std::cout<<"============================================================================="<< std::endl;
            Performance_BST();
            std::cout<<"============================================================================="<< std::endl;
        }
        else if(choose==2)
        {
            std::cout<<"============================================================================="<< std::endl;
            Performance_Min_5();
            std::cout<<"============================================================================="<< std::endl;
        }
        else if(choose==3)
        {
            std::cout<<"============================================================================="<< std::endl;
            Performance_Max_5();
            std::cout<<"============================================================================="<< std::endl;
        }
        else if(choose==4)
        {
            std::cout<<"============================================================================="<< std::endl;
            Performance();
            std::cout<<"============================================================================="<< std::endl;
        }
    }
    std::cout<<"Thanks !"<<std::endl;
    std::cout<<"Bye."<<std::endl;
}

void Executive::Performance()
{
    Performance_BST();
    Performance_Min_5();
    Performance_Max_5();
}
void Executive::Performance_BST()
{
    Timer T;

    double* buildTime_average = new double [5];
    double* deleteminTime_average = new double [5];
    double* deletemaxTime_average = new double [5];
    BinarySearchTree<int>* BST;
    std::cout<<"                      Performance(bst)"<<std::endl;
    std::cout<<"         | 1,000,000 | 2,000,000 | 3,000,000 | 4,000,000 | 5,000,000 |"<<std::endl;
    for(int i=0; i<5; i++)
    {
        double buildTime = 0;
        double deleteminTime = 0;
        double deletemaxTime = 0;
        for(int j=1; j<=5; j++)
        {
            BST = new BinarySearchTree<int>();
            srand(j);
            //build
            for(int k=0; k<(i+1)*m_m; k++)
            {
                int e = rand()%(5*m_m)+1;
                T.start();
                BST->Insert(e);
                buildTime += T.stop();
            }
            //deletemin
            for(int k=0; k<0.001*(i+1)*m_m; k++)
            {
                T.start();
                BST->DeleteMin();
                deleteminTime += T.stop();
            }
            //deletemax
            for(int k=0; k<0.001*(i+1)*m_m; k++)
            {
                T.start();
                BST->DeleteMax();
                deletemaxTime += T.stop();
            }
            delete BST;
        }
        buildTime_average[i] = buildTime/5;
        deleteminTime_average[i] = deleteminTime/5;
        deletemaxTime_average[i] = deletemaxTime/5;
    }
    std::cout<<"Build:     ";
    for(int i=0; i<5; i++)
    {
        std::cout<<buildTime_average[i]<<"  |  ";
    }
    std::cout<<""<<std::endl;
    std::cout<<"deletemin: ";
    for(int i=0; i<5; i++)
    {
        std::cout<<deleteminTime_average[i]<<" | ";
    }
    std::cout<<""<<std::endl;
    std::cout<<"deletemax: ";
    for(int i=0; i<5; i++)
    {
        std::cout<<deletemaxTime_average[i]<<" | ";
    }
    std::cout<<""<<std::endl;
    delete[] buildTime_average;
    delete[] deleteminTime_average;
    delete[] deletemaxTime_average;
}
void Executive::Performance_Min_5()
{
    Timer T;

    double* buildTime_average = new double [5];
    double* deleteminTime_average = new double [5];
    double* deletemaxTime_average = new double [5];
    Min5_Heap<int>* Min_heap;
    std::cout<<"                      Performance(Min-5 Heap)"<<std::endl;
    std::cout<<"         | 1,000,000 | 2,000,000 | 3,000,000 | 4,000,000 | 5,000,000 |"<<std::endl;
    for(int i=0; i<5; i++)
    {
        double buildTime = 0;
        double deleteminTime = 0;
        double deletemaxTime = 0;
        for(int j=1; j<=5; j++)
        {
            Min_heap = new Min5_Heap<int>(array_size);
            srand(j);
            //build
            for(int k=0; k<(i+1)*m_m; k++)
            {
                int e = rand()%(5*m_m)+1;
                T.start();
                Min_heap->insertWithoutsorted(e);
                buildTime += T.stop();
            }
            T.start();
            Min_heap->buildheap();
            buildTime += T.stop();
            //deletemin
            for(int k=0; k<0.001*(i+1)*m_m; k++)
            //for(int k=0; k<1; k++)
            {
                T.start();
                Min_heap->deletemin();
                deleteminTime += T.stop();
            }
            //deletemax
            for(int k=0; k<0.001*(i+1)*m_m; k++)
            //for(int k=0; k<10; k++)
            {
                T.start();
                Min_heap->deletemax();
                //std::cout<<k<<", ";
                deletemaxTime += T.stop();
            }
            delete Min_heap;
        }
        buildTime_average[i] = buildTime/5;
        deleteminTime_average[i] = deleteminTime/5;
        deletemaxTime_average[i] = deletemaxTime/5;
    }
    std::cout<<"Build:     ";
    for(int i=0; i<5; i++)
    {
        std::cout<<buildTime_average[i]<<" | ";
    }
    std::cout<<""<<std::endl;
    std::cout<<"deletemin: ";
    for(int i=0; i<5; i++)
    {
        std::cout<<deleteminTime_average[i]<<" | ";
    }
    std::cout<<""<<std::endl;
    std::cout<<"deletemax: ";
    for(int i=0; i<5; i++)
    {
        std::cout<<deletemaxTime_average[i]<<" | ";
    }
    std::cout<<""<<std::endl;
    delete[] buildTime_average;
    delete[] deleteminTime_average;
    delete[] deletemaxTime_average;
}
void Executive::Performance_Max_5()
{
        Timer T;

    double* buildTime_average = new double [5];
    double* deleteminTime_average = new double [5];
    double* deletemaxTime_average = new double [5];
    Max5_Heap<int>* Max_Heap;
    std::cout<<"                      Performance(Max-5 Heap)"<<std::endl;
    std::cout<<"         | 1,000,000 | 2,000,000 | 3,000,000 | 4,000,000 | 5,000,000 |"<<std::endl;
    for(int i=0; i<5; i++)
    {
        double buildTime = 0;
        double deleteminTime = 0;
        double deletemaxTime = 0;
        for(int j=1; j<=5; j++)
        {
            Max_Heap = new Max5_Heap<int>(array_size);
            srand(j);
            //build
            for(int k=0; k<(i+1)*m_m; k++)
            {
                int e = rand()%(5*m_m)+1;
                T.start();
                Max_Heap->insertWithoutsorted(e);
                buildTime += T.stop();
            }
            T.start();
            Max_Heap->buildheap();
            buildTime += T.stop();
            //deletemin
            for(int k=0; k<0.001*(i+1)*m_m; k++)
            //for(int k=0; k<10; k++)
            {
                T.start();
                Max_Heap->deletemin();
                //std::cout<<k<<", ";
                deleteminTime += T.stop();
            }
            //deletemax
            for(int k=0; k<0.001*(i+1)*m_m; k++)
            //for(int k=0; k<1; k++)
            {
                T.start();
                Max_Heap->deletemax();
                deletemaxTime += T.stop();
            }
            delete Max_Heap;
        }
        buildTime_average[i] = buildTime/5;
        deleteminTime_average[i] = deleteminTime/5;
        deletemaxTime_average[i] = deletemaxTime/5;
    }
    std::cout<<"Build:     ";
    for(int i=0; i<5; i++)
    {
        std::cout<<buildTime_average[i]<<" | ";
    }
    std::cout<<""<<std::endl;
    std::cout<<"deletemin: ";
    for(int i=0; i<5; i++)
    {
        std::cout<<deleteminTime_average[i]<<" | ";
    }
    std::cout<<""<<std::endl;
    std::cout<<"deletemax: ";
    for(int i=0; i<5; i++)
    {
        std::cout<<deletemaxTime_average[i]<<" | ";
    }
    std::cout<<""<<std::endl;
    delete[] buildTime_average;
    delete[] deleteminTime_average;
    delete[] deletemaxTime_average;
}
