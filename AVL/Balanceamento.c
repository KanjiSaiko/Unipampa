#include "bibliotecas.h"


Nodo *Balancear(Nodo *raiz){
    int fator = FatordeBalanceamento(raiz);

    //rotacao a esquerda:
    if(fator < -1 && FatordeBalanceamento(raiz->dir) <= 0){
        raiz = RotacaoEsquerda(raiz);
    }
    //rotacao a direita:
    else if(fator > 1 && FatordeBalanceamento(raiz->esq) >= 0){
        raiz = rotacaoDireita(raiz);
    }
    //rotacao dupla esquerda:
    else if(fator > 1 && FatordeBalanceamento(raiz->esq) < 0){
        raiz = rotacaoEsquerdaDireita(raiz);
    }
    //rotacao dupla direita:
    else if(fator < 1 && FatordeBalanceamento(raiz->dir) > 0){
        raiz = rotacaoDireitaEsquerda(raiz);
    }
    
    return raiz;
}