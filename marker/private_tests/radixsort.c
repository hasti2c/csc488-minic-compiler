#include "minicio.h"
int arr[8];

int getMax(int n) { 
    int mx, i;
    mx = arr[0];
    for (i = 0; i < n; i = i + 1) {
        if (arr[i] > mx) {
            mx = arr[i]; 
        }
    }
    return mx;
} 

int mod (int val, int x){
    for(;val>=x;){
        val =val- x;
    }
    return val;
}
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int n, int exp) { 
    int output[8]; // output array 
    int i, count[10];
    for (i = 0; i < 10; i=i+1) 
        count[i] = 0;  
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i=i+1) 
        count[mod((arr[i] / exp),10)]=count[mod((arr[i] / exp),10)] + 1; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i=i+1) 
        count[i] =count[i] + count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i=i-1) { 
        output[count[mod((arr[i] / exp),10)] - 1] = arr[i]; 
        count[mod((arr[i] / exp),10)]=count[mod((arr[i] / exp),10)] - 1; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i=i+1) 
        arr[i] = output[i]; 
} 
  
// The main function to that sorts arr[] of size n using 
// Radix Sort 
void radixsort(int n) 
{ 
    // Find the maximum number to know number of digits 
    int m,exp;
    m = getMax(n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (exp = 1; m / exp > 0; exp = exp * 10) 
        countSort(n, exp); 
} 
  
// A utility function to print an array 
void print(int n) 
{ 
    int i;
    for (i = 0; i < n; i=i+1) 
        putint(arr[i]); 
} 
  
// Driver Code 
int main() 
{ 
    //arr = { 170, 45, 75, 90, 802, 24, 2, 66 }; 
    int n; 
    int i;
    n = 8;
   for(i=0;i<n;i=i+1){
      arr[i]= getint();
   }
      // Function Call 
      radixsort(n); 
    print(n); 
    return 0; 
}