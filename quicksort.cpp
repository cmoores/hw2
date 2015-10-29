//  quicksort on an array of ints.
// ------------------------------ Quicksort ------------------------------------
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int separate(int* unsorted_array, int first, int last){
   int i = 0;
   int k = 0;
   int midpoint = 0;
   int pivot_point = 0;
   int temp = 0;
   bool finished = false;
   
   // midpoint is length_of_array / 2
   midpoint = first + (last - first) / 2;
   pivot_point = unsorted_array[midpoint];
   
   i = first;
   k = last;
   
   while(!finished){
     
      // increment i to the pivot
      while(unsorted_array[i] < pivot_point) {
         i++;
      }
      
      // decrement k to the pivot 
      while(pivot_point < unsorted_array[k]) {
         k--;
      }
      
      if (i >= k) {
         finished = true;
      }
      else {
         // use temp to store val at i for swap
         temp = unsorted_array[i];
         unsorted_array[i] = unsorted_array[k];
         unsorted_array[k] = temp;
         
         i++;
         k--;
      }
   }
   
   return k;
}


void quicksort(int* array, int first, int last){
   int last_of_low = 0;
  
   // if there is 1 element list already sorted
   if (first >= last){
      return;
   }
   last_of_low = separate(array, first, last);
   
   // sort low and high partitions
   quicksort(array, first, last_of_low);
   quicksort(array, last_of_low + 1, last);
   
}

int main(){
    
    int* array1;
    int* array2;
    array1 = new int[20];
    array2 = new int[50];
    
    for(int i = 0; i < 20; i++){
        array1[i] = rand() % 50;
    }
    
    for(int i = 0; i < 50; i++){
        array2[i]  = rand() % 50;
    }
    
    cout << "Array before quicksort: " << endl;
    for(int i = 0; i < 20; i++){
        cout << array1[i] << endl;
    }
    
    cout << "Array after quicksort: " << endl;
    quicksort(array1, 0, 19);
    for(int i = 0; i < 10; i++){
        cout << array1[i] << endl;
    }
    
    cout << "Array before quicksort: " << endl;
    for(int i = 0; i < 50; i++){
        cout << array2[i] << endl;
    }
    
    quicksort(array2, 0, 49);
    cout << "Array after quicksort: " << endl;
    for(int i = 0; i < 50; i++){
        cout << array2[i] << endl;
    }
    
    delete[] array1;
    delete[] array2;
    
    return 0;
}