#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	void** stackAry;
	int count;
	int stackMax;
	int top;
} STACK;

STACK* createStack(int maxSize)
{
	STACK* stack;

	stack = (STACK*)malloc(sizeof(STACK));
	if (!stack)
		return NULL;

	stack->count = 0;
	stack->top = -1;
	stack->stackMax = maxSize;
	stack->stackAry = (void**)calloc(stack->stackMax, sizeof(void*));
	if (!stack->stackAry)
	{
		free(stack);
		return NULL;
	}
	return stack;
}

bool pushStack(STACK* stack, void* dataInPtr)
{
	if (stack->count == stack->stackMax)
		return false;

	(stack->count)++;
	(stack->top)++;
	stack->stackAry[stack->top] = dataInPtr;

	return true;
}

void* popStack(STACK* stack)
{
	void* dataPtrOut;

	if (stack->count == 0)
		dataPtrOut = NULL;
	else
	{
		dataPtrOut = stack->stackAry[stack->top];
		(stack->count)--;
		(stack->top)--;
	}

	return dataPtrOut;
}

void* stackTop(STACK* stack)
{
	if (stack->count == 0)
		return NULL;
	else
		return stack->stackAry[stack->top];
}

bool emptyStack(STACK* stack)
{
	return (stack->count == 0);
}

bool fullStack(STACK* stack)
{
	return (stack->top == stack->stackMax);
}

int stackCount(STACK* stack)
{
	return stack->count;
}

STACK* destroyStack(STACK* stack)
{
	if (stack)
	{
		for (int i = 0; i < stack->count; i++)
			free(stack->stackAry[i]);

		free(stack->stackAry);

		free(stack);
	}
	return NULL;
}
