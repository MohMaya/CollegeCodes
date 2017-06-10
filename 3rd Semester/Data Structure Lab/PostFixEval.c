#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int stack[100];
int top=-1;
int c=0;
int pop()
{
	return stack[top--];
}
int push(int n)
{
	if(c==1)
	{
		int num;
	    num=pop();
	    stack[++top]=n+10*num;
	    
	}
	else if(c==0)
	{
		stack[++top]=n;
		c=1;
	}
}
int main()
{
	char post[20];
	char ch;
	int i=0,x,y;
	printf("enter postfix expression terminating with .\n");
	gets(post);
	while((ch=post[i++])!='.')
	{
		if(isdigit(ch))
		{push(ch-'0');
		}
		else if(ch==' ')
		{
			c=0;
		}
		else
		{
			c=0;
			y=pop();
			x=pop();
			switch(ch)
			{
				case '+':
					push(x+y);
					break;
				case '-':
					push(x-y);
					break;
				case '*':
					push(x*y);
					break;
				case '/':
				push(x/y);
				break;
			case '^':
				push(pow(x,y));
				break;
			default:
				printf("invalid input\n");
				return 0;
			}
		}
	}
	
	printf("Answer =%d\n",stack[top]);
	return 0;
}