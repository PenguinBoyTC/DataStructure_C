#include "Executive.h"
#include "QuadraticProbing.h"
#include "DoubleHashing.h"
#include "HashTable.h"
#include "Timer.cpp"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

Executive::Executive()
{
    m = 0;
    k = 0;
    p = 0;
}
Executive::~Executive()//distructor
{
}
void Executive::run()//run method
{
	int choose =1;
    while(choose<3)
    {
        //User menu
        std::cout<<"............................................................................"<< std::endl;
        std::cout<<"Please choose one of the following commands:"<< std::endl;
        std::cout<<"1-Test HashTables"<< std::endl;
        std::cout<<"2-Performance Comparison"<< std::endl;
        std::cout<<"3-Exit"<< std::endl;
        std::cin>>choose;
        if(choose==1)
        {
            Test_HashTable();
        }
        else if(choose==2)
        {
            std::cout<<"============================================================================="<< std::endl;
            std::cout<<"n=100000"<<std::endl;
            Performance_Comparison(100000);
            std::cout<<"============================================================================="<< std::endl;
            std::cout<<"n=200000"<<std::endl;
            Performance_Comparison(200000);
            std::cout<<"============================================================================="<< std::endl;
            std::cout<<"n=300000"<<std::endl;
            Performance_Comparison(300000);
            std::cout<<"============================================================================="<< std::endl;
            std::cout<<"n=400000"<<std::endl;
            Performance_Comparison(400000);
            std::cout<<"============================================================================="<< std::endl;
            std::cout<<"n=500000"<<std::endl;
            Performance_Comparison(500000);
        }
    }
    std::cout<<"Thanks !"<<std::endl;
    std::cout<<"Bye."<<std::endl;
}
//insert method to add number.
void Executive::Test_HashTable()
{
    std::cout<<"what is the table size?"<<std::endl;
    
    std::cin>>m;
    k = 4;
    p = 5;
    HashTable<int>* OH = new HashTable<int>(m);
    QuadraticProbing<int>* QP = new QuadraticProbing<int>(m, k);
    DoubleHashing<int>* DH = new DoubleHashing<int>(m, k, p);
    std::string filename;
    filename = "data.txt";

    std::ifstream inp;
    inp.open(filename);//open the data.txt file
    int number;//use to read the number
    while(!inp.eof())
    {
        inp>>number;
        OH->Insert(number);
        QP->Insert(number);//add number to the Hash Table
        DH->Insert(number);
    }
    inp.close();//close the data.txt file
    std::cout<<"Open Hashing:"<<std::endl;
    OH->Print();
    std::cout<<""<<std::endl;
    std::cout<<"Hash Table with Quadratic Probing:"<<std::endl;
    QP->Print();
    std::cout<<""<<std::endl;
    std::cout<<"Hash Table with Double Hashing:"<<std::endl;
    DH->Print();
    std::cout<<""<<std::endl;
    delete OH;
    delete QP;
    delete DH;
}
void Executive::Performance_Comparison(int size)
{
    p = 997;
    k = 20;
    m = 1000003;
    Timer T;
    double OH_insert = 0;
    double QP_insert = 0;
    double DH_insert = 0;
    double OH_find = 0;
    double QP_find = 0;
    double DH_find = 0;
    double OH_unfind = 0;
    double QP_unfind = 0;
    double DH_unfind = 0;

    double OH_insert_average = 0;
    double QP_insert_average = 0;
    double DH_insert_average = 0;

    double OH_find_average = 0;
    double QP_find_average = 0;
    double DH_find_average = 0;

    double OH_unfind_average = 0;
    double QP_unfind_average = 0;
    double DH_unfind_average = 0;

//start seed = 1
    std::cout<<"Seed = 1:"<<std::endl;
    HashTable<int>* OH = new HashTable<int>(m);
    QuadraticProbing<int>* QP = new QuadraticProbing<int>(m, k);
    DoubleHashing<int>* DH = new DoubleHashing<int>(m, k, p);
    srand(1);
    //Open Hashing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        OH->Insert(e);
    }
    OH_insert = T.stop();
    std::cout<<"OH-insert: "<<OH_insert<<"  ";
    OH_insert_average = OH_insert;
        //search time
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(OH->Find(e))
        {
            OH_find = OH_find + T.stop();
        }
        else
        {
            OH_unfind = OH_unfind + T.stop();
        }
    }
    std::cout<<"OH-Found: "<<OH_find<<"  ";
    std::cout<<"OH-Not Found: "<<OH_unfind<<std::endl;
    OH_find_average = OH_find;
    OH_unfind_average = OH_unfind;
    delete OH;
    //QuadraticProbing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        QP->Insert(e);
    }
    QP_insert = T.stop();
    std::cout<<"QP-insert: "<<QP_insert<<"  ";
    QP_insert_average = QP_insert;
        //search time
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(QP->Find(e))
        {
            QP_find = QP_find + T.stop();
        }
        else
        {
            QP_unfind = QP_unfind + T.stop();
        }
    }
    std::cout<<"QP-Found: "<<QP_find<<"  ";
    std::cout<<"QP-Not Found: "<<QP_unfind<<std::endl;
    QP_find_average = QP_find;
    QP_unfind_average = QP_unfind;
    delete QP;
    //Double Hashing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        DH->Insert(e);
    }
    DH_insert = T.stop();
    std::cout<<"DH-insert: "<<DH_insert<<"  ";
    DH_insert_average = DH_insert;
        //search time
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(DH->Find(e))
        {
            DH_find = DH_find + T.stop();
        }
        else
        {
            DH_unfind = DH_unfind + T.stop();
        }
    }
    std::cout<<"DH-Found: "<<DH_find<<"  ";
    std::cout<<"DH-Not Found: "<<DH_unfind<<std::endl;
    DH_find_average = DH_find;
    DH_unfind_average = DH_unfind;
    delete DH;
//end seed = 1
//start seed = 2
    std::cout<<"Seed = 2:"<<std::endl;
    OH = new HashTable<int>(m);
    QP = new QuadraticProbing<int>(m, k);
    DH = new DoubleHashing<int>(m, k, p);
    
    srand(2);
    //Open Hashing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        OH->Insert(e);
    }
    OH_insert = T.stop();
    std::cout<<"OH-insert: "<<OH_insert<<"  ";
    OH_insert_average = OH_insert_average + OH_insert;
        //search time
    OH_find = 0;
    OH_unfind = 0;
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(OH->Find(e))
        {
            OH_find = OH_find + T.stop();
        }
        else
        {
            OH_unfind = OH_unfind + T.stop();
        }
    }
    std::cout<<"OH-Found: "<<OH_find<<"  ";
    std::cout<<"OH-Not Found: "<<OH_unfind<<std::endl;
    OH_find_average = OH_find_average + OH_find;
    OH_unfind_average = OH_unfind_average + OH_unfind;
    delete OH;
    //QuadraticProbing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        QP->Insert(e);
    }
    QP_insert = T.stop();
    std::cout<<"QP-insert: "<<QP_insert<<"  ";
    QP_insert_average = QP_insert_average + QP_insert;
        //search time
    QP_find = 0;
    QP_unfind = 0;
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(QP->Find(e))
        {
            QP_find = QP_find + T.stop();
        }
        else
        {
            QP_unfind = QP_unfind + T.stop();
        }
    }
    std::cout<<"QP-Found: "<<QP_find<<"  ";
    std::cout<<"QP-Not Found: "<<QP_unfind<<std::endl;
    QP_find_average = QP_find_average + QP_find;
    QP_unfind_average = QP_unfind_average + QP_unfind;
    delete QP;
    //Double Hashing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        DH->Insert(e);
    }
    DH_insert = T.stop();
    std::cout<<"DH-insert: "<<DH_insert<<"  ";
    DH_insert_average = DH_insert_average + DH_insert;
        //search time
    DH_find = 0;
    DH_unfind = 0;
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(DH->Find(e))
        {
            DH_find = DH_find + T.stop();
        }
        else
        {
            DH_unfind = DH_unfind + T.stop();
        }
    }
    std::cout<<"DH-Found: "<<DH_find<<"  ";
    std::cout<<"DH-Not Found: "<<DH_unfind<<std::endl;
    DH_find_average = DH_find_average + DH_find;
    DH_unfind_average = DH_unfind_average + DH_unfind;
    delete DH;
//end seed = 2
//start seed = 3
    std::cout<<"Seed = 3:"<<std::endl;
    OH = new HashTable<int>(m);
    QP = new QuadraticProbing<int>(m, k);
    DH = new DoubleHashing<int>(m, k, p);
    
    srand(3);
    //Open Hashing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        OH->Insert(e);
    }
    OH_insert = T.stop();
    std::cout<<"OH-insert: "<<OH_insert<<"  ";
    OH_insert_average = OH_insert_average + OH_insert;
        //search time
    OH_find = 0;
    OH_unfind = 0;
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(OH->Find(e))
        {
            OH_find = OH_find + T.stop();
        }
        else
        {
            OH_unfind = OH_unfind + T.stop();
        }
    }
    std::cout<<"OH-Found: "<<OH_find<<"  ";
    std::cout<<"OH-Not Found: "<<OH_unfind<<std::endl;
    OH_find_average = OH_find_average + OH_find;
    OH_unfind_average = OH_unfind_average + OH_unfind;
    delete OH;
    //QuadraticProbing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        QP->Insert(e);
    }
    QP_insert = T.stop();
    std::cout<<"QP-insert: "<<QP_insert<<"  ";
    QP_insert_average = QP_insert_average + QP_insert;
        //search time
    QP_find = 0;
    QP_unfind = 0;
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(QP->Find(e))
        {
            QP_find = QP_find + T.stop();
        }
        else
        {
            QP_unfind = QP_unfind + T.stop();
        }
    }
    std::cout<<"QP-Found: "<<QP_find<<"  ";
    std::cout<<"QP-Not Found: "<<QP_unfind<<std::endl;
    QP_find_average = QP_find_average + QP_find;
    QP_unfind_average = QP_unfind_average + QP_unfind;
    delete QP;
    //Double Hashing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        DH->Insert(e);
    }
    DH_insert = T.stop();
    std::cout<<"DH-insert: "<<DH_insert<<"  ";
    DH_insert_average = DH_insert_average + DH_insert;
        //search time
    DH_find = 0;
    DH_unfind = 0;
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(DH->Find(e))
        {
            DH_find = DH_find + T.stop();
        }
        else
        {
            DH_unfind = DH_unfind + T.stop();
        }
    }
    std::cout<<"DH-Found: "<<DH_find<<"  ";
    std::cout<<"DH-Not Found: "<<DH_unfind<<std::endl;
    DH_find_average = DH_find_average + DH_find;
    DH_unfind_average = DH_unfind_average + DH_unfind;
    delete DH;
//end seed = 3
//start seed = 4
    std::cout<<"Seed = 4:"<<std::endl;
    OH = new HashTable<int>(m);
    QP = new QuadraticProbing<int>(m, k);
    DH = new DoubleHashing<int>(m, k, p);
    
    srand(4);
    //Open Hashing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        OH->Insert(e);
    }
    OH_insert = T.stop();
    std::cout<<"OH-insert: "<<OH_insert<<"  ";
    OH_insert_average = OH_insert_average + OH_insert;
        //search time
    OH_find = 0;
    OH_unfind = 0;
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(OH->Find(e))
        {
            OH_find = OH_find + T.stop();
        }
        else
        {
            OH_unfind = OH_unfind + T.stop();
        }
    }
    std::cout<<"OH-Found: "<<OH_find<<"  ";
    std::cout<<"OH-Not Found: "<<OH_unfind<<std::endl;
    OH_find_average = OH_find_average + OH_find;
    OH_unfind_average = OH_unfind_average + OH_unfind;
    delete OH;
    //QuadraticProbing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        QP->Insert(e);
    }
    QP_insert = T.stop();
    std::cout<<"QP-insert: "<<QP_insert<<"  ";
    QP_insert_average = QP_insert_average + QP_insert;
        //search time
    QP_find = 0;
    QP_unfind = 0;
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(QP->Find(e))
        {
            QP_find = QP_find + T.stop();
        }
        else
        {
            QP_unfind = QP_unfind + T.stop();
        }
    }
    std::cout<<"QP-Found: "<<QP_find<<"  ";
    std::cout<<"QP-Not Found: "<<QP_unfind<<std::endl;
    QP_find_average = QP_find_average + QP_find;
    QP_unfind_average = QP_unfind_average + QP_unfind;
    delete QP;
    //Double Hashing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        DH->Insert(e);
    }
    DH_insert = T.stop();
    std::cout<<"DH-insert: "<<DH_insert<<"  ";
    DH_insert_average = DH_insert_average + DH_insert;
        //search time
    DH_find = 0;
    DH_unfind = 0;
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(DH->Find(e))
        {
            DH_find = DH_find + T.stop();
        }
        else
        {
            DH_unfind = DH_unfind + T.stop();
        }
    }
    std::cout<<"DH-Found: "<<DH_find<<"  ";
    std::cout<<"DH-Not Found: "<<DH_unfind<<std::endl;
    DH_find_average = DH_find_average + DH_find;
    DH_unfind_average = DH_unfind_average + DH_unfind;
    delete DH;
//end seed = 4
//start seed = 5
    std::cout<<"Seed = 5:"<<std::endl;
    OH = new HashTable<int>(m);
    QP = new QuadraticProbing<int>(m, k);
    DH = new DoubleHashing<int>(m, k, p);
    
    srand(5);
    //Open Hashing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        OH->Insert(e);
    }
    OH_insert = T.stop();
    std::cout<<"OH-insert: "<<OH_insert<<"  ";
    OH_insert_average = OH_insert_average + OH_insert;
        //search time
    OH_find = 0;
    OH_unfind = 0;
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(OH->Find(e))
        {
            OH_find = OH_find + T.stop();
        }
        else
        {
            OH_unfind = OH_unfind + T.stop();
        }
    }
    std::cout<<"OH-Found: "<<OH_find<<"  ";
    std::cout<<"OH-Not Found: "<<OH_unfind<<std::endl;
    OH_find_average = OH_find_average + OH_find;
    OH_unfind_average = OH_unfind_average + OH_unfind;
    delete OH;
    //QuadraticProbing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        QP->Insert(e);
    }
    QP_insert = T.stop();
    std::cout<<"QP-insert: "<<QP_insert<<"  ";
    QP_insert_average = QP_insert_average + QP_insert;
        //search time
    QP_find = 0;
    QP_unfind = 0;
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(QP->Find(e))
        {
            QP_find = QP_find + T.stop();
        }
        else
        {
            QP_unfind = QP_unfind + T.stop();
        }
    }
    std::cout<<"QP-Found: "<<QP_find<<"  ";
    std::cout<<"QP-Not Found: "<<QP_unfind<<std::endl;
    QP_find_average = QP_find_average + QP_find;
    QP_unfind_average = QP_unfind_average + QP_unfind;
    delete QP;
    //Double Hashing
        //insert time
    T.start();
    for(int i = 0; i<size; i++)
    {
        int e = rand()%(5*m)+1;
        DH->Insert(e);
    }
    DH_insert = T.stop();
    std::cout<<"DH-insert: "<<DH_insert<<"  ";
    DH_insert_average = DH_insert_average + DH_insert;
        //search time
    DH_find = 0;
    DH_unfind = 0;
    for(int i = 0; i<(size/10); i++)
    {
        int e = rand()%(5*m)+1;
        T.start();
        if(DH->Find(e))
        {
            DH_find = DH_find + T.stop();
        }
        else
        {
            DH_unfind = DH_unfind + T.stop();
        }
    }
    std::cout<<"DH-Found: "<<DH_find<<"  ";
    std::cout<<"DH-Not Found: "<<DH_unfind<<std::endl;
    DH_find_average = DH_find_average + DH_find;
    DH_unfind_average = DH_unfind_average + DH_unfind;
    delete DH;
//end seed = 5
    std::cout<<"---------------------------------------------------------------------"<< std::endl;
    OH_insert_average = OH_insert_average/5;
    QP_insert_average = QP_insert_average/5;
    DH_insert_average = DH_insert_average/5;

    OH_find_average = OH_find_average/5;
    QP_find_average = QP_find_average/5;
    DH_find_average = DH_find_average/5;

    OH_unfind_average = OH_unfind_average/5;
    QP_unfind_average = QP_unfind_average/5;
    DH_unfind_average = DH_unfind_average/5;
    std::cout<<"<<<<<<<<<<<< Result For n = "<<size<<" >>>>>>>>>>>>>"<<std::endl;
    std::cout<<"OH Insert average: "<<OH_insert_average<<"; Found average: "<<OH_find_average<<"; Not Found: "<<OH_unfind_average<<std::endl;
    std::cout<<"QP Insert average: "<<QP_insert_average<<"; Found average: "<<QP_find_average<<"; Not Found: "<<QP_unfind_average<<std::endl;
    std::cout<<"DH Insert average: "<<DH_insert_average<<"; Found average: "<<DH_find_average<<"; Not Found: "<<DH_unfind_average<<std::endl;
    std::cout<<"---------------------------------------------------------------------"<< std::endl;
}


