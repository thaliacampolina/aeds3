#ifndef _university_h_
#define _university_h_
#include "list.h"
#include "student.h"

typedef struct university {
    int key_;
    int vagas_;
    StudentList* prefs_;
} University;
//Cria Universidade 
void* createUniversity(int key, int vagas);
//Plota dados da Universidade na tela
void dumpUniversity(University* university);

typedef struct universityList {
    List* list_;
} UniversityList;

//Cria Lista de Universidades
void* createUniversityList();
//Insere Universidade na lista de Universidades
void insertUniversityInUniversityList(UniversityList* universityList, University* university);
//Plota lista de Universidades na tela
void dumpUniversityList(UniversityList* universityList);
//Encontra uma universidade dado um numero de identificacao como entrada
University* findUniversityWithKey(UniversityList* universityList, int key);
//Insere um estudante na lista da Universidade com as preferencias dos alunos
void insertStudentInUniversityList(University* university, Student* student);
#endif
