#include<stdio.h>
#define MAX 5

int IsQueueFull(int ,int);
int IsQueueEmpty(int);
void EnQueue(int *,int * ,int *,int);
int DeQueue(int *,int * ,int *);
void Display(int *,int  ,int );

int main (void)
{
	int iFront = 0;
	int iRear = -1;
	int Queue[MAX];	

	EnQueue(Queue , &iRear , &iFront , 10);
	EnQueue(Queue , &iRear , &iFront , 20);
	EnQueue(Queue , &iRear , &iFront , 30);
	EnQueue(Queue , &iRear , &iFront , 40);
	EnQueue(Queue , &iRear , &iFront , 50);
	EnQueue(Queue , &iRear , &iFront , 60);

	Display(Queue , iRear , iFront);

	printf("Deleted Data is %d",DeQueqe(Queue , &iRear , &iFront));

	Display(Queue , iRear , iFront);

	EnQueqe(Queue , &iRear , &iFront , 60);

	Display(Queue , iRear , iFront);

	DeQueue(Queue , &iRear , &iFront);
	DeQueue(Queue , &iRear , &iFront);
	DeQueue(Queue , &iRear , &iFront);

	EnQueue(Queue , &iRear , &iFront , 70);
	EnQueue(Queue , &iRear , &iFront , 80);
	EnQueue(Queue , &iRear , &iFront , 90);

	return 0;
}

void EnQueue(int *pQueue ,int *piRear ,int *piFront, int iData)
{
	if(IsQueueFull(*piRear ,*piFront))
	{
		printf("\nQueue is Full.");
		return ;
	}

	if (*piRear == MAX-1)
		*piRear = 0;
	else
		(*piRear)++;

	pQueue[*piRear] = iData;
}

int DeQueue(int *pQueue ,int *piRear ,int *piFront)
{
	int iDelData;

	if(IsQueueEmpty(*piRear))
	{
		printf("Queqe is Empty.");
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

int IsQueueFull(int iRear , int iFront)
{
	printf("3");

	if((iRear == MAX-1 && iFront == 0) || 
		(iRear == iFront-1 && iRear != -1))
		return 1;
	printf("4");
	return 0;
}

int IsQueueEmpty(int iRear)
{
	if(-1 == iRear)
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
/*
void Display(int *pQueqe , int iFront , int iRear)
{
	printf("\n\n\t=======================================\n");
	
	for( ; iFront < iRear ; iFront++)
		printf("\t  %d  |",pQueqe[iFront]);

	printf("\n\t=======================================\n");
}
*/