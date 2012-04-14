#include dent.h"
#include <stdio.h>


Student* createStudent(int key, int grade, PrefList* prefs){
    Student* stud = (Student*) malloc(sizeof(Student));
    stud -> key_ = key;
    stud -> grade_ = grade;
    stud -> preferences_ = prefs;
    stud -> status_ = SINGLE;
    printf("Incluindo estudantes \n");
    return stud;
}


PrefList* createPrefList(){
    PrefList* preflist = (PrefList*) malloc(sizeof(PrefList));
    List* preflist = NewList();
    preflist -> list_ = preflist;
    printf("Criando listas de preferencias \n");
    return preflist;
}

void insertPref(PrefList* pref, int x){
    InsertBack (pref->list, x);
    printf("Insere pref na lista de preferencias \n");
}

/*void insertPrefInList(PrefList* prefList, unsigned int university){
    InsertBack();
    printf("Inserindo preferencias na lista de Students \n");
}
*/

StudentList* createStudentList(){
    StudentList* studlist = (StudentList*) malloc(sizeof(StudentList));
    studList->list_ = NewList();
    studList->size_=0;
    printf("Criando uma lista de estudantes \n");
    return studList;
}
//k = id do aluno que vou inserir
void insertStudentInList(StudentList* studentList, Student* student){
    Student* student = (Student*) malloc(sizeof(Student));
    student-> preferences =  
    //TODO
    printf("Inserindo um estudante na Lista de estudantes \n");
}

Student* getStudentFromList(unsigned int position){
    printf("Retorna o estudante na lista \n");
    return NULL;
}

