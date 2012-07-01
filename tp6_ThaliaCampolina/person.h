#ifndef _person_h_
#define _person_h_
#include "list.h"

#define SINGLE -1

typedef struct prefList {
    List* list_;
} PrefList;

//Cria PrefList
PrefList* createPrefList();
//Insere preferência(id do sexo oposto ) na lista de PrefList  
void insertPref(PrefList* pref, int p);                
//Plota a PrefList na tela                                     
void dumpPrefList(PrefList* pref);            
                                                             
typedef struct person {                                       
    int key_;    // line in the original file                  
    PrefList* preferences_; // list of person preferences  
    int status_; // SINGLE or MARRIED
} Person;

//Cria nova pessoa
Person* createPerson(int key, int grade, PrefList* prefs);
//Plota informacoes da pessoa na tela
void dumpPerson(Person* person);


typedef struct personList {
    List* list_;
} PersonList;

//Cria Lista de Pessoas
PersonList* createPersonList();
//Insere preferencia na Lista de uma pessoa
void insertPersonInList(PersonList* personList, Person* person);
//Plota Lista de Pessoas na tela
void dumpPersonList(PersonList* personList);


#endif

