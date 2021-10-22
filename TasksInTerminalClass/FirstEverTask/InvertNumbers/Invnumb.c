#include <stdio.h>
#include <locale.h>


int main() 
{
	int Number, Rem, Count = 0, Invers = 0;
	int isWork = 1;
	while (isWork) {
		printf("Invert Numbers\n");
		printf("For exit enter 0\n");
		int isError = 0;
		do
		{
			if (isError) printf("Wrong input\n");
			printf("Input number: ");
			scanf_s("%d", &Number);

			if (Number == 0) {
				isWork = 0;
				break;
			}
			isError = (Number <= 0);
		} while (isError);

		while (Number > 0) {
			Rem = Number % 10;
			Invers = Invers * 10 + Rem;
			Number = Number / 10;
		}
		printf("Result: %d", Invers);
		return 0;
	}
}
