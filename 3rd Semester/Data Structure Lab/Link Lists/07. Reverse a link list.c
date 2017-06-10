//Program to reverse the linklist
//Two options to choose from 1.Via For loop(iteration) 2. Via Recursion


#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node* next;
}*s1,*temp,*newnode,*prv,*curr;


int ins(int dat)
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



}



int print()
{
        temp=s1;
        if(temp==NULL)
        {
                printf("\n\nThe List is empty ");
                return 1;
        }
        printf("\n\nThe List Is :\n\n");
        while(temp->next!=NULL)
        {
                printf("|%d|->",temp->data);
                temp=temp->next;
        }
        printf("|%d|",temp->data);
        return 1;
}

void recrev(struct node *p,struct node *c)
{
        if(c==NULL)
        {
                s1=p;
                return ;
        }
        temp=c->next;
        recrev(c,temp);
        c->next=p;
        return ;
}

int main()
{
        int ch,n,sta;
        s1=(struct node *)malloc(sizeof(struct node));
        s1=NULL;
        while(1)
        {
                printf("\n\nENter your Choice :\n1. Insert DATA\n2. Reverse VIA Iteration\n3. Reverse via Recursion\nANYTHING ELSE TO EXIT\n\n");
                scanf("%d",&ch);
                if(ch==1)
                {
                        printf("\n\nEnter the Number to be Inserted : ");
                        scanf("%d",&n);
                        ins(n);
                        print();
               }
               else if(ch==2)
               {
                       prv=NULL;
                       curr=s1;
                       while(curr!=NULL)
                       {
                               temp=curr->next;
                               curr->next=prv;
                               prv=curr;
                               curr=temp;
                       }
                       s1=prv;
                       print();
               }
               else if(ch==3)
               {
                       recrev(NULL,s1);
                       print();
               }
               else
                 break;
        }

}
