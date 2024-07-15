#include "bibliotecas.h"

//Funcao auxiliar: realiza o cálculo
void buscaProfundidade(struct descritor_grafo *grafo, int Vinicial, int *visitado, int cont){
    int i;
    //marco vertice como visitado
        visitado[Vinicial] = cont;

    //visito todas as arestas que partem do vertice:
    for(i = 0; i < grafo->grau[Vinicial]; i++){
        //verifico se o vizinho foi visitado ou nao
        if(!visitado[grafo->arestas[Vinicial][i]])
            buscaProfundidade(grafo, grafo->arestas[Vinicial][i], visitado, cont+1);
    }
}






void buscaProfundidade_Grafos(struct descritor_grafo *grafo, int Vinicial, int *visitado){
    int i, cont = 1;

    //marca vertices como nao visitados
        for(i=0, i< grafo->max_vertices; i++)
            visitado[i] = 0;

    buscaProfundidade(grafo, Vinicial, visitado, cont);
}
