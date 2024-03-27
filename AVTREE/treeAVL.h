
#include <iostream>
using namespace std;

class node{
    private:
        node* lft;
        node* rght;
        int absoluto;
    public:
    node(int absl){
        absoluto = absl;
        lft = rght = NULL;
    }
    int   getabsoluto(){
        return absoluto;
    }
    node* getLft(){
        return lft;
    }
    node* getRght(){
        return rght;
    }
    void  setLft(node *no){
        lft = no;
    }
    void  setRght(node* no){
        rght = no;
    }



};

class Tree{
    private:
        node* raiz;
    public:
     ~Tree(){
    };
    Tree(){
        raiz = NULL;
    };
    void BalanceiaAVL   (node *root);
    void inordem        (node *NO);
    void insere         (int abslt);
    void removee        (int abslt);
    void preordem       (node *NO);
    void posordem       (node *NO);
   node* returnaNovo    ( node* root, int chave){
    if (root!=NULL){
        if (root->getabsoluto() == chave){
            return root; 
        }else{
             returnaNovo(root->getLft(), chave);
                returnaNovo(root->getRght(), chave);
        }   
    }   

   }; 
    void inserirAux     (node *NO, int yearday);
    int altura(node *root){
        if(!root){
            return -1;
        }
        int esq, dir;
        esq = altura(root->getLft());
        dir = altura(root->getRght());
        if (esq>dir){
            return esq + 1;
        }else{
            return 1+ dir;
        }
    }
    int FatorBalanceamento(node* root){
    
        return altura(root->getLft()) - altura(root->getRght()); 
    }

    node* rotacionarLL(node *p){
        node* temp = p;
        node* esq  = temp->getLft();
        temp->setLft(esq->getRght());
        esq->setRght(temp) ;
        return esq;
    }

    node* rotacionarRR (node *p){
        node* temp = p;
        node* dir  = temp->getRght();
        temp->setRght(dir->getLft());
        dir->setLft(temp);
        return dir;
    }

     node* rotacionarLR(node *p){
        node* temp = p;
        node* esq = temp->getLft();
        temp->setLft(esq->getRght())  ;
        esq->setRght(temp->getLft()->getLft())  ;
        temp->getLft()->setLft(esq) ;

        return rotacionarLL(temp);
    }

    node* rotacionarRL(node *p){
      node* temp = p;
      node* dir = temp->getRght();
      temp->setRght(dir->getLft())  ;
      dir->setLft(temp->getRght()->getRght())  ;
      temp->getRght()->setRght(dir);
      return rotacionarRR(temp);
    }
    node* getRaiz(){
        return raiz;
    }
    void  setRaiz(node* root){
       raiz = root;
    }

node* verraiz(node *root , node* procurado){
    if(root!= NULL){
        if(root->getLft() == procurado || root->getRght() == procurado){
            return root;
        }else {
            verraiz(root->getLft() , procurado);
            verraiz(root->getRght(), procurado);
        }
    }else if (procurado == root){
        return raiz;
    }
    }    
};

void Tree::BalanceiaAVL(node *root){
    node* PivoRoot;
    if (root != raiz){
        PivoRoot = verraiz(raiz, root);
    }int fatB=FatorBalanceamento(root);
    cout<<"fator balanceamento do chave ("<<root->getabsoluto()<<"):" <<fatB<<endl;
    if(fatB != 1 && fatB != -1 && fatB != 0 ){        
        if (altura(root->getLft()) > altura(root->getRght()) ){                        /*sub arvore da esquerda > sub arvore da direita*/    
            if(altura(root->getLft()->getLft())  >  altura(root->getLft()->getRght())){  /*descobrindo se é LL ou LR*/
             
                if(root == raiz){
                    cout<<"rotacao LL";
                    raiz = rotacionarLL(root);    
                }
                else if(PivoRoot->getLft()==root){
                    cout<<"rotacao LL";
                    PivoRoot->setLft(rotacionarLL(root)); 
                }else if(PivoRoot->getRght()==root){
                    cout<<"rotacaoLL";
                    PivoRoot->setRght(rotacionarLL(root)); 
                }     
            }else if(altura(root->getLft()->getLft()) < altura(root->getLft()->getRght()) ){   
                if(root==raiz){
                     raiz = rotacionarLR(root);
                }
                else if(PivoRoot->getLft()==root){
                    PivoRoot->setLft(rotacionarLR(root)); 
                }else if(PivoRoot->getRght()==root){
                    PivoRoot->setRght(rotacionarLR(root));
                }
            }
        }
        else if (altura(root->getLft()) < altura(root->getRght()) ) {                                                               /*sub arvore da direita > sub arvore da esquerda*/                  
            if(altura(root->getRght()->getRght()) > altura(root->getRght()->getLft())){   /*descobrindo se é RR ou RL*/
    
                if(root == raiz){  
                    cout<<"rotacao RR"<<endl;  
                    raiz = rotacionarRR(root);
                }else if(PivoRoot->getLft()== root){
                    cout<<"rotacao RR"<<endl; 
                    PivoRoot->setLft(rotacionarRR(root)) ;
                }else if(PivoRoot->getRght()== root){
                    cout<<"rotacao RR"<<endl; 
                    PivoRoot->setRght(rotacionarRR(root)) ;
                } 
            }else if(altura(root->getRght()->getRght()) <altura(root->getRght()->getLft())){
                if(root==raiz){
                cout<<"rotacao RL"<<endl;
                raiz = rotacionarRL(root);
             }
             else if(PivoRoot->getLft()==root){
                 cout<<"rotacao RL"<<endl;
                PivoRoot->setLft(rotacionarRL(root));
            }else if(PivoRoot->getRght()==root){
                 cout<<"rotacao RL"<<endl;
                PivoRoot->setRght(rotacionarRL(root));
            }     
         }
        }
        return;
    }else if (root!=raiz){
        BalanceiaAVL(PivoRoot);
    }
}    
      

void  Tree::insere(int absolut){
    if (raiz==NULL){
        raiz = new node(absolut);
    }else{
         inserirAux(raiz,absolut);
    }
}
void Tree::inserirAux(node *NO, int yearDay){
    if(yearDay < NO->getabsoluto()){
        if(NO->getLft() == NULL){
            node* novo_no = new node(yearDay);
            NO->setLft(novo_no);
            
        } else {
            inserirAux(NO->getLft(), yearDay);
        }
    } else if(yearDay > NO->getabsoluto()){
        if(NO->getRght() == NULL){
            node* novo_no = new node(yearDay);
            NO->setRght(novo_no);
          
        } else {
            inserirAux(NO->getRght(),yearDay);
        }
    } else if(yearDay == NO->getabsoluto()){
        cout << "Numero ja existe...." << endl;
    }

}
void Tree::removee(int yearDay){
     node* temp = raiz;
            node* ant, *auxdir, *auxesq;
            while(temp->getabsoluto() != yearDay){
                ant = temp;
                if(yearDay > temp->getabsoluto()){
                    temp = temp->getRght();
                } else {
                    temp =temp->getLft();
                    if(temp == NULL){
                        cout << "Nao foi possivel encontrar o valor informado" << endl;
                        return;
                    }
                }
            }
            if(temp->getRght() == NULL &&temp->getLft() == NULL){
                if(ant->getRght() == temp){
                    ant->setRght(NULL);
                } else {
                    ant->setLft(NULL);
                }
                cout << "Removendo o no " << temp->getabsoluto() << endl;
                delete(temp);
            } else if((temp->getRght() != NULL && temp->getLft() == NULL) || (temp->getRght() == NULL && temp->getLft() != NULL)){
                if (temp== ant->getRght()){
                    ant->setRght(temp->getRght());
                    delete(temp);
                }else{
                    ant->setLft(temp->getRght());
                    delete(temp);
                }

            }else if(temp->getRght() != NULL && temp->getLft() != NULL){
                if (temp== ant->getRght()){
                    ant->setRght(temp->getLft());
                    delete(temp);
                }else{
                    ant->setLft(temp->getLft());
                    delete(temp);
                }

            }else if(temp->getRght() != NULL &&temp->getLft() != NULL){
                if (temp == ant->getRght()){
                    auxdir=temp->getRght();
                    auxesq= temp->getLft();
                    auxesq->setRght(auxdir);
                    ant->setRght(auxesq);

                    delete(temp);
                }else{
                    auxdir=temp->getRght();
                    auxesq= temp->getLft();
                    auxdir->setLft(auxesq);
                    ant->setLft(auxdir);
                    delete(temp);
                }
            }
}

void Tree::inordem(node *NO){
    if(NO!=NULL){
        inordem(NO->getLft());
        cout<<NO->getabsoluto()<<endl;
        inordem(NO->getRght());
    }
}

void Tree::posordem(node *NO){
    if(NO!=NULL){
        posordem(NO->getLft());
        posordem(NO->getRght());
        cout<<NO->getabsoluto()<<endl;
    }
}

void Tree::preordem(node *NO){
    if(NO!=NULL){
        cout<<NO->getabsoluto()<<endl;
        preordem(NO->getLft());
        preordem(NO->getRght());
    }
}
