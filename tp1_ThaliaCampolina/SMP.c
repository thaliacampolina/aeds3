#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SMP.h"



// Check if the student is already approved by an university
int isApproved(Student* student){
    if(student->status_ > 0){
        return 1;
    }
    return 0;
}

int AllApproved(StudentList* studList){
    Node* node = frontList(studList->list_);
    while ( node != backList(studList->list_) ) {
        if (isApproved((Student*) getInfo(node))){
            return 0;
        }
        node = nextList(studList->list_, node);
    }
    return 1;
}


//Funcao que checa se o Estudante prefere outra Universidade a de entrada da funcao. 
//Se preferir id2, retorna 1.
int StudentPrefersUniversity(Student* student, University* university){
    Node* node = frontList(student->preferences_->list_);
    while ( node != backList(student->preferences_->list_) ) {
        if ( university->key_ == (int*) getInfo(node)){
            return 1;
        } else {
            return 0;
        }
    }
		node = nextList(student->preferences_->list_, node);
}


void AllocOnUniversity (University* university, Student* student) {
    student->status_= university->key_;
}


void Discard ( University* university, Student* student ){
    student->status_= 0;
 }

//privilegia o estudante, logo, comeca com a universidade escolhendo o estudante
void SMP_heuristica1 (StudentList* studentList, UniversityList* universityList) {
    while (!AllApproved (studentList)){
        University* university = frontList(universityList->list_);
        while (university != backList(universityList->list_)){        
                 Student* student_univList = frontList((University*) university->prefs_);
            while ( student_univList != backList(universityList->list_) ) {
                if (student_univList->status_ < 1 || 
                    StudentPrefersUniversity(student_univList, university) == 1){
                    AllocOnUniversity(university,student_univList);
                } else {
                    student_univList = nextList((University*) university->prefs_, student_univList);
            }
            university = nextList(universityList, university);
        }
    }
}


