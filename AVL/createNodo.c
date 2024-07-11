#include "bibliotecas.h"


Nodo *createNodo(int chave){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->chave = chave;
    nodo->dir = NULL;
    nodo->esq = NULL;
    nodo->pai = NULL;
    nodo->fator = 0;
    nodo->balanco = 0;

    return nodo;
}