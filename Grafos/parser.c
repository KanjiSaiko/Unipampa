#include "bibliotecas.h"


struct descritor_grafo* parser(char *nomeArquivo){

	FILE *file = fopen(nomeArquivo,"r");
	int total;
	fscanf(file,"%d",&total);
	printf("=====================================================\n");
	printf("================LEITURA GRAFO========================\n");
	
	printf("total de nodos %d\n",total);
	struct descritor_grafo *grafo = NULL;
	grafo = inicializaGrafo(total); 
	char linha[500];
	char caractere;
	int n;
	n=0;
	while((caractere =fgetc(file)) != EOF ){ //le o arquivo até o final caractere por caractere
		if(caractere != '\n'){
			linha[n]=caractere;
			n++;
		}
		else{
			linha[n]='\0';
			if(n > 0 ) //frase valida
			{
			 printf("linha eh: %s\n", linha);
			 int partida = atoi(strtok(linha," "));
			 printf("\n partida strtok= %d\n",partida);
			 int chegada = atoi(strtok(NULL," "));		 
			 printf("\n chegada strtok= %d\n",chegada);
			 
			 int peso = atoi(strtok(NULL," "));		 
			 printf("\n peso strtok= %d\n",peso);
			 
			 grafo = insereAresta(grafo,partida,chegada,peso);
			}
			n=0; //zera a frase para pegar proximas informações
			linha[n]='\0';
		}   
	}
	fclose(file);
	printf("=====================================================\n");
	return grafo;
}


struct descritor_grafo * inicializaGrafo(int tamanho){
	struct descritor_grafo * novografo = (struct descritor_grafo*) malloc(sizeof(struct descritor_grafo));
	novografo->max_vertices = tamanho;
	novografo->max_arestas = 0;
	novografo->nodos = NULL;
	int i;
	//cria a lista encadeada de nodos
	for(i=0;i<tamanho;i++){
		struct nodo *novoNodo = criaVertice(i+1);
		if(novografo->nodos == NULL){
			novografo->nodos = novoNodo;
		}
		else{
			struct nodo *temp = novografo->nodos;
			while(temp->prox!=NULL){
					temp = temp->prox;
			}
			temp->prox = novoNodo;
		}
	}
	return novografo;
}


struct nodo * criaVertice(int chave){
	struct nodo *novoVertice  = (struct nodo *) malloc(sizeof(struct nodo));
	novoVertice->chave 	= chave;
	novoVertice->prox 	= NULL;
	novoVertice->adjacencias=NULL;
	return novoVertice;
}
 
struct descritor_grafo * insereAresta(struct descritor_grafo *grafo, int chaveSaida, int chaveChegada, int peso){
	struct nodo* nodoSaida = buscaVertice(grafo,chaveSaida);
	if(nodoSaida ==NULL){
		printf("nodo buscado não existe\n");
		return grafo;
	}
	struct aresta* arestaNova = (struct aresta *) malloc(sizeof(struct aresta));
	arestaNova->peso = peso;
	arestaNova->partida = chaveSaida;
	arestaNova->chegada = chaveChegada;
	
	
	if(nodoSaida->adjacencias == NULL)
		nodoSaida->adjacencias=arestaNova;
	else{
		struct aresta *tempAdj = nodoSaida->adjacencias;
		while(tempAdj->prox != NULL){
			tempAdj = tempAdj->prox;
		}	
		tempAdj->prox = arestaNova;	
	}
	return grafo;
}


struct nodo * buscaVertice(struct descritor_grafo *grafo, int chaveBusca){
	struct nodo* temporaria = grafo->nodos;
	while(temporaria !=NULL){
		if(temporaria->chave == chaveBusca)
			return temporaria;
		temporaria = temporaria->prox;
	}
	return NULL;	
}


void imprimeGrafo(struct descritor_grafo *grafo){
	struct nodo *nodoGrafo = grafo->nodos;
	printf("========GRAFO LISTA=============\n");
		while(nodoGrafo != NULL){
			printf("Nodo %d -",nodoGrafo->chave);
			struct aresta *adjacenciaNodo = nodoGrafo->adjacencias;
				while(adjacenciaNodo != NULL){
					printf("[ ->%d (peso %d)] ",adjacenciaNodo->chegada, adjacenciaNodo->peso);
					adjacenciaNodo = adjacenciaNodo->prox;
				}	
				printf("\n");
				nodoGrafo = nodoGrafo->prox;
		}
	printf("=====================\n");
}




struct nodo * buscaAdjacencia(struct descritor_grafo *grafo, int partida, int chegada);
int tamanhoVertices(struct descritor_grafo *grafo);
int tamanhoAdjacencias(struct descritor_grafo *grafo);
int listaAjacencias(struct nodo *vertice);



//-----------------------------GRAFO COM MATRIZ ----------------------

struct descritor_grafo_matriz* parserMatriz(char *nomeArquivo){
	FILE *file = fopen(nomeArquivo,"r");
	int total;
	fscanf(file,"%d",&total);
	printf("total de nodos %d\n",total);
	struct descritor_grafo_matriz *grafo = NULL;
	grafo = inicializaGrafoMatriz(total); 
	char linha[500];
	char caractere;
	int n;
	n=0;
	while((caractere =fgetc(file)) != EOF ){ //le o arquivo até o final caractere por caractere
		if(caractere != '\n'){
			linha[n]=caractere;
			n++;
		}
		else{
			linha[n]='\0';
			if(n > 0 ) //frase valida
			{
			 printf("linha eh: %s\n", linha);
			 int partida = atoi(strtok(linha," "));
			 printf("\n partida strtok= %d\n",partida);
			 int chegada = atoi(strtok(NULL," "));		 
			 printf("\n chegada strtok= %d\n",chegada);
			 
			 int peso = atoi(strtok(NULL," "));		 
			 printf("\n peso strtok= %d\n",peso);
			 
			 grafo = insereArestaMatriz(grafo,partida,chegada,peso);
			}
			n=0; //zera a frase para pegar proximas informações
			linha[n]='\0';
		}   
	}
	fclose(file);
	return grafo;
}

struct descritor_grafo_matriz * inicializaGrafoMatriz(int tamanho){
	struct descritor_grafo_matriz * novografo = (struct descritor_grafo_matriz*) malloc(sizeof(struct descritor_grafo_matriz));
	novografo->max_vertices = tamanho;
	novografo->max_arestas = 0;
	novografo->grafoMatriz = (int **) malloc(sizeof(int *)*(tamanho));
	int i;
	for(i=0;i<tamanho;i++)
		novografo->grafoMatriz[i] = (int*) malloc(sizeof(int)*(tamanho));
	return novografo;
}

struct descritor_grafo_matriz * insereArestaMatriz(struct descritor_grafo_matriz *novografo, int chaveSaida, int chaveChegada, int peso){
	novografo->grafoMatriz[chaveSaida-1][chaveChegada-1]=peso;
	novografo->max_arestas++;
	return novografo;
}

void imprimeGrafoMatriz(struct descritor_grafo_matriz *grafoMatriz){
	int i,j;
	printf("========GRAFO MATRIZ=============\n");
	for(i=0;i<grafoMatriz->max_vertices;i++){
		for(j=0;j<grafoMatriz->max_vertices;j++){
			printf("[%d-%d]=%d \t",i+1,j+1,grafoMatriz->grafoMatriz[i][j]);
		}
		printf("\n");
	}
	printf("=====================\n");
}