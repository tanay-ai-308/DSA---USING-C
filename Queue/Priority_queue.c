#include<stdio.h>
#define MAX 5

void Display(struct Node *);
int DeQueqe(struct Node **);
int CountNodes(struct Node *);
int IsQueqeFull(struct Node *);
void DeleteAll(struct Node **);
int IsQueqeEmpty(struct Node *);
void EnQueue(struct Node ** , int , int );
void InsertFirst(struct Node **, int , int );

struct Node
{
	int iData;
	int iPriority;
	struct Node *pNext;
};

int main (void)
{
	struct Node *pQueue = NULL;

	EnQueue(&pQueue , 10 , 4);
	EnQueue(&pQueue , 20 , 2);
	EnQueue(&pQueue , 30 , 5);
	EnQueue(&pQueue , 40 , 3);
	EnQueue(&pQueue , 50 , 1);

	Display(pQueue);

	printf("\nDeleted data is - %d",DeQueue(&pQueue));

	Display(pQueue);

	if(pQueue != NULL)
	{
		DeleteAll(&pQueue);
		pQueue = NULL;
	}

	return 0;
}

void EnQueue(struct Node **ppHead , int iNo , int iPri)
{
	struct Node *pTemp = NULL;
	struct Node *pNewNode = NULL;

	if(*ppHead == NULL || (*ppHead)->iPriority < iPri)
	{
		InsertFirst(ppHead , iNo , iPri);
		return ;
	}

	pNewNode = (struct Node *)malloc(sizeof(struct Node));
	
	pNewNode->iData = iNo;
	pNewNode->iPriority = iPri;
	
	pTemp = *ppHead;

	while(pTemp->pNext != NULL)
	{
		if(iPri > pTemp->pNext->iPriority)
			break ;
		pTemp = pTemp->pNext;
	}

	pNewNode->pNext = pTemp->pNext;
	pTemp->pNext = pNewNode;
}

void InsertFirst(struct Node **ppHead , int iNo , int iPri)
{
	struct Node *pNewNode = NULL;

	pNewNode = (struct Node *)malloc(sizeof(struct Node));

	if (NULL == pNewNode)
	{
		printf("\nMemory Allocation Failed.");
		return;
	}
	pNewNode->iPriority = iPri;
	pNewNode->iData = iNo;

	pNewNode->pNext = *ppHead;
	*ppHead = pNewNode;
}

int DeQueue(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp = NULL;

	if(IsQueqeEmpty(*ppHead))
	{
		printf("\nQueqe is Empty.");
		return -1;
	}

	pTemp = *ppHead;
	*ppHead = pTemp->pNext;

	iDelData = pTemp->iData;
	pTemp->pNext = NULL;

	free(pTemp);
	pTemp = NULL;

	return iDelData;
}

int IsQueqeFull(struct Node *pHead)
{
	if(CountNodes(pHead) == MAX)
		return 1;
	return 0;
}

int IsQueqeEmpty(struct Node *pHead)
{
	if(NULL == pHead)
		return 1;
	return 0;
}

int CountNodes(struct Node *pHead)
{
	int iCount = 0;

	while(pHead != NULL)
	{
		iCount++;
		pHead = pHead->pNext;
	}

	return iCount;
}

void DeleteAll(struct Node **ppHead)
{
	struct Node *pTemp = NULL;

	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead = pTemp->pNext;
		free(pTemp);
	}
}

void Display(struct Node *pHead)
{
	printf("\n\n\t=======================================\n");
	while(pHead != NULL)
	{
		printf("\t  %d  |",pHead->iData);
		pHead = pHead->pNext;
	}
	printf("\n\t=======================================\n");
}