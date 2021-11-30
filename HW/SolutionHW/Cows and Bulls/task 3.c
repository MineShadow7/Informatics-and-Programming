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

void arr_fix(int* arr) {
	for(int tries = 0; tries < n; tries++){
		for (int i = 1; i < n; i++) {
			if (arr[i] == arr[i - 1] || arr[i] == arr[i - 2] || arr[i] == arr[i - 3] || arr[i] == arr[i - 4]) {
				if (arr[i] == 9)
					arr[i] = 0;
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

int player_array_input(int playernumber, int maxlen) {
	int workstop = 0, inverse = 0, currentlen = 0, rem, fail = 0;

	while (workstop == 0) {
		int workingvariable = 0;
		while (playernumber > 0) {
			rem = playernumber % 10;
			inverse = inverse * 10 + rem;
			playernumber = playernumber / 10;
			currentlen += 1;
		}

		//printf("%d\n", inverse);

		if (currentlen == maxlen) {
			while (inverse != 0) {
				player_number[workingvariable] = inverse % 10;
				inverse /= 10;
				workingvariable++;
			}
			workstop = 1;
			for (int i = 0; i < n; i++)
				printf("%d", player_number[i]);
		}
		else
		{
			printf("Длинна введенного числа не соответствует максимальной длине (%d), попробуйте еще раз.", maxlen);
			break;
			fail = 1;
		}
	}
	return fail;
}

void player_array_check(int* arr) {
	int checks_failed = 0, choice = 0;

	while (1) {
		for (int i = 1; i < n; i++) {
			if (arr[i] == arr[i - 1] || arr[i] == arr[i - 2] || arr[i] == arr[i - 3] || arr[i] == arr[i - 4]) {
				checks_failed = 1;
				break;
			}
			else
				break;
		}
		if (checks_failed) {
			printf("\nОбнаружено повторение цифр в введенном числе. Хотите чтобы компьютер автоматически исправил введенное число? Да(1)/Нет(0): ");
			scanf_s("%d", &choice);
			checks_failed = 0;
			break;
		}
		else
		{
			for (int i = 0; i < n; i++)
				printf("%d", player_number[i]);
			checks_failed = 0;
			break;
		}
	}
	if (choice == 1) {
		arr_fix(arr);
		choice = 0;
		checks_failed = 0;
		for (int i = 0; i < n; i++)
			printf("%d", player_number[i]);
	}
}

int main() {
	int playertemp, cows = 0, bulls = 0, win = 0, fail = 0;

	setlocale(LC_ALL, "Russian");
	printf("Введите максимальную длину числа (от 2 до 5): ");
	scanf_s("%d", &n);
	while (1) {
		if ((n >= 2) && (n <= 5))
			break;
		else{
			printf("Wrong range!\n");
			return 0;
		}
			
	};

	player_number = (int)malloc(n * sizeof(int));
	comp_number = (int)malloc(n * sizeof(int));


	arr_generate(comp_number, 1, 9, n);
	for (int i = 0; i < n; i++) {
		printf("%d", comp_number[i]);
	}

	printf("\n");
	arr_fix(comp_number);
	for (int i = 0; i < n; i++) {
		printf("%d", comp_number[i]);
	}



	do {
		printf("\nВведите число без повторений цифр: ");
		scanf_s("%d", &playertemp);
		
		player_array_input(playertemp, n);
		printf("\n");
		if (fail != 0)
			player_array_check(player_number);
		

		game(player_number, comp_number, &cows, &bulls, n);
		printf("\nВы угадали коров %d, а быков %d", cows, bulls);

		if (bulls == n) {
			printf("\nВы выиграли! Количество быков = %d", bulls);
			win = 1;
		}


	} while (win != 1);

}
