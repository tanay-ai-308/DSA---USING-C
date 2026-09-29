#include<stdio.h>
#define MAX 5

int IsQueueFull(int , int);
int IsQueueEmpty(int , int);
void Display(int * , int , int);
int DeQueueFromRear(int * , int * , int *);
int DeQueueFromFront(int * , int * , int *);
void EnQueueAtRear(int * , int * , int * , int);
void EnQueueAtFront(int * , int * , int * , int);

int main(void)
{
	int iDelData;
	int iFront = 0;
	int iRear = -1;
	int Queqe[MAX];	

	EnQueueAtRear(Queqe , &iRear , &iFront , 10);
	EnQueueAtRear(Queqe , &iRear , &iFront , 20);	
	EnQueueAtRear(Queqe , &iRear , &iFront , 30);

	Display(Queqe , iRear , iFront);

	iDelData = DeQueueFromRear(Queqe , &iRear , &iFront);
	printf("\nDeleted Data is = %d",iDelData);

	iDelData = DeQueueFromRear(Queqe , &iRear , &iFront);
	printf("\nDeleted Data is = %d",iDelData);

	iDelData = DeQueueFromRear(Queqe , &iRear , &iFront);
	printf("\nDeleted Data is = %d",iDelData);

	EnQueueAtFront(Queqe , &iRear , &iFront , 10);
	EnQueueAtFront(Queqe , &iRear , &iFront , 20);
	EnQueueAtFront(Queqe , &iRear , &iFront , 30);

	Display(Queqe , iRear , iFront);

	iDelData = DeQueueFromFront(Queqe , &iRear , &iFront);
	printf("\nDeleted Data is = %d",iDelData);

	iDelData = DeQueueFromFront(Queqe , &iRear , &iFront);
	printf("\nDeleted Data is = %d",iDelData);

	iDelData = DeQueueFromFront(Queqe , &iRear , &iFront);
	printf("\nDeleted Data is = %d",iDelData);

	return 0;
}
/*
		OUTPUT :- 

		10
		20
		30
		Deleted Data is = 30
		Deleted Data is = 20
		Deleted Data is = 10
		30
		20
		10
		Deleted Data is = 30
		Deleted Data is = 20
		Deleted Data is = 10
		
*/
void EnQueueAtRear(int *pQueue ,int *piRear ,int *piFront ,int iData)
{
	if(IsQueueFull(*piRear , *piFront))
	{
		printf("\nQueue is Full.");
		return ;
	}

	if(*piRear == MAX-1)
		*piRear = 0;
	else
		(*piRear)++;

	pQueue[*piRear] = iData;
}

int DeQueueFromFront(int *pQueue ,int *piRear ,int *piFront)
{
	int iDelData;

	if(IsQueueEmpty(*piRear , *piFront))
	{
		printf("\nQueue is Empty.");
		return -1;
	}

	iDelData = pQueue[*piFront];

	if(*piFront == *piRear)
	{
		*piRear = -1;
		*piFront = 0;
	}

	if(*piFront == MAX-1)
		*piFront = 0;
	else
		(*piFront)++;
	
	return iDelData;
}

void EnQueueAtFront(int *pQueue ,int *piRear ,int *piFront ,int iData)
{
	if(IsQueueFull(*piRear , *piFront))
	{
		printf("\nQueue is Full.");
		return ;
	}

	if(*piFront == 0)
	{
		*piFront = MAX-1;
		if((*piRear) == -1)
			*piRear = MAX-1;
	}
	else
		(*piFront)--;

	pQueue[*piFront] = iData;
}

int DeQueueFromRear(int *pQueue ,int *piRear ,int *piFront)
{
	int iDelData;

	if(IsQueueEmpty(*piRear , *piFront))
	{
		printf("\nQueue is Empty.");
		return -1;
	}

	iDelData = pQueue[*piRear];

	if(*piFront == *piRear)
	{
		*piRear = -1;
		*piFront = 0;
	}

	if(*piRear == 0)
		*piRear = MAX-1;
	else
		(*piRear)--;
	
	return iDelData;
}

int IsQueueFull(int iRear , int iFront)
{
	if((iRear == MAX-1 && iFront == 0) || 
		(iRear == iFront-1 && iRear != -1))
		return 1;
	return 0;
}

int IsQueueEmpty(int iRear ,int iFront)
{
	if(-1 == iRear && iFront == 0)
		return 1;
	return 0;
}

void Display(int *pQueue , int iRear , int iFront )
{
	int iCounter;

	if(iRear<iFront)
	{
		for(iCounter = iFront ; iCounter <= MAX-1 ; iCounter++)
			printf("\n%d",pQueue[iCounter]);
		for(iCounter = 0 ;iCounter <= iRear ; iCounter++)
			printf("\n%d",pQueue[iCounter]);		
	}
	else
	{
		for(iCounter = iFront ; iCounter <= iRear; iCounter++)
			printf("\n%d",pQueue[iCounter]);
	}
}
