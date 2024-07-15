#include "bibliotecas.h"

void Imprime_preorder(Nodo *no){
	if(no!=NULL){
		printf("<%d> ",no->chave);
		Imprime_preorder(no->esq);
		Imprime_preorder(no->dir);
	}
}
void Imprime_inorder(Nodo *no){
	if(no!=NULL){
		Imprime_inorder(no->esq);
		printf("<%d> ",no->chave);
		Imprime_inorder(no->dir);
	}
}
void Imprime_posorder(Nodo *no){
	if(no!=NULL){
		Imprime_posorder(no->esq);
		Imprime_posorder(no->dir);
		printf("<%d> ",no->chave);
	}
}