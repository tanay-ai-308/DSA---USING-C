#include<stdio.h>
#define MAX 10

int main(void)
{	
	int iCounter1;
	int iCounter2;
	int iNoVertices;
	int iNoAdjacent;
	int Vertices[MAX];
	int Graph[MAX][MAX] = {0};

	printf("\nHow many vertices you want (must be <=10) = ");
	scanf("%d",&iNoVertices);

	printf("\n\t");
	for(iCounter1 = 0 ; iCounter1 < iNoVertices ; iCounter1++)
	{
		printf("\tEnter %d Data = ",iCounter1+1);
		scanf("%d",&Vertices[iCounter1]);
	}

	for(iCounter1 = 0 ; iCounter1 < iNoVertices ; iCounter1++)
	{
		printf("\nHow Adjancent vertices for %d - ",Vertices[iCounter1]);
		scanf("%d",&iNoAdjacent);

		for(iCounter2 = 0; iCounter2 < iNoAdjacent; iCounter2++)
		{	
			int iTemp;
			int iWeight;
			int iCounter3 = 0;

			printf("\tEnter %d vertex = ",iCounter2+1);
			scanf("%d",&iTemp);
			printf("\t\tweight = ");
			scanf("%d",&iWeight);

			while(Vertices[iCounter3] != iTemp)
				iCounter3++;

			Graph[iCounter1][iCounter3] = iWeight;
		}
	}

	printf("\nGraph is :-\n\t");

	for(iCounter1 = 0 ; iCounter1 < iNoVertices ; iCounter1++)
	{
		printf("%d => ",Vertices[iCounter1]);
		for(iCounter2 = 0 ; iCounter2 < iNoVertices ; iCounter2++)
		{
			if(Graph[iCounter1][iCounter2])
				printf("%d[%d] ",Vertices[iCounter2],Graph[iCounter1][iCounter2]);
		}
		printf("\n\t");
	}

	return 0;
}
/*

How many vertices you want (must be <=10) = 4
Enter 1 Data = 10
Enter 2 Data = 20
Enter 3 Data = 30
Enter 4 Data = 40

How Adjancent vertices for 10 - 1
        Enter 1 vertex = 20
                weight = 3

How Adjancent vertices for 20 - 1
        Enter 1 vertex = 30
                weight = 2

How Adjancent vertices for 30 - 3
        Enter 1 vertex = 10
                weight = 5
        Enter 2 vertex = 20
                weight = 4
        Enter 3 vertex = 40
                weight = 6

How Adjancent vertices for 40 - 0

Graph is :-
        10 => 20[3]
        20 => 30[2]
        30 => 10[5] 20[4] 40[6]
        40 =>
*/