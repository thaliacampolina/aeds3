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
            List* mensCrushes[number]; 
            List* womansCrushes[number];

            for(i=0; i < number; i++){
                mensCrushes[i] = NewList();
                womansCrushes[i] = NewList();
            }
            for (i=0; i < number; i++) {
                for (j=0; j < number; j++) {
                    fscanf(input, "%d", &y);
                    InsertBack(&mensCrushes[i],y);
                }
            }
            for (i=0; i < number; i++) {
                for (j=0; j < number; j++) {
                    fscanf(input, "%d", &y);
                    InsertBack(&womansCrushes[i],y);
                }
            }

            SMP(mensCrushes, womansCrushes);
            float geral = Satisfaction(mensCrushes) + Satisfaction(womansCrushes);
            output = fopen("output.txt", "w");
            for (i=0; i<number; i++){
                fprintf(output,"%d %d\n", i+1 , mensCrushes[i].status_);
            }
            fprintf (output, "%.3f\n", Satisfaction(womansCrushes));
            fprintf (output, "%.3f\n", Satisfaction(mensCrushes));
            fprintf (output, "%.3f\n", geral);
        //Liberar memoria:
            for(i=0; i < number; i++){
                clear(&mensCrushes[i]);
                clear(&womansCrushes[i]);
            }
        }
        printf("Esta dando erro \n");
        fclose(input);
        fclose(output);
        return 0;
        }
    }
}

