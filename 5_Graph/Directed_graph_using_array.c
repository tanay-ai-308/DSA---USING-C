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

	for(iCounter1 = 0 ; iCounter1 < iNoVertices ; iCounter1++)
	{
		printf("Enter %d Data = ",iCounter1+1);
		scanf("%d",&Vertices[iCounter1]);
	}

	for(iCounter1 = 0 ; iCounter1 < iNoVertices ; iCounter1++)
	{
		printf("\nHow many Adjancent vertices for %d - ",Vertices[iCounter1]);
		scanf("%d",&iNoAdjacent);

		for(iCounter2 = 0; iCounter2 < iNoAdjacent; iCounter2++)
		{	
			int iTemp;
			int iCounter3 = 0;

			printf("\tEnter %d vertex = ",iCounter2+1);
			scanf("%d",&iTemp);

			while(Vertices[iCounter3] != iTemp)
				iCounter3++;

			Graph[iCounter1][iCounter3] = 1;
		}
	}

	printf("\nGraph is :-\n\t");

	for(iCounter1 = 0 ; iCounter1 < iNoVertices ; iCounter1++)
	{
		printf("%d => ",Vertices[iCounter1]);
		for(iCounter2 = 0 ; iCounter2 < iNoVertices ; iCounter2++)
		{
			if(Graph[iCounter1][iCounter2])
				printf("%d ",Vertices[iCounter2]);
		}
		printf("\n\t");
	}

	return 0;
}