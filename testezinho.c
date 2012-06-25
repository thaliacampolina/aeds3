#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"


int main(){
    char* nome;
    
    char* nome2;
    nome=calloc(10,sizeof(char));
   
    nome2=calloc(10,sizeof(char));
    nome="amanda"; 
    nome2="adalton";
   // printf("%s\n",nome);
    //char x = 'b';
    //char j = 'c';
    if (nome < nome2) {
        printf("eh menor! \n");
    } else { 
        printf("not\n");
    }
return 0;
}
