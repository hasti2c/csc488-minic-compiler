#include "minicio.h"
int number[25];
void quicksort(int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;
      for (;i<j;){
         for (;number[i]<=number[pivot] && i<last;){
            i=i+1;
         }
         for (;number[j]>number[pivot];){
            j=j-1;
         }
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(first,j-1);
      quicksort(j+1,last);

   }
   return;
}

int main(){
   int i, count;
    count = getint();
   for(i=0;i<count;i=i+1){
      number[i]= getint();
   }
   quicksort(0,count-1);
   for(i=0;i<count;i=i+1){
      putint(number[i]);
   }
   return 0;
}