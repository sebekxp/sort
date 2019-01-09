#pragma once
#include "sorting.h"

typedef void(*SortFunc)(int *arr, int n);
typedef void(*SortingFunc)(int *arr, int n);

SortingFunc sortingFuncAll[] = { insertionSort, selectionSort, bubbleSort,quickSort, shellSort,heapSort };

char *methodName[] = { (char*)"Inseration Sort",//0
(char*)"Selection Sort",//1
(char*)"Bubble Sort",//2
(char*)"Quick Sort",//3
(char*)"Shell Sort",//4
(char*)"Heap Sort" };//5

char *dataName[] = { (char*)"RANDOM DATA",
(char*)"SORTED DATA",
(char*)"REVERSED DATA" };