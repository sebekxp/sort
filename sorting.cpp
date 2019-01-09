
//Inseration Sort
void insertionSort(int *tempArray, int n) {
	int i, x, j;
	for (i = 1; i < n; i++) {
		x = tempArray[i];
		j = i - 1;
		while (j >= 0 && tempArray[j] > x) {
			tempArray[j + 1] = tempArray[j];
			j = j - 1;
		}
		tempArray[j + 1] = x;
	}
}

//Selection Sort
void selectionSort(int *tempArray, int n) {
	int i, j, minIndex;
	for (i = 0; i < n - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < n; j++)
			if (tempArray[j] < tempArray[minIndex])
				minIndex = j;
		int temp = tempArray[minIndex];
		tempArray[minIndex] = tempArray[i];
		tempArray[i] = temp;
	}
}

//Bubble Sort
void bubbleSort(int *tempArray, int n) {

	int i, j, swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = 0;
		for (j = 0; j < n - i - 1; j++) {
			if (tempArray[j] > tempArray[j + 1]) {
				int temp = tempArray[j];
				tempArray[j] = tempArray[j + 1];
				tempArray[j + 1] = temp;
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}

//Quick Sort
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int *tempArray, int left, int right) {

	int pivot = tempArray[right];
	int i = left - 1;
	int j = right;

	for (;;) {
		while (tempArray[++i] < pivot);
		while (pivot < tempArray[--j]) if (j == left) break;
		if (i >= j) break;
		swap(&tempArray[i], &tempArray[j]);
	}
	swap(&tempArray[i], &tempArray[right]);
	return i;
}
void quickSortWrapper(int *tempArray, int left, int right) {
	if (right <= left) return;
	int part = partition(tempArray, left, right);
	quickSortWrapper(tempArray, left, part - 1);
	quickSortWrapper(tempArray, part + 1, right);

}
void quickSort(int *tempArray, int n) {
	quickSortWrapper(tempArray, 0, n - 1);
}
//Shell Sort
void shellSort(int *tempArray, int n) {

	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i += 1) {
			int temp = tempArray[i];
			int j;
			for (j = i; j >= gap && tempArray[j - gap] > temp; j -= gap)
				tempArray[j] = tempArray[j - gap];
			tempArray[j] = temp;
		}
	}
}
//Heap Sort
void swapFunc(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int *tempArray, int n, int i) {

	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && tempArray[left] > tempArray[largest])
		largest = left;
	if (right < n && tempArray[right] > tempArray[largest])
		largest = right;
	if (largest != i)
	{
		swapFunc(&tempArray[i], &tempArray[largest]);
		heapify(tempArray, n, largest);
	}
}

void heapSort(int *tempArray, int n) {

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(tempArray, n, i);
	for (int i = n - 1; i >= 0; i--) {

		swapFunc(&tempArray[0], &tempArray[i]);
		heapify(tempArray, i, 0);
	}
}
