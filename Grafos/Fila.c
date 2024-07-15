#include "bibliotecas.h"

    struct queue* createQueue(int maxElements) {
        struct queue* Q;
        Q = (struct queue*)malloc(sizeof(struct queue));
        Q->elements = (int*)malloc(sizeof(int)*maxElements);
        Q->size = 0;
        Q->capacity = maxElements;
        Q->head = 0;
        Q->tail = -1;
        return Q;
    }

    void enqueue(struct queue* Q, int element) {
        if (Q->size == Q->capacity) { // Verifica se a fila está cheia
            printf("Fila cheia\n");
        } 
        else {
            Q->size++; // Incrementa o tamanho da fila
            Q->tail = (Q->tail + 1) % Q->capacity; // Move a cauda para a próxima posição circularmente
            Q->elements[Q->tail] = element; // Insere o novo elemento na posição da cauda
        }
    }

    int dequeue(struct queue* Q) {
        if (Q->size == 0) { // Verifica se a fila está vazia
            printf("Fila vazia\n");
            return -1; // Retorna -1 como indicativo de fila vazia
        } 
        else {
            Q->size--; // Decrementa o tamanho da fila
            int element = Q->elements[Q->head]; // Armazena o elemento na cabeça da fila
            Q->head = (Q->head + 1) % Q->capacity; // Move a cabeça para a próxima posição circularmente
            return element; // Retorna o elemento desenfileirado
        }
    }

    int isEmptyQueue(struct queue* Q) {
        return Q->size == 0; // Retorna verdadeiro (1) se a fila está vazia, falso (0) caso contrário
    }
