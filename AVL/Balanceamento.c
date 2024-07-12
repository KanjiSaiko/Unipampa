#include "bibliotecas.h"


Nodo *Balanceamento(Nodo *raiz){
    Nodo *aux=NULL,*aux2=NULL;
    if(raiz != NULL){

        raiz->esq = Balanceamento(raiz->esq);
        raiz->dir = Balanceamento(raiz->dir);

        atualizarFator(raiz);
        if (raiz->fator == 2) {
            if (raiz->esq && raiz->esq->fator >= 0) {
                // Rotação simples à direita
                return rotacaoDireita(raiz);
            } else if (raiz->esq && raiz->esq->fator < 0) {
                // Rotação dupla à direita (Esquerda-Direita)
                return rotacaoEsquerdaDireita(raiz);
            }
        } 
        else if (raiz->fator == -2) {
            if (raiz->dir && raiz->dir->fator <= 0) {
                // Rotação simples à esquerda
                return rotacaoEsquerda(raiz);
            } else if (raiz->dir && raiz->dir->fator > 0) {
                // Rotação dupla à esquerda (Direita-Esquerda)
                return rotacaoDireitaEsquerda(raiz);
            }
        }
    }
    return raiz;
}

int altura(Nodo *n) {
    if (!n) return 0;
    int altura_esq = altura(n->esq);
    int altura_dir = altura(n->dir);
    return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

void atualizarFator(Nodo *n) {
    if (n) {
        int altura_esq = altura(n->esq);
        int altura_dir = altura(n->dir);
        n->fator = altura_esq - altura_dir;
    }
}

Nodo *rotacaoDireita(Nodo *desbalanceado) {
    Nodo *novoRaiz = desbalanceado->esq;
    desbalanceado->esq = novoRaiz->dir;
    novoRaiz->dir = desbalanceado;

    // Atualizar fatores de balanceamento após rotação
    atualizarFator(desbalanceado);
    atualizarFator(novoRaiz);

    return novoRaiz;  // Novo raiz após rotação
}

Nodo *rotacaoEsquerda(Nodo *desbalanceado) {
    Nodo *novoRaiz = desbalanceado->dir;
    desbalanceado->dir = novoRaiz->esq;
    novoRaiz->esq = desbalanceado;

    // Atualizar fatores de balanceamento após rotação
    atualizarFator(desbalanceado);
    atualizarFator(novoRaiz);

    return novoRaiz;  // Novo raiz após rotação
}


Nodo *rotacaoDireitaEsquerda(Nodo *desbalanceado) {
    desbalanceado->esq = rotacaoEsquerda(desbalanceado->esq);
    return rotacaoDireita(desbalanceado);
}

Nodo *rotacaoEsquerdaDireita(Nodo *desbalanceado) {
    desbalanceado->dir = rotacaoDireita(desbalanceado->dir);
    return rotacaoEsquerda(desbalanceado);
}







