/////////////////////
//      lista      //
//   encadeada     //
/////////////////////
 
#include "list.h" 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// Cria um no
Node* NewNode (void* info, Node* prev, Node* next) {
    assert(prev);
    assert(next);
    Node* i = (Node*) malloc(sizeof (Node));
    i->info_ = info;
    i->prev_ = prev;
    i->next_ = next;
    return i;
}
 
//Cria lista vazia
List* NewList () {
    List* list = (List*) malloc(sizeof(List));
    list->size_ = 0;
    list->end_ = (Node*) malloc(sizeof(Node));
    list->end_->next_ = list -> end_;
    list->end_->prev_ = list -> end_;
    return list;
}

unsigned int emptyList(List* list) {
    return list->end_->next_ == list->end_;
}

//Retorna ponteiro para a posicao apos o ultimo elemento da lista (sentinela)
Node* backList(List* list) {
    assert(list);
    assert(list->end_);
    return list->end_;
}

//Retorna ponteiro para primeiro elemento da lista
Node* frontList(List* list) {
    assert(list);
    assert(list->end_);
    return list->end_->next_;
}

Node* nextList(List* list, Node* current) {
    assert(list);
    assert(current);
    return current->next_;
}


//Retorna valor ultimo elemento da lista
void* lastElement(List* list){
    assert(list);
    assert(list->end_);
    assert(list->end_->prev_);
    // if empty (list) return ???;
    return list-> end_->prev_->info_;
}

//Retorna primeiro elemento da lista
void* firstElement (List* list){
    assert(list);
    assert(list->end_);
    assert(list->end_->next_);
    return list-> end_->next_->info_;
}

//Retorna a informacao
void* getInfo(Node* node) {
    assert(node);
    return node->info_;
}

//Insere elemento antes do elemento "i" indicado
void insert (List* list, Node* i, void* info) {
    Node* node = NewNode(info, i->prev_, i);
    i->prev_->next_ = node;
    i->prev_ = node;
    list->size_++;
}


//Insere elemento no final da lista
void InsertBack (List* list, void* info) {
    insert(list, backList(list), info);
}


// Apaga node
void erase(List* list, Node* node) {
  assert(list);
  assert(node);
  assert(list->end_);
  assert(list->end_!=node);
  node->prev_->next_ = node->next_;
  node->next_->prev_ = node->prev_;
  free(node);
  list->size_--;
}

void RemoveFront(List* list) {
  assert(emptyList(list)==0);
  erase(list, frontList(list));
}

void clear(List* list) {
    while ( list -> size_ != 0 ) {
        RemoveFront(list);
    }
}

void deleteList(List* list){
    clear(list);
    free(list->end_);
    free(list);
}

void PrintList(List* list){
    Node* node; 
    printf("LIST = ");
    for (node = frontList(list); node != backList(list); node = node->next_){
        printf("%s, ", node->info_);
    }
    printf("\n");
}

