#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"

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

int isMarried(List* list, int Num_id){
    if(list[Num_id-1].status_ != 0){
        return 1;
    }
    return 0;
}

int AllMarried(List* list){
    int i, number;
    number = list[0].size_;
    for (i = 0; i < number; i++){
        if(isMarried(list, i)){
        return 0;
        }
    }
    return 1;
}


//Funcao que checa se a Mulher de id1 prefere outro Homem ao  homem de id2.Se preferir id1 retorna 1.
int Prefers(List* listWoman, int Num_id1, int Num_id2){
    Node* men;
    int status = listWoman[Num_id1-1].status_;
    men = frontList(listWoman) ;
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


void Marry (List* list1, int Num1, List* list2, int Num2) {
    list1[Num1-1].status_= Num2;
    list2[Num2-1].status_= Num1;
}


void Divorce ( List* list1, int Num1, List* list2, int Num2 ){
    list1[Num1-1].status_= 0;
    list2[Num2-1].status_= 0;
}

void SMP (List* mensCrushes, List* womansCrushes) {
    int woman, i, number;
    number = mensCrushes[0].size_;
    while (!AllMarried (mensCrushes)){
        for (i = 0;  i< number; i++){
            woman = firstElement(&mensCrushes[i]);
            if (womansCrushes[woman].status_ == 0 || Prefers(womansCrushes, woman, womansCrushes[woman].status_) == 1){
                Marry(mensCrushes, i , womansCrushes, woman );
            } else {
                Divorce(mensCrushes, i , womansCrushes, woman );
                Marry (mensCrushes,Prefers(womansCrushes, woman, womansCrushes[woman].status_), womansCrushes, woman);
            }
        }
    }
}
