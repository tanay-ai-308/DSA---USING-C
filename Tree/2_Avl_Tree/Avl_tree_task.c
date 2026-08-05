#include<stdio.h>
#include<stdlib.h>

struct Node
{	
	struct Node *pParent;
	struct Node *pLeft;
	int iData;
	struct Node *pRight;
};
	
int Height(struct Node *);
void Inorder(struct Node *);
void DisplayAVL(struct Node *);
void DeleteAll(struct Node **);
int BalanceFactor(struct Node *);
void LLRotation(struct Node **,struct Node *);
void RRRotation(struct Node **,struct Node *);
void LRRotation(struct Node **,struct Node *);
void RLRotation(struct Node **,struct Node *);
struct Node * InsertBST(struct Node ** , int);
struct Node *FindPivotElement(struct Node *,char *,int *);

int main (void)
{
	int iNo = 1;
	char chFlag;
	int iBalanceFactor;
	struct Node *pRoot = NULL;
	struct Node *pNewNode = NULL;
	struct Node *pPivotNode = NULL;

	printf("\n\t===== Enter '0' to stop accepting number =====\n");

	while(iNo)
	{
		printf("\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\nEnter a number = ");
		scanf("%d",&iNo);
		
		if (iNo == 0)
			break;

		pNewNode = InsertBST(&pRoot,iNo);
			
		pPivotNode = FindPivotElement(pNewNode,&chFlag,&iBalanceFactor);
	
		if(iBalanceFactor == -2)	// RIGHT HEAVY
		{
			if(chFlag =='l')
			{
				printf("\nCALLIIN RL");
				RLRotation(&pRoot, pPivotNode);
			}
			else if(chFlag == 'r')
				RRRotation(&pRoot, pPivotNode);
		}
		else if(iBalanceFactor == 2)	//LEFT HEAVY
		{
			if(chFlag == 'r')
			{
				printf("\nCALLIIN LR");
				LRRotation(&pRoot, pPivotNode);
			}
			else if(chFlag == 'l')
				LLRotation(&pRoot, pPivotNode);
		}
	}

	DisplayAVL(pRoot);
	printf("\nInorder is : \n\t");
	Inorder(pRoot);
	printf("\n");

	if(pRoot != NULL)
	{
		DeleteAll(&pRoot);
		pRoot = NULL;
	}

	return 0;
}

struct Node* InsertBST(struct Node **ppRoot, int iData)
{
	struct Node *pTemp = *ppRoot;
	struct Node *pParent = NULL;
	struct Node *pNewNode = NULL;

	while(pTemp != NULL)
	{
		pParent = pTemp;
		if(iData < pTemp->iData)
			pTemp = pTemp->pLeft;
		else if(iData > pTemp->iData)
			pTemp = pTemp->pRight;
		else
		{
			printf("\nDuplicate Data");
			return NULL;
		}
	}

	pNewNode = (struct Node *)malloc(sizeof(struct Node));

	if(NULL == pNewNode)
	{
		printf("\nMemory Allocation Failed.");
		return NULL;
	}

	pNewNode->iData = iData;
	pNewNode->pLeft = pNewNode->pRight = NULL;
	pNewNode->pParent = pParent;

	if(NULL == pParent)
		*ppRoot = pNewNode;
	else if(iData < pParent->iData)
		pParent->pLeft = pNewNode;
	else
		pParent->pRight = pNewNode;

	return pNewNode;
}

struct Node *FindPivotElement(struct Node * pNewNode ,char *pchFlag ,int *piBalanceFactor)
{
    struct Node *pTemp = pNewNode;

    while(pTemp != NULL)
    {
        *piBalanceFactor = BalanceFactor(pTemp);

        if(*piBalanceFactor == 2)
        {
            if(BalanceFactor(pTemp->pLeft) < 0)
                *pchFlag = 'r';
            else
                *pchFlag = 'l';

            return pTemp;
        }
        else if(*piBalanceFactor == -2)
        {
            if(BalanceFactor(pTemp->pRight) > 0)
                *pchFlag = 'l';
            else
                *pchFlag = 'r';

            return pTemp;
        }

        pTemp = pTemp->pParent;
    }

    return NULL;
}

void LLRotation(struct Node **ppRoot, struct Node *pGParent)
{
	struct Node *pTemp = pGParent->pLeft;
	
	if(pTemp->pLeft == NULL && pTemp->pRight == NULL)
	{
		pTemp->pRight = pGParent->pRight;
		pGParent->pRight = pTemp;
		pGParent->pRight = pTemp->pLeft;
		if(pTemp->pRight != NULL)
			pTemp->pRight->pParent = pTemp;
	}
	else
	{
		if(NULL == pGParent->pParent)
		{
			*ppRoot = pTemp;
			pTemp->pParent = NULL;
		}
		else
			pTemp->pParent = pGParent->pParent;

		pGParent->pParent = pTemp;
		pGParent->pLeft = pTemp ->pRight;
		pTemp->pRight = pGParent;
	}  
}

void RRRotation(struct Node **ppRoot, struct Node *pGParent)
{
	struct Node *pTemp = pGParent->pRight;

	if(pTemp->pLeft == NULL && pTemp->pRight == NULL)
	{
		pTemp->pLeft = pGParent->pLeft;
		pGParent->pLeft = pTemp;
		pGParent->pLeft = pTemp->pRight;
		if(pTemp->pLeft != NULL)
			pTemp->pLeft->pParent = pTemp;
	}
	else
	{
		if(NULL == pGParent->pParent)
		{
			*ppRoot = pTemp;
			pTemp->pParent = NULL;
		}
		else
			pTemp->pParent = pGParent->pParent;

		pGParent->pParent = pTemp;
		pGParent->pRight = pTemp ->pLeft;
		pTemp->pLeft = pGParent;
	}
}

void LRRotation(struct Node **ppRoot, struct Node *pGParent)
{
	RRRotation(ppRoot, pGParent->pLeft);
    LLRotation(ppRoot, pGParent);
}

void RLRotation(struct Node **ppRoot, struct Node *pGParent)
{
	LLRotation(ppRoot, pGParent->pRight);
	RRRotation(ppRoot,pGParent);
}

int BalanceFactor(struct Node *pNewNode)
{
	return Height(pNewNode->pLeft)-Height(pNewNode->pRight);
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

void Inorder(struct Node *pRoot)
{
	if(NULL == pRoot)
		return;

	Inorder(pRoot->pLeft);
	printf("\t%d",pRoot->iData);
	Inorder(pRoot->pRight);
}

void DisplayAVL(struct Node *pRoot)
{
    if(pRoot == NULL)
        return;

    printf("\n========================================");
    printf("\nNode Address      : %p", (void*)pRoot);
    printf("\nData              : %d", pRoot->iData);

    if(pRoot->pParent != NULL)
        printf("\nParent Address    : %p [%d]",
                (void*)pRoot->pParent,
                pRoot->pParent->iData);
    else
        printf("\nParent Address    : NULL");

    if(pRoot->pLeft != NULL)
        printf("\nLeft Child Address: %p [%d]",
                (void*)pRoot->pLeft,
                pRoot->pLeft->iData);
    else
        printf("\nLeft Child Address: NULL");

    if(pRoot->pRight != NULL)
        printf("\nRight Child Addr  : %p [%d]",
                (void*)pRoot->pRight,
                pRoot->pRight->iData);
    else
        printf("\nRight Child Addr  : NULL");

    printf("\nBalance Factor    : %d",
            BalanceFactor(pRoot));

    DisplayAVL(pRoot->pLeft);
    DisplayAVL(pRoot->pRight);
}

void DeleteAll(struct Node **ppRoot)
{
	if(*ppRoot == NULL)
		return ;

	DeleteAll(&((*ppRoot)->pLeft));
	DeleteAll(&((*ppRoot)->pRight));

	(*ppRoot)->pLeft=NULL;
	(*ppRoot)->pRight=NULL;
	(*ppRoot)->pParent=NULL;

	free(*ppRoot);
	*ppRoot = NULL;
}