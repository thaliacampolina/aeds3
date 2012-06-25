#ifndef _list_h_
#define _list_h_



typedef struct node {
    struct node* next_;
    struct node* prev_;
    char *info_;
    char *suggest_;
    int dif_;
} Node;

typedef struct list {
    Node* end_;
    int size_;
} List;



Node* NewNode(char* word, Node* next, Node* prev);
List* NewList();
void insert(List* list, Node* i, char* info);
Node* backList(List* list) ;
void InsertBack (List* list, char* info) ;
char* firstElement (List* list);
void PrintList(List* list);
Node* frontList(List* list) ;

#endif
