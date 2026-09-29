#include<stdio.h>
#include"queue.h"

struct Queue
{
	struct Node *pLONext;
	struct Queue *pNext;
};

void EnQueue(struct Node *pHead , struct Queue **ppQueue)
{
	struct Queue *pTemp = NULL;
	struct Queue *pNewNode = NULL;

	if(NULL == pHead)
		return ;

	pNewNode = (struct Queue*)malloc(sizeof(struct Queue));
	if(NULL == pNewNode)
	{
		printf("\nMemory Allocation Failed.");
		return ;
	}

	pNewNode->pLONext = pHead;
	pNewNode->pNext = NULL;

	if(NULL == *ppQueue)
	{
		*ppQueue = pNewNode;
		return ;
	}

	pTemp = *ppQueue;

	while(pTemp->pNext != NULL)
		pTemp = pTemp->pNext;

	pTemp->pNext = pNewNode;

	return ;
}

int IsEmpty(struct Queue *pFirst)
{
	if(NULL == pFirst)
		return 1;
	return 0;
}

struct Node* DeQueue(struct Queue **ppFirst)
{
	struct Queue *pQTemp = NULL;
	struct Node *pNode = NULL;

	if(NULL == *ppFirst)
		return NULL;

	pQTemp = *ppFirst;
	pNode = pQTemp->pLONext;

	*ppFirst = pQTemp->pNext;

	pQTemp->pNext = NULL;
	pQTemp->pLONext = NULL;

	free(pQTemp);
	
	return pNode;

}/*
struct Node* DeQueue(struct Queue *pFirst)
{
	static struct Queue *pTemp = NULL;

	if(NULL == pTemp)
		pTemp = pFirst;
	
	pFirst = pTemp;

	pTemp = pTemp->pNext;

	return pFirst->pLONext;
}*/

void DeleteQueue(struct Queue **ppFirst)
{	
	struct Queue *pTemp = NULL;

	if(NULL == *ppFirst)
		return;

	while((*ppFirst) != NULL)
	{
		pTemp = *ppFirst;
		*ppFirst = pTemp->pNext;
		free(pTemp);
	}
}