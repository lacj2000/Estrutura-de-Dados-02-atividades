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

};


int main(){
    clock_t t;

    Node<char> *n1 = new Node<char>('f');
    Node<char> *n2 = new Node<char>('e');
    Node<char> *n3 = new Node<char>('d');
    Node<char> *n4 = new Node<char>('c', n2, n1);
    Node<char> *n5 = new Node<char>('b', NULL, n3);
    Node<char> *n6 = new Node<char>('a', n5, n4);
    Tree<char> *t1 = new Tree<char>(n6);

    t1->startRPO();
  
    t1->startIPO();
    

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete t1;
    return 0;

}