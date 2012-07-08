
#ifndef _list_h_
#define _list_h_

//return 1 if person is Married
int isMarried(PersonList* personList , int key);

//if all men or all women are married, return 1. Number = number of person, given in the input file
int AllMarried(PersonList* personList, int number);

//Checks if id_woman prefers id_man or the one she is married. If she prefers id_man, return 1
int Prefers(PersonList* listWoman, int id_woman, int id_man, int number);

//Marries 
void Marry (PersonList* menList, int id_man, PersonList* womenList, int id_woman);

//Divorces
void Divorce (PersonList* menList, int id_man, PersonList* womenList, int id_woman);

//Stable Marriage Problem function
void SMP (PersonList* menCrushes, PersonList* womenCrushes, int number);

//Calculates man or woman satisfaction
int satisfactionBySex(PersonList* personList);

//Calculates General Satisfaction
int satisfactionGeneral(PersonList* menList, PersonList* womenList);

//Writes the tree satisfaction types in output file (man, woman, general)
void writeOutputSatisfaction(PersonList* menList, PersonList* womenList,int number, FILE* output);

#endif
