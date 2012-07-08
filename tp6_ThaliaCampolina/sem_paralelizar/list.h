/////////////////////
//      lista      //
//   encadeada     //
/////////////////////


#ifndef _list_h_
#define _list_h_
 
typedef struct node {
    struct node* next_;
    struct node* prev_;
    void* info_;
} Node;

typedef struct list {
    Node* end_;
    int size_;
    int status_;
} List;


// Cria um node
Node* NewNode (void* info, Node* prev, Node* next);

// Cria uma lista
List* NewList ();

// Verifica se uma lista esta vazia
unsigned int emptyList(List* list);

//Retorna ponteiro para primeiro elemento da lista
Node* frontList(List* list);
//Retorna ponteiro para a posicao apos o ultimo elemento da lista (sentinela)
Node* backList(List* list);
//Retorna primeiro elemento da lista
void* firstElement (List* list);
//Retorna ultimo elemento da lista
void* lastElement(List* list);
//Retorna o proximo elemento da lista
Node* nextList(List* list, Node* current);

// Retorna a informacao do no
void* getInfo(Node* node);

//Insere elemento antes do elemento indicado
void insert (List* list, Node* i, void* info);

//Insere elemento no final da lista
void InsertBack (List* list, void* info);

void erase(List* list, Node* node);
void RemoveFront(List* list);
void clear(List* list);
void deleteList(List* list);

//Imprime lista na tela, para debug!
void PrintList(List* list);

#endif

