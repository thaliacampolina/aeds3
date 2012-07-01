#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"


float Satisfaction(List* list);

int isMarried(List* list, int Num_id);

int AllMarried(List* list);

int Prefers(List* listWoman, int Num_id1, int Num_id2);

void Marry (List* list1, int Num1, List* list2, int Num2) ;

void Divorce ( List* list1, int Num1, List* list2, int Num2 );

void SMP (List* list1, List* list2) ;



//Funcao que le o arquivo input.txt e guarda as listas dos pretendendes em estruturas de listas encadeadas.

int main (int argc, char* argv[]) {
    FILE *input,*output;
    char option;
    char *s_input, *s_output;
    List* words;
    words = NewList();
    if (argc<8){
        puts("ARGUMENT MISSING");
        return 0;
    } else {
        while((option = getopt(argc,argv,"i:d:s:o:")) != -1){
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
    entrada=fopen("input.txt", "r");
    fscanf(entrada, "%d", &instances);
    for (a=1; a <= instances; a++) {
        fscanf(entrada, "%d", &number);
        List* mensCrushes = (List*) malloc (sizeof(List)*number);
        List* womansCrushes = (List*) malloc (sizeof(List)*number);
        for(i=0; i < number; i++){
            NewList(&mensCrushes[i]);
            NewList(&womansCrushes[i]);
        }
        for (i=0; i < number; i++) {
            for (j=0; j < number; j++) {
                fscanf(entrada, "%d", &y);
                InsertBack(y, &mensCrushes[i]);
            }
        }
        for (i=0; i < number; i++) {
            for (j=0; j < number; j++) {
                fscanf(entrada, "%d", &y);
                InsertBack(y, &womansCrushes[i]);
            }
        }

        SMP(mensCrushes, womansCrushes);
        float geral = Satisfaction(mensCrushes) + Satisfaction(womansCrushes);
        saida = fopen("output.txt", "w");
        for (i=0; i<number; i++){
            fprintf(saida,"%d %d\n", i+1 , mensCrushes[i].status_);
        }
        fprintf (saida, "%.3f\n", Satisfaction(womansCrushes));
        fprintf (saida, "%.3f\n", Satisfaction(mensCrushes));
        fprintf (saida, "%.3f\n", geral);
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

float Satisfaction(List* list){
    float number;
    int i;
    float v = 0;
    Node* node;
    number = (float) list[0].size_;
    for (i=0; i < number; i++){
       for (node = frontList(list); node != backList(list); node = node->next_){
           v++;
           if(node->info_ == list[i].status_){
            break;
           }
        }
    }
    return v/number;
}

int isMarried(List* list, int Num_id){
    if(list[Num_id-1].status_ != 0){
        return 1;
    }
    return 0;
}

int AllMarried(List* list){
    int i, number;
    number = list[0].size_;
    for (i = 0; i < number; i++){
        if(isMarried(list, i)){
        return 0;
        }
    }
    return 1;
}


//Funcao que checa se a Mulher de id1 prefere outro Homem ao  homem de id2.Se preferir id1 retorna 1.
int Prefers(List* listWoman, int Num_id1, int Num_id2){
    Node* men;
    int status = listWoman[Num_id1-1].status_;
    men = frontList(listWoman) ;
    while (getInfo(men) != lastElement(listWoman) ){
        if ( getInfo(men) == status){
            return 0;
        }
        if ( getInfo(men) == Num_id2){
            return 1;
        }
            men = men->next_;
   }
}


void Marry (List* list1, int Num1, List* list2, int Num2) {
    list1[Num1-1].status_= Num2;
    list2[Num2-1].status_= Num1;
}


void Divorce ( List* list1, int Num1, List* list2, int Num2 ){
    list1[Num1-1].status_= 0;
    list2[Num2-1].status_= 0;
}

void SMP (List* mensCrushes, List* womansCrushes) {
    int woman, i, number;
    number = mensCrushes[0].size_;
    while (!AllMarried (mensCrushes)){
        for (i = 0;  i< number; i++){
            woman = firstElement(&mensCrushes[i]);
            if (womansCrushes[woman].status_ == 0 || Prefers(womansCrushes, woman, womansCrushes[woman].status_) == 1){
                Marry(mensCrushes, i , womansCrushes, woman );
            } else {
                Divorce(mensCrushes, i , womansCrushes, woman );
                Marry (mensCrushes,Prefers(womansCrushes, woman, womansCrushes[woman].status_), womansCrushes, woman);
            }
        }
    }
}
