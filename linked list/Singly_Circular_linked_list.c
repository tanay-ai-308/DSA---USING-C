#include <stdio.h>
#include <malloc.h>

struct Node
{
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

    Display(pFirst1,pLast1);											// 10 20 30 20 40 50 60

    iData = DeleteFirst(&pFirst1,&pLast1);
    if(iData != -1)
        printf("Deleted data is %d\n", iData); 						// 10

    Display(pFirst1,pLast1); 										// 20 30 20 40 50 60

    iData = DeleteLast(&pFirst1,&pLast1);
    if(iData != -1)
        printf("Deleted data is %d\n", iData); 						// 60

    Display(pFirst1,pLast1); 										// 20 30 20 40 50

    iData = DeleteAtPosition(&pFirst1,&pLast1,4);
    if(iData != -1)
        printf("Deleted data is %d\n", iData); 						// 40

    Display(pFirst1,pLast1); 										// 20 30 20 50

    iData = SearchFirstOccurrence(pFirst1,pLast1,20);
    if(iData != 0)
        printf("First %d found at %d position\n", 20, iData); 		// 1

    iData = SearchLastOccurrence(pFirst1,pLast1,20);
    if(iData != 0)
        printf("Last %d found at %d position\n", 20, iData); 		// 3

    iData = SearchAllOccurrences(pFirst1,pLast1,20);
    printf("%d found %d times\n", 20, iData); 						// 2

    iData = CountNodes(pFirst1,pLast1);
    printf("Total node count is %d\n", iData); 						// 4

    Display(pFirst1,pLast1); // 20 30 20 50

    PhysicalReverse(&pFirst1,&pLast1);
    Display(pFirst1,pLast1); 										// 50 20 30 20

    PhysicalReverse(&pFirst1,&pLast1);
    Display(pFirst1,pLast1); 										// 20 30 20 50

    ReverseDisplay(pFirst1,pLast1); 									// 50 20 30 20
    Display(pFirst1,pLast1); 										// 20 30 20 50

    InsertLast(&pFirst2,&pLast2,100);
    InsertLast(&pFirst2,&pLast2,200);
    
    Display(pFirst2,pLast2); 										// 100 200

    ConcatLists(&pFirst1,&pLast1,&pFirst2,&pLast2);

    Display(pFirst1,pLast1);											// 20 30 20 50 100 200
    Display(pFirst2,pLast2); 										// list is empty

    InsertLast(&pFirst2,&pLast2,400);
    InsertLast(&pFirst2,&pLast2,500);

    Display(pFirst1,pLast1); 										// 20 30 20 50 100 200
    Display(pFirst2,pLast2); 										// 400 500

    ConcatAtPosition(&pFirst1,&pLast1,&pFirst2,&pLast2, 3);
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

    Display(pFirst1,pLast1); 										// list is empty
    Display(pFirst2,pLast2); 										// list is empty

    return 0;
}

//===========================================
//                  OUTPUT
/*===========================================

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
        |20|-->|30|-->|400|-->|500|-->|20|-->|50|-->|100|-->|200|-->|NULL|

Current linked list is :-
        |NULL|

Current linked list is :-
        |NULL|

Current linked list is :-
        |NULL|
*/

void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iNo)
{
    struct Node *pNewNode = NULL;

    pNewNode=(struct Node *)malloc(sizeof(struct Node));

    if(NULL==pNewNode)
    {
        printf("Memory allocation FAILED\n");
        return;
    }
    
    pNewNode->iData = iNo;

    if(NULL == *ppHead)
        *ppHead = *ppTail = pNewNode;

    pNewNode->pNext = *ppHead;
    (*ppTail)->pNext = pNewNode;
    *ppHead=pNewNode;
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
       *ppHead = *ppTail = pNewNode;

    (*ppTail)->pNext = pNewNode;
    pNewNode->pNext = *ppHead;
    *ppTail = pNewNode;
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
  	pTemp->pNext=pNewNode;
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
    }while(pTail->pNext!=pHead);
    
    return iCount;
}

int DeleteFirst(struct Node **ppHead ,struct Node **ppTail)
{
    int iDelData;
    struct Node * pTemp=NULL;
  
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
    	pTemp=*ppHead;
    	*ppHead=(*ppHead)->pNext;
    	free(pTemp);
    	(*ppTail)->pNext=*ppHead;
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
        struct Node *pTemp=*ppHead;
        while(pTemp->pNext!=*ppTail)
        	pTemp=pTemp->pNext;
            
        free(*ppTail);
        *ppTail=pTemp;
        (*ppTail)->pNext = *ppHead;
    }
    return iDelData;
}

int DeleteAtPosition(struct Node **ppHead, struct Node **ppTail, int iPos)
{
    int iCount;
    struct Node *pTemp1=NULL;
    struct Node *pTemp2=NULL;

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

int SearchFirstOccurrence(struct Node *pHead,struct Node *pTail,int iKey)
{
    int iPos = 0;
    do
    {
        iPos++;
        if(iKey == pHead->iData){
   		return iPos;
    }
    pHead = pHead->pNext;
    } while(pTail != pHead);

    return 0;
}

int SearchLastOccurrence(struct Node *pHead,struct Node *pTail,int iKey)
{
    int iPos = 0;
    int iLastPos = 0;
    do
    {
        iPos++;
        if(iKey == pHead->iData)
            iLastPos = iPos;
        pHead = pHead->pNext;
    }while(pTail != pHead);
   
    return iLastPos;
}

int SearchAllOccurrences(struct Node *pHead,struct Node *pTail,int iKey)
{
    int iCount=0;
    do{
        
        if(iKey==pHead->iData)
            iCount++;
            pHead=pHead->pNext;
    } while(pTail!=pHead);

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
   
    if(NULL==*ppHead1)
    {
        *ppHead1=*ppHead2;
        *ppTail1=*ppTail2;
        *ppHead2=NULL;
        *ppTail2=NULL;
        return;
    }
   (*ppTail1)->pNext=*ppHead2;
   *ppTail1=*ppTail2;
   (*ppTail1)->pNext=*ppHead1;
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
    if( iPos<0 || iPos>=iCount+1 )
        return ;
   
    if(1 == iPos)
    {
        ConcatLists(ppHead2,ppTail2,ppHead1,ppTail1);
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
	pTemp->pNext = *ppHead2;
	*ppHead2 = NULL;
	*ppTail2 = NULL;
	pTemp = NULL;

	return;
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
	    pPrev = pCurrent;
	    pCurrent = pNext;
	}while(pCurrent != *ppHead);

  	*ppHead = pPrev;
  	*ppTail = pCurrent;
}

void ReverseDisplay(struct Node *pHead, struct Node *pTail)
{
    if(NULL==pHead)
        return;
    
    PhysicalReverse(&pHead,&pTail);

    Display(pHead,pTail);
    
    PhysicalReverse(&pHead,&pTail);
}

void Display (struct Node * pHead,struct Node *pTail)
{
	printf("\nCurrent linked list is :- \n\t");

	if(NULL==pHead);
    else do
	    {
	        printf("|%d|-->",pHead->iData);
	        pHead=pHead->pNext;
	    }while(pHead != pTail->pNext);

	printf("|NULL|\n");
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
	    *ppHead=(*ppHead)->pNext;
	     free(pTemp);
    }
    *ppTail=NULL;
}