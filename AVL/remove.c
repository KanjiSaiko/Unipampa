#include "bibliotecas.h"

// Função auxiliar para encontrar o nodo com o valor mínimo
Nodo* findMin(Nodo* node) {
    while (node->esq != NULL) node = node->esq;
    return node;
}

Nodo* Remove(Nodo* raiz, int chave) {
    if (raiz == NULL) {
        return raiz;
    }

    // Procura a chave a ser removida
    if (chave < raiz->chave)
        raiz->esq = Remove(raiz->esq, chave);
    else if (chave > raiz->chave)
        raiz->dir = Remove(raiz->dir, chave);
    else {
        // Nodo encontrado
        if (raiz->esq == NULL) {
            Nodo* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            Nodo* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // Nodo com dois filhos
        Nodo* temp = findMin(raiz->dir);
        raiz->chave = temp->chave;
        raiz->dir = Remove(raiz->dir, temp->chave);
    }

    // Balanceamento
    raiz = Balanceamento(raiz);
    return raiz;
}