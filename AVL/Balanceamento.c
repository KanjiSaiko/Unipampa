#include "bibliotecas.h"


Nodo *Balanceamento(Nodo *raiz){
    Nodo *aux=NULL,*aux2=NULL;
    if(raiz !=NULL){
        raiz->esq = Balanceamento(raiz->esq);
        raiz->dir = Balanceamento(raiz->dir);
        if((raiz->fator==2)||(raiz->fator==-2)){
            if((raiz->fator > 0)&&(raiz->esq->fator>0)){
                //fator Direita
                aux = raiz->esq;
                raiz->esq = aux->dir;
                aux->dir = raiz;
                raiz->fator = 0;
                raiz=aux;
            }
            else{
                if((raiz->fator<0)&&(raiz->dir->fator<0)){
                    //fator Esquerda
                    aux = raiz->dir;
                    raiz->dir = aux->esq;
                    aux->esq = raiz;
                    raiz->fator = 0;
                    raiz = aux;
                }
                else{
                    //fator Dupla Direita
                    if((raiz->fator>0)&&(raiz->esq->fator<0)){
                        aux=raiz->esq;
                        aux2=aux->dir;
                        aux->dir=aux2->esq;
                        aux2->esq=aux;
                        raiz->esq=aux2->dir;
                        aux2->dir=raiz;
                        if(aux2->fator==-1){
                            raiz->fator=1;
                        }
                        else{
                            raiz->fator=0;
                        }
                        if(aux2->fator==1){
                            aux->fator=-1;
                        }
                        else{
                            aux->fator=0;
                        }
                        raiz=aux2;
                    }
                    else{
                        //fator Dupla Esquerda
                        if((raiz->fator<0)&&(raiz->dir->fator>0)){
                            aux=raiz->dir;
                            aux2=aux->esq;
                            aux->esq=aux2->dir;
                            aux2->dir=aux;
                            raiz->dir=aux2->esq;
                            aux2->esq=raiz;
                            if(aux2->fator==-1){
                                raiz->fator=1;
                            }
                            else{
                                raiz->fator=0;
                            }
                            if(aux2->fator==1){
                                aux->fator=-1;
                            }
                            else{
                                aux->fator=0;
                            }
                            raiz=aux2;
                        }
                    }
                }
            }
        }
        return raiz;
    }
    return NULL;
}