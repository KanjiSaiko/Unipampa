#include "bibliotecas.h"


Nodo *insert(Nodo *raiz, Nodo *nodo){
    if(raiz == NULL){
        raiz = nodo;
        return raiz;
    }
    else{
        //A CHAVE É MENOR QUE A RAIZ?
        if(nodo->chave <= raiz->chave){
            raiz->esq = insert(raiz->esq, nodo);
        }
        else if(nodo->chave > raiz->chave){
            raiz->dir = insert(raiz->dir, nodo);
        }
    }

    raiz->altura = maiorAltura(AlturaDoNo(raiz->esq), AlturaDoNo(raiz->dir)) + 1;

    raiz = Balancear(raiz);

    return raiz;
}