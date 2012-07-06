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

int isMarried(PersonList* personList , int key){
    Person* person;
    person=findPersonWithKey(personList, key);
    if(person->preferences_->list_->status_!= 0){
        return 1;
    }
    return 0;
}

int AllMarried(PersonList* personList){
    int i, number;
    number = personList->list_->size_;
    for (i = 0; i < number; i++){
        if(isMarried(personList, i)){
        return 0;
        }
    }
    return 1;
}


//Funcao que checa se a Mulher de id1 prefere outro Homem ao  homem de id2.Se preferir id1 retorna 1.
int Prefers(PersonList* listWoman, int Num_id1, int Num_id2){
    Node* men;
    Person* woman;
    
    woman=findPersonWithKey(listWoman, Num_id1);
    int status = woman->status_;
    men = frontList(woman->preferences_);
    while (getInfo(men) != lastElement(listWoman) ){
        if ( getInfo(men) == status){
            return 0;
        }
        if ( getInfo(men) == Num_id2){
            return 1;
        }
            men = men->next_;
   }
}


void Marry (PersonList* list1, int Num1, PersonList* list2, int Num2) {
    Person* person1;
    person1=findPersonWithKey(list1, Num1);
    Person* person2;
    person2=findPersonWithKey(list2, Num2);
    person1->status_= Num2;
    person2->status_= Num1;
}


void Divorce ( PersonList* list1, int Num1, PersonList* list2, int Num2 ){
    Person* person1;
    person1=findPersonWithKey(list1, Num1);
    Person* person2;
    person2=findPersonWithKey(list2, Num2);
    person1->status_= 0;
    person2->status_= 0;
}

void SMP (PersonList* menCrushes, PersonList* womenCrushes) {
    int  i, number;
    Node* node;
    Person* woman;
 //   number = mensCrushes[0].size_;
    while (!AllMarried (menCrushes)){
        node = frontList(menCrushes->list_);
        while ( node != backList(menCrushes->list_) ) {    
            woman = firstElement(womenCrushes->list_);
            if (woman->status_ == 0 || Prefers(womenCrushes, woman, womenCrushes->list_->status_) == 1){
                Marry(menCrushes, i , womenCrushes, woman );
            } else {
                Divorce(menCrushes, i , womenCrushes, woman );
                Marry (menCrushes,Prefers(womenCrushes, woman, womenCrushes->list_->status_), womenCrushes, woman);
            }
        node = nextList(womenCrushes->list_, node);
        }
    }
}