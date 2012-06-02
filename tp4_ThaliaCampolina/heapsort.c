///////////////
// heapsort  //
///////////////

#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"
#include "contact.h"

void HeapSort(Contact* vector[], int size) {
   int mid = size/2;
   int pai, filho;
   Contact* t;
 
   for (;;){
      if (mid > 0){
          mid--;
          strcpy(t->name_,vector[mid]->name_);
      } else {
          size--;
          if (size == 0)
             return;
          strcpy(t->name_,vector[size]->name_);
          strcpy(vector[size]->name_,vector[0]->name_);
      }
 
      pai = mid;
      filho = mid*2 + 1;
 
      while (filho < size) {
          if ((filho + 1 < size)  &&  (IsMinorThen(vector[filho]->name_, vector[filho + 1]->name_)))
              filho++;
          if (IsMinorThen(t->name_,vector[filho]->name_)){
              strcpy(vector[pai]->name_,vector[filho]->name_);
              pai = filho;
              filho = pai*2 + 1;
          }
          else
             break;
      }
      strcpy(vector[pai]->name_,t->name_);
   }
}

