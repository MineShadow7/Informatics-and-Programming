#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	int n = 0, m = 0, mode, temp, attempts = 0, working = 1;
	char action;
	setlocale(LC_ALL, "Russian");

	printf("Введите режим для работы программы. Режим 1 - вы угадываете число загаданное программой. Режим 2 - программа пытается угадать ваше число.\n Ваш режим: ");
	scanf_s("%d", &mode);

	do {
		switch (mode) {
		case 1:
			srand(time(0));
			n = (1 + rand() % 1000);
			printf("%d - загаданное число компьютером\n", n);
			printf("Угадайте число загаданное компьютером от 1 до 1000.\n");
			while (m != n) {
				printf("Введите число: ");
				scanf_s("%d", &m);
				if (m < n)
					printf("Число загаданное компьютером больше введенного. Попробуйте еще раз.\n");

				else if (m > n)
					printf("Число загаданное компьютером меньше введенного. Попробуйте еще раз.\n");
			}
			printf("Число с точностью угадано. Поздравляем!\n");
			working = 0;
			break;
		case 2:
			printf("Введите число которое должен отгадать компьютер: ");
			scanf_s("%d", &m);
			srand(time(0));
			n = (1 + rand() % 1000);
			printf("Число компьютера: %d \n", n);
			printf("Число загаданное компьютером больше (>), меньше (<) или равно (=) вашему числу? Введите знак: ");
			do {
				
				
				{
					scanf_s("%c", &action);
					switch (action) {
					case '>':
						temp = (1 + rand() % 250);
						n -= temp;
						attempts += 1;
						printf("Число компьютера: %d \n", n);
						printf("Число загаданное компьютером больше (>), меньше (<) или равно (=) вашему числу? Введите знак: ");
						break;
					case '<':
						temp = (1 + rand() % 250);
						n += temp;
						attempts += 1;
						printf("Число компьютера: %d \n", n);
						printf("Число загаданное компьютером больше (>), меньше (<) или равно (=) вашему числу? Введите знак: ");
						break;
					case '=':
						attempts += 1;
						working = 0;
						break;
					}
				}
			} while (working != 0);
			printf("Компьютеру удалось угадать ваше число. Уже страшно? Ему потребовалось попыток: %d", attempts);
		}
	} while (working != 0);
}