#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "list.h"

int main () {
    List* Thatha;
    Thatha=NewList();
    PrintList(&Thatha);
    InsertBack(&Thatha,1);
    InsertBack(&Thatha,2);
    printf("Lista: ");
    PrintList(&Thatha);
    InsertBack(&Thatha,3);
    InsertBack(&Thatha,4);
    InsertBack(&Thatha,5);
    printf("Lista de novo: ");
    PrintList(&Thatha);
    printf( "\n");
    printf( " ultimo elemento: %d \n" ,ListEnd(&Thatha));
    RemoveFront(&Thatha);
    printf("depois de remover o primeiro, a lista e:");
    PrintList(&Thatha);
    clear(&Thatha);
    printf("Agora dei o clear, e a lista e:");
    PrintList(&Thatha);

    return 0;
}


