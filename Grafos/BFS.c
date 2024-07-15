#include "bibliotecas.h"

void BFS(struct descritor_grafo *grafo, int chaveInicio) {
    int totalVertices = tamanhoVertices(grafo);
    int* visitados = inicializaVisitados(totalVertices);

    //cria fila de acordo com o total de vertices no grafo
        struct queue* fila = createQueue(totalVertices);

    //Enfileira o vértice inicial e marca como visitado.
        enqueue(fila, chaveInicio);
        visitados[chaveInicio - 1] = 1; // Marca como visitado

    //Continua a explorar enquanto houver vértices na fila.
        while (!isEmptyQueue(fila)) {
            int vertice = dequeue(fila);
            printf("Visitado %d\n", vertice);

            struct nodo* nodoVertice = buscaVertice(grafo, vertice);
            struct aresta* adjacencia = nodoVertice->adjacencias;
            while (adjacencia != NULL) {
                int adjVertex = adjacencia->chegada;
                // Se o vértice adjacente não foi visitado, ele é enfileirado e marcado como visitado.
                    if (!visitados[adjVertex - 1]) {
                        visitados[adjVertex - 1] = 1;
                        enqueue(fila, adjVertex);
                    }
                // Move para a próxima adjacência.
                adjacencia = adjacencia->prox;
            }
        }

    free(visitados);
    free(fila->elements);
    free(fila);
}
