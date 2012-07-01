
#ifndef _list_h_
#define _list_h_

float Satisfaction(List* list);

int isMarried(List* list, int Num_id);

int AllMarried(List* list);

int Prefers(List* listWoman, int Num_id1, int Num_id2);

void Marry (List* list1, int Num1, List* list2, int Num2) ;

void Divorce ( List* list1, int Num1, List* list2, int Num2 );

void SMP (List* list1, List* list2) ;



#endif
