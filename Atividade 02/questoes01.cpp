#include <iostream>

using namespace std;
//pilha
template<typename I>
class Item{
    public:
        I item;
        Item *proximo;   
    Item(I i = 0, Item * n = 0){
        this->item = i;
        this->proximo = n;
    }
    I getItem(){
        return this->item;
    }
};

template<typename P>
class Pilha{
    public:
        Item<P> *topo;
        int tamanho = 0;

        Pilha(P i){
            this->topo = new Item<P>(i);
            tamanho = 1;
        }
        void empilhar(P n){
            this->topo=new Item<P>(n,this->topo);
            tamanho++;
        }
        bool pilhaVazia(){
            return this->tamanho == 0;
        }

        P desempilhar(){
            Item<P> desempilhado;        
            if (!pilhaVazia()){
                desempilhado = *this->topo;
                this->topo = desempilhado.proximo;
                tamanho--;
                return desempilhado.getItem();
            }
            return 0;
        }
};


//arvore
template<typename N>
class No{
    public:
        No<N> *esq, *dir;
        N valor;

        No(N v, No *e = 0, No *d = 0){
            this->esq = e;
            this->valor = v;
            this->dir = d;
        }
        N getValor(){
            return this->valor;
        }
};
template<typename A>
class Arvore{
    public:
        No<A> *raiz;


        Arvore(No<A> *r){
            this->raiz = r;
        }


        Arvore(){
            this->raiz = 0;
        }

        /*
        void pilha(){
            Pilha<A> *pilha1 = new Pilha<A>(10);
            pilha1->empilhar(15);
            cout<<pilha1->desempilhar()<<"\n";
            cout<<pilha1->desempilhar()<<"\n";
            delete pilha1; 
        }
        */
        
        //recursivo erd
        void iniciarIterativoErd(){
            cout<<"Iterativo ERD:";
            iterativoERD();
            cout<<"\n";
        }



        void iterativoERD(){
            Pilha<No<A>*> *pilha = new Pilha<No<A>*>(this->raiz);
            No<A> *n;
            while (!pilha->pilhaVazia()){
                n = pilha->desempilhar();
                if(n->esq!=0){
                    pilha->empilhar(n);
                    pilha->empilhar(n->esq);
                }else{
                    //imprimindo esq
                    cout<<n->getValor()<<" ";
                    //imprimindo centro/raiz
                    n = pilha->desempilhar();
                    cout<<n->getValor()<<" ";
                    //adicionando a dir. a árvore
                    if(n->dir!=0){
                        n = n->dir;
                        pilha->empilhar(n);
                        /*
                            cout<<n->getValor()<<" ";
                        */
                    }
                }
            }
            delete pilha;
            delete n;
        }

        //recursivo erd
        void iniciarRecursivoErd(){
            cout<<"Recursivo ERD:";
            recursivoERD(this->raiz);
            cout<<"\n";
        }


        void recursivoERD(No<A> *n){
            if(this->raiz==0){
            cout<<"Vazio\n";
            }else{
                if(n!=0){
                cout<<"<";
                recursivoERD(n->esq);
                cout<<n->getValor();
                recursivoERD(n->dir);
                cout<<">";
                }
            }
        }
};




int main(){
    cout<<"teste\n";
    No<char> *n1 = new No<char>('c');
    No<char> *n2 = new No<char>('f');
    No<char> *n3 = new No<char>('d',n1,n2);
    No<char> *n4 = new No<char>('a');
    No<char> *n5 = new No<char>('b', n4, n3);
    Arvore<char> *a1 = new Arvore<char>(n5);
    a1->iniciarRecursivoErd();
    a1->iniciarIterativoErd();
    delete n1;   
    delete n2;   
    delete n3;   
    delete n4;   
    delete n5;   
    delete a1;   
    return 0;
}