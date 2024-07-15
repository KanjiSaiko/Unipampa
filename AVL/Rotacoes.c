#include "bibliotecas.h"

Nodo *RotacaoEsquerda(Nodo *raiz){
    Nodo *direita, *esquerdaDaDireita;
    direita = raiz->dir;
    esquerdaDaDireita = direita->esq;


    direita->esq = raiz;
    //caso tenha um no na esquerda da direita, guardo este no para nao perde-lo
    raiz->dir = esquerdaDaDireita;

    //ATUALIZO A ALTURA
    raiz->altura = maiorAltura(AlturaDoNo(raiz->esq), AlturaDoNo(raiz->dir)) + 1;
    direita->altura = maiorAltura(AlturaDoNo(direita->esq), AlturaDoNo(direita->dir)) + 1;

}


Nodo *rotacaoDireita(Nodo *raiz){
    Nodo *esquerda, *direitaDaEsquerda;
    esquerda = raiz->esq;
    direitaDaEsquerda = esquerda->dir;

    esquerda->dir = raiz;
    raiz->esq = direitaDaEsquerda;

    raiz->altura = maiorAltura(AlturaDoNo(raiz->esq), AlturaDoNo(raiz->dir)) + 1;
    esquerda->altura = maiorAltura(AlturaDoNo(esquerda->esq), AlturaDoNo(esquerda->dir)) + 1;

}

Nodo *rotacaoDireitaEsquerda(Nodo *raiz){
    raiz->dir = rotacaoDireita(raiz->dir);
    return RotacaoEsquerda(raiz);
}

Nodo *rotacaoEsquerdaDireita(Nodo *raiz){
    raiz->esq = RotacaoEsquerda(raiz->esq);
    return rotacaoDireita(raiz);
}