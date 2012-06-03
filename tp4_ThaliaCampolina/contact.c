///////////////////////////////
//// Contacts structure    ////
///////////////////////////////

//Author: Thalia Campolina


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

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
    if(strncmp(contact1.name_,contact2.name_,100)<0){
        return 1;     
    }
    return 0;
}


void HeapSort(Contact vector[], int size) {
   int mid = size/2;
   int pai, filho;
   Contact t;
   t.name_=calloc(120,sizeof(char));
 
   for (;;){
      if (mid > 0){
          mid--;
          strcpy(t.name_,vector[mid].name_);
      } else {
          size--;
          if (size == 0)
             return;
          strcpy(t.name_,vector[size].name_);
          strcpy(vector[size].name_,vector[0].name_);
      }
 
      pai = mid;
      filho = mid*2 + 1;
 
      while (filho < size) {
          if ((filho + 1 < size)  &&  (IsMinorThen(vector[filho], vector[filho + 1])))
              filho++;
          if (IsMinorThen(t,vector[filho])){
              strcpy(vector[pai].name_,vector[filho].name_);
              pai = filho;
              filho = pai*2 + 1;
          }
          else
             break;
      }
      strcpy(vector[pai].name_,t.name_);
   }
}


void SortNames(Contact vetor[], int m) {
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

void SortNameInFile(FILE *arquivo,int m) {

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
	SortNames(vetor,m);

	//rebobina o ponteiro do arquivo pra escrever desde o comeco
	rewind(arquivo);

	//escreve no arquivo de saida
	for(i=0;i<m;i++){
	    fputs(vetor[i].name_,arquivo);
	}
}

//---------------------------------is working untill so far, end implemantation------------------------------------//

//INTERCALAR OS FILES

void TreatFiles(int mbuffer, int numblocos) {
    int i;
    FILE* arquivo[numblocos];
    char* name=calloc(120,sizeof(char));
    char* fileName=calloc(15,sizeof(char));
    int diff;
    fpos_t pos;
    int j=0;

    Contact heap[mbuffer];
//alloc heap[] memory
    for(i=0;i<mbuffer;i++) {
        heap[i].name_=calloc(120,sizeof(char));
    } 
//open files
    for(i=0;i<numblocos;i++){
        sprintf(fileName,"output_%d.txt",i+1);
        arquivo[i]=fopen(fileName,"r");
    }
//copy names to heap 


    for(i=0;i<mbuffer;i++){
        fgets(name,120,arquivo[j]);
        strcpy(heap[i].name_,name);
        j++;
        if((j)==numblocos){
            j=0;
        }
    }

    HeapSort(heap,mbuffer);


//debug: print heap
    for(i=0; i<mbuffer;i++){
        printf("@@  %s\n",heap[i].name_);
    }
}

//------------------------------------------------------------------ is working so far ---------------------------//

/*

void ThrowNamesInFile(Contact heap[], int mbuffer, FILE* arquivo, int numcontacts){
    while(numcontacts>0){
        fputs(heap[0].name_,arquivo);
        numcontacts --;
    }
}

*/
