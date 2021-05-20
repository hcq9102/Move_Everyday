/*
case description:
Encapsulate a function, use bubble sort, to sort an int array in ascending order.
 */

#include <iostream>
using namespace std;

//bubble sort

void bubbleSort(int *arr , int len){ // int arr[] = int *arr ;  *arr means 数组首地址
    for(int i = 0; i< len-1; i++){
        for(int j = 0; j < len -i -1; j++){
            if(arr[j]> arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// print
void printArr(int *arr, int len){
    for(int i = 0; i< len; i++){
        cout << arr[i] << endl;
    }
}

int main() {
    // creat array
    int arr[10] = {4,3,6,9,1,2,10,8,7,5};
    //creat function, bubble sort;
    int len = sizeof(arr)/ sizeof(arr[0]);
    bubbleSort(arr,len);
    //print the sorted array
    printArr(arr,len);

    return 0;
}
