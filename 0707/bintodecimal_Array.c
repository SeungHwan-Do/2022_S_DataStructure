#include <stdio.h>
#include <math.h>
#include "ArrayStackADT.h"

int main(void)
{
	char bin;
	int* digit;
	int deci = 0;
	int cnt = 0;
	STACK* stack;

	stack = createStack(10);

	printf("Enter an binary number:		");

	while ((bin = getchar()) != '\n')
	{
		digit = (int*)malloc(sizeof(int));
		*digit = atoi(&bin);
		pushStack(stack, digit);
	}

	while (!emptyStack(stack))
	{
		digit = (int*)popStack(stack);
		int i = *digit;

		deci = deci + pow(2, cnt) * i;
		cnt++;
	}
	printf("The decimal number is: ");
	printf("%d", deci);

	destroyStack(stack);
	return 0;
}
