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
	int i;

	//alloc names memory
	for(i=0;i<m;i++)
	{
		vetor[i].name_=calloc(100,sizeof(char));
	}
	//puts filenames in vector
	for(i=0;i<m;i++)
	{
        	fgets(stuingue,100,arquivo);
		strcpy(vetor[i].name_,stuingue);
	}
	
	//call the selection sort function
	SortNames(vetor,m);

	//rewind the file so it can be written on it since its beggining
	rewind(arquivo);

	//write on output file
	for(i=0;i<m;i++){
	    fputs(vetor[i].name_,arquivo);
	}
}

//--------------------------------- is working so far ------------------------------------//

//INTERCALATES FILES

void TreatFiles(int mbuffer, int numblocos, int numcontacts) {
    int i;
    FILE* arquivo[numblocos];
    FILE* saida=fopen("output.txt","w");
    char* name=calloc(120,sizeof(char));
    char* fileName=calloc(15,sizeof(char));
    int diff;
    fpos_t pos;
    int j=0;
    int last=0;

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
        last=i;

    }

    HeapSort(heap,(int)mbuffer);

//put names on file output.txt
    fputs(heap[0].name_,saida);
    while(numcontacts>0){
       if(fgets(name,120,arquivo[last])>0)
       {
	 strcpy(heap[0].name_,name);
	 HeapSort(heap,(int)mbuffer);
	 
	 fputs(heap[0].name_,saida);
       }
        
        numcontacts--;
	last=last+1;
	if(last>numblocos){
		last=0;
	}
    }


//debug: print heap
    for(i=0; i<mbuffer;i++){
        printf("@@  %s\n",heap[i].name_);
    }
}

//------------------------------------------- is not sorting correctly ------------------------------------------//

