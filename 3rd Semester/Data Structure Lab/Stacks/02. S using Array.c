//Implementation of Stack using Array[Global Variables]

#include<stdio.h>
#include<stdlib.h>

#define MAX 20


int A[MAX];
int top=0;

int push(int dat)
{
        if(top==MAX)
        {
                printf("\n\nOverflow Error");
                return 1;
        }
        A[top++]=dat;
        return 1;

}


int pop()
{
        if(top==0)
        {
                printf("\n\nUnderflow Error");
                return 1;
        }

        printf("\n\n%d Popped",A[--top]);



        return 1;

}


int prin()
{
        int i=top-1;
        printf("\n\nNow the stack is :\n\n");
        if(top==0)
        {
                printf(" EMPTY");
                return 1;
        }
        printf("| %d |\n",A[i]);
        for(i=top-2;i>=0;i--)
        {
                printf("| %d |\n",A[i]);
        }
        //printf("| %d |",A[i]);
        return 1;
}

int main()
{
        int ch,n;

        while(1)
        {
                printf("\n\nEnter Your Choice :\n1. Push\n2. Pop\nAny other number to exit\n");
                scanf("%d",&ch);
                if(ch==1)
                {
                        printf("\nEnter The Number to be Inserted : ");
                        scanf("%d",&n);
                        push(n);
                        prin();
                }
                else if(ch==2)
                {
                        pop();
                        prin();
                }
                else
                        break;

        }
        printf("\n\nThank You");
}

