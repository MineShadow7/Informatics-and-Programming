	//Copyright 2021 ��������� ������
	/*
		�������� ������ �� ������ � ���������.

		���������� ������:
		1. ��������� ��������� �������.
		2. 
	
	*/
#include <stdio.h>
#include <math.h>
#define SIZE 10


	//����������� �������.
int main() {
	/*
	int massive[100] = { 0 };		//������ �� 100 ���������
	int mass_1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int mass_2[5];	//������ ������ 

	//const int sizer = 10;		//����� ����� ������ ��������� ���������� ����� �� ����� ���� ����� �������� � ������ ����.
	//int mass_3[sizer];			//�� � ���� ������, ������ ��������.

	int mass_4[SIZE];

	//������������ ������.
	* �������������� ����:
	* int name;
	* char firstSymName = 'M';
	* 
	* name = (char)firstSymName;
	

	*/
	int size;
	//���������� ������������� �������
	float* mass;

	printf("Input size of dynamic array: \n>");
	scanf_s("%d", &size);

	/*��������� ������ ��� ������������ ������
	*malloc (size);
	*sizeof(float) - ���������� ������ ���� ������.
	*/
	mass = (float*)malloc(size * sizeof(float));

	int i;
	for (i = 0, i < size; i++;)
	{
		mass[i] = i + 1;
	}

	for (i = 0, i < size; i++;) 
	{
		printf("%.1f", mass[i]);
	}

	float sum_even_el = 0.0, sum_even_values = 0.0, sum_even_index = 0.0;

	for (i = 0; i < size; i++) {
		if ((i + 1) % 2 == 0) {
			sum_even_el = sum_even_el + mass[i];
		}
		else 
		{
			sum_even_index = sum_even_index + mass[i];
		}
		if ((int)mass[i] % 2 == 0)	//��� ����������� float � ����� ��������.
		{
			sum_even_values += mass[i];
		}
	}

	//������� �������� �������
	printf("\nSum of even elements: %.1f", sum_even_el);
	printf("\nSum of even index: %.1f", sum_even_index);
	printf("\nSum of even value: %.1f", sum_even_values);
	
	int indx;
	printf("Input index to replace: \n>");
	scanf_s("%d", &indx);


	float new_value;
	printf("Input new value: \n>");
	scanf_s("%f", &new_value);

	//��� ����� ������
	/*
	for (i = 0, i < size; i++;) {
		if (i == indx) {
			mass[indx] = new_value;
		}
	}
	*/

	float finding_element;
	printf("Input element for search and replace:\n> ");
	scanf_s("%f", &finding_element);
	for (i = 0; i < size; i++) {
		if (mass[i] == finding_element) {


		}
	}

	mass[indx] = new_value;
	printf("Your array now: ");
	for (i = 0; i < size; i++) {
		printf("%.1lf", mass[i]);
	}
	/*
	* i = 0;
	* while (i < size){ 
	* mass[i] = i + 1;
	* 
	*  i++;
	* }
	*/
	/*�������� ���������� �������
	int m1[10]; //�� �� �������
	int m2[SIZE];
	int m3[] = { 1, 2, 3, 4, 5 };
	*/
	/*��������� ��� ���������. int* - ��������� �� ����� �����. 
	int* m4; //��������� �� ������ �������������� �������.

	int summ = 0, indx = 0, new_value = 0;

	printf("%f", mass[0]);				//������ ������� ��������.
	*/


	//������ ����� �������� ������ ����� ��� �� ����.
	free(mass);
	
	return 0;
}
