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

void Display(struct Node *,struct Node *);
int CountNodes(struct Node *,struct Node *);
int DeleteLast(struct Node **,struct Node **);
int DeleteFirst(struct Node **,struct Node **);
void DeleteAll (struct Node **,struct Node **);
void ReverseDisplay(struct Node *,struct Node *);
void InsertLast(struct Node **,struct Node **,int);
void InsertFirst(struct Node **,struct Node **,int);
void PhysicalReverse(struct Node **,struct Node **);
int DeleteAtPosition(struct Node **,struct Node **,int);
int SearchAllOccurrences(struct Node *,struct Node *,int);
int SearchLastOccurrence(struct Node *,struct Node *,int);
int SearchFirstOccurrence(struct Node *,struct Node *,int);
void InsertAtPosition(struct Node **,struct Node **,int,int);
void ConcatLists(struct Node **,struct Node **,struct Node **,struct Node **);
void ConcatAtPosition(struct Node **,struct Node **,struct Node **,struct Node **,int);

//==========================================================

int main (void)
{
    int iData;
    struct Node *pFirst1 = NULL;
    struct Node *pFirst2 = NULL;
    struct Node *pLast1 = NULL;
    struct Node *pLast2 = NULL;										//expected output


    Display(pFirst1,pLast1); 										// list is empty

    InsertFirst(&pFirst1,&pLast1,30);
    InsertFirst(&pFirst1,&pLast1,20);
    InsertFirst(&pFirst1,&pLast1,10);

    Display(pFirst1,pLast1); 										// 10 20 30

    InsertLast(&pFirst1,&pLast1,40);
    InsertLast(&pFirst1,&pLast1,50);
    InsertLast(&pFirst1,&pLast1,60);

    Display(pFirst1,pLast1); 										// 10 20 30 40 50 60

    InsertAtPosition(&pFirst1,&pLast1,20, 4);

    Display(pFirst1,pLast1);										// 10 20 30 20 40 50 60

    iData = DeleteFirst(&pFirst1,&pLast1);
    if(iData != -1)
        printf("\nDeleted data is %d", iData); 						// 10

    Display(pFirst1,pLast1); 										// 20 30 20 40 50 60

    iData = DeleteLast(&pFirst1,&pLast1);
    if(iData != -1)
        printf("\nDeleted data is %d", iData); 						// 60

    Display(pFirst1,pLast1); 										// 20 30 20 40 50

    iData = DeleteAtPosition(&pFirst1,&pLast1,4);
    if(iData != -1)
        printf("\nDeleted data is %d", iData); 						// 40

    Display(pFirst1,pLast1); 										// 20 30 20 50

    iData = SearchFirstOccurrence(pFirst1,pLast1,20);
    if(iData != 0)
        printf("\nFirst %d found at %d position", 20, iData); 		// 1

    iData = SearchLastOccurrence(pFirst1,pLast1,20);
    if(iData != 0)
        printf("\nLast %d found at %d position", 20, iData); 		// 3

    iData = SearchAllOccurrences(pFirst1,pLast1,20);
    printf("\n%d found %d times", 20, iData); 						// 2

    iData = CountNodes(pFirst1,pLast1);
    printf("\nTotal node count is %d", iData); 						// 4

    Display(pFirst1,pLast1);                                        // 20 30 20 50

    printf("\nPhysical Reverse.");
    PhysicalReverse(&pFirst1,&pLast1);
    Display(pFirst1,pLast1); 										// 50 20 30 20

    printf("\nPhysical Reverse.");
    PhysicalReverse(&pFirst1,&pLast1);
    Display(pFirst1,pLast1); 										// 20 30 20 50

    printf("\nReverse Display.");
    ReverseDisplay(pFirst1,pLast1); 								// 50 20 30 20
    Display(pFirst1,pLast1); 										// 20 30 20 50

    InsertLast(&pFirst2,&pLast2,100);
    InsertLast(&pFirst2,&pLast2,200);
    
    printf("\nSecond linked list.");
    Display(pFirst2,pLast2); 										// 100 200

    ConcatLists(&pFirst1,&pLast1,&pFirst2,&pLast2);

    printf("\nAfter ConcatLists.");
    Display(pFirst1,pLast1);										// 20 30 20 50 100 200
    Display(pFirst2,pLast2); 										// list is empty

    InsertLast(&pFirst2,&pLast2,400);
    InsertLast(&pFirst2,&pLast2,500);

    Display(pFirst1,pLast1); 										// 20 30 20 50 100 200
    Display(pFirst2,pLast2); 										// 400 500

    ConcatAtPosition(&pFirst1,&pLast1,&pFirst2,&pLast2, 3);
    printf("\nAfter ConcatAtPosition.");
    Display(pFirst1,pLast1); 										// 20 30 400 500 20 50 100 200
    Display(pFirst2,pLast2); 										// list is empty

    if(pFirst1 != NULL)
    {
        DeleteAll(&pFirst1,&pLast1);
        pFirst1 = NULL;
        pLast1 = NULL;
    }

    if(pFirst2 != NULL)
    {
        DeleteAll(&pFirst2,&pLast2);
        pFirst2 = NULL;
        pLast2 = NULL;
    }

    printf("\nAfter DeleteAll.");
    Display(pFirst1,pLast1); 										// list is empty
    Display(pFirst2,pLast2); 										// list is empty

    return 0;
}

//===========================================
//                  OUTPUT
/*===========================================

Current linked list is :-
        |NULL|.

Current linked list is :-
        |10|<-->|20|<-->|30|<-->|NULL|.

Current linked list is :-
        |10|<-->|20|<-->|30|<-->|40|<-->|50|<-->|60|<-->|NULL|.

Current linked list is :-
        |10|<-->|20|<-->|30|<-->|20|<-->|40|<-->|50|<-->|60|<-->|NULL|.

Deleted data is 10
Current linked list is :-
        |20|<-->|30|<-->|20|<-->|40|<-->|50|<-->|60|<-->|NULL|.

Deleted data is 60
Current linked list is :-
        |20|<-->|30|<-->|20|<-->|40|<-->|50|<-->|NULL|.

Deleted data is 40
Current linked list is :-
        |20|<-->|30|<-->|20|<-->|50|<-->|NULL|.

First 20 found at 1 position
Last 20 found at 3 position
20 found 2 times
Total node count is 4
Current linked list is :-
        |20|<-->|30|<-->|20|<-->|50|<-->|NULL|.

Physical Reverse.
Current linked list is :-
        |50|<-->|20|<-->|30|<-->|20|<-->|NULL|.

Physical Reverse.
Current linked list is :-
        |20|<-->|30|<-->|20|<-->|50|<-->|NULL|.

Reverse Display.|50|<-->|20|<-->|30|<-->|20|<-->|Null|.

Current linked list is :-
        |20|<-->|30|<-->|20|<-->|50|<-->|NULL|.

Second linked list.
Current linked list is :-
        |100|<-->|200|<-->|NULL|.

After ConcatLists.
Current linked list is :-
        |20|<-->|30|<-->|20|<-->|50|<-->|100|<-->|200|<-->|NULL|.

Current linked list is :-
        |NULL|.

Current linked list is :-
        |20|<-->|30|<-->|20|<-->|50|<-->|100|<-->|200|<-->|NULL|.

Current linked list is :-
        |400|<-->|500|<-->|NULL|.

After ConcatAtPosition.
Current linked list is :-
        |20|<-->|30|<-->|400|<-->|500|<-->|20|<-->|50|<-->|100|<-->|200|<-->|NULL|.

Current linked list is :-
        |NULL|.

After DeleteAll.
Current linked list is :-
        |NULL|.

Current linked list is :-
        |NULL|.
*/


void InsertFirst(struct Node **ppHead, struct Node **ppTail, int iNo)
{
    struct Node *pNewNode = NULL;
    
    pNewNode = (struct Node *) malloc (sizeof(struct Node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation Failed");
        return;
    }

    pNewNode -> iData = iNo;            

    if((*ppHead) == NULL)
    {
        *ppHead = *ppTail =  pNewNode;
        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;

        return;
    }
    else
    {
        pNewNode->pNext = *ppHead;
        (*ppHead)->pPrev = pNewNode;
        pNewNode->pPrev = *ppTail;
        (*ppTail)->pNext = pNewNode;
        *ppHead = pNewNode;
    }
}

void InsertLast(struct Node **ppHead, struct Node **ppTail, int iNo)
{
    struct Node * pNewNode = NULL;

    pNewNode = (struct Node *)malloc(sizeof(struct Node));
    
    if(NULL == pNewNode)
    {
       printf("Memory allocation FAILED");
       return;
    }
    
    pNewNode->iData = iNo;

    if(NULL == *ppHead)
    {   
        *ppHead = pNewNode;
        *ppTail = *ppHead;
    }
    else
    {
        (*ppTail)->pNext = pNewNode;
        pNewNode->pPrev = *ppTail;
        *ppTail = pNewNode;
    }
    (*ppTail)->pNext = *ppHead;
    (*ppHead)->pPrev = *ppTail;
}

void InsertAtPosition(struct Node **ppHead, struct Node **ppTail, int iNo, int iPos)
{
    int iCount;
    struct Node *pNewNode = NULL;
    struct Node *pTemp = NULL;
  	
  	iCount=CountNodes(*ppHead,*ppTail);

  	if( iPos<0 || iPos>iCount+1 )
  	{
    	printf("Position is invalid\n");
    	return;
  	}
  
    if(1==iPos)
    {
        InsertFirst(ppHead,ppTail,iNo);
        return;
  	}
  	
  	if(	iPos==iCount+1 )
  	{
    	InsertLast(ppHead,ppTail,iNo);
    	return;
  	}

  	pNewNode = (struct Node*) malloc(sizeof(struct Node));
  	
  	if(NULL == pNewNode)
  	{
    	printf("Memory allocation FAILED\n");
    	return ;
  	}
  
  	pNewNode->iData=iNo;
  	pTemp=*ppHead;
  	iCount=1;
  	
  	while(iCount<iPos-1)
  	{
    	iCount++;
    	pTemp=pTemp->pNext;
  	}
  	
  	pNewNode->pNext=pTemp->pNext;
    pTemp->pNext->pPrev=pNewNode;
  	pTemp->pNext=pNewNode;
    pNewNode->pPrev=pTemp;
}

int CountNodes(struct Node *pHead,struct Node *pTail)
{
    int iCount=0;

    if(NULL==pHead)
        return 0;
  	do
  	{
        iCount++;
        pHead=pHead->pNext;
    }while(pTail->pNext != pHead);
    
    return iCount;
}

int DeleteFirst(struct Node **ppHead ,struct Node **ppTail)
{
    int iDelData;
  
    if(NULL==*ppHead)
    	return -1;
  	
    iDelData=(*ppHead)->iData;
    
    if((*ppHead)==*ppTail)
    {
    	free(*ppHead);
    	*ppHead=*ppTail=NULL;
    }
    else
  	{
    	*ppHead=(*ppHead)->pNext;
    	free((*ppHead)->pPrev);
    	(*ppTail)->pNext=*ppHead;
        (*ppHead)->pPrev=*ppTail;
  	}
  	
  	return iDelData;
}

int DeleteLast(struct Node **ppHead,struct Node **ppTail)
{
    int iDelData;

    if(NULL==*ppHead)
        return -1;
    
    iDelData=(*ppTail)->iData;

    if(*ppHead==*ppTail)
    {
        free(*ppTail);
        *ppHead=*ppTail=NULL;
    }
    else
    {
        *ppTail = (*ppTail)->pPrev;
        free((*ppTail)->pNext);
        (*ppTail)->pNext = *ppHead;
        (*ppHead)->pPrev = *ppTail;
    }
    return iDelData;
}

int DeleteAtPosition(struct Node **ppHead, struct Node **ppTail, int iPos)
{
    int iCount;
    struct Node *pTemp=NULL;

   iCount = CountNodes(*ppHead,*ppTail);

    if(iPos <= 0 || iPos > iCount)
    {
        printf("\nInvalide position.");
        return -1;
    }

   if(iPos == 1)
        return DeleteFirst(ppHead,ppTail);

    if(iPos == iCount)
        return DeleteLast(ppHead,ppTail);

    pTemp = *ppHead;
    iCount = 1;

    while(iCount < iPos)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    pTemp->pPrev->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = pTemp->pPrev;
    pTemp->pNext = pTemp->pPrev = NULL;
    iCount = pTemp->iData;
    free(pTemp);

    return iCount;
}

int SearchFirstOccurrence(struct Node *pHead,struct Node *pTail,int iKey)
{
    int iPos = 0;

    if(NULL == pHead)
        return -1;
    do
    {
        iPos++;
        if(iKey == pHead->iData)
   	    	return iPos;
    
        pHead = pHead->pNext;
    } while(pTail->pNext != pHead);

    return 0;
}

int SearchLastOccurrence(struct Node *pHead,struct Node *pTail,int iKey)
{
    int iPos = 0;
    int iLastPos = 0;

    if(NULL == pHead)
        return -1;

    do
    {
        iPos++;
        if(iKey == pHead->iData)
            iLastPos = iPos;
        pHead = pHead->pNext;
    }while(pTail->pNext != pHead);
   
    return iLastPos;
}

int SearchAllOccurrences(struct Node *pHead,struct Node *pTail,int iKey)
{
    int iCount=0;

    if(NULL == pHead)
        return -1;

    do
    {
        if(iKey==pHead->iData)
            iCount++;
        pHead=pHead->pNext;

    } while(pTail->pNext != pHead);

    return iCount;
}

void ConcatLists(
			    struct Node **ppHead1,
			    struct Node **ppTail1,
			    struct Node **ppHead2,
			    struct Node **ppTail2
			    )
{
    if(NULL==*ppHead2)
        return;
   
    if(NULL == *ppHead1)
        *ppHead1=*ppHead2;
    else
    {
        (*ppTail1)->pNext=*ppHead2;
        (*ppHead2)->pPrev=*ppTail1;
        (*ppTail2)->pNext=*ppHead1;
        (*ppHead1)->pPrev=*ppTail2;
    }
    
    *ppTail1=*ppTail2;
    *ppHead2=*ppTail2=NULL;
}

void ConcatAtPosition(
					  struct Node **ppHead1,
					  struct Node **ppTail1,
					  struct Node **ppHead2,
					  struct Node **ppTail2,
					  int iPos
					  )
{
    int iCount;
    struct Node *pTemp=NULL; 

    iCount = CountNodes(*ppHead1,*ppTail1);

    if( iPos <= 0 || iPos > iCount+1 )
    {
        printf("\nPosition is invalid.");
        return ;
    }
   
    if(1 == iPos)
    {
        ConcatLists(ppHead2,ppTail2,ppHead1,ppTail1);
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;

        *ppHead2 = *ppTail2 = NULL;
        return;
    }

    if(iPos == iCount+1)
    {
        ConcatLists(ppHead1,ppTail1,ppHead2,ppTail2);
        return;
    }

	pTemp = *ppHead1;
	iCount = 1;

	while(iPos > iCount+1)
	{
		iCount++;
		pTemp = pTemp->pNext;
	}

    (*ppTail2)->pNext = pTemp->pNext;
    (*ppTail2)->pNext->pPrev = *ppTail2;
    pTemp->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp;
	
	*ppHead2 = NULL;
	*ppTail2 = NULL;
	pTemp = NULL;

}

void PhysicalReverse(struct Node **ppHead, struct Node **ppTail)
{   
	struct Node * pCurrent = *ppHead;
	struct Node * pNext = NULL;
	struct Node * pPrev = *ppTail;

	do
	{
	    pNext = pCurrent->pNext;
	    pCurrent->pNext = pPrev;
        pCurrent->pPrev = pNext;
	    pPrev = pCurrent;
	    pCurrent = pNext;
	}while(pCurrent != *ppHead);

  	*ppHead = pPrev;
  	*ppTail = pCurrent;
}

void ReverseDisplay(struct Node *pHead, struct Node *pTail)
{
    if(NULL == pTail)
    {
        printf("\nList is empty.");
        return;
    }
    do
    {
        printf("|%d|<-->",pTail->iData);
        pTail = pTail->pPrev;
    }while(pTail != pHead->pPrev);
    printf("|Null|.\n");
}

void Display (struct Node * pHead,struct Node *pTail)
{
    printf("\nCurrent linked list is :- \n\t");

    if(NULL==pHead);
    else do
        {
            printf("|%d|<-->",pHead->iData);
            pHead=pHead->pNext;
        }while(pHead != pTail->pNext);

    printf("|NULL|.\n");
}

void DeleteAll (struct Node ** ppHead , struct Node **ppTail)
{
  	struct Node *pTemp=NULL;

    if(NULL==*ppHead)
        return;
    (*ppTail)->pNext=NULL;
	
	while(*ppHead!=NULL)
	{
	    pTemp=*ppHead;
        pTemp->pNext = NULL;
        pTemp->pPrev = NULL;
	    *ppHead=(*ppHead)->pNext;
	     free(pTemp);
    }
    *ppTail=NULL;
}

