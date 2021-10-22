// Copyright 2021 Marina Usova

/*
Постановка задачи.

Реализована некоторая программа, работающая с матричными операциями.

Программист начал работать над ней и понял, что в ней много дублирования кода. 
Он посмотрел свой код и не увидел проблем в самом коде. Чтобы исправить
проблему дублирования он решил вынести часть кода в функции. 
Помогите ему в этом, а также допишите функционал, который он не успел.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3
#define K 2

/// <summary>
/// Генерация рандомного числа из указанного диапазона min и max.
/// </summary>
/// <param name="max"> Максимально допустимое значение диапазона </param>
/// <param name="min"> Минимально допустимое значение диапазона </param>
/// <returns> Value - Значение диапазона </returns>
int genRandNumber(int max, int min) {
    int value = (max - min) * ((float)rand() / RAND_MAX) + min;
    return value;
}

// int* одномерный динамический массив
/*
 1 2 3 4 5 6

 Двумерный массив
 1 2 ...
 2 3...
 3 4..
 4 5..
 5 6..
*/

/// <summary>
/// Выделение указанного размера памяти 
/// </summary>
/// <param name="matrix">Матрица</param>
/// <param name="n"> Длина строк </param>
/// <param name="m"> Длина столбцов </param>
int** setMemory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));
    return matrix;
}

/// <summary>
/// Вывод матрицы на экран
/// </summary>
/// <param name="matrix">Матрица</param>
/// <param name="n"> Длина строк </param>
/// <param name="m"> Длина столбцов </param>
void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


/// <summary>
/// Работает неправильно, пример с передачей по адресу обычной переменной
/// чтобы она поменяла и сохранила свое значение вне этой функции
/// </summary>
/// <param name="matrix">Матрица</param>
/// <param name="value">Число на которое умножим</param>
/// <param name="n">Размер строки</param>
/// <param name="m">Размер столбца</param>
/// <returns>Возвращает результат умножения</returns>
int** multMatrixonNumber(int** matrix, int* value, int n, int m) {
    int** res = NULL;                   // nullptr также можно использовать
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


  // умножение матрицы на число
  result = setMemory(result, N, M);
  result = multMatrixonNumber(matrix_A, &value, N, M);
  printf("Matrix A x %d =\n", value);
  printMatrix(result, N, M);


  //чистим память массива после работы 
  freeMemory(result, N, M);

  // транспонирование матрицы

  result = setMemory(result, M, N);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      result[i][j] = matrix_A[j][i];
    }
  }
  printf("Matrix AT =\n");
  printMatrix(result, M, N);

  // очищение результата после вывода
  for (int i = 0; i < M; i++) free(result[i]);
  free(result);

  // умножение двух матриц
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
  // печать матрицы на экран
  printMatrix(result, N, K);

  // очищение результата после вывода
  freeMemory(result, N, M);

  // сложение двух матриц
  // ???

  // умножение вектора на число
  // ???

  // сложение двух векторов
  // ???

  // умножение двух векторов
  // ???

    // очищение всей выделенной памяти
  freeMemory(matrix_A, N, M);
  freeMemory(matrix_B, M, K);

  return 0;
}
