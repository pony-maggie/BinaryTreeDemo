#include "stdafx.h"
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "BinaryTree.h"
#include "stack.h"

int MAX_DEPTH = 3; //树的深度，决定了最大能创建总结点数
int nCurrentNode = 0;


static int GetRandom();

//创建二叉树, 先序顺序
int CreateBiTree(pBiTree *root)
{
	char ch = 0;
	fflush(stdin);
	if ((ch = getchar()) == 'a')//控制树的结构
	{
		*root = NULL;
	}
	else
	{
		*root = (BiTNode *)malloc(sizeof(BiTNode));
		if (!(*root))
		{
			return RET_ERROR;
		}
		(*root)->data = GetRandom();
		CreateBiTree(&(*root)->leftChild);
		CreateBiTree(&(*root)->rightChild);
	}
	return RET_OK;
}

int g_i = 0;
//创建二叉树,自动执行，方便测试
int CreateBiTreeAuto(pBiTree *root)
{
	char szOrder[] = "bbaabaa";
	char ch = 0;
	if (szOrder[g_i++] == 'a')//控制树的结构
	{
		*root = NULL;
	}
	else
	{
		*root = (BiTNode *)malloc(sizeof(BiTNode));
		if (!(*root))
		{
			return RET_ERROR;
		}
		(*root)->data = GetRandom();
		CreateBiTreeAuto(&(*root)->leftChild);
		CreateBiTreeAuto(&(*root)->rightChild);
	}
	return RET_OK;
}


//先序遍历
int PreOrderVisitTree(pBiTree T, VisitType pFuncVisit)
{
	if (T)
	{
		(*pFuncVisit)(T->data);
		if (PreOrderVisitTree(T->leftChild, pFuncVisit) == RET_OK)
		{
			if (PreOrderVisitTree(T->rightChild, pFuncVisit) == RET_OK)
			{
				return RET_OK;
			}
		}
		return RET_ERROR;
	}
	else
	{
		return RET_OK;
	}
}

//中序遍历, 非递归实现
int InOrderVisitTree(pBiTree T, VisitType pFuncVisit)
{
	ponyStack binaryTreeStack;
	InitStack(&binaryTreeStack, 4);
	Push(&binaryTreeStack, &T);
	pBiTree pTempNode;

	while (!IsEmptyStack(binaryTreeStack))
	{
		while((GetTop(binaryTreeStack, &pTempNode) == RET_OK) && (pTempNode != NULL))
		{
			Push(&binaryTreeStack, &(pTempNode->leftChild));
		}
		Pop(&binaryTreeStack, &pTempNode);
		if (!IsEmptyStack(binaryTreeStack))
		{
			Pop(&binaryTreeStack, &pTempNode);
			(*pFuncVisit)(pTempNode->data);
			Push(&binaryTreeStack, &(pTempNode->rightChild));
		}
	}
	return RET_OK;
}




//随机生成1~100之间的数
static int GetRandom()
{
	int nResult = (int)(rand()%100);
	return nResult;

}