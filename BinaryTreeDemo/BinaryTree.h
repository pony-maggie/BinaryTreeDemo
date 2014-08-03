#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#define RET_OK 0
#define RET_ERROR -1

typedef struct _BiTNode
{
	int data;
	_BiTNode *leftChild;
	_BiTNode *rightChild;
}BiTNode, *pBiTree;

typedef void (*VisitType)(int data);

int CreateBiTree(pBiTree *root);
int CreateBiTreeAuto(pBiTree *root);
int PreOrderVisitTree(pBiTree T, VisitType pFuncVisit);
int InOrderVisitTree(pBiTree T, VisitType pFuncVisit);


#endif