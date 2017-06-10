//Queue using Link Lists
#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
}*s1,*temp;

int enqueue(int dat)
{
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=dat;
        newnode->next=NULL;
        temp=s1;
        if(s1==NULL)
        {
                s1=newnode;
                return 1;
        }
        while(temp->next!=NULL)
        {
                temp=temp->next;
        }
        temp->next=newnode;
        return 1;
}



int dequeue()
{
        if(s1==NULL)
        {
                printf("\n\nQueue Empty Error");
                return 1;
        }
        printf("\n\n%d Dequeued : ",s1->data);
        //if(s1->next==NULL)
        //        s1=NULL;
        s1=s1->next;
        return 1;
}



int print()
{
        temp=s1;
        if(temp==NULL)
        {
                printf("\n\nThe Queue is empty ");
                return 1;
        }
        printf("\n\nThe Queue Is :\n\n");
        while(temp->next!=NULL)
        {
                printf("|%d|->",temp->data);
                temp=temp->next;
        }
        printf("|%d|",temp->data);
        return 1;

}



int main()
{
        int ch,n;
        s1=(struct node *)malloc(sizeof(struct node));
        s1=NULL;
        while(1)
        {
                printf("\n\nENter your Choice :\n1. Enqueue\n2. Dequeue\nANYTHING ELSE TO EXIT\n\n");
                scanf("%d",&ch);
                if(ch==1)
                {
                        printf("\n\nEnter the Number to be Enqueued : ");
                        scanf("%d",&n);
                        enqueue(n);
                        print();
               }
               else if(ch==2)
               {
                       dequeue();
                       print();
               }
               else
                 break;
        }

}
