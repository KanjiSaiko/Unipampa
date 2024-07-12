#include "bibliotecas.h"

void Imprime_preorder(Nodo *raiz){ //visita a raiz, o lado esquerdo e depois o direito
	if(raiz!=NULL){
		printf("<%d>",raiz->chave);
		Imprime_preorder(raiz->esq);
		Imprime_preorder(raiz->dir);
	}
}
void Imprime_inorder(Nodo *raiz){ //visita primeiro a subárvore esquerda até a raiz, seguido do lado direito
	if(raiz!=NULL){
		Imprime_inorder(raiz->esq);
		printf("<%d>",raiz->chave);
		Imprime_inorder(raiz->dir);
	}
}
void Imprime_posorder(Nodo *raiz){ //primeiro subarvores sao visitadas e por ultimo a raiz
	if(raiz!=NULL){
		Imprime_posorder(raiz->esq);
		Imprime_posorder(raiz->dir);
		printf("<%d>",raiz->chave);
	}
}