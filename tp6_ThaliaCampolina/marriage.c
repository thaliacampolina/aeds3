#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "person.h"

float Satisfaction(List* list){
    float number;
    int i;
    float v = 0;
    Node* node;
    number = (float) list[0].size_;
    for (i=0; i < number; i++){
       for (node = frontList(list); node != backList(list); node = node->next_){
           v++;
           if(node->info_ == list[i].status_){
            break;
           }
        }
    }
    return v/number;
}

//return 1 if person is Married
int isMarried(PersonList* personList , int key){
    Person* person=(Person*) malloc(sizeof(Person));
    person=findPersonWithKey(personList, key);
    //dumpPerson(person);

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

int getPreferred(Person* person)
{
    return firstElement(person->preferences_->list_);
    
}

int getHusband(Person* woman)
{
    return woman->status_;
}

//retorna o mais desejado
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
    //Node* node;
    //Person* man;
    Person* woman;
    int id_woman;

    Person* man=(Person*) malloc(sizeof(Person));
    
    
    Node* node = frontList(menList->list_);
    Node* nodePrefListMan ;
    man=( (Person*) getInfo(node) );

    while (AllMarried (menList,number)==0){
        node = frontList(menList->list_);
        man=( (Person*) getInfo(node) );
        while ( node != backList(menList->list_) ) {    
            
            nodePrefListMan=frontList(man->preferences_->list_);
            while ( nodePrefListMan != backList(man->preferences_->list_) && man->status_==-1) {
                
                
                id_woman=getInfo(nodePrefListMan);
                woman=findPersonWithKey(womenList,id_woman);
                //printf("id_woman=%d\n",id_woman);
                //int i;scanf("%d",&i);
                if(isMarried(womenList,woman->key_)==0)
                {
                     //printf("dumpando mulher:\n");dumpPerson(woman);
            
                     Marry(menList,man->key_,womenList,woman->key_);
                }
                else
                {
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
        
        //int i;scanf("%d",&i);
        //break;

    }
}
