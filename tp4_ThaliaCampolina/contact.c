///////////////////////////////
//// Contacts structure    ////
///////////////////////////////

//Author: Thalia Campolina


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cellphone contacts struct. 
typedef struct contact {
    char* name_;
    int number_;
}Contact;

//creates a new contact
Contact* CreateNewContact (){
    Contact* contact=(Contact*) malloc(sizeof(Contact));
    contact->name_=calloc(15,sizeof(char));
    return contact;
}
//insert name in contact struct
void* InsertNameInContact(Contact* contact, char* name, int number){
    strcpy(contact->name_, name);
    contact->number_=number;
}
//free contact
void* FreeContact(Contact* contact){
    free(contact->name_);
}
//returns 1 if contact1 is minor than contact2
int IsMinorThen(Contact* contact1, Contact* contact2){
    char* name1=contact1->name_; 
    char* name2=contact2->name_; 
    if(strncmp(name1,name2,15)<0){
        return 1;     
    }
    return 0;
}



