// Copyright 2021 Marina Usova

/*
���������� ������.

����������� ��������� ���������, ���������� � ���������� ����������.

����������� ����� �������� ��� ��� � �����, ��� � ��� ����� ������������ ����. 
�� ��������� ���� ��� � �� ������ ������� � ����� ����. ����� ���������
�������� ������������ �� ����� ������� ����� ���� � �������. 
�������� ��� � ����, � ����� �������� ����������, ������� �� �� �����.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3
#define K 2

/// <summary>
/// ��������� ���������� ����� �� ���������� ��������� min � max.
/// </summary>
/// <param name="max"> ����������� ���������� �������� ��������� </param>
/// <param name="min"> ���������� ���������� �������� ��������� </param>
/// <returns> Value - �������� ��������� </returns>
int genRandNumber(int max, int min) {
    int value = (max - min) * ((float)rand() / RAND_MAX) + min;
    return value;
}

// int* ���������� ������������ ������
/*
 1 2 3 4 5 6

 ��������� ������
 1 2 ...
 2 3...
 3 4..
 4 5..
 5 6..
*/

/// <summary>
/// ��������� ���������� ������� ������ 
/// </summary>
/// <param name="matrix">�������</param>
/// <param name="n"> ����� ����� </param>
/// <param name="m"> ����� �������� </param>
int** setMemory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));
    return matrix;
}

/// <summary>
/// ����� ������� �� �����
/// </summary>
/// <param name="matrix">�������</param>
/// <param name="n"> ����� ����� </param>
/// <param name="m"> ����� �������� </param>
void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


/// <summary>
/// �������� �����������, ������ � ��������� �� ������ ������� ����������
/// ����� ��� �������� � ��������� ���� �������� ��� ���� �������
/// </summary>
/// <param name="matrix">�������</param>
/// <param name="value">����� �� ������� �������</param>
/// <param name="n">������ ������</param>
/// <param name="m">������ �������</param>
/// <returns>���������� ��������� ���������</returns>
int** multMatrixonNumber(int** matrix, int* value, int n, int m) {
    int** res = NULL;                   // nullptr ����� ����� ������������
    res = setMemory(res, N, M);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix[i][j] * (*value);
        }
    }
    (*value) = 3;
    return res;
}

void fillArrayRandValue(int** matrix, int n, int m, int max, int min) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = genRandNumber(max, min);
        }
    }
}

int** createMatrix(int** matrix, int n, int m, int max, int min, char name) {
    matrix = setMemory(matrix, n, m);
    fillArrayRandValue(matrix, n, m, max, min);
    printf("Matrix A %c =\n", name);
    printMatrix(matrix, n, m);
    return matrix;
}


void freeMemory(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

int main() {
  int **matrix_A = NULL, **matrix_B = NULL, **result = NULL;
  int max = 4, min = 0, value = 0;

  //srand(time(0));

  matrix_A = createMatrix(matrix_A, N, M, max, min, 'A');
  matrix_B = createMatrix(matrix_B, N, M, max, min, 'B');
  value = genRandNumber(max, min);  


  // ��������� ������� �� �����
  result = setMemory(result, N, M);
  result = multMatrixonNumber(matrix_A, &value, N, M);
  printf("Matrix A x %d =\n", value);
  printMatrix(result, N, M);


  //������ ������ ������� ����� ������ 
  freeMemory(result, N, M);

  // ���������������� �������

  result = setMemory(result, M, N);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      result[i][j] = matrix_A[j][i];
    }
  }
  printf("Matrix AT =\n");
  printMatrix(result, M, N);

  // �������� ���������� ����� ������
  for (int i = 0; i < M; i++) free(result[i]);
  free(result);

  // ��������� ���� ������
  result = setMemory(result, N, K);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      result[i][j] = 0;
      for (int k = 0; k < M; k++) {
        result[i][j] += matrix_A[i][k] * matrix_B[k][j];
      }
    }
  }
 

  printf("Matrix AxB =\n");
  // ������ ������� �� �����
  printMatrix(result, N, K);

  // �������� ���������� ����� ������
  freeMemory(result, N, M);

  // �������� ���� ������
  // ???

  // ��������� ������� �� �����
  // ???

  // �������� ���� ��������
  // ???

  // ��������� ���� ��������
  // ???

    // �������� ���� ���������� ������
  freeMemory(matrix_A, N, M);
  freeMemory(matrix_B, M, K);

  return 0;
}
