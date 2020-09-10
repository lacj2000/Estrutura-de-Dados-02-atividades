#include <iostream>
#include <stack>
#include <time.h>
#include "BinaryTree.h"
#include "AlignedTree.h"

using namespace std;

int main(){
    BinaryTree<int> *t1 = new BinaryTree<int>();
    //inserts
    t1->insertI(14);
    t1->insertI(15);
    t1->insertI(16);
    t1->insertI(17);
    t1->insertI(18);
    t1->insertI(19);
    t1->insertI(20);
    t1->insertI(21);
    t1->insertI(22);
    t1->insertI(23);
    t1->insertI(24);
    t1->insertI(25);
    t1->insertI(26);
    t1->insertI(27);
    t1->insertI(28);
    t1->insertI(29);
    t1->insertI(30);
    t1->insertI(1);
    t1->insertI(2);
    t1->insertI(3);
    t1->insertI(4);
    t1->insertI(5);
    t1->insertI(6);
    t1->insertI(7);
    t1->insertI(8);
    t1->insertI(9);
    t1->insertI(10);
    t1->insertI(11);
    t1->insertI(12);
    t1->insertI(13);

    t1->startRPO();
  
    t1->startIPO();
    
    /*
    
    AlignedTree<int> *t2 = new AlignedTree<int>();

    t2->insertIn(10);
    t2->insertIn(11);
    t2->preOrder();
    delete t2;
    /*/ 
    delete t1;
    
}