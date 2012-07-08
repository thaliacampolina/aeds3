#include "person.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

PrefList* createPrefList(){
    PrefList* preflist = (PrefList*) malloc(sizeof(PrefList));
    List* pref = NewList();
    preflist->list_=pref;
    return preflist;
}

void insertPref(PrefList* pref, int p){
    InsertBack (pref->list_, p);
}

void dumpPrefList(PrefList* pref) {
    assert(pref);
    assert(pref->list_);
    Node* node = frontList(pref->list_);
    void* p;
    printf ("(PrefList ==> ");
    while ( node != backList(pref->list_) ) {
        if (node!=NULL && getInfo(node)!=NULL) {
            p = getInfo(node);
            printf ("%d ", p);
        }
        node = nextList(pref->list_, node);
    }
    printf (") \n");
}


Person* createPerson(int key, PrefList* prefs){
    Person* pers = (Person*) malloc(sizeof(Person));
    pers -> key_ = key;
    pers -> preferences_ = prefs;
    pers -> status_ = SINGLE;
    return pers;
}
void dumpPerson(Person* person){
    printf("(Person ==> key = %d, status = %d ",
        person->key_,  person->status_);
    dumpPrefList(person->preferences_);
    printf(")");
}

void dumpPersonStatusToOutput(Person* person, FILE* output){
    fprintf(output,"%d %d \n", person->key_,  person->status_);
}

PersonList* createPersonList(){
    PersonList* personlist = (PersonList*) malloc(sizeof(PersonList));
    List* pref = NewList();
    personlist->list_ = pref;
    return personlist;
}

//Insere person no final da lista
void insertPersonInList(PersonList* personList, Person* person){
    InsertBack(personList->list_, (void*) person);
}

void dumpPersonList(PersonList* personList) {
    printf("Lista de alunos: \n");
    assert(personList);
    assert(personList->list_);
    Node* node = frontList(personList->list_);
    while ( node != backList(personList->list_) ) {
        if (node!=NULL && getInfo(node)!=NULL) {
            dumpPerson( (Person*) getInfo(node) );
        }
        node = nextList(personList->list_, node);
    }
}

void dumpPersonListStatusToOutput(PersonList* personList, FILE* output){
    assert(personList);
    assert(personList->list_);
    Node* node = frontList(personList->list_);
    while ( node != backList(personList->list_) ) {
        if (node!=NULL && getInfo(node)!=NULL) {
            dumpPersonStatusToOutput( (Person*) getInfo(node), output );
        }
        node = nextList(personList->list_, node);
    }
}


Person* findPersonWithKey(PersonList* personList, void* key){
    assert(personList);
    assert(personList->list_);
    Node* node = frontList(personList->list_);
    //dumpPerson( (Person*) getInfo(node) );
    Person* person=(Person*) malloc(sizeof(Person));
    person=( (Person*) getInfo(node) );
    
    while ( node != backList(personList->list_) ) {
        if(person->key_==key){
            return person;
        }
        node = nextList(personList->list_, node);
        person=( (Person*) getInfo(node) );

    }

}

