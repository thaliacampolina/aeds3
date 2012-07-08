#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "person.h"
#include <assert.h>

//return 1 if person is Married
int isMarried(PersonList* personList , int key){
    Person* person=(Person*) malloc(sizeof(Person));
    person=findPersonWithKey(personList, key);

    if(person->status_ != -1){
        return 1;
    }
    return 0;
}

//if all men or all women are married, return 1. Number = number of person, given in the input file
int AllMarried(PersonList* personList, int number){

    int i;
    for (i = 1; i <= number; i++){
        if(isMarried(personList, i)==0){

        return 0;
        }
    }

    return 1;
}

//Checks if id_woman prefers id_man or the one she is married. If she prefers id_man, return 1
int Prefers(PersonList* listWoman, int id_woman, int id_man, int number){
    int i = 0;
    Node* node;
    Person* woman;
    
    woman=findPersonWithKey(listWoman, id_woman);
    int status = woman->status_;
    node = frontList(woman->preferences_->list_);
    while (i<number){
        if (getInfo(node) == status){
            return 0;
        }
        if (getInfo(node) ==id_man){
            return 1;
        }
        i++;
        node = node->next_;
    }
    return -1;
}


//return the preferred man given two options
int mostPreferred(Person* woman,int id_1,int id_2)
{
    Node* node = frontList(woman->preferences_->list_);
    
    while ( node != backList(woman->preferences_->list_) ) {
        if(getInfo(node)==id_1){
            return id_1;
        }
        if(getInfo(node)==id_2){
            return id_2;
        }
        node = nextList(woman->preferences_->list_, node);
    }
    return 0;//not found
    
}

//Marries 
void Marry (PersonList* menList, int id_man, PersonList* womenList, int id_woman) {
    Person* man;
    man=findPersonWithKey(menList, id_man);
    Person* woman;
    woman=findPersonWithKey(womenList, id_woman);
    man->status_= id_woman;
    woman->status_= id_man;
}

//Divorces
void Divorce (PersonList* menList, int id_man, PersonList* womenList, int id_woman) {
    Person* man;
    man=findPersonWithKey(menList, id_man);
    Person* woman;
    woman=findPersonWithKey(womenList, id_woman);
    man->status_= -1;
    woman->status_= -1;
}

//Stable Marriage Problem function
void SMP (PersonList* menList, PersonList* womenList, int number) {
    Person* woman;
    int id_woman;

    Person* man=(Person*) malloc(sizeof(Person));
    
    
    Node* node = frontList(menList->list_);
    Node* nodePrefListMan ;
    man=( (Person*) getInfo(node) );
    //While all man are single
    while (AllMarried (menList,number)==0){
        node = frontList(menList->list_);
        man=( (Person*) getInfo(node) );
        //Goes through menList 
        while ( node != backList(menList->list_) ) {    
            //Goes throgh each men pref list
            nodePrefListMan=frontList(man->preferences_->list_);
            while ( nodePrefListMan != backList(man->preferences_->list_) && man->status_==-1) {
                
                
                id_woman=getInfo(nodePrefListMan);
                woman=findPersonWithKey(womenList,id_woman);
                //if woman is single, man marries her
                if(isMarried(womenList,woman->key_)==0){
            
                     Marry(menList,man->key_,womenList,woman->key_);
                }
                //if woman is married, she picks the men she prefers
                else{
                     if(mostPreferred(woman,man->key_,woman->status_)==man->key_)
                     {
                         Divorce(menList,woman->status_,womenList,woman->key_);
                         Marry(menList,man->key_,womenList,woman->key_);
                    
                     }
                }
            
                nodePrefListMan = nextList(man->preferences_->list_, nodePrefListMan);
            }
            

            node = nextList(menList->list_, node);
            man=( (Person*) getInfo(node) );

        }
        
    }
}

//Calculates General Satisfaction
int satisfactionGeneral(PersonList* menList, PersonList* womenList){
    return satisfactionBySex(menList)+satisfactionBySex(womenList);
}

//Calculates man or woman satisfaction
int satisfactionBySex(PersonList* personList){
    int i=0;
    assert(personList);
    assert(personList->list_);
    Person* person;
    Node* node = frontList(personList->list_);
    Node* nodePref;
    while ( node != backList(personList->list_) ) {
        person=(Person*) getInfo(node);
        nodePref = frontList(person->preferences_);
        while(nodePref != backList(person->preferences_)){
            if(person->status_ == getInfo(nodePref)){
                break;
            }
            i++;
            nodePref = nextList(personList, nodePref);
        }
        node = nextList(personList->list_, node);
    }
    return i;
}


//Writes the tree satisfaction types in output file (man, woman, general)
void writeOutputSatisfaction(PersonList* menList, PersonList* womenList,int number, FILE* output){
    fprintf(output,"%.3f\n",(float)satisfactionGeneral(menList,womenList)/(2*number)); 
    fprintf(output,"%.3f\n",(float)satisfactionBySex(menList)/number);
    fprintf(output,"%.3f\n",(float)satisfactionBySex(womenList)/number);
    
}

