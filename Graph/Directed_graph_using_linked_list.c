#include<stdio.h>
#include<malloc.h>

struct Edge;

struct Vertex
{
	struct Vertex *pNextVertex;
	int iData;
	struct Edge *pAdjEdge;
};

struct Edge
{
	struct Vertex *pAdjVertex;
	struct Edge *pNextEdge;
};

void Display(struct Vertex *);
void DeleteGraph(struct Vertex **);
struct Vertex* SearchVertex(struct Vertex* , int );
struct Vertex* InsertVertex(struct Vertex ** , int );
void InsertEdges(struct Vertex * , struct Vertex * , int );

int main(void)
{
	int iNo;
	int iFlag = 1;
	struct Vertex *pGraph = NULL;
	struct Vertex *pCurrentVertex = NULL;

	while(iFlag)
	{
		printf("\nEnter the vertex :- ");
		scanf("%d",&iNo);

		pCurrentVertex = InsertVertex(&pGraph , iNo);

		printf("\nHow many Adjacent Vertex for %d Vertex :- ",iNo);
		scanf("%d",&iNo);

		if(iNo)
			InsertEdges(pGraph , pCurrentVertex , iNo);

		printf("\nDo you want to enter another vertex (1 for Yes / 0 for No) :- ");
		scanf("%d",&iFlag);
	}

	printf("\nGraph is :-");
	Display(pGraph);

	DeleteGraph(&pGraph);

	Display(pGraph);

	return 0;
}

struct Vertex* InsertVertex(struct Vertex **ppGraph , int iNo)
{
	struct Vertex *pTemp = NULL;
	struct Vertex *pNewNode = NULL;

	pNewNode = SearchVertex(*ppGraph , iNo);
	if(pNewNode != NULL)
		return pNewNode;

	pNewNode = (struct Vertex *)malloc(sizeof(struct Vertex));
	if(NULL == pNewNode)
	{
		printf("\nMemory allocation Failed.");
		return NULL; 
	}

	pNewNode->iData = iNo;
	pNewNode->pAdjEdge = NULL;
	pNewNode->pNextVertex = NULL;

	if(NULL == (*ppGraph))
	{
		(*ppGraph) = pNewNode;
		return pNewNode;
	}

	pTemp = *ppGraph;

	while(pTemp->pNextVertex != NULL)
		pTemp = pTemp->pNextVertex;

	pTemp->pNextVertex = pNewNode;
	
	return pNewNode;
}

void InsertEdges(struct Vertex *pGraph , struct Vertex *pVertex , int iNo)
{
	int iVertex;
	int Counter;
	struct Edge *pNewNode = NULL;
	struct Vertex *pAdjVertex = NULL;
	struct Edge *pTemp = NULL;

	for(Counter = 0 ; Counter < iNo ; Counter++)
	{
		pNewNode = (struct Edge*)malloc(sizeof(struct Edge));

		printf("\nEnter Adjacent Vertex :- ");
		scanf("%d",&iVertex);

		pAdjVertex = SearchVertex(pGraph , iVertex);
		
		if(NULL == pAdjVertex)
			pAdjVertex = InsertVertex(&pGraph , iVertex);
		
		pNewNode->pAdjVertex = pAdjVertex;
		pNewNode->pNextEdge = NULL;
		
		if(NULL == pVertex->pAdjEdge)
		{
			pVertex->pAdjEdge = pNewNode;
			continue;
		}
		
		pTemp = pVertex->pAdjEdge;

		while(pTemp->pNextEdge != NULL)
			pTemp = pTemp->pNextEdge;

		pTemp->pNextEdge = pNewNode;
	}

}

struct Vertex* SearchVertex(struct Vertex *pGraph , int iVertex)
{
	if(pGraph == NULL)
		return NULL;

	while(pGraph != NULL)
	{
		if(pGraph->iData == iVertex)
			return pGraph;

		pGraph = pGraph->pNextVertex;
	}

	return NULL;
}

void Display(struct Vertex *pVertex)
{
	struct Edge *pEdge = NULL;

	if(NULL == pVertex)
	{
		printf("\nGraph is NULL.");
		return ;
	}

	while(pVertex != NULL)
	{
		printf("\n%d -> ",pVertex->iData);

		pEdge = pVertex->pAdjEdge;

		if(NULL == pEdge)
			printf("NULL.");
		else
		{
			while(pEdge != NULL)
			{
				printf("%d ",pEdge->pAdjVertex->iData);
				pEdge = pEdge->pNextEdge;
			}
		}

		pVertex = pVertex->pNextVertex;
	}
}

void DeleteGraph(struct Vertex **ppHead)
{
	struct Vertex *pVertex = *ppHead;
	struct Edge *pEdge = NULL;
	struct Edge *pTemp = NULL;

	while(*ppHead != NULL)
	{
		pEdge = pTemp = pVertex->pAdjEdge;

		*ppHead = pVertex->pNextVertex;

		pVertex->pAdjEdge = NULL;
		
		while(pEdge != NULL)
		{
			pTemp = pEdge;
			pEdge = pEdge->pNextEdge;

			pTemp->pAdjVertex = NULL;
			pTemp->pNextEdge = NULL;

			free(pTemp);
		}

		pVertex->pNextVertex = NULL;
		free(pVertex);

		pVertex = *ppHead;
	}
}
