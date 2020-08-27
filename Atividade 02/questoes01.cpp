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
        
        Pilha(){
            this->topo = 0;
            tamanho = 0;
        }


        void empilhar(P z){
            this->topo=new Item<P>(z,this->topo);
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

        //iterativo ERD
        void iniciarIterativoERD(){
            cout<<"Iterativo ERD:";
            iterativoERD();
            cout<<"\n";
        }



        void iterativoERD(){
            Pilha<No<A>*> *pilha = new Pilha<No<A>*>();
            No<A> *n = this->raiz;

            while(n!=0){
                while (n!=0){
                    if(n->dir!=0) pilha->empilhar(n->dir); // guarda a direita 
                    pilha -> empilhar(n); // empilha o centro
                    n = n->esq;
                }
                n = pilha->desempilhar();
                while(!pilha->pilhaVazia() && n->dir==0){
                    cout<<n->getValor()<<" ";
                    n = pilha->desempilhar();
                }
                cout<<n->getValor()<<" ";
                if (!pilha->pilhaVazia()){
                    n = pilha->desempilhar();
                }else{
                    n = 0;
                }

            }
            delete pilha;
            delete n;
        }


        //iterativo EDR
        void iniciarIterativoEDR(){
            cout<<"Iterativo EDR:";
            iterativoEDR();
            cout<<"\n";
        }



        void iterativoEDR(){
            Pilha<No<A>*> *pilha = new Pilha<No<A>*>();
            No<A> *n = this->raiz, *g = this->raiz;
        
            while(n!=0){
                for (;n->esq!=0;n = n->esq){
                    pilha->empilhar(n);
                }
                while(n->dir == 0 || n->dir == g ){
                    cout<<n->getValor()<<" ";
                    g = n;
                    if(pilha->pilhaVazia()) return;
                    n = pilha->desempilhar(); 
                }

                pilha->empilhar(n);
                n = n->dir;
            }
            delete pilha;
            delete n;
            delete g;
        }


        //iterativo RED
        void iniciarIterativoRED(){
            cout<<"Iterativo RED:";
            iterativoRED();
            cout<<"\n";
        }



        void iterativoRED(){
            Pilha<No<A>*> *pilha = new Pilha<No<A>*>();
            No<A> *n = this->raiz;
            //int d = 0;
            if(n != 0){
                pilha->empilhar(n);
               
                while(!pilha->pilhaVazia()){
                    n = pilha->desempilhar();
                    cout<<n->getValor()<<" ";
                    if (n->dir!=0) pilha->empilhar(n->dir);
                    if (n->esq!=0) pilha->empilhar(n->esq);
                    //if (d==900) cout<<"exit";
                    //if (d++==1000) break;
                }
            }
            delete pilha;
            delete n;
        }



        //recursivo erd
        void iniciarRecursivoERD(){
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


        //recursivo RED
        void iniciarRecursivoRED(){
            cout<<"Recursivo RED:";
            recursivoRED(this->raiz);
            cout<<"\n";
        }


        void recursivoRED(No<A> *n){
            if(this->raiz==0){
            cout<<"Vazio\n";
            }else{
                if(n!=0){
                cout<<"<";
                cout<<n->getValor();
                recursivoRED(n->esq);
                recursivoRED(n->dir);
                cout<<">";
                }
            }
        }
        
        //recursivo EDR
        void iniciarRecursivoEDR(){
            cout<<"Recursivo EDR:";
            recursivoEDR(this->raiz);
            cout<<"\n";
        }


        void recursivoEDR(No<A> *n){
            if(this->raiz==0){
            cout<<"Vazio\n";
            }else{
                if(n!=0){
                cout<<"<";
                recursivoEDR(n->esq);
                recursivoEDR(n->dir);
                cout<<n->getValor();
                cout<<">";
                }
            }
        }
                
};




int main(){
    cout<<" Questão 01\n";
    No<char> *n1 = new No<char>('c');
    No<char> *n2 = new No<char>('f');
    No<char> *n3 = new No<char>('d',n1,n2);
    No<char> *n0 = new No<char>('k');
    No<char> *n4 = new No<char>('a',NULL,n0);
    No<char> *n5 = new No<char>('b', n4, n3);
    Arvore<char> *a1 = new Arvore<char>(n5);
    /*
    */
    a1->iniciarRecursivoERD();
    a1->iniciarIterativoERD();
    a1->iniciarRecursivoEDR();
    a1->iniciarIterativoEDR();
    a1->iniciarRecursivoRED();
    a1->iniciarIterativoRED();
    /*
    */
    delete n1;   
    delete n2;   
    delete n3;   
    delete n0;   
    delete n4;   
    delete n5;   
    delete a1;   
    return 0;
}