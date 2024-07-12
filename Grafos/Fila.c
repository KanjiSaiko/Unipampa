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
        if (Q->size == Q->capacity) {
            printf("Fila cheia\n");
        } else {
            Q->size++;
            Q->tail = (Q->tail + 1) % Q->capacity;
            Q->elements[Q->tail] = element;
        }
    }

    int dequeue(struct queue* Q) {
        if (Q->size == 0) {
            printf("Fila vazia\n");
            return -1;
        } else {
            Q->size--;
            int element = Q->elements[Q->head];
            Q->head = (Q->head + 1) % Q->capacity;
            return element;
        }
    }

    int isEmptyQueue(struct queue* Q) {
        return Q->size == 0;
    }
