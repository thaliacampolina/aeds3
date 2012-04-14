#ifndef _student_h_
#define _student_h_
#include "list.h"
#include "node.h"

#define SINGLE -1

typedef struct student {
    int key_;    // line in the original file
    int grade_;  // grade
    //int status_; //SINGLE or the number of the university the student will study
    List* preferences_; // list of university preferences

    int status_; // SINGLE or pointer to university number
} Student;





typedef struct prefList {
    List* list_;
    //int size_;
} PrefList;

PrefList* createPrefList();

Student* createStudent(int key, int grade, PrefList* prefs); 

void insertPrefInList(PrefList* prefList, unsigned int university);



typedef struct studentList {
    List* list_;
    int size_;
} StudentList;

StudentList* createStudentList();

void insertStudentInList(StudentList* studentList, Student* student);

Student* getStudentFromList(unsigned int position);

#endif
