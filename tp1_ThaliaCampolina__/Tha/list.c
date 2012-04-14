/////////////////////
//      lista      //
//   encadeada     //
/////////////////////
 
#include "list.h" 
#include "node.h" 
#include "student.h" 
#include "student.c" 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// Cria um no
Node* NewNode (int k, Node* p, Node* n) {
    assert(p);
    assert(n);
    Node* i = (Node*) malloc(sizeof (Node));
    i -> key = k;
    i -> prev = p;
    i -> next = n;
    return i;
}
 
//Cria lista vazia
List* NewList () {
    List* list = (List*) malloc(sizeof(List));
    list -> size_ = 0;
    list -> end_ = (Node*) malloc(sizeof(Node));
    list -> end_->next = list -> end_;
    list -> end_->prev = list -> end_;
    return list;
}

//Retorna ponteiro para ultimo elemento da lista
Node* back(List* list) {
    assert(list);
    assert(list->end_);
    return list -> end_;
}

//Retorna valor ultimo elemento da lista
int ListEnd (List* list ){
    assert(list);
    assert(list->end_);
    assert(list->end_->prev);
    // if empty (list) return ???;
    return list-> end_->prev->key;
}


//Retorna primeiro elemento da lista
int ListFirst (List* list){
    assert(list);
    assert(list->end_);
    assert(list->end_->next);
    return list-> end_-> next-> key;
}

//Retorna chave do no
int Key (Node* node) {
    return node->key;
}


//Insere elemento antes do elemento "i" indicado
void insert (List* list, Node* i, int k) {
    Node* node = (Node*) malloc(sizeof(Node));
    node -> next = i;
    node -> prev = i -> prev;
    i->prev->next = node;
    i->prev = node;
    list -> size_++;
    node -> key = k;
}


//Insere elemento no final da lista
void InsertBack (List* list, int x) {
    insert(list,back(list),x);
}


//Retorna ponteiro para primeiro elemento da lista
Node* begin(List* list) {
    assert(list->end_);
    return list->end_->next;
}

// Apaga node
void erase(List* list, Node* node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
  free(node);
  list -> size_--;
}

void RemoveFront(List* list) {
  erase(list, begin(list));
}

void clear(List* list) {
    while ( list -> size_ !=0 ) {
        RemoveFront(list);
    }
}

void deleteList(List* list){
    clear(list);
    free(list->end_);
}

void PrintList(List* list){
    Node* node; 
    for (node = begin(list); node != back(list); node = node->next){
        printf("%d, ", node->key);
    }
    printf("\n");
}

