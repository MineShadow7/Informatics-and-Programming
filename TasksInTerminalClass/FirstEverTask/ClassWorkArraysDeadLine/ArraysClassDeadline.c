#include <stdio.h>
#include <math.h>
#include <locale.h>


#define SIZE 10	//Размер массива

int i, k, max, s, d;
int mas[SIZE];


int main() {

	setlocale(LC_ALL, "Russian");
	printf("Введите число K для сдвига элемента: ");
	scanf_s("%d", &k);


	//Заполнить массив случайными числами от 0 до 20
	srand(time(0));
	for (i = 0; i < SIZE; i++) {
		mas[i] = rand() % 20;
		printf("%d ", mas[i]);
	}
	printf("\n");

	for (i = 0; i < k; i++) {
		s = mas[SIZE - 1];
		for (d = SIZE - 1; d > -1; d--) 
		{
			mas[d] = mas[d - 1];
		}
		mas[0] = s;
	}
	for (i = 0; i < SIZE; i++) {
		printf("%d ", mas[i]);
	}


	printf("\n");

	for (i = 0; i < (SIZE / 2); i++) {
		s = mas[i];
		mas[i] = mas[SIZE - i - 1];
		mas[SIZE - i - 1] = s;
	}
	
	for (i = 0; i < SIZE; i++) {
		printf("%d ", mas[i]);
	}

	return 0;
}