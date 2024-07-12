#include "bibliotecas.h"


Nodo *insert(Nodo *raiz, int chave) {
    if (raiz == NULL) {
        raiz = malloc(sizeof(Nodo));
        if (raiz == NULL) {
            fprintf(stderr, "Erro de alocação de memória\n");
            exit(EXIT_FAILURE);
        }
        raiz->chave = chave;
        raiz->esq = NULL;
        raiz->dir = NULL;
        raiz->fator = 0;  // Inicializado corretamente
    } 
	else {
        if (chave <= raiz->chave) {
            raiz->esq = insert(raiz->esq, chave); // Correção aqui
        } else {
            raiz->dir = insert(raiz->dir, chave); // Correção aqui
        }

        // Atualiza o fator de balanceamento de forma apropriada
        atualizarFator(raiz);
    }

    // Aplica o balanceamento após a inserção para manter a árvore AVL
    return Balanceamento(raiz);
}
