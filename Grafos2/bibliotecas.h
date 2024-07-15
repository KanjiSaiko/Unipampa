#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
    int vertices;
    int ponderado;
    int **arestas;
    int *grau; //pra cada vertice, quantas arestas possui
    int grauMax; //quantas arestas tenho pra 1 vertice
    int **peso;
}grafos;