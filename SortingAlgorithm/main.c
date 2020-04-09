#include <stdio.h>
#include "sortAlgorithm.h"

int main() {
    int array[10] = {3, 44, 38, 5, 47, 15, 36, 50, 27, 48};
    PrintArray(array,10);
//    InsertionSort(array,10);
//    PrintArray(array,10);
//    BubbleSort(array,10);
//    PrintArray(array,10);
    SelectionSort(array,10);
    PrintArray(array,10);

    return 0;
}

void PrintArray(int a[], int len){
    int i;
    for(i = 0; i < len; i++)
        printf("%d  ",a[i]);
    printf("\n");
}

void BubbleSort (int *arr, int len) {
    int i,j,temp;
    for (i = 0; i < len-1; i++) {
        for (j = 0; j < len-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void InsertionSort (int *arr, int len) {
    int preIndex, currentElem;
    int i;
    for (i = 1; i < len; i++) {
        preIndex = i - 1;
        currentElem = arr[i];
        while (preIndex > 0 && arr[preIndex] > currentElem) {
            arr[preIndex + 1] = arr[preIndex];
            preIndex--;
        }
        arr[preIndex + 1] = currentElem;
    }
}

void SelectionSort (int *arr, int len) {
    int minIndex, temp;
    int i, j;
    for (i = 0; i < len -1; i++) {
        minIndex = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
