#include "student.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

PrefList* createPrefList(){
    PrefList* preflist = (PrefList*) malloc(sizeof(PrefList));
    List* pref = NewList();
    preflist->list_=pref;
    return preflist;
}

void insertPref(PrefList* pref, Preference* p){
    InsertBack (pref->list_, (void*) p);
}

void dumpPrefList(PrefList* pref) {
    assert(pref);
    assert(pref->list_);
    Node* node = frontList(pref->list_);
    printf ("(PrefList ==> ");
    while ( node != backList(pref->list_) ) {
        if (node!=NULL && getInfo(node)!=NULL) {
            Preference *p = getInfo(node);
            printf ("%d ", p->university);
        }
        node = nextList(pref->list_, node);
    }
    printf (") ");
}


Student* createStudent(int key, int grade, PrefList* prefs){
    Student* stud = (Student*) malloc(sizeof(Student));
    stud -> key_ = key;
    stud -> grade_ = grade;
    stud -> preferences_ = prefs;
    stud -> status_ = SINGLE;
    return stud;
}

void dumpStudent(Student* student){
    printf("(Student ==> key = %d, grade = %d, status = %d ", 
        student->key_, student->grade_, student->status_);
    dumpPrefList(student->preferences_);
    printf(")"); 
}

StudentList* createStudentList(){
    StudentList* studentlist = (StudentList*) malloc(sizeof(StudentList));
    List* pref = NewList();
    studentlist->list_ = pref;
    return studentlist;
}

//Insere student no final da lista
void insertStudentInList(StudentList* studentList, Student* student){
    InsertBack(studentList->list_, (void*) student);
}

void dumpStudentList(StudentList* studentList) {
    printf("Lista de alunos: ");
    assert(studentList);
    assert(studentList->list_);
    Node* node = frontList(studentList->list_);
    while ( node != backList(studentList->list_) ) {
        if (node!=NULL && getInfo(node)!=NULL) {
            dumpStudent( (Student*) getInfo(node) );
        }
        node = nextList(studentList->list_, node);
    }
    printf("\n");
}

Student* findStudentWithKey(StudentList* studentList, int key){
    Node* node = frontList(studentList->list_);
    while (node != backList(studentList->list_) ) {
        Student* student = (Student*) getInfo(node);
            if( student->key_ == key ){
                return student; 
            } 
            node = nextList(studentList->list_, node);
    }
    return NULL;
}


