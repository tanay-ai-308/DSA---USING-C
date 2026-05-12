#include <stdio.h>
#include <malloc.h>

struct Node
{
    int iData;
    struct Node *pNext;
};
//------------------------------------------------------------------
//       		FUNCTION DECLARATION
//------------------------------------------------------------------


void Display(struct Node *);
int CountNodes(struct Node *);
int DeleteLast(struct Node **);
int DeleteFirst(struct Node **);
void DeleteAll (struct Node **);
void ReverseDisplay(struct Node *);
void InsertLast(struct Node **,int);
void InsertFirst(struct Node **,int);
void PhysicalReverse(struct Node **);
int DeleteAtPosition(struct Node **,int);
int SearchAllOccurrences(struct Node *,int);
int SearchLastOccurrence(struct Node *,int);
int SearchFirstOccurrence(struct Node *,int);
void InsertAtPosition(struct Node **,int,int);
void ConcatLists(struct Node **,struct Node **);
void ConCatAtPosition(struct Node **,struct Node **,int);

//===================================================================

int main (void)								//Expected output
{
    int iData;
    struct Node *pFirst = NULL;
    struct Node *pSecond = NULL;
    
    Display(pFirst); 							// list is empty

    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,10);

    Display(pFirst); 							// 10 20 30

    InsertLast(&pFirst,40);
    InsertLast(&pFirst,50);
    InsertLast(&pFirst,60);

    Display(pFirst); 							// 10 20 30 40 50 60

    InsertAtPosition(&pFirst,20, 4);

    Display(pFirst);							// 10 20 30 20 40 50 60

    iData = DeleteFirst(&pFirst);
    if(iData != -1)
        printf("Deleted data is %d\n", iData); 				// 10

    Display(pFirst); 							// 20 30 20 40 50 60

    iData = DeleteLast(&pFirst);
    if(iData != -1)
        printf("Deleted data is %d\n", iData); 				// 60

    Display(pFirst); 							// 20 30 20 40 50

    iData = DeleteAtPosition(&pFirst,4);
    if(iData != -1)
        printf("Deleted data is %d\n", iData); 				// 40

    Display(pFirst); 							// 20 30 20 50

    iData = SearchFirstOccurrence(pFirst,20);
    if(iData != 0)
        printf("\nFirst %d found at %d position\n", 20, iData); 	// 1

    iData = SearchLastOccurrence(pFirst,20);
    if(iData != 0)
        printf("\nLast %d found at %d position\n", 20, iData); 		// 3

    iData = SearchAllOccurrence(pFirst,20);
    printf("\n%d found %d times\n", 20, iData); 			// 2

    iData = CountNodes(pFirst);
    printf("\nTotal node count is %d\n", iData); 			// 4

    Display(pFirst); 							// 20 30 20 50

    PhysicalReverse(&pFirst);
    Display(pFirst); 							// 50 20 30 20

    PhysicalReverse(&pFirst);
    Display(pFirst); 							// 20 30 20 50

    ReverseDisplay(pFirst); 						// 50 20 30 20
    Display(pFirst); 							// 20 30 20 50

    InsertLast(&pSecond,100);
    InsertLast(&pSecond,200);
    
    Display(pSecond); 							// 100 200

    ConcatLists(&pFirst,&pSecond);

    Display(pFirst);							// 20 30 20 50 100 200
    Display(pSecond); 							// list is empty

    InsertLast(&pSecond,400);
    InsertLast(&pSecond,500);

    Display(pFirst); 							// 20 30 20 50 100 200
    Display(pSecond); 							// 400 500

    ConCatAtPosition(&pFirst,&pSecond,3);
    Display(pSecond); 							// 20 30 400 500 20 50 100 200
    Display(pSecond); 							// list is empty

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    if(pSecond != NULL)
    {
        DeleteAll(&pSecond);
        pSecond = NULL;
    }

    Display(pFirst); 							// list is empty
    Display(pSecond); 							// list is empty

    return 0;
}

//==================================================================
/*
OUTPUT :-

Current linked list is :-
        |NULL|

Current linked list is :-
        |10|-->|20|-->|30|-->|NULL|

Current linked list is :-
        |10|-->|20|-->|30|-->|40|-->|50|-->|60|-->|NULL|

Current linked list is :-
        |10|-->|20|-->|30|-->|20|-->|40|-->|50|-->|60|-->|NULL|
Deleted data is 10

Current linked list is :-
        |20|-->|30|-->|20|-->|40|-->|50|-->|60|-->|NULL|
Deleted data is 60

Current linked list is :-
        |20|-->|30|-->|20|-->|40|-->|50|-->|NULL|
Deleted data is 40

Current linked list is :-
        |20|-->|30|-->|20|-->|50|-->|NULL|

First 20 found at 1 position

Last 20 found at 3 position

20 found 2 times

Total node count is 4

Current linked list is :-
        |20|-->|30|-->|20|-->|50|-->|NULL|

Current linked list is :-
        |50|-->|20|-->|30|-->|20|-->|NULL|

Current linked list is :-
        |20|-->|30|-->|20|-->|50|-->|NULL|

Current linked list is :-
        |50|-->|20|-->|30|-->|20|-->|NULL|

Current linked list is :-
        |20|-->|30|-->|20|-->|50|-->|NULL|

Current linked list is :-
        |100|-->|200|-->|NULL|

Current linked list is :-
        |20|-->|30|-->|20|-->|50|-->|100|-->|200|-->|NULL|

Current linked list is :-
        |NULL|

Current linked list is :-
        |20|-->|30|-->|20|-->|50|-->|100|-->|200|-->|NULL|

Current linked list is :-
        |400|-->|500|-->|NULL|

Current linked list is :-
        |NULL|

Current linked list is :-
        |NULL|

Current linked list is :-
        |NULL|

Current linked list is :-
        |NULL|

====================================================================
*/

//------------------------------------------------------------------
//       		FUNCTION DEFINATION
//------------------------------------------------------------------

void InsertFirst(struct Node **ppHead,int iNo)
{
	struct Node *pNewNode = NULL;

	pNewNode = (struct Node *)malloc(sizeof(struct Node));

	if (NULL == pNewNode)
	{
		printf("\nMemory Allocation Failed.");
		return;
	}

	pNewNode->iData = iNo;

	pNewNode->pNext = *ppHead;
	*ppHead = pNewNode;
}

void InsertLast(struct Node **ppHead,int iNo)
{
	struct Node *pNewNode = NULL;
	struct Node *pTemp = NULL;

	pNewNode = (struct Node *)malloc(sizeof(struct Node));

	if (NULL == pNewNode)
	{
		printf("\nMemory Allocation Failed.");
		return;
	}

	pNewNode->pNext = NULL;
	pNewNode->iData = iNo;

	if(NULL == *ppHead)
	{
		*ppHead = pNewNode;
		return ;
	}

	pTemp = *ppHead;
	while(pTemp->pNext != NULL)
		pTemp = pTemp->pNext;

	pTemp->pNext = pNewNode;
}

void InsertAtPosition(struct Node **ppHead ,int iNo ,int iPos)
{
	int iCount;
	struct Node *pTemp = NULL;
	struct Node *pNewNode = NULL;

	iCount = CountNodes(*ppHead);

	if(iPos <= 0 || iPos > iCount+1)
	{
		printf("\nInvalid Position.");
		return;
	}

	if(iPos == 1)
	{
		InsertFirst(ppHead,iNo);
		return;
	}
	if(iPos == iCount+1)
	{
		InsertLast(ppHead,iNo);
		return;
	}

	pNewNode = (struct Node*)malloc(sizeof(struct Node));

	if(NULL == pNewNode)
		printf("\nMemory Allocation Failed.");

	pNewNode->iData = iNo;

	pTemp = *ppHead;
	iCount = 1;

	while(iCount < iPos-1)
	{
		iCount++;
		pTemp = pTemp->pNext;
	}

	pNewNode->pNext = pTemp->pNext;
	pTemp->pNext = pNewNode;
}

int DeleteFirst(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp = NULL;

	if(NULL == *ppHead)
		return -1;
	
	pTemp = *ppHead;
	*ppHead = pTemp->pNext;

	iDelData = pTemp->iData;
	pTemp->pNext = NULL;

	free(pTemp);
	pTemp = NULL;

	return iDelData;
}

int DeleteLast(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp = NULL;

	if(NULL == *ppHead)
		return -1;
	
	pTemp = *ppHead;
	
	if(NULL == pTemp->pNext)
	{
		iDelData = pTemp->iData;
		free(pTemp);
	}
	else
	{
		while(pTemp->pNext->pNext != NULL)
			pTemp = pTemp->pNext;

		iDelData = pTemp->pNext->iData;
		free(pTemp->pNext);
		pTemp->pNext = NULL;
	}

	return iDelData;
}

int DeleteAtPosition(struct Node **ppHead ,int iPos)
{
	int iCount;
	struct Node *pTemp1 = NULL;
	struct Node *pTemp2 = NULL;

	iCount = CountNodes(*ppHead);

	if(iPos <= 0 || iPos > iCount)
	{
		printf("\nInvalide position.");
		return -1;
	}

	if(iPos == 1)
		return DeleteFirst(ppHead);

	if(iPos == iCount)
		return DeleteLast(ppHead);

	pTemp1 = *ppHead;
	iCount = 1;

	while(iCount < iPos-1)
	{
		iCount++;
		pTemp1 = pTemp1->pNext;
	}

	pTemp2 = pTemp1->pNext;

	pTemp1->pNext = pTemp2->pNext;
	iCount = pTemp2->iData;
	pTemp2->pNext = NULL;

	free(pTemp2);
	return iCount;
}

int SearchFirstOccurrence(struct Node *pHead , int iKey)
{
	int iPosCount = 0;

	while(pHead != NULL)
	{
		iPosCount++;
		if(pHead->iData == iKey)
			return iPosCount;

		pHead = pHead->pNext;
	}
	return -1;
}

int SearchLastOccurrence(struct Node *pHead , int iKey)
{
	int iCount = 0;
	int iPosCount = 0;

	while(pHead != NULL)
	{
		iCount++;
		if(pHead->iData == iKey)
			iPosCount = iCount;

		pHead = pHead->pNext;
	}
	return iPosCount;
}

int SearchAllOccurrence(struct Node *pHead , int iKey)
{
	int iCount = 0;

	while(pHead != NULL)
	{
		if(pHead->iData == iKey)
			iCount++;

		pHead = pHead->pNext;
	}
	return iCount;
}

void ConcatLists(struct Node **ppHead1 ,struct Node **ppHead2)
{
	struct Node *pTemp = NULL;

	if(NULL == *ppHead2)
		return;

	if(NULL == *ppHead1)
	{
		*ppHead1 = *ppHead2;
		*ppHead2 = NULL;
		return;
	}

	pTemp = *ppHead1;

	while(pTemp->pNext != NULL)
		pTemp = pTemp->pNext;
	pTemp->pNext = *ppHead2;
	*ppHead2 = NULL;
}

void ConCatAtPosition(struct Node **ppHead1 ,struct Node **ppHead2 ,int iPos)
{
	int iCount;
	struct Node *pTemp1 = NULL;
	struct Node *pTemp2 = NULL;

	iCount = CountNodes(*ppHead1);

	if(iPos <= 0 || iPos > iCount+1)
	{
		printf("\nInvalid Postion.");
		return ;
	}

	if(NULL == *ppHead2)
		return ;

	if(1 == iPos)
	{
		ConcatLists(ppHead2 , ppHead1);
		*ppHead1 = *ppHead2;
		*ppHead2 = NULL;
		return;
	}

	if(iPos == iCount+1)
	{
		ConcatLists(ppHead1 , ppHead2);
		return;
	}

	pTemp1 = *ppHead1;
	iCount = 1;

	while(iCount < iPos-1)
	{
		iCount++;
		pTemp1 = pTemp1->pNext;
	}

	pTemp2 = *ppHead2;
	while(pTemp2->pNext != NULL)
		pTemp2 = pTemp2->pNext;

	pTemp2->pNext = pTemp1->pNext;
	pTemp1->pNext = *ppHead2;
	*ppHead2 = NULL;
}

void PhysicalReverse(struct Node **ppHead)
{
	struct Node *pNext = NULL;
	struct Node *pPrev = NULL;
	struct Node *pCurrent = *ppHead;

	while(pCurrent != NULL)
	{
		pNext = pCurrent->pNext;
		pCurrent->pNext = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;
	}

	*ppHead = pPrev;
}

void ReverseDisplay(struct Node *pHead)
{
	if (pHead == NULL)
	{
		printf("List is Empty");
		return;
	}
	PhysicalReverse(&pHead);
	Display(pHead);
	PhysicalReverse(&pHead);
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

void Display(struct Node *pHead)
{
	printf("\nCurrent linked list is :- \n\t");
	while(pHead != NULL)
	{
		printf("|%d|-->",pHead->iData);
		pHead = pHead->pNext;
	}
	printf("|NULL|\n");

}

void DeleteAll(struct Node **ppHead)
{
	struct Node *pTemp = NULL;

	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead = pTemp->pNext;
		pTemp->pNext  = NULL;
		free(pTemp);
	}
}