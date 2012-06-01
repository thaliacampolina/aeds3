///////////////////////////////
//// Contacts structure    ////
///////////////////////////////

//Author: Thalia Campolina


#ifndef _list_h_
#define _list_h_

//cellphone contacts struct. 
typedef struct contact {
    char* name_;
    int number_;
}Contact;


//creates a new contact
Contact* CreateNewContact ();

//insert name in contact struct
void* InsertNameInContact(Contact* contact, char* name, int number);

//free contact
void* FreeContact(Contact* contact);

//returns 1 if contact1 is minor than contact2
int IsMinorThen(Contact* contact1, Contact* contact2);


#endif
