#include "bibliotecas.h"

int maiorAltura(int alturaE, int alturaD){
    return (alturaE > alturaD) ? alturaE : alturaD;
}

//RETORNO A ALTURA DAQUELE NO
int AlturaDoNo(Nodo *no){
    if(no == NULL){
        return -1;
    }
    else{
        return no->altura;
    }
}

int FatordeBalanceamento(Nodo *no){
    if(no){
        return (AlturaDoNo(no->esq) - AlturaDoNo(no->dir));
    }
    else
        return 0;
}