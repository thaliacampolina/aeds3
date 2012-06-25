#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ReadFromFile(FILE* input){
    char* c = NULL;
    char* d = NULL;
    c = (char*)malloc(10);
    d = (char*)malloc(10);
    int instances;
    fscanf(input,"%d",&instances);
    int i = 1;
    while (i < instances){
        while (input != EOF){
            //c = getc(input);
            fscanf(input,"%s",&d);
            printf("@@@@@@ c = %s \n",d);
            if (d = "\n") {
                i = i+1;
            }
        }
    }
    fclose(input);
}

int main (int argc, char* argv[]) {
    bool a = true && false;
    printf("%s", a);
    char o = "-i";
    //if (argc<3){
    if (argc<2){
        puts("O NOME DO ARQUIVO NAO FOI ESPECIFICADO");
        return 0;
    } else {
puts ("@@@@@@@@ MAIN @@@@@@@@@@@");
       // if (argv[1] == o){
puts ("@@@@@@@@ ENTROU AQUI @@@@@@@@@@@");
            FILE* input;
            //input =  fopen (argv[2], "r");
            input =  fopen (argv[1], "r");
            if (input == NULL){
                puts("O ARQUIVO NAO FOI ABERTO");
                return 0;
            } else {
                ReadFromFile(input);
            }
       // }
        return 0;
    }

}

