// Copyright 2021 Marina Usova

/*
Ïîñòàíîâêà çàäà÷è.
Äàíû íåêîòîðûå ïîïóëÿðíûå çàäà÷è, ïðåäñòàâèòü èõ ïðîñòîå ðåøåíèå
(åñëè òàêîå åñòü) è èõ ðåøåíèå ñ ðåêóðñèåé. Åñëè ïðîñòîãî ðåøåíèÿ íåò,
âûâåñòè èíôîðìàöèþ îá îòñóòñâèè òàêîãî.
ÐÅÊÓÐÑÈß - îïðåäåëåíèå ÷àñòè ôóíêöèè (ìåòîäà) ÷åðåç ñàìó ñåáÿ.
Ìîæåò âûçûâàòü ÷åáÿ íåïîñðåäñòâåííî (â ñâî¸ì òåëå) èëè êîñâåííî (÷åðåç äðóãóþ ôóíêöèþ).
Â ïåðâóþ î÷åðåäü íàäî ïîíèìàòü ÷òî ðåêóðñèÿ ýòî ñâîåãî ðîäà ïåðåáîð (öèêë).
Âîîáùå ãîâîðÿ, âñ¸ òî, ÷òî ðåøàåòñÿ èòåðàòèâíî ìîæíî ðåøèòü ðåêóðñèâíî,
òî åñòü ñ èñïîëüçîâàíèåì ðåêóðñèâíîé ôóíêöèè.
ÏÐÀÂÈËÀ ÐÅÊÓÐÑÈÈ.
1. Ó ðåêóðñèè äîëæíî áûòü ïðàâèëî (óñëîâèå) îñòàíîâêè (áàçîâûé ñëó÷àé).
2. Ïðè êàæäîì øàãå âûçûâàåòñÿ ðåêóðñèâíàÿ ôóíêöèÿ. È óñëîâèå èç ïóíêòà 1. ÿâëÿåòñÿ òåì
ñëó÷àåì, ê êîòîðîìó ðåêóðñèÿ èäåò.
Çàäà÷êè.
1. Äàíî íàòóðàëüíîå ÷èñëî N, íàïèñàòü ôóíêöèþ, âûâîäÿùóþ íà ýêðàí âñå ÷èñëà îò 1 äî N.
2. Íàïèñàòü ôóíêöèþ, âû÷èñëÿþùóþ ôóíêöèþ Àêêåðìàíà ñ ïàðàìåòðàìè m è n.
A(m, n) = {
  n + 1,                  m = 0
  A(m - 1, 1),            m > 0, n = 0
  A(m - 1, A(m, n - 1)),  m > 0, n > 0
}
Ïðèìåðû: À(3, 4) = 125, À(3, 2) = 29
3. Äàíî íàòóðàëüíîå ÷èñëî, íàïèñàòü ôóíêöèþ, âû÷èñëÿþùóþ ôàêòîðèàë ýòîãî ÷èñëà.
4. Äàíî íàòóðàëüíîå ÷èñëî, íàïèñàòü ôóíêöèþ, âû÷èñëÿþùóþ ñóììó öèôð ÷èñëà.
5. Äàíî íàòóðàëüíîå ÷èñëî, íàïèñàòü ôóíêöèþ, ðàçâîðàâ÷èâàþùóþ äàííîå ÷èñëî.
6. Äàíî íàòóðàëüíîå ÷èñëî, íàïèñàòü ôóíêöèþ, ïðîâåðÿþùóþ ÿâëÿåòñÿ ëè ÷èñëî ïðîñòûì.
7. Äàíî ñëîâî, îïðåäåëèòü ÿâëÿåòñÿ ëè îíî ïàëèíäðîìîì.
8. Äàí ìàññèâ, íàéòè ìàêñèìàëüíûé ýëåìåíò ìàññèâà (åãî çíà÷åíèå).
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

/* ÏÐÈÌÅÐ: Âûâîä íà ýêðàí ïîñëåäîâàòåëüíîñòè */

void showSequenceBaseMethod(int N) {
    for (int i = 1; i <= N; ++i) {
        printf("%d ", i);
    }
}

void showSequenceRecursionMethod(int N) {
    if (N == 0) return;                         // óñëîâèå âûõîäà
    showSequenceRecursionMethod(N - 1);         // øàã ðåêóðñèè
    printf("%d ", N);
}

/* Âû÷èñëåíèå ôóíêöèè Àêêåðìàíà */

// íåò î÷åâèäíîãî ñïîñîáà ðåàëèçîâàòü âû÷èñëåíèå äàííîé ôóíêöèè,
// ìîæíî ïîïðîáîâàòü ðåàëèçîâàòü ñàìîñòîÿòåëüíî äîïîëíèòåëüíî
int getAkermanFuncValueBaseMethod(int m, int n) {}

/*
A(m, n) = {
  n + 1,                  m = 0
  A(m - 1, 1),            m > 0, n = 0
  A(m - 1, A(m, n - 1)),  m > 0, n > 0
}
Ïðèìåðû: À(3, 4) = 125, À(3, 2) = 29
*/
int getAkermanFuncValueRecursionMethod(int m, int n) {
    if (m == 0) return n + 1;
    else if (m > 0 && n == 0) return getAkermanFuncValueRecursionMethod(m - 1, 1);
    else return getAkermanFuncValueRecursionMethod(m - 1, getAkermanFuncValueRecursionMethod(m, n - 1));
}

/* Âû÷èñëåíèå ôàêòîðèàëà ÷èñëà */

// 7! = 1 * 2 * 3 * 4 * ... * 7

int getFactorialBaseMethod(int N) {
    int fact = 1;
    for (int i = 2; i <= N; ++i) {
        fact *= i;
    }
    return fact;
}

int getFactorialRecursionMethod(int N) {
    if (N == 1) return 1;
    return N * getFactorialRecursionMethod(N - 1);
}

/* Âû÷èñëåíèå ñóììû öèôð ÷èñëà */

int getSumOfNumbersBaseMethod(int num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int getSumOfNumbersRecursionMethod(int num) {
    if (num == 0) return 0;
    return num % 10 + getSumOfNumbersRecursionMethod(num / 10);
}

/* Ôóíêöèÿ, ðàçâîðà÷èâàþùàÿ ÷èñëî */

int inverseNumberBaseMethod(int num) {
    int reverse = 0, rem;
    while (num) {
        rem = num % 10;
        reverse = reverse * 10 + rem;
        num = num / 10;
    }
    return reverse;
}

int inverseNumberRecursionMethod(int number, int* result) {
    
    if (number == 0) return 0;
    (*result) = (*result) * 10 + number % 10;
    return inverseNumberRecursionMethod(number / 10, result);
}


/* Ôóíêöèÿ, ïðîâåðÿþùàÿ ÷èñëî íà ïðîñòîòó */

int isPrimeNumberBaseMethod(int num) {}
int isPrimeNumberRecursionMethod(int num) {}

/* Ôóíêöèÿ, ïðîâåðÿþùàÿ ÿâëÿåòñÿ ëè ñëîâî ïàëèíäðîìîì */

int isPalindromBaseMethod(char* word, int start, int end) {

}

int isPalindromRecursionMethod(char* word, int start, int end) { // g h t y 3 4 t 2 5 h 1 6 g 0 7
    if (end == 0) return -1;
    if (end - start <= 1) return 1;
    if (word[start] == word[end - 1]) {
        isPalindromRecursionMethod(word, start + 1, end - 1);
    }
    else {
        return 0;
    }

}

/* Ôóíêöèÿ, íàõîäÿùàÿ ìàêñèìàëüíûé ýëåìåíò ìàññèâà */

float findMaximumBaseMethod(float* mass, int size) {
    float cur_max = -1000000;                          // MAX_FLOAT???
    for (int i = 0; i < size; i++) {
        if (mass[i] > cur_max)
            cur_max = mass[i];
    }
    return cur_max;
}

float findMaximumRecursionMethod(float* mass, int size) {  // 1 3 5 3 7 6 2
    if (size == 0) return -1000000;
    float cur_max = findMaximumRecursionMethod(mass, size - 1);
    return max(cur_max, mass[size - 1]);
    /*
    if (mass[size - 1] > cur_max)
        return mass[size - 1];
    else
        return cur_max;
    */
}

int main() {
    // áëîê ïåðåìåííûõ
    int N = 0, m = 0, n = 0, num = 0;
    char word[20];
    int inv = 0;
    int size = 0;
    float* mass = NULL;
    int choosen = 0, type = 0;
    int temp = 0;
    float temp_f = 0;
    float ans = 0;

    while (1) {
        printf("Choose task number:\n1. Show all numbers from 1 to N;");
        printf("\n2. Calculates the Ackermann function A(m, n); ");
        printf("\n3. Find factorial of the number;\n4. Calculates sum of the digits of the number; \n5. Invers the number; \n6. Check if the number is prime;");
        printf("\n7. Check if the word is palindrom; ");
        printf("\n8. Find the maximum element of the array;");
        printf("\n0. Exit.");
        printf("\n> ");
        scanf_s("%d", &choosen);

        if (choosen == 0) break;

        // èíèöèàëèçàöèÿ
        switch (choosen) {
        case 1:
            printf("Input N: ");
            scanf_s("%d", &N);
            break;
        case 2:
            printf("Input m and n: ");
            scanf_s("%d %d", &m, &n);
            break;
        case 3: case 4: case 5: case 6:
            printf("Input number: ");
            scanf_s("%d", &num);
            break;
        case 7:
            getchar();
            printf("Input word: ");
            gets(word);
            for (size = 0; word[size] != '\0'; size++);
            break;
        case 8:
            printf("Input size of array: ");
            scanf_s("%d", &size);
            srand(time(0));
            printf("Your random array: ");
            mass = (float*)malloc(size * sizeof(float));
            for (int i = 0; i < size; ++i) {
                mass[i] = rand() % 10;
                printf("%.2f ", mass[i]);
            }
            printf("\n");
            break;
        default:
            printf("Haven't such task!");
        }

        printf("Input type of method: 1. base; 2. recursion.; 3. both\n> ");
        scanf_s("%d", &type);

        if (type == 1)
            printf("Base methods start...\n");
        else if (type == 2)
            printf("Recursion methods start...\n");

        // ðåøåíèå çàäà÷
        switch (choosen) {
        case 1:
            printf("Suquence:\n");
            if (type == 1 || type == 3) {
                showSequenceBaseMethod(N);
                printf("\n");
            }
            if (type == 2 || type == 3) {
                showSequenceRecursionMethod(N);
                printf("\n");
            }
            break;
        case 2:
            if (type == 1 || type == 3)
                printf("Task have only recursion method\n");
            if (type == 2 || type == 3)
                printf("A(%d, %d) = %d", m, n, getAkermanFuncValueRecursionMethod(m, n));
            printf("\n");
            break;
        case 3:
            if (type == 1 || type == 3) {
                printf("%d! = %d", num, getFactorialBaseMethod(num));
                printf("\n");
            }
            if (type == 2 || type == 3) {
                printf("%d! = %d", num, getFactorialRecursionMethod(num));
                printf("\n");
            }
            break;
        case 4:
            if (type == 1 || type == 3) {
                printf("Sum = %d", getSumOfNumbersBaseMethod(num));
                printf("\n");
            }
            if (type == 2 || type == 3) {
                printf("Sum = %d", getSumOfNumbersRecursionMethod(num));
                printf("\n");
            }
            break;
        case 5:
            if (type == 1 || type == 3)
                printf("Inverse base method = %d", inverseNumberBaseMethod(num));
            if (type == 2 || type == 3) {
                inverseNumberRecursionMethod(num, &inv);
                printf("Inverse of number: %d", inv);
            }
            printf("\n");
            break;
        case 6:
            break;
        case 7:
            if (type == 1 || type == 3)
                printf("Task have only recursion method\n");
            if (type == 2 || type == 3) {
                int flag = isPalindromRecursionMethod(word, 0, size);
                if (flag == -1) {
                    printf("Empty input!\n");
                }
                else if (flag) {
                    printf("%s - IS palindrom\n", word);
                }
                else if (!flag) {
                    printf("%s - IS NOT palindrom\n", word);
                }
            }
            break;
        case 8:
            // ans = findMaximumBaseMethod(mass, size);
            printf("Max = %.2f\n", findMaximumBaseMethod(mass, size));
            ans = findMaximumRecursionMethod(mass, size);
            printf("Max = %.2f\n", ans);
            break;
        default:
            printf("Haven't such task!");
        }
        printf("\n");
        system("pause");
    }

    return 0;
}