///////////////////////////////
//// Contacts structure    ////
///////////////////////////////

//Author: Thalia Campolina


#ifndef _list_h_
#define _list_h_

//cellphone contacts struct. 
typedef struct contact {
    char* name_;
}Contact;

//Creates new contact
Contact* CreateNewContact();
//Insert a name in the contact structure
void InsertNameInContact(Contact* contact, char* name);
//Checks if contact1 is minor then contact2
int IsMinorThen(Contact contact1, Contact contact2);
//Sort a vector so it becames a heap
void HeapSort(Contact vector[], int size);
//Sort names using selection sort
void SortNames(Contact vetor[], int m);
//Sort names inside a file
void SortNameInFile(FILE *arquivo,int m);
//Intercalates files sorting them in an output file
void TreatFiles(int mbuffer, int numblocos, int numcontacts);

#endif
