#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.c"
#include "contact.h"
#include "heapsort.h"


int main(){
    printf(" entrou no main\n");
    Contact* vector[5];
    int i;
    
    for(i=0;i<5;i++){
        vector[i]=(Contact*) malloc(sizeof(Contact));
        vector[i]->name_=calloc(120,sizeof(char));
    }

    strcpy(vector[0]->name_,"amanda");
    strcpy(vector[1]->name_,"adalthon");
    strcpy(vector[2]->name_,"frederico");
    strcpy(vector[3]->name_,"lucaomau");
    strcpy(vector[4]->name_,"thalia");
    HeapSort(vector,5);
    printf("o menor nome eh %s\n", vector[0]->name_);
    for(i=0;i<5;i++) {
        printf("%s\n", vector[i]->name_);
    }
    return;
}
