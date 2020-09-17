#include <iostream>
#include <time.h>

using namespace std;

template <typename N>
class NodeAligned {
    public:
    N value;
    NodeAligned<N> *left, *right;
    int successor = 0;

    NodeAligned(N value, NodeAligned<N> *l = 0, NodeAligned<N> *r = 0, int s = 0){
        this->value = value;
        this->left = l;
        this->right = r;
        this->successor = s;
    }
    
};


template <typename T>
class AlignedTree{
    public:
    NodeAligned<T> *root;
    AlignedTree(NodeAligned<T> *r){this->root = r;}
    AlignedTree(){this->root = 0;}
    bool isEmpty(){return (this->root==0);}
   
    void insert(T element){
        if(this->isEmpty())
            this->root = new NodeAligned<T>(element);         
        else{
            NodeAligned<T> *p = this->root, *prev = 0; 
            while(p!=0){
                prev = p;
                if(p->value > element) 
                    p = p->left;
                else if (p->successor == 0)
                    p = p->right;
                else break;
            }
            if(prev->value > element){
                prev->left = new NodeAligned<T>(element,NULL,prev, 1);
            }else if(prev->successor==1){
                prev->successor = 0;
                prev->right = new NodeAligned<T>(element,NULL,prev->right,1);
            }else prev->right = new NodeAligned<T>(element);
        }
    }

    void preOrder(){
        cout<<"Árvore-Alinhada pre-order: ";    
        clock_t t = clock();
        //processamento
        stack<NodeAligned<T>*> auxStack ;
        NodeAligned<T> *p = this->root;
        while(p!=0){
            this->visit(p);
            if (p->successor==0){
                auxStack.push(p);
            }
            if (p->left!=0){
                p = p->left;
            }else if (p->successor == 1){
                p = auxStack.top()->right;
                auxStack.pop();
            }else break;
        }        
        t = clock()- t;
        cout<<"\n"<<"time : "<<t<<" milisegundos\n";
    }


    void visit(NodeAligned<T> *n){
        cout<<n->value<<" ";
    }


};