///////////////////////////////
//// Contacts structure    ////
///////////////////////////////

//Author: Thalia Campolina


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "heapsort.c"

Contact* CreateNewContact (){
    Contact* contact=(Contact*) malloc(sizeof(Contact));
    contact->name_=calloc(30,sizeof(char));
    return contact;
}

void* InsertNameInContact(Contact* contact, char* name){
    strcpy(contact->name_, name);
}

//void* FreeContact(Contact* contact){
//    free(contact->name_);
//}

int IsMinorThen(Contact* contact1, Contact* contact2){
    char* name1=contact1->name_; 
    char* name2=contact2->name_; 
    if(strncmp(name1,name2,30)<0){
        return 1;     
    }
    return 0;
}





void SelectionSortNames(Contact vetor[], int m) {
    int i,j,n;
    n=m;        
    char* aux_char=calloc(100,sizeof(char));
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {        
            if(strncmp(vetor[i].name_,vetor[j].name_,15)>0){
                strcpy(aux_char, vetor[i].name_);
                strcpy(vetor[i].name_, vetor[j].name_);
                strcpy(vetor[j].name_, aux_char);        
            }
        }
    }
}



void SortNameInFile(FILE* arquivo,float msize){
    int size=(int)msize;
    Contact vetor[size-1];
    char* stuingue=calloc(100,sizeof(char));
    //vetor[0]=(Contact*) malloc(sizeof(Contact));
    int i;

    //aloca espaco no vetor para os nomes
    for(i=0;i<size;i++){
        vetor[i].name_=calloc(100,sizeof(char));
    }

    //pega do arquivo os nomes e armazena no vetor
    for(i=0;i<size;i++){
       fgets(stuingue,100,arquivo);
       strcpy(vetor[i].name_,stuingue);
    }
        
    //chama o metodo de ordenacao por selecao
    SelectionSortNames(vetor,size);

    //rebobina o ponteiro do arquivo pra escrever desde o comeco
    rewind(arquivo);

    //escreve no arquivo de saida
    for(i=0;i<size;i++) {
        fputs(vetor[i].name_,arquivo);
    }
        
}
