#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int  x1, x2, y1, y2, r1, r2, dist;
	printf("������� ����� ������ ���������� x, y � ������ r ������ ����������:\n");
	scanf_s("%d %d %d", &x1, &y1, &r1);

	printf("������� ����� ������ ���������� x, y � ������ r ������ ����������:\n");
	scanf_s("%d %d %d", &x2, &y2, &r2);

	//������ ����������� ����������� �� ���� �������

	dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	
	//������ ������������ �����������


	if (dist == r1 + r2)
	{
		printf("���������� ��������");
	}
	else if (dist < r1 + r2)
	{
		if ((dist == 0) && (r1 == r2))
		{
			printf("���������� ���������");
		}
		else if ((dist + r1 < r2) || (dist + r2 < r1))
		{
			printf("���� ���������� ������ � ������");
		}
		else
		{
			printf("���������� ������������");
		}
	}
	if (dist > r1 + r2) 
	{
		printf("���������� ����� �� �������");
	}
};
