#include <stdio.h>
#include <stdlib.h>


void ReadFromFile(FILE* input){
    float ncontatos;
    float mbuffer;
    int  numblocos;
    char heap[1000];


    // calculates the necessary number of blocks
    fscanf(input,"%f",&ncontatos);
    fscanf(input,"%f",&mbuffer);
    numblocos =(int)ceil(ncontatos/mbuffer);

    CreateBlocks(input, mbuffer);
}



void CreateBlocks(FILE* input, int mbuffer){
    FILE* output;
    char* fileName;
    int fileCounter=1;
    printf("@@@@@ mbuffer = %d\n", mbuffer);
    fileName=calloc(10,sizeof(char));
    sprintf(fileName,"output_%d.txt",fileCounter); 
    printf("%s\n",fileName);
    output=fopen(fileName,"w");

    float count=0;
    char* nome=calloc(100,sizeof(char));

    fgets(nome,100,input);
    printf("\n%s\n",nome);

    while(fgets(nome,100,input)>0){
        printf("%s\n",nome);   
        count++;
	fputs(nome,output);	//escreve no arquivo
	if(count==mbuffer){
	    fclose(output);
	    count=0;
	    fileCounter++;
            sprintf(fileName,"output_%d.txt",fileCounter); 
            output=fopen(fileName,"w+");

	}
    }

	fclose(output);        
}

void SortBuffer(FILE* fileName, int mbuffer){
    char* contato=calloc(100,sizeof(char));
    int vectorSize=100*mbuffer;
    char* vector=calloc(vectorSize,sizeof(char));
    FILE* file = fopen(fileName,"r");
    fgets(contato,100,file);
    float count=0;
    while(fgets(nome,100,input)>0){
        count++;
        
    }
 
}


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

/*
 while((linha_comando = (getopt(argc,argv,"a:r:s:"))) != -1)
        {
                switch(linha_comando)
                {
                        case 'a' :  nome_arquivo_ambiente = optarg;
                                break;

                        case 'r' : nome_arquivo_requisicoes = optarg;
                                break;

                        case 's' : nome_arquivo_requisicoes_atendidas = optarg;
                                break;

                        default: printf("Parametro invalido %c\n", linha_comando);
                                exit(1);
                }
        }

*/
