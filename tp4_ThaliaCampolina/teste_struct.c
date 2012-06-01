#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.c"


int main(){
    Contact* contact1 = CreateNewContact(); 
    char* name1;
    name1="amanda"; 
    //int* number = (int*)999999;
    int number = 999999;
    InsertNameInContact(contact1, name1, number);

    Contact* contact2=CreateNewContact(); 
    char* name2;
    name2="adalton";
    InsertNameInContact(contact2, name2, number);

    if(IsMinorThen(contact1, contact2) == 1){
       // int numbering = (int)contact1->number_;
        int numbering = contact1->number_;
        printf("CONTAC MENOR %s # %d",contact1->name_, numbering);
    } 
    printf("saida do file, nao, nao eh menor.\n");
    FreeContact(contact1);
    FreeContact(contact2);
    return;
}
