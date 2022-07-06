/* Apply stack to perform infix to postfix */

#include<stdio.h>
#include<ctype.h>
#define n 50

int top=-1;
int stack[n];

void push(char val)
{	top++;
	stack[top]=val;
}

char pop()
{	
	char x;
	x=stack[top];
	top--;
	return x;
	
}

int precedence(char symb)
{
	switch(symb)
	{
		case '/':
		{
			return 2;
		}
		
		case '*':
		{
			return 2;
		}
		
		case '+':
		{
			return 1;
		}
		
		case '-':
		{
			return 1;
		}
		
		default:
		{
			return 0;
		}
	}
}

void main()
{
	char exp[100],arr[100];
	char *ptr,a,b;
	int i=0,j;
	printf("Enter the expression ");
	scanf("%s",exp);
	ptr=exp;
	while(*ptr!='\0')
	{
		if(isdigit(*ptr) || isalpha(*ptr))
		{
			arr[i]=*ptr;
			i++;
		}
		else
		{
			a=pop();
		
			if(precedence(*ptr)>=precedence(a))
			{
				push(a);
				push(*ptr);
				
			}
			else
			{
				arr[i]=a;
				i++;
				while(top!=-1)
				{
					
					arr[i]=pop();
					i++;
				}
				push(*ptr);
			}
		}
		ptr++;
	}
	while(top!=-1)

		{
			arr[i]=pop();
			i++;
		}
	
	for(i=0;arr[i]!='\0';i++)
	{
		printf("%c",arr[i]);
		
	}
}
				
