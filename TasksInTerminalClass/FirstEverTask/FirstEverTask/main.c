//��� ������ ����������� ��� ������ ��� ���������� ��� ������ (����-�����, �������������� �������).
#include <stdio.h>
#define _USE_MATH_DEFINES			//�������� ����, �� � �� ����� ����� ��� ��� �������� �� ��������. ����� ������ ��������, �� � ����� ������ � ������� ��� � �����.
#include <math.h>
#include <locale.h>

//�������� ������ ��� ��������� ������������ ������ ��������� ������ ������ ����� � �� ������ �� ������� ������������ ������� ���� �����.

int main(){
	setlocale(LC_ALL, "Russian");								//����� �� ������ ������� ���� ��� �������, �������� ������ �������.
	int t1, t2, p1, p2, r1;										//����� �������������� ��� ������ ��� ����������. ����� �������� �� 1 ����� ������ �� ����. ����� ���� ������� ������ ���.
	float t3, p3, r2;											//��� ���������� ����� �������� �� ���� �������. � ����� ��� ��� ����� � ������� float.
	printf("������� 2 ������� ��� ������������ = \n");			
	scanf_s("%d %d", &t1, &t2);									//������ ������������ ������ � ������� ������.
	t3 = (t1 * t2) * 0.5;										//������������ ������� ������������ �� ��� ����� ������� �������.
	printf("������� ������������ ����� = %.1f \n", t3);			//������� ����� � �������.


	printf("������� 2 ������� �������������� = \n");			//����� �� ������ ������ ������.
	scanf_s("%d %d", &p1, &p2);
	p3 = p1 * p2;												//������������ �� ���������� �������.
	printf("������� �������������� = %.1f \n", p3);				//������� ����� � ���������.


	printf("������� ������ ���������� = \n");
	scanf_s("%d", &r1);
	r2 = M_PI * (r1 ^ 2);										//������������ ������� ���������� ����� ��������� M_PI (3.14..) ���������� �� ������ � ��������.
	printf("������� ���������� ����� = %.2f\n", r2);			//������� ����� � ������� �� ����. (Proshu ne beite za russkiy yazik v commentaries)
}
