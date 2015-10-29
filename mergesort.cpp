//  mergesort on an array of ints.
// ------------------------------ Mergesort ------------------------------------
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void merge(int* sorted_array, int first, int half, int last){
    int size = last - first + 1;
    int* mergedNums = new int[size];
    int rightIndex = 0;
    int leftIndex = 0;
    int mergeIndex = 0;
    leftIndex  = first;     
    rightIndex = half + 1; 

    // assume array is sorted, and needs to be merged only
    while(leftIndex <= half && rightIndex <= last){
        if(sorted_array[leftIndex] < sorted_array[rightIndex]){
            mergedNums[mergeIndex] = sorted_array[leftIndex];
            leftIndex++;
        }
        else{
            mergedNums[mergeIndex] = sorted_array[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }
    
    // consider left partition needs to be fully added
    // maybe check if && -> || for condition in while to get rid of these
    while(leftIndex <= half){
        mergedNums[mergeIndex] = sorted_array[leftIndex];
        leftIndex++;
        mergeIndex++;
        
    }
    while(rightIndex <= last){
        mergedNums[mergeIndex] = sorted_array[rightIndex];
        rightIndex++;
        mergeIndex++;
    }
    //now we need to copy all of the elements back into a temp
    mergeIndex = 0;
    while(mergeIndex < size){
        sorted_array[first + mergeIndex] = mergedNums[mergeIndex];
        mergeIndex++;
    }
    
}

void mergeSort(int* unsorted_array, int first, int last){
    int midpoint = 0;
    if(first < last){
        midpoint = (first + last) / 2;
        
        mergeSort(unsorted_array, first, midpoint);
        mergeSort(unsorted_array, midpoint + 1, last);
        // now sorted array
        merge(unsorted_array, first, midpoint, last);
    }
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
    
    cout << "Array before Mergesort: " << endl;
    for(int i = 0; i < 20; i++){
        cout << array1[i] << endl;
    }
    
    cout << "Array after Mergesort: " << endl;
    mergeSort(array1, 0, 19);
    for(int i = 0; i < 10; i++){
        cout << array1[i] << endl;
    }
    
    cout << "Array before Mergesort: " << endl;
    for(int i = 0; i < 50; i++){
        cout << array2[i] << endl;
    }
    
    mergeSort(array2, 0, 49);
    cout << "Array after Mergesort: " << endl;
    for(int i = 0; i < 50; i++){
        cout << array2[i] << endl;
    }
    
    delete[] array1;
    delete[] array2;
    
    return 0;
}
