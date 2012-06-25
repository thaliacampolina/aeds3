///////////////////////////////
//// Contacts structure    ////
///////////////////////////////

//Author: Thalia Campolina


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "heapsort.c"

Contact* CreateNewContact() {
    Contact* contact=(Contact*) malloc(sizeof(Contact));
    contact->name_=calloc(120,sizeof(char));
    return contact;
}

void InsertNameInContact(Contact* contact, char* name){
    strcpy(contact->name_, name);
}

//void* FreeContact(Contact* contact){
//    free(contact->name_);
//}

int IsMinorThen(Contact contact1, Contact contact2){
    char* name1; 
    strcpy(name1,contact1.name_); 
    char* name2;
    strcpy(name2,contact2.name_); 
    if(strncmp(name1,name2,100)<0){
        return 1;     
    }
    return 0;
}



/*
void SelectionSortNames(Contact* vetor[], int m) {
    int i,j,n;
    n=m;        
    char* aux_char=calloc(120,sizeof(char));
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {        
            if(strncmp(vetor[i]->name_,vetor[j]->name_,15)>0){
                strcpy(aux_char, vetor[i]->name_);
                strcpy(vetor[i]->name_, vetor[j]->name_);
                strcpy(vetor[j]->name_, aux_char);        
            }
        }
    }
}



void SortNameInFile(FILE* arquivo,float msize){
    int size=(int)msize;
    Contact* vetor[size-1];
    char* stuingue=calloc(120,sizeof(char));
    //vetor[0]=(Contact*) malloc(sizeof(Contact));
    int i;

    //aloca espaco no vetor para os nomes
    for(i=0;i<size;i++){
        vetor[i]=CreateNewContact();
    }

    //pega do arquivo os nomes e armazena no vetor
    for(i=0;i<size;i++){
       fgets(stuingue,120,arquivo);
       InsertNameInContact(vetor[i], stuingue);
       //strcpy(vetor[i].name_,stuingue);
    }
        
    //chama o metodo de ordenacao por selecao
    SelectionSortNames(vetor,size);

    //rebobina o ponteiro do arquivo pra escrever desde o comeco
    rewind(arquivo);

    //escreve no arquivo de saida
    for(i=0;i<size;i++) {
        fputs(vetor[i]->name_,arquivo);
    }
        
}
*/


 void ordenar_selecao_nome(Contact vetor[], int m) {
    int i,j,n;
    n=m;        
    char* aux_char=calloc(100,sizeof(char));
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {        
                if(strncmp(vetor[i].name_,vetor[j].name_,15)>0)
                {
                        strcpy(aux_char, vetor[i].name_);
                            strcpy(vetor[i].name_, vetor[j].name_);
                            strcpy(vetor[j].name_, aux_char);        
                }
        }
    }
}

void maluco(FILE *arquivo,int m)
{

        Contact vetor[m-1];
        char* stuingue=calloc(100,sizeof(char));
        //vetor[0]=(Contact*) malloc(sizeof(Contact));
        int i;

        //aloca espaco no vetor para os nomes
        for(i=0;i<m;i++)
        {
                vetor[i].name_=calloc(100,sizeof(char));
        }
        //pega do arquivo os nomes e armazena no vetor
        for(i=0;i<m;i++)
        {
                fgets(stuingue,100,arquivo);
                strcpy(vetor[i].name_,stuingue);
        }
        
        //chama o metodo de ordenacao por selecao
        ordenar_selecao_nome(vetor,m);

        //rebobina o ponteiro do arquivo pra escrever desde o comeco
        rewind(arquivo);

        //escreve no arquivo de saida
        for(i=0;i<m;i++)
        {
                fputs(vetor[i].name_,arquivo);
        }

}


/*
void IntercalatesTwoFiles(FILE* file1, FILE* file2){
//the heap is defined with only two contacts
    Contact* buffer[2];
    int i; 
    char* stuingue=calloc(120,sizeof(char));
    //aloca espaco no vetor para os nomes
    for(i=0;i<2;i++){
        vetor[i].name_=calloc(120,sizeof(char));
    }

    //pega dos arquivos os nomes e armazena no vetor
       fgets(stuingue,120,file1);
       strcpy(vetor[0].name_,stuingue);
       fgets(stuingue,120,file2);
       strcpy(vetor[1].name_,stuingue);
       HeapSort(buffer,2);
}
*/

