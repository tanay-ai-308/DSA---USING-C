#include<stdio.h>
#include"stack.h"

#define MAX 50

int IsOpeningBracket(char);
int IsCloseingBracket(char);
int BracketValidation(const char *);

int main(void)
{
	char szStr[MAX];

	printf("Enter expression :- \n\t");
	gets(szStr);

	if(BracketValidation(szStr))
		printf("\nInvalide Bracket.");
	else
		printf("\nValide Bracket.");

	return 0;
}

int BracketValidation(const char *pszStr)
{
	int iCounter;
	char chSymbol;
	int iPriority;

	extern int g_Stack[STACK_MAX];
	extern int g_iTop;

	for(iCounter = 0 ; pszStr[iCounter] != '\0' ; iCounter++)
	{
		chSymbol = pszStr[iCounter];

		if(IsOpeningBracket(chSymbol))
			Push(chSymbol);
		else if(iPriority = IsCloseingBracket(chSymbol))
				if(IsOpeningBracket(g_Stack[g_iTop]) == iPriority)
					Pop();
				else
					return 1;
		else
			continue ;
	}
	if(IsEmpty())
		return 0;
	return 1;
}

int IsOpeningBracket(char chSymbol)
{
	switch(chSymbol)
	{
		case '(':
			return 1;
		case '[':
			return 2;
		case '{':
			return 3;
		case '<' :
			return 4;
		default :
			return 0;
	}
}

int IsCloseingBracket(char chSymbol)
{
	switch(chSymbol)
	{
		case ')':
			return 1;
		case ']':
			return 2;
		case '}':
			return 3;
		case '>' :
			return 4;
		default :
			return 0;
	}
}