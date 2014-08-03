#include "stdafx.h"
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

int InitStack(ponyStack *stack, int elementSize)
{
	stack->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char)*elementSize);
	if (!stack->base)
	{
		return RET_ERROR;
	}

	stack->top = stack->base; //为空
	stack->stackSize = STACK_INIT_SIZE;
	stack->elementSize = elementSize;

	return RET_OK;
}

int ClearStack(ponyStack *stack)
{
	stack->top = stack->base;
	return RET_OK;
}

bool IsEmptyStack(ponyStack stack)
{
	if (stack.top == stack.base)
	{
		return true;
	}
	return false;
}

//返回实际个数
int CountOfStack(ponyStack stack)
{
	int nCount = 0;
	int i = 0;
	while((stack.top-(i*stack.elementSize)) != stack.base)
	{
		i++;
		nCount++;
	}
	return nCount;
}


int GetTop(ponyStack stack, void *element)
{
	if (stack.base == stack.top)
	{
		return RET_ERROR;
	}
	memcpy(element, (stack.top - stack.elementSize), stack.elementSize);
	return RET_OK;
}

int Push(ponyStack *stack, const void *element)
{
	if ((stack->top - stack->base) >= stack->stackSize) //空间已满
	{ 
		stack->base = (char *)realloc(stack->base, (stack->stackSize + STACK_INCREMENT)*sizeof(char)*(stack->elementSize));
		if (!stack->base)
		{
			return RET_ERROR;
		}
		stack->stackSize += STACK_INCREMENT;
	}
	memcpy(stack->top, element, stack->elementSize);
	stack->top += stack->elementSize;
	return RET_OK;
}

int Pop(ponyStack *stack, void *element)
{
	if (stack->base == stack->top)
	{
		return RET_ERROR;
	}
	stack->top -= stack->elementSize;
	memcpy(element, stack->top, stack->elementSize);
	return RET_OK;
}

int DestroyStack(ponyStack *stack)
{
	if (stack->base != NULL)
	{
		free(stack->base);
		stack->base = NULL;
		stack->top = NULL;
		stack->stackSize = 0;
	}
	return RET_OK;
}