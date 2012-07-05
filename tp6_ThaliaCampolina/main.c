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
            PersonList* men=createPersonList(); 
            PersonList* women=createPersonList();
            PrefList* menCrushes = createPrefList();
            PrefList* womenCrushes = createPrefList();

            for (i=0; i < number; i++) {
                for (j=0; j < number; j++) {
                    fscanf(input, "%d", &y);
                    insertPref(menCrushes,y );
                }
            }
            for (i=0; i < number; i++) {
                for (j=0; j < number; j++) {
                    fscanf(input, "%d", &y);
                    insertPref(womenCrushes,y );
                }
            }

            SMP(menCrushes, womenCrushes);
            float geral = Satisfaction(menCrushes) + Satisfaction(womenCrushes);
            output = fopen("output.txt", "w");
            //Escreve no arquivo os casais formados
            Node* node1 = frontList(menCrushes->list_); 
            Node* node2 = frontList(menCrushes->list_->preferences_->list_); 
            while ( node1 != backList(menCrushes->list_) ) {
                while (node2 != backList(menCrushes->person->preferences_->list_)) {
                    int num=0;
                    fprintf(output,"%d %d\n", num+1 , menCrushes.person->preferences_.status_);
                    i++;
                    node1 = node->next_;
                }
                node2 = node->next_;
            }
            fprintf (output, "%.3f\n", Satisfaction(womenCrushes));
            fprintf (output, "%.3f\n", Satisfaction(menCrushes));
            fprintf (output, "%.3f\n", geral);
        //Liberar memoria:
            //for(i=0; i < number; i++){
            node1 = frontList(menCrushes->list_); 
            node2 = frontList(womenCrushes->list_); 
            while ( node1 != backList(womenCrushes->list_) ) {
                clear(womenCrushes->person->preferences_->list_);
                node1 = node1->next_;
            }
            while ( node2 != backList(menCrushes->list_) ) {
                clear(menCrushes->person->preferences_->list_);            }
                node2 = node2->next_;
        }
        printf("Esta dando erro \n");
        fclose(input);
        fclose(output);
        return 0;
        }
    }
}

