#include <iostream>
#include <stack>
#include <time.h>


using namespace std;

template <typename N>
class Node {
    public:
    N value;
    Node<N> *left, *right;

    Node(N value, Node<N> *l = 0, Node<N> *r = 0){
        this->value = value;
        this->left = l;
        this->right = r;
    }
    void setLeft(Node<N> *l){
        this->left = l;
    }
    void setRight(Node<N> *r){
        this->right = r;
    }
    N getValue(){
        return this->value; 
    }
};
 

template <typename T>
class Tree{
    public:
    Node<T> *root;
    Tree(Node<T> *r){
        this->root = r;
    }

    Tree(){
        this->root = 0;
    }

    void startRPO(){
        cout<<"Recursivo pre-order: ";    
        clock_t t = clock();
        recursivePreOrder(this->root);
        t = clock()- t;
        cout<<"\n"<<"time : "<<t<<" milisegundos\n";

    }

    void recursivePreOrder(Node<T> *n){
        if(root==0){
           cout<<"vazio";
        }else{
            if(n!=0){
            cout<<n->getValue()<<" ";
            recursivePreOrder(n->left);
            recursivePreOrder(n->right);
            }
        }
    }


    void startIPO(){
        cout<<"Iterativo pre-order: ";
        clock_t t = clock();
        iterativePreOrder();
        t = clock()- t;
        cout<<"\n"<<"time : "<<t<<" milisegundos\n";

    }


    void iterativePreOrder(){
        stack<Node<T>*> pilha ;
        Node<T> *n = this->root;
        if(n != 0){
            pilha.push(n); 
            while(!pilha.empty()){
                n = pilha.top();
                pilha.pop();
                cout<<n->getValue()<<" ";
                if (n->right!=0) pilha.push(n->right);
                if (n->left!=0) pilha.push(n->left);
            }
        }else{
            cout<<"vazio ";
        }
        delete n;
    }


    void insertI(T n){
        Node<T> *p = this->root, *prev=0;
        while(p!=0){
            prev = p;
            if (n < p->getValue())
                p = prev->left;
            else
                p = prev->right;
        }
        if (root==0){
            this->root = new Node<T>(n);
        }else{
            if(n < prev->getValue()){
                prev->left = new Node<T>(n);
            }else{
                prev->right = new Node<T>(n);
            }
        }

    }


    void recursiveInsertion(T n, Node<T> *p, Node<T> *prev){
        //inserção
        if(p==0){
           if(n < prev->getValue()){
                prev->left = new Node<T>(n);
            }else{
                prev->right = new Node<T>(n);
            } 
        }    
        //recusão
        else{
             if(n < p->getValue()){
                recursiveInsertion(n, p->left, p);
            }else{
                recursiveInsertion(n, p->right, p);
            }
        }
    }

    
    void insertR(T n){
        if (this->root == 0){
            this->root = new Node<T>(n);
        }else{
            if(n < root->getValue()){
                recursiveInsertion(n, this->root->left, this->root);
            }else{
                recursiveInsertion(n, this->root->right, this->root);
            }
        }
    }

};


int main(){
    clock_t t;
    Tree<int> *t1 = new Tree<int>();
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
    

    
    delete t1;
    return 0;

}