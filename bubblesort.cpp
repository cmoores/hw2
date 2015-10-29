//  bubblesort on an array of ints.
// ------------------------------ Bubblesort ------------------------------------
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubblesort(int* unsorted_array, int size){
    int temp = 0;
    bool done = false;
    while(size != 0){
        int newSize = 0;
        for(int i = 1; i <= size - 1 ; i++){
            if(unsorted_array[i - 1] >= unsorted_array[i]){
                temp = unsorted_array[i];
                unsorted_array[i] = unsorted_array[i - 1];
                unsorted_array[i - 1] = temp;
                newSize = i;
            }
        }
        size = newSize;
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
    
    cout << "Array before bubblesort: " << endl;
    for(int i = 0; i < 20; i++){
        cout << array1[i] << endl;
    }
    
    cout << "Array after bubblesort: " << endl;
    bubblesort(array1, 20);
    for(int i = 0; i < 20; i++){
        cout << array1[i] << endl;
    }
    
    cout << "Array before bubblesort: " << endl;
    for(int i = 0; i < 50; i++){
        cout << array2[i] << endl;
    }
    
    bubblesort(array2, 50);
    cout << "Array after bubblesort: " << endl;
    for(int i = 0; i < 50; i++){
        cout << array2[i] << endl;
    }
    
    delete[] array1;
    delete[] array2;
    
    return 0;
}