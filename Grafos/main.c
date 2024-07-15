#include "bibliotecas.h"

int main(){
	
	int opcao,chave_busca, tam, *vis;
	struct descritor_grafo *grafo = NULL;
	struct descritor_grafo_matriz *grafoMatriz = NULL;
	struct desc_stack *minhaPilha = NULL;
	opcao = -1;
	while(opcao != 0){
		printf("\n\n=========MENU=========\n");
		printf("1-carrega grafo lista\n2-Tamanho de Vertices\n3-imprime grafo lista\n4-carrega grafo Matriz\n5-imprime grafo matriz\n6- Imprime DFS\n7- Imprime BFS\n0-SAIR\n");
		setbuf(stdin,NULL);
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
					grafo = parser("grafos2.txt");
					if(grafo !=NULL)
						printf("grafo lista inicializado com sucesso\n");
					break;

			case 2:
					if(grafo == NULL){
						printf("\nCarregue grafos antes");
						break;
					}
					printf("\nTamanho de vértices: %d", tamanhoVertices(grafo));
					break;

			case 3:
					imprimeGrafo(grafo);
					break;

			case 4:
					grafoMatriz = parserMatriz("grafos2.txt");
					if(grafoMatriz != NULL)
						printf("grafo inicializado com sucesso\n");
					break;

			case 5:
					imprimeGrafoMatriz(grafoMatriz);
					break;
			
			case 6:
				printf("Digite o vértice inicial para DFS:\n");
				scanf("%d", &chave_busca);
				DFS(grafo, chave_busca);
				break;

			case 7:
				printf("Digite o vértice inicial para BFS:\n");
				scanf("%d", &chave_busca);
				BFS(grafo, chave_busca);
				break;

			case 0:
					free(grafo);
					free(grafoMatriz);
					free(minhaPilha);
		}	
	}
	return 0;
}