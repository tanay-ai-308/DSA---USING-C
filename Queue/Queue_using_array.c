#include<stdio.h>
#define MAX 5

int IsQueqeFull(int);
int IsQueqeEmpty(int);
void EnQueqe(int *,int * ,int);
int DeQueqe(int *,int * ,int *);
void Display(int *,int  ,int );

int main (void)
{
	int iFront = 0;
	int iRear = -1;
	int Queqe[MAX];	

	EnQueqe(Queqe , &iRear , 10);
	EnQueqe(Queqe , &iRear , 20);
	EnQueqe(Queqe , &iRear , 30);
	EnQueqe(Queqe , &iRear , 40);
	EnQueqe(Queqe , &iRear , 50);

	Display(Queqe , iFront , iRear);

	printf("Deleted Data is %d",DeQueqe(Queqe , &iFront , &iRear));

	Display(Queqe , iFront , iRear);

	return 0;
}

void EnQueqe(int *pQueqe ,int *piRear ,int iData)
{
	if(IsQueqeFull(*piRear))
	{
		printf("\nQueqe is Full.");
		return ;
	}

	pQueqe[++*piRear] = iData;
}

int DeQueqe(int *pQueqe ,int *piFront ,int *piRear)
{
	int iDelData;

	if(IsQueqeEmpty(*piRear))
	{
		printf("Queqe is Empty.");
		return -1;
	}

	iDelData = pQueqe[*piFront];

	if(*piFront == *piRear)
	{
		*piRear = -1;
		*piFront = 0;
	}
	else
		(*piFront)++;
	
	return iDelData;
}

int IsQueqeFull(int iRear)
{
	if(iRear == MAX-1)
		return 1;
	return 0;
}

int IsQueqeEmpty(int iRear)
{
	if(-1 == iRear)
		return 1;
	return 0;
}

void Display(int *pQueqe , int iFront , int iRear)
{
	printf("\n\n\t=======================================\n");

	for( ; iFront < iRear ; iFront++)
		printf("\t  %d  |",pQueqe[iFront]);

	printf("\n\t=======================================\n");
}