#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "list.h"
#include "student.h" 

int main () {
    StudentList* studentList;
    PrefList* prefs;
    Student* student;
printf("antes de entrar no arquivo \n"); 
    ReadFile(studentList, prefs, student);
   return 0;
}

//FUNCAO QUE LE O ARQUIVO E MODIFICA AS LISTAS
void ReadFile(StudentList* studentList, PrefList* prefs, Student* student){
    int instances, num_stud, num_univ, max_list;
    int i, j, k, c;
    int grade, key;
    int vaga;
    FILE* input;
    input = fopen ("input.txt", "r");
    fscanf(input, "%d", &instances); 
printf("instances %d \n", instances); 
    fscanf(input, "%d %d %d", &num_stud, &num_univ, &max_list); 
printf("numeros lidos %d %d %d \n", num_stud, num_univ, max_list); 
printf("\n");
    //instances
    for (i=0; i<instances; i++){
        //students
        for (j=0; j < num_stud; j++){
            key = j + 1;
printf("aluno = %d \n", key);
            fscanf(input, "%d", &grade);
printf("grade = %d \n", grade);
            studentList = createStudentList();
            prefs = createPrefList();
            //preferences
            for (c = getc(input);;c = getc(input)){
                if (isdigit(c)){
printf("pref %c\n", c);
                    insertPrefInList(prefs, c);
                }
                if (c == '\n') {
                    break;
                }
            }
            student = createStudent(key, grade, prefs);
            insertStudentInList(studentList, student);
printf("\n");
        }
        //vaga
        //List* univList = newList();
        for (k=0; k < num_univ; k++){
            fscanf(input, "%d", &vaga);
            printf("%d", vaga);
            //insertBack(univList, vaga);
        }
    }
    fclose(input);
}
