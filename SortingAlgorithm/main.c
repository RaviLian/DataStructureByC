#include <stdio.h>
#include "sortAlgorithm.h"
#include <math.h>
int main() {
    int array[10] = {5, 18, 151, 138, 160, 63, 174, 169, 79, 200};
    PrintArray(array,10);
    mergeSort(array,0,9);
    PrintArray(array,10);
//    quickSort(array,0,9);
//    PrintArray(array,10);
//    ShellSort(array,10);
//    PrintArray(array,10);
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

void quickSort (int *arr, int begin, int end) {
    if (end <= begin) return;
    int pivot;
    pivot = partition(arr, begin, end);
    quickSort(arr, begin, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

int partition (int *a, int begin, int end) {
    //pivot 标杆位置，counter 小于pivot的元素的个数
    int pivot = end, counter = begin;
    int i, temp;
    //counter代表第一个大于pivot的位置
    //找到比pivot小的元素就会和counter位置的元素交换
    for (i = begin; i < end; i++) {
        if (a[i] < a[pivot]) {
            temp = a[counter]; a[counter] = a[i]; a[i] = temp;
            counter++;
        }
    }
    //最后pivot和counter位置的元素互换，左侧元素均小于pivot，右侧元素均大于pivot
    temp = a[pivot]; a[pivot] = a[counter]; a[counter] = temp;
    return counter;
}

void mergeSort (int *arr, int left, int right) {
    if (right <= left)
        return;
    int mid = (left + right) >> 1; //(left + right)/2

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void merge (int *a, int left, int mid, int right) {
    int temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    int p;

    while (i <= mid && j <= right) {
        temp[k++] = a[i] <= a[j] ? a[i++] : a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];

    for (p = 0; p < right - left + 1; p++) {
        a[left + p] = temp[p];
    }
}