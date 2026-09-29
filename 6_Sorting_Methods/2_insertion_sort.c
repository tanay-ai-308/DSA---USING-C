#include<stdio.h>
#define MAX 50

int main(void)
{
	int iNo;
	int iTemp;
	int Arr[MAX];
	int iCounter1;
	int iCounter2;

	printf("\nHow many numbers you want to enter :- ");
	scanf("%d",&iNo);

	for(iCounter1 = 0 ; iCounter1<iNo ; iCounter1++)
	{
		printf("\nEnter %d element :- ",iCounter1+1);
		scanf("%d",&Arr[iCounter1]);
	}

	for(iCounter1 = 1 ; iCounter1<iNo ; iCounter1++)
	{
		iTemp = Arr[iCounter1];

		for(iCounter2 = iCounter1-1 ; iCounter2>=0 && iTemp<Arr[iCounter2] ; iCounter2--)
			Arr[iCounter2+1] = Arr[iCounter2];
		Arr[iCounter2+1] = iTemp;
	}

	printf("\n\nSorted elements are :\n\t");
	for(iCounter1 = 0 ; iCounter1<iNo ; iCounter1++)
		printf("%d\t",Arr[iCounter1]);

	return 0;
}
/*

How many numbers you want to enter :- 10

Enter 1 element :- 85

Enter 2 element :- 14

Enter 3 element :- 36

Enter 4 element :- 23

Enter 5 element :- 69

Enter 6 element :- 91

Enter 7 element :- 18

Enter 8 element :- 9

Enter 9 element :- 20

Enter 10 element :- 65


Sorted elements are :
        9       14      18      20      23      36      65      69      85      91
*/