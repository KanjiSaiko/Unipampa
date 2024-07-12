#include "bibliotecas.h"


int* inicializaVisitados(int tamanho) {
    int* visitados = (int*)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        visitados[i] = 0;  // 0 significa não visitado
    }
    return visitados;
}


void DFS(struct descritor_grafo *grafo, int chaveInicio) {
    int totalVertices = tamanhoVertices(grafo);
    int* visitados = inicializaVisitados(totalVertices);
    DFSUtil(grafo, chaveInicio, visitados);
    free(visitados);
}

void DFSUtil(struct descritor_grafo *grafo, int vertice, int* visitados) {
    visitados[vertice - 1] = 1;  // Marca como visitado
    printf("Visitado %d \n", vertice);

    struct nodo* nodoVertice = buscaVertice(grafo, vertice);
    if (nodoVertice == NULL) return;

    struct aresta* adjacencia = nodoVertice->adjacencias;
    while (adjacencia != NULL) {
        if (!visitados[adjacencia->chegada - 1]) {
            DFSUtil(grafo, adjacencia->chegada, visitados);
        }
        adjacencia = adjacencia->prox;
    }
}

int tamanhoVertices(struct descritor_grafo *grafo) {
    int contador = 0;
    struct nodo* temp = grafo->nodos;
    while (temp != NULL) {
        contador++;
        temp = temp->prox;
    }
    return contador;
}
