/////////////////////
//      lista      //
//   encadeada     //
/////////////////////


#ifndef _list_h_
#define _list_h_
 
typedef struct node {
    struct node* next;
    struct node* prev;
    int key;
} Node;

typedef struct list {
    Node* end_;
    int size_;
} List;


// Cria um node
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
void InsertBack (List* list, int x);

//Insere elemento antes do elemento indicado
void insert (List* list, Node* i, int k);


void erase(List* list, Node* x);

void RemoveFront(List* list);

void clear(List* list);

void deleteList(List* list);

//Imprime lista na tela, para debug!
void PrintList(List* list);
#endif

