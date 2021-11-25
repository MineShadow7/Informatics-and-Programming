#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	int n = 0, m = 0, mode, temp, attempts = 0, working = 1;
	char action;
	setlocale(LC_ALL, "Russian");

	printf("������� ����� ��� ������ ���������. ����� 1 - �� ���������� ����� ���������� ����������. ����� 2 - ��������� �������� ������� ���� �����.\n ��� �����: ");
	scanf_s("%d", &mode);

	do {
		switch (mode) {
		case 1:
			srand(time(0));
			n = (1 + rand() % 1000);
			printf("%d - ���������� ����� �����������\n", n);
			printf("�������� ����� ���������� ����������� �� 1 �� 1000.\n");
			while (m != n) {
				printf("������� �����: ");
				scanf_s("%d", &m);
				if (m < n)
					printf("����� ���������� ����������� ������ ����������. ���������� ��� ���.\n");

				else if (m > n)
					printf("����� ���������� ����������� ������ ����������. ���������� ��� ���.\n");
			}
			printf("����� � ��������� �������. �����������!\n");
			working = 0;
			break;
		case 2:
			printf("������� ����� ������� ������ �������� ���������: ");
			scanf_s("%d", &m);
			srand(time(0));
			n = (1 + rand() % 1000);
			printf("����� ����������: %d \n", n);
			printf("����� ���������� ����������� ������ (>), ������ (<) ��� ����� (=) ������ �����? ������� ����: ");
			do {
				
				
				{
					scanf_s("%c", &action);
					switch (action) {
					case '>':
						temp = (1 + rand() % 250);
						n -= temp;
						attempts += 1;
						printf("����� ����������: %d \n", n);
						printf("����� ���������� ����������� ������ (>), ������ (<) ��� ����� (=) ������ �����? ������� ����: ");
						break;
					case '<':
						temp = (1 + rand() % 250);
						n += temp;
						attempts += 1;
						printf("����� ����������: %d \n", n);
						printf("����� ���������� ����������� ������ (>), ������ (<) ��� ����� (=) ������ �����? ������� ����: ");
						break;
					case '=':
						attempts += 1;
						working = 0;
						break;
					}
				}
			} while (working != 0);
			printf("���������� ������� ������� ���� �����. ��� �������? ��� ������������� �������: %d", attempts);
		}
	} while (working != 0);
}