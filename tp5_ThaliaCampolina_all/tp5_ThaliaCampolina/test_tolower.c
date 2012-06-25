#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
char* tha = (char*)calloc(100,sizeof(char));
strcpy(tha, "THAlia");
char* tha2 = (char*)calloc(100,sizeof(char));
int i = 0;

while(tha[i] != '\0'){
    //char c =(char)(tolower(tha[i]));
    char c=tha[i];
    tha[i]=putchar(tolower(c));
    i++;
    //printf("%c",tha[i]);
}

//strcpy(tha, tha2);
printf(" STRING :%s \n", tha);
return 0;

}
