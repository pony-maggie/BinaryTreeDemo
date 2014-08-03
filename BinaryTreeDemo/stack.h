#ifndef _STACK_H
#define _STACK_H

#define STACK_INIT_SIZE 100 //空间初始分配量
#define STACK_INCREMENT 10 //分配增量(每次空间不够重新分配时的增量)



//void**其为双指针，意味入栈和出栈的将只是对应数据的地址，而不需要对数据本身进行拷贝
typedef struct _ponyStack
{
	char *base;
	char *top;
	int elementSize; //元素所点字节大小
	int stackSize;	//当前已分配的空间(注意不是元素的实际个数)
}ponyStack;


#define RET_OK 0
#define RET_ERROR -1


///////////////////////////////////////////////////////
int InitStack(ponyStack *stack, int elementSize);
int ClearStack(ponyStack *stack);
int DestroyStack(ponyStack *stack);
bool IsEmptyStack(ponyStack stack);
int CountOfStack(ponyStack stack);
int Push(ponyStack *stack, const void *element);
int Pop(ponyStack *stack, void *element);

int GetTop(ponyStack stack, void *element);


#endif