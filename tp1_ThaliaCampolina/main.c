#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "list.h"
#include "student.h" 
#include "university.h" 


void CreateUniversityStudentList(UniversityList* universityList, StudentList* studentList){
    Node* node = frontList(studentList->list_);
    University* university;
    while ( node != backList(studentList->list_) ) { 
        Student* student = (Student*) getInfo(node);
        printf("Verificando aluno : "); dumpStudent(student);
        printf("\n");
        Node* nodePref = frontList(student->preferences_->list_);
        while ( nodePref != backList(student->preferences_->list_) ) { 
            unsigned int pref = * ( (unsigned int*) getInfo(nodePref) );
            printf("    Preferencia: %d \n", pref);
            university = findUniversityWithKey(universityList, pref);
            insertStudentInUniversityList(university, student);
            nodePref = nextList(student->preferences_->list_, nodePref);
        }
        node = nextList(studentList->list_, node); 
    }
}

void ReadFromFile() {
    int instances, num_stud, num_univ, max_list;
    int i, j, k,c;
    int grade, key;
    int vaga;
    FILE* input;
    input = fopen ("input.txt", "r");
    fscanf(input, "%d", &instances); 
    fscanf(input, "%d %d %d", &num_stud, &num_univ, &max_list); 
    //***instances
    for (i=0; i<instances; i++){
        StudentList* studentList = createStudentList();
        UniversityList* universityList = createUniversityList();
        for (j=0; j < num_stud; j++) {
            key = j + 1;
            fscanf(input, "%d", &grade);
            PrefList* prefs = createPrefList();
            //***preferences
            for (c = getc(input);;c = getc(input)){
                if (isdigit(c)) {
                    Preference* p = (Preference*) malloc(sizeof(Preference));
                    p->university = c - (unsigned int)'0';
                    insertPref(prefs, p);
                }
                if (c == '\n') {
                    break;
                }
            }
            //dumpPrefList(prefs);
            Student* student = createStudent(key, grade, prefs);
            //dumpStudent(student);
            insertStudentInList(studentList, student);
        }
        dumpStudentList(studentList);
        //***vaga
        for (k=0; k < num_univ; k++){
            int u_key=k+1; /* id starts with 1 */
            fscanf(input, "%d", &vaga);
            printf("Universidade %d : %d vagas \n", u_key, vaga);
            University* university = createUniversity(u_key, vaga);
            insertUniversityInUniversityList(universityList, university);
        }
        //dumpUniversityList(universityList);

        CreateUniversityStudentList(universityList, studentList);
        dumpUniversityList(universityList);
    }
    fclose(input);
}

int main () {
    ReadFromFile();
    return 0;
}




