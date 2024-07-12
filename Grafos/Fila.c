#include "bibliotecas.h"

    struct queue* createQueue(int maxElements) {
        struct queue* Q;
        Q = (struct queue*)malloc(sizeof(struct queue));
        Q->elements = (int*)malloc(sizeof(int)*maxElements);
        Q->size = 0;
        Q->capacity = maxElements;
        Q->front = 0;
        Q->rear = -1;
        return Q;
    }

    void enqueue(struct queue* Q, int element) {
        if (Q->size == Q->capacity) {
            printf("Queue is Full\n");
        } else {
            Q->size++;
            Q->rear = (Q->rear + 1) % Q->capacity;
            Q->elements[Q->rear] = element;
        }
    }

    int dequeue(struct queue* Q) {
        if (Q->size == 0) {
            printf("Queue is empty\n");
            return -1; // Return that queue is empty
        } else {
            Q->size--;
            int element = Q->elements[Q->front];
            Q->front = (Q->front + 1) % Q->capacity;
            return element;
        }
    }

    int isEmptyQueue(struct queue* Q) {
        return Q->size == 0;
    }
