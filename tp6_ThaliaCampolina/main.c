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

//Funcao que le o arquivo input.txt e guarda as listas dos pretendendes em estruturas de listas encadeadas.

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

        int a,i,j,y, number, instances;
        number = 0;
        input=fopen("input.txt", "r");
        fscanf(input, "%d", &instances);

        for (a=1; a <= instances; a++) {
            fscanf(input, "%d", &number);
            //List* menCrushes[number]; 
            //List* womenCrushes[number];
            PersonList* menList=createPersonList(); 
            PersonList* womenList=createPersonList();
            PrefList* menCrushes = createPrefList();
            PrefList* womenCrushes = createPrefList();
            Person* men; 
            Person* women; 

//Creating men preference list
//Insert men on men list
            for (i=0; i < number; i++) {
                for (j=0; j < number; j++) {
                    fscanf(input, "%d", &y);
                    insertPref(menCrushes,y );
                }
                men=createPerson(i,menCrushes);
                insertPersonInList(menList, men);
//DEBUG
puts("\n");
puts("men preflist:");
dumpPrefList(menCrushes);
puts("\n");
            }

//creating women preference list
            for (i=0; i < number; i++) {
                for (j=0; j < number; j++) {
                    fscanf(input, "%d", &y);
                    insertPref(womenCrushes,y );
                }
                women=createPerson(i,womenCrushes);
                insertPersonInList(menList, women);
//DEBUG
puts("\n");
puts("women preflist:");
dumpPrefList(womenCrushes);
puts("\n");
            }


            SMP(menCrushes, womenCrushes);
            float geral = Satisfaction(menCrushes) + Satisfaction(womenCrushes);
            output = fopen("output.txt", "w");

            //Write on file the created couples
            Node* node1 = frontList(menList->list_); 
            Node* node2; 
            int num;
            while ( node1 != backList(menList->list_) ) {
                num=0;
          //      fprintf(output,"%d %d\n", num+1 , node1->info_->status_);
                num++;
                node1 = node1->next_;
            }
            fprintf (output, "%.3f\n", Satisfaction(womenCrushes));
            fprintf (output, "%.3f\n", Satisfaction(menCrushes));
            fprintf (output, "%.3f\n", geral);

            //Memory free:
            //for(i=0; i < number; i++){
            node1 = frontList(menList->list_); 
            node2 = frontList(womenList->list_); 
            while ( node1 != backList(women->preferences_) ) {
                clear(womenList->list_);
                node1 = node1->next_;
            }
            while ( node2 != backList(menList->list_) ) {
                clear(menList->list_);            }
                node2 = node2->next_;
        }
        printf("Esta dando erro \n");
        fclose(input);
        fclose(output);
        return 0;
        }
    }
}
