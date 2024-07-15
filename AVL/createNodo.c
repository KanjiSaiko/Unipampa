#include "bibliotecas.h"


Nodo *createNodo(int chave){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->chave = chave;
    nodo->dir = NULL;
    nodo->esq = NULL;
    nodo->altura = 0;

    return nodo;
}