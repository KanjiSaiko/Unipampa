#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct descritor_grafo{
	int max_vertices;
	int max_arestas;
	struct nodo *nodos;
};

struct nodo{
	int chave;
	struct nodo *prox;
	struct aresta *adjacencias;	
};

//LIGACOES E PESOS DOS NODOS
struct aresta{
	int partida;
	int chegada;
	int peso;
	struct aresta *prox;
};


struct descritor_grafo* parser(char *nomeArquivo);
struct descritor_grafo * inicializaGrafo(int tamanho);
struct nodo* criaVertice(int chave);
void insereVertice(struct descritor_grafo *grafo, int chave);
struct descritor_grafo * insereAresta(struct descritor_grafo *grafo, int chaveSaida, int chaveChegada, int peso);
struct nodo* buscaVertice(struct descritor_grafo *grafo, int chaveBusca);
struct nodo* buscaAdjacencia(struct descritor_grafo *grafo, int partida, int chegada);
int tamanhoVertices(struct descritor_grafo *grafo);
int tamanhoAdjacencias(struct descritor_grafo *grafo);
int listaAjacencias(struct nodo *vertice);
void imprimeGrafo(struct descritor_grafo *grafo);

//DFS
	void DFS(struct descritor_grafo *grafo, int chaveInicio);
	void DFSVisita(struct descritor_grafo *grafo, int vertice, int* visitados);
	int tamanhoVertices(struct descritor_grafo *grafo);
	int* inicializaVisitados(int tamanho);

//BFS
	struct queue {
    int capacity;
    int size;
    int head;
    int tail;
    int* elements;
	};

	struct queue* createQueue(int maxElements);
	void enqueue(struct queue* Q, int element);
	int dequeue(struct queue* Q);
	void BFS(struct descritor_grafo *grafo, int chaveInicio);
	int isEmptyQueue(struct queue* Q);




//////---------------REPRESENTAÇÃO COM MATRIZ DE ADJACÊNCIA---------------------

struct descritor_grafo_matriz{
	int max_vertices;
	int max_arestas;
	int **grafoMatriz;
};


struct descritor_grafo_matriz* parserMatriz(char *nomeArquivo);
struct descritor_grafo_matriz * inicializaGrafoMatriz(int tamanho);
struct descritor_grafo_matriz * insereArestaMatriz(struct descritor_grafo_matriz *grafo, int chaveSaida, int chaveChegada, int peso);
void imprimeGrafoMatriz(struct descritor_grafo_matriz *grafoMatriz);
