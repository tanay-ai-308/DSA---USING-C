#include<stdio.h>
#include<malloc.h>
#define MAX 5

struct Node
{
	int iData;
	struct Node *pNext;
};

void Display(struct Node *);
int DeQueqe(struct Node **);
int CountNodes(struct Node *);
int IsQueqeFull(struct Node *);
void DeleteAll(struct Node **);
int IsQueqeEmpty(struct Node *);
void EnQueqe(struct Node ** ,int );

int main (void)
{
	struct Node *pQueqe = NULL;

	EnQueqe(&pQueqe , 10);
	EnQueqe(&pQueqe , 20);
	EnQueqe(&pQueqe , 30);
	EnQueqe(&pQueqe , 40);
	EnQueqe(&pQueqe , 50);

	Display(pQueqe);

	printf("Deleted Data is %d",DeQueqe(&pQueqe));

	Display(pQueqe);

	if(pQueqe != NULL)
	{
		DeleteAll(&pQueqe);
		pQueqe = NULL;
	}

	return 0;
}

void EnQueqe(struct Node **ppHead ,int iNo)
{
	struct Node *pTemp = NULL;
	struct Node *pNewNode = NULL;
	
	if(IsQueqeFull(*ppHead))
	{
		printf("\nQueqe is full.");
		return ;
	}

	pNewNode = (struct Node *)malloc(sizeof(struct Node));

	if(NULL == pNewNode)
	{
		printf("\nMemory allocation Failed.");
		return ;
	}

	pNewNode->iData = iNo;
	pNewNode->pNext = NULL;

	pTemp = *ppHead;

	if(NULL == pTemp)
	{
		*ppHead = pNewNode;
		return ;
	}
	while(pTemp->pNext != NULL)
		pTemp = pTemp->pNext;

	pTemp->pNext = pNewNode;
}

int DeQueqe(struct Node **ppHead)
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