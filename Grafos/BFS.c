#include "bibliotecas.h"

void BFS(struct descritor_grafo *grafo, int chaveInicio) {
    int totalVertices = tamanhoVertices(grafo);
    int* visitados = inicializaVisitados(totalVertices);

    struct queue* queue = createQueue(totalVertices);
    enqueue(queue, chaveInicio);
    visitados[chaveInicio - 1] = 1; // Marca como visitado

    while (!isEmptyQueue(queue)) {
        int vertice = dequeue(queue);
        printf("Visitado %d\n", vertice);

        struct nodo* nodoVertice = buscaVertice(grafo, vertice);
        struct aresta* adjacencia = nodoVertice->adjacencias;
        while (adjacencia != NULL) {
            int adjVertex = adjacencia->chegada;
            if (!visitados[adjVertex - 1]) {
                visitados[adjVertex - 1] = 1;
                enqueue(queue, adjVertex);
            }
            adjacencia = adjacencia->prox;
        }
    }

    free(visitados);
    free(queue->elements);
    free(queue);
}
