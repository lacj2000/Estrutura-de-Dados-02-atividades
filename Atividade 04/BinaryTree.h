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
    
};
 

template <typename T>
class BinaryTree{
    public:
    Node<T> *root;
    BinaryTree(Node<T> *r){
        this->root = r;
    }

    BinaryTree(){
        this->root = 0;
    }

    // pre ordem recursivo
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
                visit(n);
                recursivePreOrder(n->left);
                recursivePreOrder(n->right);
            }
        }
    }

    // pre ordem iterativo
    void startIPO(){
        cout<<"Iterativo pre-order: ";
        clock_t k = clock();
        iterativePreOrder();
        k = clock()- k;
        cout<<"\n"<<"time : "<<k<<" milisegundos\n";

    }


    void iterativePreOrder(){
        stack<Node<T>*> pilha ;
        Node<T> *n = this->root;
        if(n != 0){
            pilha.push(n); 
            while(!pilha.empty()){
                n = pilha.top();
                pilha.pop();
                cout<<n->value<<" ";
                if (n->right!=0) pilha.push(n->right);
                if (n->left!=0) pilha.push(n->left);
            }
        }else{
            cout<<"vazio ";
        }
        delete n;
    }

    // insercao iterativa
    void insertI(T n){
        Node<T> *p = this->root, *prev=0;
        while(p!=0){
            prev = p;
            if (n < p->value)
                p = prev->left;
            else
                p = prev->right;
        }
        if (root==0){
            this->root = new Node<T>(n);
        }else{
            if(n < prev->value){
                prev->left = new Node<T>(n);
            }else{
                prev->right = new Node<T>(n);
            }
        }

    }

    // inserção recursiva
    void recursiveInsertion(T n, Node<T> *p, Node<T> *prev){
        //inserção
        if(p==0){
           if(n < prev->value){
                prev->left = new Node<T>(n);
            }else{
                prev->right = new Node<T>(n);
            } 
        }    
        //recusão
        else{
             if(n < p->value){
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
            if(n < root->value){
                recursiveInsertion(n, this->root->left, this->root);
            }else{
                recursiveInsertion(n, this->root->right, this->root);
            }
        }
    }

    // exclusão
    void exclusion(T ex){
        cout<<"excluindo "<<ex<<": ";
        clock_t k = clock();
        //processamento
        Node<T> *p = this->root, *prev = 0, *br = 0;
        int lado;
        while(p!=0){
            if (p->value != ex) prev = p ;
            if (ex < p->value){ 
                p = p->left;
                lado = 0;
            }    
            else if (ex > p->value){
                p = p->right;
                lado = 1;
            }
            else if(p==0) {
                cout<<"Não existe!";
                break;
            }
            else if (ex == p->value){
                if (p->left!=0){
                    br = p->right;
                    if (lado==0){
                        prev->left = p->left;
                    }else if (lado==1){
                        prev->right = p->left;
                    } 
                    if(p->right != 0){
                        p = p->left;
                        //inserir esquerda
                        while (p!=0){
                            if (p != 0) prev = p;
                            if (ex < p->value){ 
                                p = p->left;
                                lado = 0;
                            }else{
                                p = p->right;
                                lado = 1;
                            }  
                        }
                        if (lado == 0 ) prev->left = br; 
                        else prev->right = br;


                    }
                }else if(p->right!= 0){
                    if (lado==0){
                        prev->left = p->right;
                    }else{
                        prev->right = p->right;
                    } 
                }else{
                    if (lado==0){
                        prev->left = 0;
                    }else{
                        prev->right = 0;
                    } 
                }
                break;
            } 
        }
        k = clock()- k;
        cout<<"\n"<<"time : "<<k<<" milisegundos\n";
    }

    void visit(Node<T> *n){
        cout<<n->value<<" ";
    }

};
