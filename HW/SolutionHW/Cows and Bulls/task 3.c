#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <locale.h>



int *player_number, *comp_number, n;

void arr_generate(int *arr, int min_val, int max_val, int n) {
	int i = 0;
	int equal = 1;
	srand(time(0));
	for (i = 0; i < n; i++) 
		arr[i] = rand() % (max_val - min_val + 1) + min_val;
}
void arr_check(int* arr) {
	for(int tries = 0; tries < n; tries++){
		for (int i = 1; i < n; i++) {
			if (arr[i] == arr[i - 1] || arr[i] == arr[i - 2] || arr[i] == arr[i - 3] || arr[i] == arr[i - 4]) {
				if (arr[i] == 9)
					arr[i] = arr[i] - 1;
				else if (arr[i] == 0)
					arr[i] = arr[i] + 1;
				else
					arr[i] = arr[i] + 1;
			}
		}
	}
}


void game(int* player_number, int* comp_number, int *cows, int *bulls, int n) {
	*cows = *bulls = 0;
	for (int i = 0; i < n; i++) {
		if ((comp_number[i] == player_number[i]) && (player_number[i] != -1)) {
			*bulls += 1;
			player_number[i] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if ((comp_number[k] == player_number[i]) && (player_number[k] > -1)) {
				*cows += 1;
				player_number[k] = -1;
			}
		}
	}
}


int main() {
	int rem, playertemp, workstop = 0, inverse = 0, cows = 0, bulls = 0;

	setlocale(LC_ALL, "Russian");
	printf("Введите максимальную длину числа (от 2 до 5): ");
	scanf_s("%d", &n);


	player_number = (int)malloc(n * sizeof(int));
	comp_number = (int)malloc(n * sizeof(int));


	arr_generate(comp_number, 1, 9, n);
	for (int i = 0; i < n; i++) {
		printf("%d", comp_number[i]);
	}

	printf("\n");
	arr_check(comp_number);
	for (int i = 0; i < n; i++) {
		printf("%d", comp_number[i]);
	}


	printf("\nВведите число без повторений цифр: ");
	scanf_s("%d", &playertemp);

	
	while (workstop == 0) {
		int workingvariable = 0;
		while (playertemp > 0){
			rem = playertemp % 10;
			inverse = inverse * 10 + rem;
			playertemp = playertemp / 10;
		}
		
		printf("%d\n", inverse);

		while (inverse != 0) {
			player_number[workingvariable] = inverse % 10;
			inverse /= 10;
			workingvariable++;
		}
		workstop = 1;
		for (int i = 0; i < n; i++)
			printf("%d", player_number[i]);
	}


	game(player_number, comp_number, &cows, &bulls, n);
	printf("\nВы угадали коров %d, а быков %d", cows, bulls);
	

}