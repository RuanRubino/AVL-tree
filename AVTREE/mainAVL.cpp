#include <iostream>
#include<stdio.h>
#include "treeAVL.h"
using namespace std;
int main(){
    Tree* arvore = new Tree();
    int op = 1;
    int chave;
    int choice;
    
    node* novo;
    do {
        cout << "BEM VINDO : " << endl;
        cout << "[1] Inserir " << endl;
        cout << "[2] Ver balanceamento " << endl;
        cout << "[3] Remover" << endl;
        cout << "[4] Ver Datas Marcadas" << endl;
        cout << "[0] Encerra" << endl;
        cin >> choice;
        switch(choice){
            case 1:
           do{
            cout << "insira a chave ";
            cin >> chave;
            arvore->insere(chave);
            novo = arvore->returnaNovo(arvore->getRaiz(), chave);
            system("cls");
            arvore->BalanceiaAVL(novo);
            cout << "Deseja adicionar mais valores?" << endl;
            cout << "0. Nao" << endl;
            cout << "1. Sim" << endl;
            cin >> op;

        }while(op == 1);
            break;
            case 2:
                cout<<endl;
                cout<<"Pos ordem (EDR)";
                cout<<endl;
                arvore->posordem(arvore->getRaiz());
                 cout << endl;
            break;
            case 3:
                cout << "Qual no deseja remover? "<<endl;
                cin>>chave;
                arvore->removee(chave);
            break;

            case 4:
                cout<<" datas marcadas"<<endl;
                arvore->inordem(arvore->getRaiz());
            break;

        }
    } while(choice != 0);
    return 0;

}
