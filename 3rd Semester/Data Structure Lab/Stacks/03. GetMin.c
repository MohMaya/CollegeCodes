//stack based program such that he function returning min of the element stack is constant tym
#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
}*s1,*temp,*s2;

int Push(int sta,int dat)
{
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=dat;
        newnode->next=NULL;
        if(sta==1)
                temp=s1;
        else
                temp=s2;
        if(s1==NULL&&sta==1)
        {
                s1=newnode;
                return 1;
        }
        if(s2==NULL&&sta==2)
        {
                s2=newnode;
                return 1;
        }

        if(sta==1)
         {
                newnode->next=s1;
                s1=newnode;
         }
        else
        {
               newnode->next=s2;
               s2=newnode;
        }

        return 1;
}



int pop()
{
        if(s1==NULL)
        {
                printf("\n\nStack UnderFlow Error");
                return 1;
        }
        printf("\n\n%d Popped",s1->data);
        //if(s1->next==NULL)
        //        s1=NULL;
        s1=s1->next;
        s2=s2->next;
        return 1;
}



int print(int sta)
{
        if(sta==1)
                temp=s1;
        else
                temp=s2;
        if(temp==NULL)
        {
                printf("\n\nThe stack %d is empty ",sta);
                return 1;
        }
        printf("\n\nThe Stack %d Is :\n\n",sta);
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
        int ch,n,min=605876;
        s1=(struct node *)malloc(sizeof(struct node));
        s1=NULL;
        s2=NULL;
        while(1)
        {
                printf("\n\nENter your Choice :\n1. Push Into Stack\n2. Pop from stack\n3. Get Min\nANYTHING ELSE TO EXIT\n\n");
                scanf("%d",&ch);
                if(ch==1)
                {
                        printf("\n\nEnter the Number to be pushed : ");
                        scanf("%d",&n);
                        Push(1,n);

                        if(n<min)
                                Push(2,n);
                        else
                                Push(2,s2->data);
                        min=s2->data;
                        print(1);
                        print(2);
               }
               else if(ch==2)
               {
                       pop();
                       print(1);
                       print(2);
               }
               else if(ch==3)
               {
                       printf("\n\n%d is the minimum data.",s2->data);
               }
               else
                 break;
        }

}
