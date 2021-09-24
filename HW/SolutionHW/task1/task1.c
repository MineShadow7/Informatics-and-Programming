#include <stdio.h>
#include <locale.h>




int main()
{
	setlocale(LC_ALL, "Russian");

	//��������� ��� ����������: ���, ���, ������ (� ��/��^3)
	double dvpdens = 0.7, dspdens = 0.55, wooddens = 0.85;

	//����� ������ �������� ����� ������������ ��-��� ������ ������ � ��������� �� ����������� ��������
	int bdoorh, bdoorw;
	float bdoort = 0.5;
	double bdoorV, bdoorM;

	printf("������� ������ ������ ������ ����� (� �������� �� 180 �� 220 ��):\n");
	scanf_s("%d", &bdoorh);

	printf("������� ������ ������ ������ ����� (� �������� �� 80 �� 120 ��):\n");
	scanf_s("%d", &bdoorw);

	if ((180 <= bdoorh <= 220) && (80 <= bdoorw <= 120))
	{
		printf("��� ������ ������������� �������. ������������� ����� ������ ������ �����...\n");
	}
	else
	{
		printf("������� ������ �����, �������� �������.");
	}



	//������ ���������� ����� � ����� ������ ������
	bdoorV = bdoorh * bdoorw * bdoort;
	printf("����� ������ ������ ����� ����� ����� = %.1lf ���.��\n", bdoorV);
	bdoorM = (bdoorV * dvpdens);												//������������ ����� � �������
	bdoorM = bdoorM * 0.001;												//��������� ����� � ���������� ��� �������� ���������
	printf("����� ������ ������ ����� ����� = %.3lf ��\n", bdoorM);


	//������ ������ ��� ������� � ����������� � ��������� ����� �������
	int swalld;
	float swallw = 1.5;
	double swallV, swallM;
	//������ � ������ ������ ������� ������������� ������ ������ ������, ��� ��� ��� �� ����� ������������ � ������� ����� ���������� ��� ���.

	printf("������� ������� ������� (�� 50 �� 90 ��):\n");
	scanf_s("%d", &swalld);

	if (50 <= swalld <= 90)
	{
		printf("������ ������������� �������. ���������� � ��������...\n");
	}
	else
	{
		printf("��������� ������������ ������ �� ����������� �������.");
	}

	//���������� �������� �������. �� ������� �� 2, ��� ��� ����� �������� ����� ����� 2-�.
	swallV = bdoorh * swalld * swallw;
	swallM = (swallV * dspdens) * 2;

	printf("����� ����� �������� ����� ����� ����� = %.1lf ���.��\n", swallV);
	printf("����� ���� ������� ����� ����� = %.3lf ��\n", swallM);


	//���������� ��� ������� � ������ ������. ������ �������� � ��, ������� ���.
	int lidw, lidd;
	float lidt = 1.5;
	double lidV, lidM;

	printf("������� ������ ������ �����:\n");
	scanf_s("%d", &lidw);

	printf("������� ������� ������ �����:\n");
	scanf_s("%d", &lidd);

	//������ �������
	lidV = lidw * lidd * lidt;
	lidM = (lidV * dspdens) * 2;
	printf("����� ������ ����� ����� = %.1lf ���.��\n", lidV);
	printf("����� ������ ����� ����� = %.3lf ��\n", lidM);


	//���������� ��� ��������� ������. �� 2, ������� ���. 
	int doorh, doorw, doort = 1;
	double doorV, doorM;
	
	printf("������� ������ �����:\n");
	scanf_s("%d", &doorh);

	printf("������� ������ �����:\n");
	scanf_s("%d", &doorw);

	//������� ������ � ����� ������ ����� 
	doorV = doorh * doorw * doort;
	doorM = (doorV * wooddens) * 2;
	printf("����� ����� ����� ����� = %.1lf ���.��\n", doorV);
	printf("����� ���� ������ ����� = %.3lf ��\n");


	//���������� ���-�� ����� � �����. ������ ����� �������� ��� ����� 40 ��. 
	int shelfamount;
	double shelfV, shelfM;

	//������� ���-�� ����� ������� ����� ��������.
	shelfamount = bdoorh / 40;
	//����� � ������ ����� ����� ����� � ������ ������. ��� ������ ������� ����� ����������
	printf("� ���� ��������� %d �����. ������� ����� %d � ������, 1 �� � ������, %d � �����\n", shelfamount, lidw, lidd);

	shelfV = lidw * lidd;
	shelfM = (shelfV * dspdens) * shelfamount;

	printf("����� ����� ����� = %.1lf ���.��\n", shelfV);
	printf("����� ����� ����� = %.3lf ��\n", shelfM);

	//�������� ������� ��� �����, ����� �������� ����� �����.

	double ShkafM;
	ShkafM = bdoorM + swallM + lidM + doorM + shelfM;

	printf("����� ����� ����� ����� ����� = %.3lf ��", ShkafM);
	return 0;
};