#include <stdio.h>
#include "sortAlgorithm.h"
#include <math.h>
int main() {
    int array[10] = {5, 18, 151, 138, 160, 63, 174, 169, 79, 200};
    PrintArray(array,10);
    ShellSort(array,10);
    PrintArray(array,10);
//    InsertionSort(array,4);
//    PrintArray(array,4);
//    BubbleSort(array,10);
//    PrintArray(array,10);
//    SelectionSort(array,10);
//    PrintArray(array,10);

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
        while (preIndex >= 0 && arr[preIndex] > currentElem) {
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

void ShellSort (int *arr, int len) {
    int i, j, temp, gap;
    //The step size is initialized to half the length of the array,
    // and the step size is halved after each traversal
    for (gap = len / 2; gap >= 1; gap /= 2) {
        //认为步长为gap的元素是一组，对它们进行插入排序，
        // 当gap为1时，就是对整个数组进行插入排序；此段代码可以完全参考插入排序
        for (i = gap; i < len; i += gap) {
            temp = arr[i];  //备份，因为从后向前扫描，元素可能会后移覆盖
            j = i - gap; //j初始化为i的前一个元素（与i相差gap长度）
            while (j >= 0 && arr[j] > temp) {
                arr[j + gap] = arr[j];  //将在arr[i]前且比temp的值大的元素向后移动一位
                j -= gap;
            }
            arr[j + gap] = temp;
        }
    }
}