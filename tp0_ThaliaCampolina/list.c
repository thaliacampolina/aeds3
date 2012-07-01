/////////////////////
//      lista      //
//   encadeada     //
/////////////////////
 
#include "list.h" 
#include "node.h" 
#include <stdio.h>
#include <stdlib.h>


// Cria um nó
Node* NewNode (int k, Node* p, Node* n) {
    Node* i = (Node*) malloc(sizeof (Node));
    i -> key = k;
    i -> prev = p;
    i -> next = n;
    return i;
}
 

void NewList (List* list) {
    list -> size_ = 0;
    list -> status_= 0;
    list -> end_ = (Node*) malloc(sizeof(Node));
    list -> end_->next = list -> end_;
    list -> end_->prev = list -> end_;
}

//Retorna ponteiro para ultimo elemento da lista
Node* back(List* list) {
    return list -> end_->prev;
}



//Retorna ultimo elemento da lista
int ListEnd (List* list ){
    return list-> end_->prev->key;
}


//Retorna primeiro elemento da lista
int ListFirst (List* list){
    return list-> end_-> next-> key;
}

//Retorna chave do no
int Key (Node* node) {
    return node->key;
}


//Insere elemento antes do elemento indicado
Node* insert (List* list, Node* i, int k) {
    Node* node = (Node*) malloc(sizeof (Node));
    node -> prev = i -> prev;
    node -> next = i;
    i->prev->next = node;
    i->prev = node;
    list -> size_++;
    return node;
}


//Insere elemento no final da lista
void InsertBack (int x, List* list) {
    insert(list,back(list),x);
}


//Retorna ponteiro para primeiro elemento da lista
Node* begin(List* list) {
    return list -> end_->next;
}


void erase(List* list, Node* x) {
  x->prev->next = x->next;
  x->next->prev = x->prev;
  free(x);
  list -> size_--;
}

void RemoveFront(List* list) {
  erase(list, begin(list));
}

void clear(List* list) {
    while ( list -> size_ !=0 ) {
printf("%d", list -> size_);
        RemoveFront(list);
    }
    free(list->end_);
}
