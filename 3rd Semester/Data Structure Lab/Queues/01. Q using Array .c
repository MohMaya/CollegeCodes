//Implementation of Linear Queue using Array[Global Variables]
//This code even shows the flaw in the concept of implementing Linear Queues Using array

#include<stdio.h>
#include<stdlib.h>

#define MAX 20


int A[MAX];
int front=0,rear=0;

int enq(int dat)
{
        if(rear==MAX)
        {
                printf("\n\nQueue Full");
                return 1;
        }
        A[rear++]=dat;
        return 1;

}


int deq()
{
        if(front==0&&rear==0)
        {
                printf("\n\nQueue Empty!! Nothin to dequeue");
                return 1;
        }

        printf("\n\n%d Dequeued",A[front]);
        A[front++]=38629;

        if(front>=rear)
        {
                front=0;
                rear=0;
                return 1;
        }
        return 1;

}


int prin()
{
        int i;
        printf("\n\nNow the queue is :\n\n");

        for(i=0;i<MAX-1;i++)
        {
                if(A[i]==38629)
                        printf("|   |->");
                else
                        printf("| %d |->",A[i]);
        }
        if(A[i]==38629)
                printf("|   |");
        else
                printf("| %d |",A[i]);
        return 1;
}

int main()
{
        int ch,n;
        for(n=0;n<MAX;n++)
        {
                A[n]=38629;
        }
        while(1)
        {
                printf("\n\nEnter Your Choice :\n1. Enqueue\n2. Dequeue\nAny other number to exit\n");
                scanf("%d",&ch);
                if(ch==1)
                {
                        printf("\nEnter The Number to be Inserted : ");
                        scanf("%d",&n);
                        enq(n);
                        prin();
                }
                else if(ch==2)
                {
                        deq();
                        prin();
                }
                else
                        break;

        }
        printf("\n\nThank You");
}
