#include "bibliotecas.h"


DescAVL *createAVL(){
    DescAVL *AVL = (DescAVL*)malloc(sizeof(DescAVL));
    AVL->raiz = NULL;
    AVL->tamanho = 0;

    return AVL;
}