#include <iostream>
#include "BinaryTree.h"
#include "AlignedTree.h"


int main(){
    BinaryTree<int> *bt = new BinaryTree<int>();
    bt->insertR(10);
    bt->insertR(7);
    bt->insertR(15);
    bt->insertR(9);
    bt->insertR(8);
    bt->insertR(11);
    bt->insertR(1);
    // pre order recursivo
    bt->startRPO();
    // pre order iterativo
    bt->startIPO();

    AlignedTree<int> *at = new AlignedTree<int>();
    
    at->insert(10);
    at->insert(7);
    at->insert(15);
    at->insert(9);
    at->insert(8);
    at->insert(11);
    at->insert(1);
    
    at->preOrder();
    at->preOrder2();
    
    bt->exclusion(7);

    delete bt;
    delete at;
    return 0;
}