#include "bibliotecas.h"

Nodo *remocao(Nodo *raiz, int chave){
    if(raiz == NULL){
        printf("Valor nao encontrado");
        return NULL;
    }

    else{
        if(raiz->chave == chave){
            //remove nos folhas (nós sem filhos)
                if(raiz->esq == NULL && raiz->dir == NULL){
                    free(raiz);
                    printf("Elemento folha removido: %d !\n", chave);
                    return NULL;
                }
            //remove nós que possuem filhos
                else{
                    //remove nós que possuem 2 filhos
                        if(raiz->esq != NULL && raiz->dir != NULL){
                            Nodo *aux = raiz->esq;
                            //percorro até o elemento mais a direita do nó a esquerda e troco de lugar com o nó de 2 filhos
                                while(aux->dir != NULL)
                                    aux = aux->dir;
                                raiz->chave = aux->chave;
                                aux->chave = chave;
                                printf("Elemento trocado: %d\n", chave);
                                //agora que o elemento a ser removido virou uma folha/1 filho, basta fazer a recursao:
                                    raiz->esq = remocao(raiz->esq, chave);
                                return raiz;
                        }
                    //remove nós com 1 filho
                        else{
                            Nodo *aux;
                            //CASO TENHA FILHO À ESQUERDA, AUXILIAR APONTARÁ PARA ELE (O MESMO PARA DIREITA)
                            if(raiz->esq != NULL)
                                aux = raiz->esq;
                            else
                                aux = raiz->dir;
                            free(raiz);
                            printf("Elemento com 1 filho removido: %d\n", chave);
                            return aux;
                        }
                }
         }
        //caso nao seja o nodo que quero remover, continuo a percorrer a arvore de forma recursiva
            else {
                    if(chave < raiz->chave)
                        raiz->esq = remocao(raiz->esq, chave);
                    
                    else
                        raiz->dir = remocao(raiz->dir, chave);
                    
            }
        raiz->altura = maiorAltura(AlturaDoNo(raiz->esq), AlturaDoNo(raiz->dir)) + 1;

        raiz = Balancear(raiz);

        return raiz;
    }
}
