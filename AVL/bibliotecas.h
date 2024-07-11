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
void insert(Nodo **raiz, int chave);
void Imprime_preorder(Nodo *raiz);
void Imprime_inorder(Nodo *raiz);
void Imprime_posorder(Nodo *raiz);
void Remove(Nodo **raiz, int chave);
Nodo *Balanceamento(Nodo *raiz);
