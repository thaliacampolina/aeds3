//////////////////////
//    funcao        //
//   principal      //
//////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "list.h"
#include "person.h"
#include "marriage.h"

int main (int argc, char* argv[]) {
    FILE *input,*output;
    char option;
    char *s_input, *s_output;
    List* words;
    words = NewList();
    if (argc<2){
        puts("ARGUMENT MISSING");
        return 0;
    } else {
        while((option = getopt(argc,argv,"i:o:")) != -1){
                switch(option){
                        case 'i':
                                s_input = optarg;
                                break;
                        case 'o':
                                s_output = optarg;
                                break;
                        default :
                                exit(0);
                }
        }

        input = fopen(s_input, "r");
        output = fopen(s_output, "w");

     if (input == NULL){
         puts("O ARQUIVO NAO FOI ABERTO");
         return 0;
     } else {
        //starts to read the input file
        int a,i,j,y, number, instances;
        number = 0;
        input=fopen("input.txt", "r");
        fscanf(input, "%d", &instances);
        
        PersonList* menList=createPersonList(); 
        PersonList* womenList=createPersonList();
        PrefList* menCrushes;
        PrefList* womenCrushes;
        Person* men; 
        Person* women;
         
        //Reading instances
        for (a=1; a <= instances; a++) {
            fscanf(input, "%d", &number);
 
            //Creating men preference list
            for (i=1; i <= number; i++) {

                menCrushes = createPrefList();
                
                for (j=0; j < number; j++) {
                    fscanf(input, "%d", &y);
                    insertPref(menCrushes,y );
                }
                
                men=createPerson(i,menCrushes);
                insertPersonInList(menList, men);

            }

            //creating women preference list
            for (i=1; i <= number; i++) {

                womenCrushes = createPrefList();
                for (j=0; j < number; j++) {
                    fscanf(input, "%d", &y);

                    insertPref(womenCrushes,y );
                }
                women=createPerson(i,womenCrushes);
                insertPersonInList(womenList, women);
  
            }

            //Stable Marriage Problem -> print in output file
            SMP(menList, womenList, number);
            dumpPersonListStatusToOutput(menList, output);

            //Satisfaction 0> print in output file
            writeOutputSatisfaction(menList, womenList,number, output);

        }
        fclose(input);
        fclose(output);
        }
    }
    return 0;
}
