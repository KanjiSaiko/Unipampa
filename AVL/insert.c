#include "bibliotecas.h"


void insert(Nodo **raiz, int chave){
    if((*raiz)==NULL){ //se a raiz estiver vazia:
		(*raiz) = malloc(sizeof(Nodo));
		(*raiz)->chave = chave;
        //restante permanecerá null
	}

	else{
		if(chave <= (*raiz)->chave){ //se a chave for menor ou igual à chave da raiz:
            (*raiz)->fator++;
			insert(&(*raiz)->esq, chave); //insiro a esquerda
		}

		else{ //caso a chave seja maior
		    (*raiz)->fator--;
			insert(&(*raiz)->dir, chave); //insiro na direita
		}
	}
}