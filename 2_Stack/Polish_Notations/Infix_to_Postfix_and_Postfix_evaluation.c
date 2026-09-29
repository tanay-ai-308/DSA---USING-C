#include<stdio.h>
#include<math.h>
#include"stack.h"

#define MAX 50

int IsSpace(char);
int IsOperator(char);
long int PostFixEvaluation(const char *);
void InfixToPostfix(const char * , char *);

int main(void)
{
	long int iResult;
	char szInfix[MAX];
	char szPostfix[MAX];

	printf("Enter arithmatic expression :- \n\t");
	gets(szInfix);

	InfixToPostfix(szInfix , szPostfix);

	printf("\nPost fix string is :- \n\t");
	puts(szPostfix);

	iResult = PostFixEvaluation(szPostfix);

	printf("  ");
	puts(szInfix);
	printf("-> %d.",iResult);

	return 0;
}

void InfixToPostfix (const char *pszInFix , char *pszPostfix)
{
	int iCounter1;
	int iCounter2;
	char chSymbol;
	int iPriority;

	extern long int g_Stack[STACK_MAX];
	extern int g_iTop;

	iCounter2 = 0;

	for(iCounter1 = 0 ; pszInFix[iCounter1] != '\0' ; iCounter1++)
	{
		chSymbol = pszInFix[iCounter1];

		if(IsSpace(chSymbol))
			continue;

		if((iPriority = IsOperator(chSymbol)) != 0)
		{
			while((!IsEmpty()) && IsOperator(g_Stack[g_iTop]) >= iPriority)
				pszPostfix[iCounter2++] = Pop();

			Push(chSymbol);
		}
		else
		{
			if(chSymbol == '(')
				Push(chSymbol);
			else if(chSymbol == ')')
			{
				while((chSymbol = Pop()) != '(')
					pszPostfix[iCounter2++] = chSymbol;
			}
			else
			{
				pszPostfix[iCounter2++] = '[';
				while(1)
				{
					pszPostfix[iCounter2++] = chSymbol;

					chSymbol = pszInFix[++iCounter1];
					if(IsOperator(chSymbol) || chSymbol == '(' || chSymbol == ')' || chSymbol == '\0')
						break ;
				}

				pszPostfix[iCounter2++] = ']';
				iCounter1--;
			}
		}
	}

	while(!IsEmpty())
		pszPostfix[iCounter2++] = Pop();

	pszPostfix[iCounter2] = '\0';
}

long int PostFixEvaluation (const char *pszPostfix)
{
	int iCounter1;
	int iCounter2;
	char chSymbol;
	char szTemp[10];

	for(iCounter1 = 0 ; pszPostfix[iCounter1] != '\0' ; iCounter1++)
	{
		chSymbol = pszPostfix[iCounter1];

		if(chSymbol == '[')
		{
			iCounter2 = 0;
			while((chSymbol = pszPostfix[++iCounter1]) != ']')
				szTemp[iCounter2++] = chSymbol;

			szTemp[iCounter2] = '\0';

			Push(atoi(szTemp));
		}
		else
		{
			long int lAns;
			long int lOperand1;
			long int lOperand2;

			lOperand2 = Pop();
			lOperand1 = Pop();

			switch(chSymbol)
			{
				case '+' :
					lAns = lOperand1 + lOperand2;
					break ;
				case '-' :
					lAns = lOperand1 - lOperand2;
					break ;
				case '*' :
					lAns = lOperand1 * lOperand2;
					break ;
				case '/' :
					lAns = lOperand1 / lOperand2;
					break ;
				case '%' :
					lAns = lOperand1 % lOperand2;
					break ;
				case '^' :
					lAns = pow(lOperand1 , lOperand2);
					break ;
			}

			Push(lAns);
		}
	}

	return Pop();
}

int IsSpace(char chSymbol)
{
	if(chSymbol == ' ' || chSymbol == '\t')
		return 1;
	return 0;
}

int IsOperator(char chSymbol)
{
	switch(chSymbol)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
			return 3;
		default :
			return 0;
	}
}