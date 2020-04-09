//
// Created by RaviLian on 2020/4/9.
//
#include <stdlib.h>
#ifndef SORTINGALGORITHM_SORTALGORITHM_H
#define SORTINGALGORITHM_SORTALGORITHM_H

/***
 * Print an array
 * @param a
 * @param len
 */
void PrintArray(int a[], int len);

/***
 * Bubble sort algorithm sorts array elements from small to large
 * @param arr
 * @param len
 */
void BubbleSort (int *arr, int len);

/***
 * Insertion sort algorithm sorts array elements from small to large
 * @param arr
 * @param len
 */
void InsertionSort (int *arr, int len);

/***
 * Selection sort algorithm sorts array elements from small to large
 * @param arr
 * @param len
 */
void SelectionSort (int *arr, int len);
#endif //SORTINGALGORITHM_SORTALGORITHM_H
