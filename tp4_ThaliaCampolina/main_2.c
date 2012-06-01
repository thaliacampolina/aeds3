#include <stdio.h>
#include <stdlib.h>


void ReadFromFile(FILE* input){
    FILE* output;
    float ncontatos;
    float mbuffer;
    int  numblocos;
    int fileCounter=1;

    // calculates the necessary number of blocks
    fscanf(input,"%f",&ncontatos);
    fscanf(input,"%f",&mbuffer);
    numblocos =(int)ceil(ncontatos/mbuffer);

    //creates the first output file (block)
    char* fileName;
    fileName=calloc(10,sizeof(char));
    sprintf(fileName,"output_%d.txt",fileCounter); 
    printf("%s\n",fileName);
    output=fopen(fileName,"w");


    //creates the rest of the output files (blocks)
    char* nome=calloc(100,sizeof(char));
    float count=0;
    fgets(nome,100,input);
    printf("\n%s\n",nome);
    while(fgets(nome,100,input)>0){
        printf("%s\n",nome);   
        count++;
	fputs(nome,output);	//escreve no arquivo
	if(count==mbuffer){
    //        fclose(output);
	    count=0;
	    fileCounter++;
            sprintf(fileName,"output_%d.txt",fileCounter); 
            output=fopen(fileName,"w+");

	}
    }
    fclose(output);        

//sort each block    
    int i;
    for(i=1; i<=numblocos;i++){
            puts("OIOIOIO \n");
        sprintf(fileName,"output_%d.txt",i); 
        FILE* fileBlock=fopen(fileName,"rw");
        while(fgets(nome,50,fileBlock)>0){
            printf("parte 2: %s \n",nome);   
        }
        fclose(fileBlock);
    }





}

//void SortBlock(char fileName){
//   FILE* 
//}

int main (int argc, char* argv[]) {

    if (argc<2){
        puts("O NOME DO ARQUIVO NAO FOI ESPECIFICADO");
        return 0;
    } else {
        FILE* input;
        input = fopen(argv[1], "r");
        if (input == NULL){
            puts("O ARQUIVO NAO FOI ABERTO");
            return 0;
        } else {
            ReadFromFile(input);
        }
        return 0;
    }
}

