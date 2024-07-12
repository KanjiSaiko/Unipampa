#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct nodo Nodo;
typedef struct desc_avl DescAVL;


struct nodo{
    struct nodo *pai;
    int chave;
    struct nodo *esq;
    struct nodo *dir;
    int fator;
    int balanco;
};

struct desc_avl{
    struct nodo *raiz;
    int tamanho;
};


DescAVL *createAVL();
Nodo *insert(Nodo *raiz, int chave);
void Imprime_preorder(Nodo *raiz);
void Imprime_inorder(Nodo *raiz);
void Imprime_posorder(Nodo *raiz);
Nodo *Remove(Nodo *raiz, int chave);
Nodo *Balanceamento(Nodo *raiz);
void atualizarFator(Nodo *n);
int altura(Nodo *n);
Nodo *rotacaoDireita(Nodo *desbalanceado);
Nodo *rotacaoEsquerda(Nodo *desbalanceado);
Nodo *rotacaoDireitaEsquerda(Nodo *desbalanceado);
Nodo *rotacaoEsquerdaDireita(Nodo *desbalanceado);
