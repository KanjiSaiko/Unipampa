#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct nodo Nodo;
typedef struct desc_avl DescAVL;


struct nodo{
    int chave;
    struct nodo *esq;
    struct nodo *dir;
    int altura;
};

struct desc_avl{
    struct nodo *raiz;
    int tamanho;
};


DescAVL *createAVL();
Nodo *createNodo(int chave);
Nodo *insert(Nodo *raiz, Nodo *nodo);
int maiorAltura(int alturaE, int alturaD);
int AlturaDoNo(Nodo *no);
int FatordeBalanceamento(Nodo *no);
Nodo *Balancear(Nodo *raiz);
void Imprime_preorder(Nodo *no);
void Imprime_inorder(Nodo *no);
void Imprime_posorder(Nodo *no);
Nodo *RotacaoEsquerda(Nodo *raiz);
Nodo *rotacaoDireita(Nodo *raiz);
Nodo *rotacaoDireitaEsquerda(Nodo *raiz);
Nodo *rotacaoEsquerdaDireita(Nodo *raiz);
Nodo *remocao(Nodo *raiz, int chave);



