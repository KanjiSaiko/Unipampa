#include "bibliotecas.h"


int main(void){
    int chave;
    int escolha;
    Nodo *nodo = NULL;
    DescAVL *AVL = NULL;

    do{
        printf("\n\nDigite:\n[1]Create AVL\n[2]Insert\n[3]Remove\n[4]Imprime\n[0]Sair\n");
        setbuf(stdin, NULL);
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                AVL = createAVL();
                break;

            case 2:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                nodo = createNodo(chave);
                AVL->raiz = insert(AVL->raiz, nodo);
                break;

            case 3:
                printf("Digite a chave a ser removida: ");
                scanf("%d", &chave);
                AVL->raiz = remocao(AVL->raiz, chave);
                break;

            case 4:
                printf("\nImprimindo PreOrder: ");
                Imprime_preorder(AVL->raiz);

                printf("\nImprimindo InOrder: ");
                Imprime_inorder(AVL->raiz);
                
                printf("\nImprimindo PosOrder: ");
                Imprime_posorder(AVL->raiz);

                break;
            case 0:
                break;
        }

    }while(escolha != 0);


    return 0;
}