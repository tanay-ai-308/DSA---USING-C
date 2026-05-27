#include<stdio.h>
#include<malloc.h>

#define MAX 5

struct Node
{
	int iData;
	struct Node *pNext;
};

int Pop(struct Node **);
int IsFull(struct Node *);
int IsEmpty(struct Node *);
void Display(struct Node *);
int CountNodes(struct Node *);
void DeleteALL(struct Node **);
void Push(struct Node **, int);

int main (void)
{
	struct Node *pStack = NULL;

	Push(&pStack , 10);
	Push(&pStack , 20);
	Push(&pStack , 30);

	Display(pStack);

	printf("\npoped data is %d\n",Pop(&pStack));

	Display(pStack);

	if(pStack != NULL)
	{
		DeleteALL(&pStack);
		pStack = NULL;
	}

	return 0;
}
/*

        |======|
        |  30  |
        |======|
        |  20  |
        |======|
        |  10  |
        |======|
        |-NULL-|

poped data is 30


        |======|
        |  20  |
        |======|
        |  10  |
        |======|
        |-NULL-|

*/
void Push(struct Node **ppHead , int iData)
{
	struct Node *pNewNode = NULL;

	if(IsFull(*ppHead))
	{
		printf("\tStack is Full.");
		return ;
	}

	pNewNode = (struct Node *)malloc(sizeof(struct Node));

	if(NULL == pNewNode)
	{
		printf("memory allocation faild.");
		return ;
	}

	pNewNode->iData = iData;

	pNewNode->pNext = *ppHead;
	*ppHead = pNewNode;
}

int Pop(struct Node **ppHead)
{
	struct Node *pTemp = NULL;
	int iDelData;

	if(IsEmpty(*ppHead))
	{
		printf("\t stack is Empty.");
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

int IsFull(struct Node *pHead)
{
	if(CountNodes(pHead) == MAX)
		return 1;
	return 0;
}

int IsEmpty(struct Node *pHead)
{
	if(NULL == pHead)
		return 1;
	return 0;
}

int CountNodes(struct Node *pHead)
{
	int iCount = 0;

	while(pHead!= NULL)
	{
		iCount++;
		pHead = pHead->pNext;
	}

	return iCount;
}

void Display(struct Node *pHead)
{
	printf("\n\n\t|======|");
	while(pHead != NULL)
	{
		printf("\n\t|  %d  |",pHead->iData);
		printf("\n\t|======|");
		pHead = pHead->pNext;
	}
	printf("\n\t|-NULL-|\n");
}

void DeleteALL(struct Node **ppHead)
{
	struct Node *pTemp = NULL;

	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead = pTemp->pNext;
		free(pTemp);
	}
}