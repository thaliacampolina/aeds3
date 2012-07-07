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
    Person* person;
    person=findPersonWithKey(personList, key);
//person->status_ = 8;
puts("bobo");
printf("status = %d \n", person->status_);
    if(person->status_ != -1){
        return 1;
    }
    return 0;
}

//if all men or all women are married, return 1. Number = number of person, given in the input file
int AllMarried(PersonList* personList, int number){
    int i;
    for (i = 1; i <= number; i++){
        if(isMarried(personList, i)){
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
    Node* node;
    Person* man;
    Person* woman;
    int id_woman;
 //   number = mensCrushes[0].size_;
    while (!AllMarried (menList,number)){
puts("ti cole mano");
        man = frontList(menList->list_);
        while ( man != backList(menList->list_) ) {    
puts("faaaaala fiii");
            id_woman = getInfo((firstElement(man->preferences_->list_)));
            woman=findPersonWithKey(womenList, id_woman);
            if (woman->status_ == 0 || Prefers(womenList, woman->key_, man->key_,number) == 1){
                Marry(menList, man->key_ , womenList, woman->key_ );
            } else {
                Divorce(menList, man->key_ , womenList, woman->key_ );
                Marry (menList,man->key_,womenList,woman->key_);
            }
        man = nextList(menList->list_,man);
        }
    }
}
