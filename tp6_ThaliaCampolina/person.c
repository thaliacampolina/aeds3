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
    InsertBack (pref->list_, (void*) p);
}

void dumpPrefList(PrefList* pref) {
    assert(pref);
    assert(pref->list_);
    Node* node = frontList(pref->list_);
    printf ("(PrefList ==> ");
    while ( node != backList(pref->list_) ) {
        if (node!=NULL && getInfo(node)!=NULL) {
            int *p = getInfo(node);
            printf ("%d ", p->university);
        }
        node = nextList(pref->list_, node);
    }
    printf (") ");
}


Person* createPerson(int key, int grade, PrefList* prefs){
    Person* pers = (Person*) malloc(sizeof(Person));
    pers -> key_ = key;
    pers -> grade_ = grade;
    pers -> preferences_ = prefs;
    pers -> status_ = SINGLE;
    return pers;
}
void dumpPerson(Person* person){
    printf("(Person ==> key = %d, grade = %d, status = %d ",
        person->key_, person->grade_, person->status_);
    dumpPrefList(person->preferences_);
    printf(")");
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
    printf("Lista de alunos: ");
    assert(personList);
    assert(personList->list_);
    Node* node = frontList(personList->list_);
    while ( node != backList(personList->list_) ) {
        if (node!=NULL && getInfo(node)!=NULL) {
            dumpPerson( (Person*) getInfo(node) );
        }
        node = nextList(personList->list_, node);
    }
    printf("\n");
}

Person* findPersonWithKey(PersonList* personList, int key){
    Node* node = frontList(personList->list_);
    while (node != backList(personList->list_) ) {
        Person* person = (Person*) getInfo(node);
            if( person->key_ == key ){
                return person;
            }
            node = nextList(personList->list_, node);
    }
    return NULL;
}


                                                                                                            88,0-1        Fim

