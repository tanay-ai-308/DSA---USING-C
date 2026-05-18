#include <stdio.h>
#include <malloc.h>

struct Node
{
    struct Node *pPrev;
    int iData;
    struct Node *pNext;
};

//=========================================================
//              FUNCTION DECLARATION
//=========================================================

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
void ConCatLists(struct Node **,struct Node **);
void ConCatAtPosition(struct Node **,struct Node **,int);

//==========================================================

int main(void)                                          //  Expected output :-
{
    int iData;
    struct Node *pFirst = NULL;
    struct Node *pSecond = NULL;
    
    Display(pFirst); 										// list is empty

    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,10);

    Display(pFirst); 										// 10 20 30

    InsertLast(&pFirst,40);
    InsertLast(&pFirst,50);
    InsertLast(&pFirst,60);

    Display(pFirst); 										// 10 20 30 40 50 60

    InsertAtPosition(&pFirst,20, 4);

    Display(pFirst);										// 10 20 30 20 40 50 60

    iData = DeleteFirst(&pFirst);
    if(iData != -1)
        printf("Deleted data is %d\n", iData); 				// 10

    Display(pFirst); 										// 20 30 20 40 50 60

    iData = DeleteLast(&pFirst);
    if(iData != -1)
        printf("Deleted data is %d\n", iData); 				// 60

    Display(pFirst); 										// 20 30 20 40 50

    iData = DeleteAtPosition(&pFirst,4);
    if(iData != -1)
        printf("Deleted data is %d\n", iData); 				// 40

    Display(pFirst); 										// 20 30 20 50

    iData = SearchFirstOccurrence(pFirst,20);
    if(iData != 0)
        printf("First %d found at %d position\n", 20, iData); 		// 1

    iData = SearchLastOccurrence(pFirst,20);
    if(iData != 0)
        printf("Last %d found at %d position\n", 20, iData); 		// 3

    iData = SearchAllOccurrence(pFirst,20);
    printf("%d found %d times\n", 20, iData); 						// 2

    iData = CountNodes(pFirst);
    printf("Total node count is %d\n", iData); 						// 4

    Display(pFirst); // 20 30 20 50

    PhysicalReverse(&pFirst);
    Display(pFirst); 										// 50 20 30 20

    PhysicalReverse(&pFirst);
    Display(pFirst); 										// 20 30 20 50

    ReverseDisplay(pFirst); 								// 50 20 30 20
    Display(pFirst); 										// 20 30 20 50

    InsertLast(&pSecond,100);
    InsertLast(&pSecond,200);
    
    Display(pSecond); 										// 100 200

    ConCatLists(&pFirst,&pSecond);

    Display(pFirst);										// 20 30 20 50 100 200
    Display(pSecond); 										// list is empty

    InsertLast(&pSecond,400);
    InsertLast(&pSecond,500);

    Display(pFirst); 										// 20 30 20 50 100 200
    Display(pSecond); 										// 400 500

    ConCatAtPosition(&pFirst,&pSecond,3);
    Display(pSecond); 										// 20 30 400 500 20 50 100 200
    Display(pSecond); 										// list is empty

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

    Display(pFirst); 										// list is empty
    Display(pSecond); 										// list is empty

    return 0;
}
//===========================================
//                  OUTPUT
//===========================================

/*

Current linked list is :-
        |NULL|

Current linked list is :-
        |10|<-->|20|<-->|30|<-->|NULL|

Current linked list is :-
        |10|<-->|20|<-->|30|<-->|40|<-->|50|<-->|60|<-->|NULL|

Current linked list is :-
        |10|<-->|20|<-->|30|<-->|20|<-->|40|<-->|50|<-->|60|<-->|NULL|
Deleted data is 10

Current linked list is :-
        |20|<-->|30|<-->|20|<-->|40|<-->|50|<-->|60|<-->|NULL|
Deleted data is 60

Current linked list is :-
        |20|<-->|30|<-->|20|<-->|40|<-->|50|<-->|NULL|
Deleted data is 40

Current linked list is :-
        |20|<-->|30|<-->|20|<-->|50|<-->|NULL|
First 20 found at 1 position
Last 20 found at 3 position
20 found 2 times
Total node count is 4

Current linked list is :-
        |20|<-->|30|<-->|20|<-->|50|<-->|NULL|

Current linked list is :-
        |50|<-->|20|<-->|30|<-->|20|<-->|NULL|

Current linked list is :-
        |20|<-->|30|<-->|20|<-->|50|<-->|NULL|
|50|<-->|20|<-->|30|<-->|20|<-->
Current linked list is :-
        |20|<-->|30|<-->|20|<-->|50|<-->|NULL|

Current linked list is :-
        |100|<-->|200|<-->|NULL|

Current linked list is :-
        |20|<-->|30|<-->|20|<-->|50|<-->|100|<-->|200|<-->|NULL|

Current linked list is :-
        |NULL|

Current linked list is :-
        |20|<-->|30|<-->|20|<-->|50|<-->|100|<-->|200|<-->|NULL|

Current linked list is :-
        |400|<-->|500|<-->|NULL|

Current linked list is :-
        |NULL|

Current linked list is :-
        |NULL|

Current linked list is :-
        |NULL|

Current linked list is :-
        |NULL|
*/


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
    pNewNode->pPrev = NULL;             //NEW LINE

    pNewNode->pNext = *ppHead;
    if(*ppHead != NULL)
        (*ppHead)->pPrev = pNewNode;
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
        pNewNode->pPrev = NULL;         //NEW LINE
        *ppHead = pNewNode;
        return ;
    }

    pTemp = *ppHead;
    while(pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;
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
    pTemp->pNext->pPrev = pNewNode;
    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;
}

int DeleteFirst(struct Node **ppHead)
{
    int iDelData;

    if(NULL == *ppHead)
        return -1;
    
    iDelData = (*ppHead)->iData;

    *ppHead = (*ppHead)->pNext;
    (*ppHead)->pPrev->pNext = NULL;


    free((*ppHead)->pPrev);
    (*ppHead)->pPrev = NULL;

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
        *ppHead = NULL;
    else
    {
        while(pTemp->pNext != NULL)
            pTemp = pTemp->pNext;

        pTemp->pPrev->pNext = NULL;
        pTemp->pPrev = NULL;
    }

    iDelData = pTemp->iData;
    free(pTemp);
    
    return iDelData;
}

int DeleteAtPosition(struct Node **ppHead ,int iPos)
{
    struct Node *pTemp = NULL;
    int iCount = 0;

    iCount = CountNodes(*ppHead);

    if(iPos <= 0 || iPos > iCount)
    {
        printf("\nInvalide position.");
        return -1;
    }

    pTemp = *ppHead;
    iCount = 1;

    while(iCount < iPos)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    if(pTemp->pPrev == NULL)
        *ppHead = pTemp->pNext;
    else
        pTemp->pPrev->pNext = pTemp->pNext;
    if(pTemp->pNext != NULL)
        pTemp->pNext->pPrev = pTemp->pPrev;
    iCount = pTemp->iData;

    pTemp->pNext = NULL;
    free(pTemp);

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

void ConCatLists(struct Node **ppHead1 ,struct Node **ppHead2)
{
    struct Node *pTemp = NULL;

    if(NULL == *ppHead2)
        return;

    if(NULL == *ppHead1)
        *ppHead1 = *ppHead2;
    else
    {
        pTemp = *ppHead1;
        while(pTemp->pNext != NULL)
            pTemp = pTemp->pNext;
        pTemp->pNext = *ppHead2;
        (*ppHead2)->pPrev = pTemp;
    }

    *ppHead2 = NULL;
}

void PhysicalReverse(struct Node **ppHead)
{
    struct Node *pNext = NULL;
    struct Node *pCurrent = *ppHead;

    while(pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pCurrent->pPrev;
        pCurrent->pPrev = pNext;
        *ppHead = pCurrent;
        pCurrent = pNext;
    }
}

void ReverseDisplay(struct Node *pHead)
{
    if (pHead == NULL)
    {
        printf("List is Empty");
        return;
    }
    while(pHead->pNext != NULL)
        pHead = pHead->pNext;
    while(pHead != NULL)
    {
        printf("|%d|<-->",pHead->iData);
        pHead = pHead->pPrev;
    }
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
        ConCatLists(ppHead2 , ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    if(iPos == iCount+1)
    {
        ConCatLists(ppHead1 , ppHead2);
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
    pTemp1->pNext->pPrev = pTemp2;
    pTemp1->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp1;
    *ppHead2 = NULL;
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

void Display(struct Node *pHead)
{
    printf("\nCurrent linked list is :- \n\t");
    while(pHead != NULL)
    {
        printf("|%d|<-->",pHead->iData);
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
        pTemp->pNext = NULL;
        pTemp->pPrev = NULL;
        free(pTemp);
    }
}