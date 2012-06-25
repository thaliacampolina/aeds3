#include "university.h"

#include "list.h"
#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void* createUniversity(int key, int vagas) {
    University* univ = (University*) malloc(sizeof(University));
    univ->key_ = key;
    univ->vagas_ = vagas;
    univ->prefs_ = createStudentList();
    return univ;
}

void dumpUniversity(University* university){
    printf("(University ==> key = %d, vagas = %d, ", 
        university->key_, university->vagas_ );
    dumpStudentList(university->prefs_);
    printf(")"); 
}


void* createUniversityList(){
    UniversityList* universitylist = (UniversityList*) malloc(sizeof(UniversityList));
    List* pref = NewList();
    universitylist->list_ = pref;
    return universitylist;
}


void insertUniversityInUniversityList(UniversityList* universityList, University* university){
    InsertBack(universityList->list_, (void*) university);
}

void dumpUniversityList(UniversityList* universityList) {
    printf("Lista de universidades: ");
    assert(universityList);
    assert(universityList->list_);
    Node* node = frontList(universityList->list_);
    while ( node != backList(universityList->list_) ) {
        if (node!=NULL && getInfo(node)!=NULL) {
            dumpUniversity( (University*) getInfo(node) );
            printf(" ");
        }
        node = nextList(universityList->list_, node);
    }
    printf("\n");
}



University* findUniversityWithKey(UniversityList* universityList, int key){
    Node* node = frontList(universityList->list_);
    while (node != backList(universityList->list_) ) {
        University* university = (University*) getInfo(node);
            if( university->key_ == key ){
                return university; 
            } 
            node = nextList(universityList->list_, node);
    }
    return NULL;
}
void insertStudentInUniversityList(University* university, Student* student){
    if (emptyList(university->prefs_->list_)){
        InsertBack(university->prefs_->list_, (void*) student);
    } else {
        Node* node = frontList(university->prefs_->list_);
        Student* existingStudent =(Student*) getInfo(node);
        while (node != backList(university->prefs_->list_)) {
            if (existingStudent->grade_ < student->grade_) {
                insert(university->prefs_->list_,node, (Student*) student );
                return;
            }
            node = nextList(university->prefs_->list_, node);
        }
        InsertBack(university->prefs_->list_, (void*) student);
    } 
}


