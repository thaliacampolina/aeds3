/////////////////////
//      lista      //
//   encadeada     //
/////////////////////


#ifndef _list_h_
#define _list_h_
 
#include "node.h"


typedef struct list {
    Node* end_;
    int size_;
    int status_;
} List;


// Cria um nó
Node* NewNode (int k, Node* p, Node* n); 
 

void NewList (List* list);

//Retorna ponteiro para ultimo elemento da lista
Node* back(List* list);

//Retorna ponteiro para primeiro elemento da lista
Node* begin(List* list);


//Retorna ultimo elemento da lista
int ListEnd (List* list );


//Retorna primeiro elemento da lista
int ListFirst (List* list);

//Retorna chave do no
int Key (Node* node);

//Insere elemento no final da lista
void InsertBack (int x, List* list);

//Insere elemento antes do elemento indicado
Node* insert (List* list, Node* i, int k);


void erase(List* list, Node* x);

void RemoveFront(List* list);

void clear(List* list);

#endif
