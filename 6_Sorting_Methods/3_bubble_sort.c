#include<stdio.h>
#define MAX 50

int main(void)
{
	int iNo;
	int Arr[MAX];
	int iCounter1;
	int iCounter2;
	int iNoSwaps;

	printf("\nHow many numbers you want to enter :- ");
	scanf("%d",&iNo);

	for(iCounter1 = 0 ; iCounter1<iNo ; iCounter1++)
	{
		printf("\nEnter %d element :- ",iCounter1+1);
		scanf("%d",&Arr[iCounter1]);
	}

	for(iCounter1 = 0 ; iCounter1<iNo-1 ; iCounter1++)
	{
		iNoSwaps = 0;

		for(iCounter2 = 0 ; iCounter2<iNo-iCounter1-1 ; iCounter2++)
		{
			if(Arr[iCounter2]>Arr[iCounter2+1])
			{
				Arr[iCounter2] = Arr[iCounter2] ^ Arr[iCounter2+1];	
				Arr[iCounter2+1] = Arr[iCounter2] ^ Arr[iCounter2+1];	
				Arr[iCounter2] = Arr[iCounter2] ^ Arr[iCounter2+1];

				iNoSwaps++;	
			}
		}

		if(0==iNoSwaps)
			break;
	}

	printf("\n\nSorted elements are :\n\t");
	for(iCounter1 = 0 ; iCounter1<iNo ; iCounter1++)
		printf("%d\t",Arr[iCounter1]);

	return 0;

}