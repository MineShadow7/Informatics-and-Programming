//Copyright Andrey Karagodin

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int* mass, int n, int* countOfComp, int* countOfSwap) {
	int temp;
	(*countOfComp) = 0;
	(*countOfSwap) = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (mass[i] < mass[i + 1]) {
				temp = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = temp;
				(*countOfSwap) += 1;
			}
			(*countOfComp) += 1;
		}
	}
}
	void printMatrix(int** matrix, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
}

void swap(int* mass, int indx1, int indx2) {
	int temp = mass[indx1];

}
int genRandNumber(int max, int min) {
	int value = (max - min) * ((float)rand() / RAND_MAX) + min;
	return value;
}

void bubbleSortWithFlag(int* mass, int n, int* countOfComp, int* countOfSwap) {
		int temp;
		(*countOfComp) = 0;
		(*countOfSwap) = 0;
		int all_right = 0;
		for (int j = 0; j < n; j++){
			for (int i = 0; i < n; i++) {
				if (mass[i] < mass[i + 1]) {
					temp = mass[i];
					mass[i] = mass[i + 1];
					mass[i + 1] = temp;
					(*countOfSwap) += 1;
					all_right = 0;
				}
				(*countOfComp) += 1;
			}
			if (all_right) break;
		}
}

void countingSort(int* mass, int n, int min, int max, int* countOfComp, int* countOfSwap) {
	int* count = NULL;
	int size = max - min + 1;

	count = (int*)malloc(size * sizeof(int));

	(*countOfSwap) = 0;
	(*countOfComp) = 0;
	for (int i = 0; i < size; i++) {
		count[i] = 0;

	}
	for (int i = 0; i < n; i++) {
		count[mass[i] - min] += 1;
	}
	int ind = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < count[size - i - 1]; j++) {
			mass[ind] = size - i - 1;
			ind += 1;
			(*countOfSwap) += 1;
		}
		(*countOfComp) += 1;
	}
}

int main() {
	int* mass;
	int* copy_3;
	int n = 0, min = 0, max = 0;
	int countOfComp = 0, countOfSwap = 0;
	int m = 0;

	printf("Input Array size: \n> ");
	scanf_s("%d", &n);

	printf("Input min and max value of random (between space): \n> ");
	scanf_s("%d %d", &min, &max);

	mass = (int*)malloc(n * sizeof(int));
	copy_3 = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		mass[i] = genRandNumber(max, min);
	}

	for (int i = 0; i < n; i++) {
		printf("%d", mass[i]);
	}
	int time = clock();
	bubbleSort(mass, n, &countOfComp, &countOfSwap);
	time = clock() - time;


	if (n < 21){
	printf("Sort Array: ");
	printMatrix(mass, n, m);
	}


	time = clock();
	countingSort(copy_3, n, min, max, &countOfComp, &countOfSwap);
	time = clock() - time;

	printf("\Time of work: %d ms \nCount of comparisons: %d\Count Of Swap: %d\n", time, countOfComp, countOfSwap);
	

	/* Counting Sort */


	return 0;
}
