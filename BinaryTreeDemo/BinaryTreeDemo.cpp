// BinaryTreeDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <stdlib.h>
#include "BinaryTree.h"


void VisitElement(int data);

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));

	pBiTree pTree;
	//CreateBiTree(&pTree);
	CreateBiTreeAuto(&pTree);
	PreOrderVisitTree(pTree, VisitElement);
	InOrderVisitTree(pTree, VisitElement);
	fflush(stdin);
	getchar();
	
	return 0;
}



//·ÃÎÊº¯Êý
void VisitElement(int data)
{

	printf("%d\n", data);
}

