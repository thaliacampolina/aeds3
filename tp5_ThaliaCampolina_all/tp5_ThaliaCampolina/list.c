
#include "list.h"                   
#include <stdio.h>                 
#include <stdlib.h>
#include <assert.h>    


Node* NewNode(char* word, Node* next, Node* prev){
    assert(prev);
    assert(next);
    Node* node = (Node*)malloc(sizeof(Node));
    node->info_ = (char*)calloc(100,sizeof(char)); 
    node->suggest_=(char*)calloc(100,sizeof(char)); 
    node->dif_=100;
    node->next_ = next;
    node->prev_ = prev;
    strcpy(node->info_, word);
    return node;
}

List* NewList(){
    List* list = (List*) malloc(sizeof(List));          
    list->size_ = 0;                             
    list->end_ = (Node*) malloc(sizeof(Node));
    list->end_->next_ = list -> end_;
    list->end_->prev_ = list -> end_;                         
    return list; 
}

void insert(List* list, Node* i, char* info){
    Node* node = NewNode(info, i->prev_, i);
    i->prev_->next_ = node;
    i->prev_ = node;
    list->size_++;
} 


Node* backList(List* list) {
    assert(list);
    assert(list->end_);
    return list->end_;
}

void InsertBack (List* list, char* info) {
    insert(list, backList(list), info);
}

char* firstElement (List* list){
    assert(list);
    assert(list->end_);
    assert(list->end_->next_);
    return list-> end_->next_->info_;
}

Node* frontList(List* list) {
    assert(list);
    assert(list->end_);
    return list->end_->next_;
}

void PrintList(List* list){
    Node* node;
    printf("LIST = ");
    int i = 0;
    for (node = frontList(list); node != backList(list); node = node->next_){
        printf("%s ", node->info_);
        i++;
        if(i==12){
            break;
        }
    }
    printf("\n");
}


