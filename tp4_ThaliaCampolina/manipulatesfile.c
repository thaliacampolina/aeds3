#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

    // calculates the necessary number of blocks
int CaculatesBlocks(float ncontatos, float mbuffer){
    int  numblocos =(int)ceil(ncontatos/mbuffer);
    return numblocos;
}
    //creates the name output_INTEGER.txt for the file
char* CreateFileName(int fileCounter){
    char* fileName;
    fileName=calloc(50,sizeof(char));
    sprintf(fileName,"output_%d.txt",fileCounter);
    return fileName;
}

/*
void InsertNamesInBlocks(FILE* input, char* fileName, int mbuffer, int fileCounter){
puts("entrou insertnames\n");
    FILE* output=fopen(fileName,"w");
    char* name=calloc(50,sizeof(char));
    float count=0;
    fgets(name,50,input);
puts("chegou no fgets\n");
puts("chegou no fgets\n");
    while(fgets(name,50,input)>0){
puts("entrou no while\n");
        count++;
	fputs(name,output);	//write on file
	if(count==mbuffer){
	    fclose(output);
	count=0;
        fileCounter++;
        fileName=CreateFileName(fileCounter);
        output=fopen(fileName,"w+");
        } 
    }
    fclose(output);
}*/
