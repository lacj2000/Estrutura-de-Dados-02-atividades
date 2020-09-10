#include <iostream>
#include <stack>
#include <time.h>

using namespace std;

template <typename NT>
class NodeA{
    public: 
        NT value;
        NodeA<NT> *left, *right;
        int successor;

        NodeA(){
            this->left = 0;
            this->right = 0;
            this->successor = 0;
        }


        NodeA(NT v,NodeA<NT> *l=0, NodeA<NT> *r = 0, int s = 0){
            this->value = v;
            this->left = l;
            this->right = r;
            this->successor = s;        
        }

        NT getValue(){
            return this->value;
        }

        bool hasSuccessor(){
            return this->successor == 1;
        }
        
};

template <typename NT>
class AlignedTree{
    public:
        NodeA<NT> *root;

        AlignedTree(NodeA<NT> *r = 0){
            this->root = r;
        }


};