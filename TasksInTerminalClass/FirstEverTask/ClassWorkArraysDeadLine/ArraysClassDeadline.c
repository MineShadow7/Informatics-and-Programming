#include <stdio.h>
#include <math.h>
#include <locale.h>


#define SIZE 10	//Размер массива

int i, k, max, s;
int mas[SIZE], mas2[SIZE];


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

	max = mas[0];
	for (i = 1; i < SIZE; i++) {
		if (mas[i] > max) {
			max = mas[i];
			k = i;
		}
	}
	for (i = 0; i < SIZE; i++) {
		mas2[i] = mas[i];
	}

	for (i = 0; i < k; i++) {
		mas[i] = mas2[i + SIZE - k];
	}
	for (i = k; i < SIZE; i++) {
		mas[i] = mas2[i - k];
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d ", mas[i]);		//Сдвинули массив, теперь перевернем его
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