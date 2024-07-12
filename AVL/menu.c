#include "bibliotecas.h"


int main(void){
    int chave;
    char escolha;
    DescAVL *AVL = NULL;

    do{
        printf("\nDigite:\n[1]create AVL\n[2]insert\n[3]remove\n[4]imprimir\n[0]sair\n");
        setbuf(stdin, NULL);
        scanf(" %c", &escolha);

        switch(escolha){
            case '1':
                AVL = createAVL();
                printf("\nArvore criada com suceso.\n");
                break;

            case '2':
                if(AVL == NULL){
                    printf("Crie a arvore primeiro\n");
                    break;
                }
                printf("\nDigite a chave: ");
                setbuf(stdin, NULL);
                scanf("%d", &chave);
                AVL->raiz = insert((AVL->raiz), chave);
                //AVL->raiz = Balanceamento(AVL->raiz);
                printf("\nChave adicionada com sucesso.\n");
                break;

            case '3':
                if(AVL == NULL){
                    printf("Crie a arvore primeiro\n");
                    break;
                }
                printf("Digite a chave a ser removida: ");
                setbuf(stdin, NULL);
                scanf("%d", &chave);
                AVL->raiz = Remove((AVL->raiz), chave);


                break;

            case '4':
            if(AVL == NULL){
                printf("Crie uma arvore primeiro\n");
                break;
            }
            else if(AVL->raiz == NULL){
                printf("Adicione elementos primeiro\n");
                break;
            }
            printf("Pre order: ");
            Imprime_preorder(AVL->raiz);
            printf("\nIn order: ");
            Imprime_inorder(AVL->raiz);
            printf("\nPos order: ");
            Imprime_posorder(AVL->raiz);
            printf("\n");
            break;

            case '0':
                break;
        }

    }while(escolha != '0');


    return 0;
}