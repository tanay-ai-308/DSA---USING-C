#include<stdio.h>
#include<malloc.h>
#include"queue.h"	//struct Queue ,declaration of Queue Function

struct Node
{
	struct Node *pLeft;
	int iData;
	struct Node *pRight;
};

//X===========================X FUNCTION DECLARATION X===========================X

int Height(struct Node *);								
void Inorder(struct Node *);
void Preorder(struct Node *);
void Postorder(struct Node *);
int LargestBST(struct Node *);
int SmallestBST(struct Node *);
void Levelorder(struct Node *);
void DeleteAll(struct Node **);
int CountNodesV1(struct Node *);
int CountNodesV2(struct Node *);
int CountLeafNodes(struct Node *);
void DeleteBST(struct Node ** , int);
void InsertBST(struct Node ** , int);
int CountNonLeafNodes(struct Node *);
struct Node* SearchBSTRecursive(struct Node * , int);
struct Node* SearchBSTNonRecursive(struct Node * , int);

//X==========================================================================X

int main (void)
{
	struct Node *pPtr = NULL;
	struct Node *pRoot = NULL;

	InsertBST(&pRoot , 100);
	InsertBST(&pRoot , 45);
	InsertBST(&pRoot , 121);						
	InsertBST(&pRoot , 150);
	InsertBST(&pRoot , 9);
	InsertBST(&pRoot , 130);
	InsertBST(&pRoot , 50);
	InsertBST(&pRoot , 170);

	printf("\nPreorder is : \n\t");								
	Preorder(pRoot);

	printf("\nInorder is : \n\t");
	Inorder(pRoot);

	printf("\nPostorder is :\n\t");
	Postorder(pRoot);

	printf("\nLevelorder is :\n\t");
	Levelorder(pRoot);

	printf("\n\nNode Count by v1 is - %d.",CountNodesV1(pRoot));
	printf("\nNode Count by v2 is - %d.",CountNodesV2(pRoot));

	printf("\n\nLeaf node count is - %d.",CountLeafNodes(pRoot));
	printf("\nNonleaf node count is - %d.",CountNonLeafNodes(pRoot));

	printf("\n\nHeight of tree is - %d.",Height(pRoot));

	printf("\n\nLargest element is - %d.",LargestBST(pRoot));
	printf("\nSmallest element is - %d.",SmallestBST(pRoot));

	pPtr = SearchBSTRecursive(pRoot , 50);
	if(pPtr != NULL)
		printf("\n\n%d found at %d address.",pPtr->iData , pPtr);

	pPtr = SearchBSTNonRecursive(pRoot , 50);
	if(pPtr != NULL)
		printf("\n%d found at %d address.",pPtr->iData , pPtr);

	DeleteBST(&pRoot , 50);
	printf("\n\nLevelorder is :\n\t");
	Levelorder(pRoot);

	DeleteBST(&pRoot , 121);
	printf("\n\nLevelorder is :\n\t");
	Levelorder(pRoot);
	
	DeleteBST(&pRoot , 150);
	printf("\n\nLevelorder is :\n\t");
	Levelorder(pRoot);

	if(pRoot != NULL)
	{
		DeleteAll(&pRoot);
		pRoot = NULL;
	}

	return 0;
}
//X=====================================X OUTPUT X=====================================X
/*
Preorder is :
                100     45      9       50      121     150     130     170
Inorder is :
                9       45      50      100     121     130     150     170
Postorder is :
                9       50      45      130     170     150     121     100
Levelorder is :
                100     45      121     9       50      150     130     170

Node Count by v1 is - 8.
Node Count by v2 is - 8.

Leaf node count is - 4.
Nonleaf node count is - 4.

Height of tree is - 4.

Largest element is - 170.
Smallest element is - 9.

50 found at 18693368 address.
50 found at 18693368 address.

Levelorder is :
                100     45      121     9       150     130     170

Levelorder is :
                100     45      150     9       130     170

Levelorder is :
                100     45      170     9       130
*/

//X================================X FUNCTION DEFINATION X================================X

void Preorder(struct Node *pRoot)
{
	if(NULL == pRoot)
		return;

	printf("\t%d",pRoot->iData);
	Preorder(pRoot->pLeft);
	Preorder(pRoot->pRight);
}

void Inorder(struct Node *pRoot)
{
	if(NULL == pRoot)
		return;

	Inorder(pRoot->pLeft);
	printf("\t%d",pRoot->iData);
	Inorder(pRoot->pRight);
}

void Postorder(struct Node *pRoot)
{
	if(NULL == pRoot)
		return;

	Postorder(pRoot->pLeft);
	Postorder(pRoot->pRight);
	printf("\t%d",pRoot->iData);
}

void Levelorder(struct Node *pRoot)
{
	struct Queue *pFirst = NULL;
	struct Node *pPtr = NULL;

	if(NULL == pRoot)
		return;
	
	EnQueue(pRoot , &pFirst);

	while(!IsEmpty(pFirst))
	{	
		pPtr = DeQueue(&pFirst);
		printf("\t%d",pPtr->iData);
		EnQueue(pPtr->pLeft , &pFirst);
		EnQueue(pPtr->pRight , &pFirst);
	}
}

void DeleteAll(struct Node **ppRoot)
{
	if(*ppRoot == NULL)
		return ;

	DeleteAll(&((*ppRoot)->pLeft));
	DeleteAll(&((*ppRoot)->pRight));

	free(*ppRoot);
	*ppRoot = NULL;
}

int CountNodesV1(struct Node *pRoot)
{
	static int iCount; 
	if(NULL == pRoot)
		return 0;

	iCount++;
	CountNodesV1(pRoot->pLeft);
	CountNodesV1(pRoot->pRight);

	return iCount;
}

int CountNodesV2(struct Node *pRoot)
{
	if(NULL == pRoot)
		return 0;

	return 	CountNodesV2(pRoot->pLeft) + CountNodesV2(pRoot->pRight) + 1;
}

int CountLeafNodes(struct Node *pRoot)
{
	static int iCount = 0;

	if(NULL == pRoot)
		return 0;

	if(pRoot->pLeft == NULL && pRoot->pRight == NULL)
		iCount++;

	CountLeafNodes(pRoot->pLeft);
	CountLeafNodes(pRoot->pRight);

	return iCount;
}

int CountNonLeafNodes(struct Node *pRoot)
{
	static int iCount = 0; 
	if(NULL == pRoot)
		return 0;

	if(pRoot->pLeft != NULL || pRoot->pRight != NULL)
		iCount++;

	CountNonLeafNodes(pRoot->pLeft);
	CountNonLeafNodes(pRoot->pRight);

	return iCount;
}

int LargestBST(struct Node *pRoot)
{
	static int iMax;

	if(NULL == pRoot)
		return 0;

	if(iMax<pRoot->iData)
		iMax=pRoot->iData;

	LargestBST(pRoot->pLeft);
	LargestBST(pRoot->pRight);

	return iMax;
}

int SmallestBST(struct Node *pRoot)
{
	static int iMin;

	if(NULL == pRoot)
		return 0;

	if(!iMin)
		iMin = pRoot->iData;

	if(iMin > pRoot->iData)
		iMin=pRoot->iData;

	SmallestBST(pRoot->pLeft);
	SmallestBST(pRoot->pRight);

	return iMin;
}

struct Node* SearchBSTRecursive(struct Node *pRoot , int iKey)
{
	if(pRoot == NULL)
		return NULL;

	if(iKey < pRoot->iData)
		return SearchBSTRecursive(pRoot->pLeft , iKey);
	else if(iKey > pRoot->iData)
		return SearchBSTRecursive(pRoot->pRight , iKey);
	else
		return pRoot;
}

struct Node* SearchBSTNonRecursive(struct Node *pRoot , int iKey)
{
	while(pRoot != NULL)
	{
		if(iKey < pRoot->iData)
			pRoot = pRoot->pLeft;
		else if(iKey > pRoot->iData)
			pRoot = pRoot->pRight;
		else
			return pRoot;
	}
	return NULL;
}

int Height(struct Node *pRoot)
{
	int iLeftHeight;
	int iRightHeight;

	if(pRoot == NULL)
		return 0;

	iLeftHeight = Height(pRoot->pLeft);
	iRightHeight = Height(pRoot->pRight);

	if(iLeftHeight > iRightHeight)
		return iLeftHeight+1;
	else
		return iRightHeight+1;
}

void InsertBST(struct Node **ppRoot , int iData)
{
	struct Node *pPtr = *ppRoot;
	struct Node *pParent = NULL;
	struct Node *pNewNode = NULL;

	while(pPtr != NULL)
	{
		pParent = pPtr;
		if(iData < pPtr->iData)
			pPtr = pPtr->pLeft;
		else if(iData > pPtr->iData)
			pPtr = pPtr->pRight;
		else
		{
			printf("\nDuplicate Data");
			return ;
		}
	}

	pNewNode = (struct Node *)malloc(sizeof(struct Node));

	if(NULL == pNewNode)
	{
		printf("\nMemory Allocation Failed.");
		return;
	}

	pNewNode->iData = iData;
	pNewNode->pLeft = pNewNode->pRight = NULL;

	if(NULL == pParent)
		*ppRoot = pNewNode;
	else if(iData < pParent->iData)
		pParent->pLeft = pNewNode;
	else
		pParent->pRight = pNewNode;
}

void DeleteBST(struct Node **ppRoot , int iKey)
{
	struct Node *pChild = NULL;
	struct Node *pParent = NULL;
	struct Node *pPtr = *ppRoot;
	struct Node *pSuccessor = NULL;

	while(pPtr != NULL)
	{
		if(pPtr->iData == iKey)
			break;
		pParent = pPtr;

		if(iKey < pPtr->iData)
			pPtr = pPtr->pLeft;
		else
			pPtr = pPtr->pRight;
	}

	if(NULL == pPtr)
		return;

	if(pPtr->pLeft != NULL && pPtr->pRight != NULL)
	{
		pSuccessor = pPtr->pRight;
		pParent = pPtr;

		while(pSuccessor->pLeft != NULL)
		{
			pParent = pSuccessor;
			pSuccessor = pSuccessor->pLeft;
		}

		pPtr->iData = pSuccessor->iData;
		pPtr = pSuccessor;
	}

	if(pPtr->pLeft != NULL)
		pChild = pPtr->pLeft;
	else
		pChild = pPtr->pRight;

	if(NULL == pParent)
		*ppRoot = pChild;
	else if(pPtr == pParent->pLeft)
		pParent->pLeft = pChild;
	else
		pParent->pRight = pChild;

	free(pPtr);
}
