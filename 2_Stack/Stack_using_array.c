#include<stdio.h>
#include<malloc.h>

#define MAX 5

void Push(int * , int * , int );
int Pop(int * , int *);
int IsFull(int);
int IsEmpty(int);
void Display(int * , int);

int main (void)
{
	int Stack[MAX];
	int iTop = -1;

	Push(Stack , &iTop , 10);
	Push(Stack , &iTop , 20);
	Push(Stack , &iTop , 30);


	Display(Stack , iTop);

	printf("\npoped data is %d\n",Pop(Stack , &iTop));

	Display(Stack , iTop);

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

void Push(int *pStack ,int *piTop ,int iData)
{
	if(IsFull(*piTop))
	{
		printf("\n\t\tstack is Full.");
		return ;
	}

	pStack[++(*piTop)] = iData;
}

int Pop(int *pStack ,int *piTop)
{
	if(IsEmpty(*piTop))
	{
		printf("\n\t\tStack is Empty.");
		return -1;
	}

	return pStack[(*piTop)--];
}

int IsFull(int iNo)
{
	if(MAX-1 == iNo)
		return 1;
	return 0;
}

int IsEmpty(int iNo)
{
	if(-1 == iNo)
		return 1;
	return 0;
}

void Display(int *pStack ,int iTop)
{
	if(-1 != iTop)
		for(; iTop>=0; iTop--)
			printf("\n\t|  %d  |\n\t|======|",pStack[iTop]);
	printf("\n\t|-NULL-|\n");
}