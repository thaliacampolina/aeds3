#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "student.h"
#include "university.h"


float SatisfactionStudents(StudentList* studList);

float SatisfactionUniv(List* list);

int isApproved(Student* student);

int AllApproved(StudentList* studlist);

int StudentPrefersUniversity(Student* student, University* university);

void AllocOnUniversity (University* university, Student* student) ;

void Discard ( University* university, Student* student);

void SMP_heutistica1 (StudentList* studentList, UniversityList* universityList) ;



