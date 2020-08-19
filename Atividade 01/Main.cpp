#include<iostream>

using namespace std;

template <typename T>
class Node {
    public:
    T value;
    Node<T> *left, *right;

    Node(T value, Node<T> *l = 0, Node<T> *r = 0){
        this->value = value;
        this->left = l;
        this->right = r;
    }
    void setLeft(Node<T> *l){
        this->left = l;
    }
    void setRight(Node<T> *r){
        this->right = r;
    }
    T getValue(){
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

    //Questão 2 -  funções 
    void printTreeRootLeftRight(Node<T> *n){
        if(root==0){
           cout<<"Vazio\n";
        }else{
            cout<<"<";
            if(n!=0){
            cout<<n->getValue();
            printTreeRootLeftRight(n->left);
            printTreeRootLeftRight(n->right);
            }
            cout<<">";
        }
    }
    

    void printTreeLeftRightRoot(Node<T> *n){
        if(root==0){
           cout<<"Vazio\n";
        }else{
            cout<<"<";
            if(n!=0){
            printTreeLeftRightRoot(n->left);
            printTreeLeftRightRoot(n->right);
            cout<<n->getValue();
            }
            cout<<">";
        }
    }
    
    
    void printTreeLeftRootRight(Node<T> *n){
        if(root==0){
           cout<<"Vazio\n";
        }else{
            cout<<"<";
            if(n!=0){
            printTreeLeftRootRight(n->left);
            cout<<n->getValue();
            printTreeLeftRootRight(n->right);
            }
            cout<<">";
        }
    }

    void printTree(Node<T> *n){
        if(root==0){
           cout<<"Vazio\n";
        }else{
            if(n!=0){
            cout<<"<";
            printTree(n->left);
            cout<<n->getValue();
            printTree(n->right);
            cout<<">";
            }
        }
    }

    
    void insertWithout(T n){
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

    void insertWith(T n){
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
    Node<char> *n1 = new Node<char>('f');
    Node<char> *n2 = new Node<char>('e');
    Node<char> *n3 = new Node<char>('d');
    Node<char> *n4 = new Node<char>('c', n2, n1);
    Node<char> *n5 = new Node<char>('b', NULL, n3);
    Node<char> *n6 = new Node<char>('a', n5, n4);
    Tree<char> *t1 = new Tree<char>(n6);
    t1->printTreeRootLeftRight(t1->root);
    cout<<"\n";
    t1->printTreeLeftRightRoot(t1->root);
    cout<<"\n";
    t1->printTreeLeftRootRight(t1->root);
    cout<<"\n";

    Tree<int> *t2 = new Tree<int>();
    t2->insertWith(10);
    t2->insertWith(5);
    t2->insertWith(12);
    t2->insertWith(15);
    t2->insertWith(3);
    t2->insertWith(7);
    t2->printTree(t2->root);
    cout<<"\n";

    Tree<int> *t3 = new Tree<int>();
    t3->insertWithout(10);
    t3->insertWithout(5);
    t3->insertWithout(12);
    t3->insertWithout(15);
    t3->insertWithout(3);
    t3->insertWithout(7);
    t3->printTree(t3->root);
    cout<<"\n";
    return 0;
}
