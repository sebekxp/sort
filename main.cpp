#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include "interFace.h"

#pragma warning (disable: 4996)
#pragma comment(linker, "/STACK:1000000000")

typedef void(*SortFunc)(int *arr, int n);
typedef void(*SortingFunc)(int *arr, int n);

void fillArray(int *arr, int n);
void displayArray(int *arr, char *title, int n);
double timeCalculation(SortFunc sortFunc, int *tempArray, int n);
void savetofile(int *tempArray, int n);
void addToArray(int *tempArray, int n);
void reverseArray(int *tempArray, int n);


int main()
{
	srand(time(NULL));
	int choice, i, j, end, n;
	
	do {
		printf("[0] - Sort I group method\n");
		printf("[1] - Sort II group method\n");
		printf("[2] - Sort All group method\n");
		printf("[3] - Exit\n");
		printf("Choose option: ");
		scanf("%d", &choice);
		switch (choice) {
		case 0:
			i = 0;
			end = 3;
			break;
		case 1:
			i = 3;
			end = 6;
			break;
		case 2:
			i = 0;
			end = 6;
			break;
		}
		if (choice != 3) {
			printf("\nEnter array size: ");
			scanf("%d", &n);
			int *arr = (int*)malloc(n * sizeof(int));
			fillArray(arr, n);

			int *tempArray = (int*)malloc(n * sizeof(int));
			memcpy(tempArray, arr, n * sizeof(int));

			for (int x = 0; x < 3; x++) {
				if (x == 1)
					memcpy(arr, tempArray, n * sizeof(int));
				if (x == 2) {
					reverseArray(tempArray, n);
					memcpy(arr, tempArray, n * sizeof(int));
				}
				printf("\n\n\t   %s\n", dataName[x]);
				printf(" ___________________________________\n");
				printf("|     METHOD\t  |\t  TIME      |\n");
				printf("|_________________|_________________|\n");
				for (j = i; j < end; j++) {
					memcpy(tempArray, arr, n * sizeof(int));
					printf("| %-15s | %-10.5lf s    |\n", methodName[j], timeCalculation(sortingFuncAll[j], tempArray, n));
				}
				printf("|_________________|_________________|\n\n");
				if (x == 0)
				{
					savetofile(tempArray, n);
					addToArray(tempArray, n);
				}
			}
			if (arr) {
				free(arr);
				arr = NULL;
			}
			if (tempArray) {
				free(tempArray);
				tempArray = NULL;
			}
		}
	} while (choice != 3);
	return 0;
}
void fillArray(int *arr, int n) {

	size_t i;
	for (i = 0; i < n; ++i) {
		arr[i] = -100 + rand() % 201;
	}
}
void displayArray(int *tempArray, char *title, int n) {
	size_t i;
	printf("%s\n", title);
	for (i = 0; i < n; ++i) {
		printf("%d ", tempArray[i]);
	}
	printf("\n");
}
void reverseArray(int *tempArray, int n) {
	int temp;
	for (int i = 0; i < (n - 1) / 2; i++) {
		temp = tempArray[i];
		tempArray[i] = tempArray[n - 1 - i];
		tempArray[n - 1 - i] = temp;
	}

}
double timeCalculation(SortFunc sortFunc, int *tempArray, int n) {
	clock_t start, end;
	double timeUsed;
	start = clock();
	sortFunc(tempArray, n);
	end = clock();
	return timeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;
}
void savetofile(int *tempArray, int n) {
	FILE *save;
	if ((save = fopen("dane.txt", "w")) == NULL)
	{
		printf("Brak pliku :(\n");
		return;
	}

	for (int i = 0; i<n; i++)
	{
		fprintf(save, "%d\n", tempArray[i]);
	}

	fclose(save);
}
void addToArray(int *tempArray, int n) {

	FILE *file;
	file = fopen("dane.txt", "r");
	if (file == NULL)
	{
		printf("Brak pliku :(\n");
		return;
	}

	for (int i = 0; i<n; i++)
		fscanf(file, "%d", &tempArray);
	fclose(file);
}