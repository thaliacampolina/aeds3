////////////////
// heapsort   //
///////////////

#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

void HeapSort(Contact* vector[], int n) {
   int i = n/2;
   int pai, filho;
   Contact* t;
 
   for (;;){
      if (i > 0){
          i--;
          t = vector[i];
      } else {
          n--;
          if (n == 0)
             return;
          t = vector[n];
          vector[n] = vector[0];
      }
 
      pai = i;
      filho = i*2 + 1;
 
      while (filho < n) {
          if ((filho + 1 < n)  &&  (vector[filho + 1] > vector[filho]))
              filho++;
          if (vector[filho] > t){
             vector[pai] = vector[filho];
             pai = filho;
             filho = pai*2 + 1;
          }
          else
             break;
      }
      vector[pai] = t;
   }
}

