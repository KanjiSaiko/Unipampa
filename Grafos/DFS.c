#include "bibliotecas.h"

void DFSVisita(struct descritor_grafo *grafo, int vertice, int* visitados) {
    // Marca o vértice como visitado (como o vetor inicializa com 0, faço 0-1)
    visitados[vertice - 1] = 1;  
    printf("Visitado %d \n", vertice);

    struct nodo* nodoVertice = buscaVertice(grafo, vertice);
    if (nodoVertice == NULL) return;

    struct aresta* adjacencia = nodoVertice->adjacencias;
    while (adjacencia != NULL) {
        //verifica se o vértice no final de uma aresta adjacente não foi visitado
            if (!visitados[adjacencia->chegada - 1]) {
            // Recursivamente visita vértices adjacentes não visitados
                DFSVisita(grafo, adjacencia->chegada, visitados);  
        }
        adjacencia = adjacencia->prox;
    }
}

void DFS(struct descritor_grafo *grafo, int chaveInicio) {
    int totalVertices = grafo->max_vertices;
    int* visitados = inicializaVisitados(totalVertices);
    DFSVisita(grafo, chaveInicio, visitados);  // Inicia a busca em profundidade a partir de chaveInicio
    free(visitados);
}

//INICIALIZA UM VETOR DE ACORDO COM N VERTICES QUE TENHO NO GRAFO
    int* inicializaVisitados(int tamanho) {
        int* visitados = (int*)malloc(tamanho * sizeof(int));
        for (int i = 0; i < tamanho; i++) {
            visitados[i] = 0;  // 0 significa não visitado
        }
        return visitados;
    }




