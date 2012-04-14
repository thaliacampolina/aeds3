#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "node.h"
#include "list.h"


float SatisfactionStudents(List* list);

float SatisfactionUniv(List* list);

int isMarried(List* list, int Num_id);

int AllMarried(List* list);

int Prefers(List* listWoman, int Num_id1, int Num_id2);

void Marry (List* list1, int Num1, List* list2, int Num2) ;

void Divorce ( List* list1, int Num1, List* list2, int Num2 );

void SMP (List* list1, List* list2) ;


float SatisfactionStudents(StudentList studList){
    float number;
    int i;
    float v = 0;
    float ratio;
    float percentual = 0;
    //PrefList* node;
    Student student;
    List* prefs;
    Node* univ;
    stud_number = (float) studList.size_;
    univ_number = (float) prefs.size_; 
    for (student = begin(studList); student != back(studList); student = node->next){
        for (univ = begin(prefs); univ != back(prefs); univ = prefs -> next){
            v++;
            if(univ -> key == student.status_){
            break;
            ratio = (v)/(univ_number);
            }
        }
        percentual = percentual + ratio;
    }
    return (percentual*100)/stud_number;
}

float SatisfactionUniv(List* list){
    //TODO
    return NULL;
}

int isMarried(StudentList* studList, int Num_id){
    Student student;
    for (student = begin(studList); student != back(studList); student = node->next){
        if (student->key = Num_id) {
            break;
        }
    }
        if(student.status_ != SINGLE){
        return 1;
    }
    return 0;
}

int AllMarried(StudentList* studList){
    Student student;
    int i=0;
    for (student = begin(studList); student != back(studList); student = node->next){
        i++;
        if(isMarried(studList, i)){
        return 0;
    }
    return 1;
}


//Funcao que checa se o Estudante de id1 prefere outro Homem ao homem de id2.Se preferir id1 retorna 1.
// TODO

int Prefers(StudentList* studList, int Num_id1, int Num_id2){
    Node* men;
    int status = listWoman[Num_id1-1].status_;
    men = begin(listWoman) ;
    while (Key(men) != ListEnd(listWoman) ){
        if ( Key(men) == status){
            return 0;
        }
        if ( Key(men) == Num_id2){
            return 1;
        }
            men = men->next;
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
            woman = ListFirst(&mensCrushes[i]);
            if (womansCrushes[woman].status_ == 0 || Prefers(womansCrushes, woman, womansCrushes[woman].status_) == 1){
                Marry(mensCrushes, i , womansCrushes, woman );
            } else {
                Divorce(mensCrushes, i , womansCrushes, woman );
                Marry (mensCrushes,Prefers(womansCrushes, woman, womansCrushes[woman].status_), womansCrushes, woman);
            }
        }
    }
}
