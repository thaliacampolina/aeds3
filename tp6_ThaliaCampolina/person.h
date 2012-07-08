#ifndef _person_h_
#define _person_h_
#include "list.h"
#include <stdio.h>

#define SINGLE -1

typedef struct prefList {
    List* list_;
} PrefList;

//Creates PrefList
PrefList* createPrefList();

//Inst preferece(id oposite sex) in PrefList  
void insertPref(PrefList* pref, int p);                

//dumps PrefList on screen                                     
void dumpPrefList(PrefList* pref);            
                                                             
typedef struct person {                                       
    int key_;    // line in the original file                  
    PrefList* preferences_; // list of person preferences  
    int status_; // SINGLE or MARRIED
} Person;

//Criates a new person
Person* createPerson(int key, PrefList* prefs);

//dumps Person on screen
void dumpPerson(Person* person);

//dumps Person status in output file
void dumpPersonStatusToOutput(Person* person, FILE* output);

typedef struct personList {
    List* list_;
} PersonList;
 

//Criates PersonList (a list of persons(man or woman))
PersonList* createPersonList();

//Find person when is given its key
Person* findPersonWithKey(PersonList* personList, void* key);

//Insert preference in a PersonList
void insertPersonInList(PersonList* personList, Person* person);
//dumps PersonList on screen
void dumpPersonList(PersonList* personList);

//dumps status of all persons from PersonList on screen
void dumpPersonListStatusToOutput(PersonList* personList, FILE* output);

#endif

