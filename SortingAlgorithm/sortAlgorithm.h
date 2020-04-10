//
// Created by RaviLian on 2020/4/9.
//
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

/***
 * Shell sort algorithm sorts array elements from small to large
 * @param arr
 * @param len
 */
void ShellSort (int *arr, int len);

/***
 * quick Sort
 * @param arr
 * @param begin
 * @param end
 */
void quickSort (int *arr, int begin, int end);

/***
 * 返回标杆位置pivot
 * @param a
 * @param begin
 * @param end
 * @return
 */
int partition (int *a, int begin, int end);

/***
 *
 * @param arr
 * @param left
 * @param right
 */
void mergeSort (int *arr, int left, int right);

/***
 *
 * @param a
 * @param left
 * @param mid
 * @param right
 */
void merge (int *a, int left, int mid, int right);
#endif //SORTINGALGORITHM_SORTALGORITHM_H
