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
    if(person.status_ != 0){
        return 1;
    }
    return 0;
}

int AllMarried(PersonList* personList){
    int i, number;
    number = personList[0].size_;
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
    woman=findPersonWithKey(listWoman, key);
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
    person1=findPersonWithKey(personList, key);
    Person* person2;
    person2=findPersonWithKey(personList, key);
    person1->status_= Num2;
    person2->status_= Num1;
}


void Divorce ( PersonList* list1, int Num1, PersonList* list2, int Num2 ){
    Person* person1;
    person1=findPersonWithKey(personList, key);
    Person* person2;
    person2=findPersonWithKey(personList, key);
    person1->status_= 0;
    person2->status_= 0;
}

void SMP (PersonList* menCrushes, PersonList* womenCrushes) {
    int woman, i, number;
    Node* node;
 //   number = mensCrushes[0].size_;
    while (!AllMarried (menCrushes)){
        node = frontList(menCrushes->preferences_->list_);
        while ( node != backList(menCrushes->personList->list_) ) {    
            woman = firstElement(womenCrushes->preferences_->list_);
            if (woman.status_ == 0 || Prefers(womansCrushes, woman, womansCrushes[woman].status_) == 1){
                Marry(mensCrushes, i , womansCrushes, woman );
            } else {
                Divorce(mensCrushes, i , womansCrushes, woman );
                Marry (mensCrushes,Prefers(womansCrushes, woman, womansCrushes[woman].status_), womansCrushes, woman);
            }
        node = nextList(womenCrushes->preferences_->list_, node);
        }
    }
}
