#ifndef _student_h_
#define _student_h_
#include "list.h"

#define SINGLE -1


typedef struct preference {
    unsigned int university;
} Preference;

typedef struct prefList {
    List* list_;
} PrefList;

//Cria PrefList
PrefList* createPrefList();
//Insere preferência(id da universidade) na lista de PrefList
void insertPref(PrefList* pref, Preference* p);
//Plota a PrefList na tela
void dumpPrefList(PrefList* pref);



typedef struct student {
    int key_;    // line in the original file
    int grade_;  // grade
    PrefList* preferences_; // list of university preferences

    int status_; // SINGLE or pointer to university number
} Student;

//Cria novo Estudante
Student* createStudent(int key, int grade, PrefList* prefs); 
//Plota informacoes do Estudante na tela
void dumpStudent(Student* student);


typedef struct studentList {
    List* list_;
} StudentList;

//Cria Lista de Estudantes
StudentList* createStudentList();
//Insere Estudante na Lista de Estudantes
void insertStudentInList(StudentList* studentList, Student* student);
//Plota Lista de Estudantes na tela
void dumpStudentList(StudentList* studentList);


#endif
