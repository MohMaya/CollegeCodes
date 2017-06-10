//Program to Find the Middle Element of a link list
#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node* next;
}*s1,*temp,*newnode,*prv;


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


int rem(int dat)
{
        temp=s1;
        if(temp==NULL)
        {
                printf("\n\n%d Not Found in LIST  ",dat);
                return 1;
        }
        prv=temp;
        while(temp!=NULL)
        {
                if(temp->data==dat)
                {
                           if(temp==s1)
                           {
                                   s1=s1->next;
                                   return 1;
                           }
                           prv->next=temp->next;
                           return 1;
                }
                prv=temp;
                temp=temp->next;
        }
        printf("\n\n%d Not Found in LIST  ",dat);


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


int main()
{
        int ch,n,sta;
        s1=(struct node *)malloc(sizeof(struct node));
        s1=NULL;
        while(1)
        {
                printf("\n\nENter your Choice :\n1. Insert DATA\n2. Remove DATA\n3. Print the middle Element of the Link List\nANYTHING ELSE TO EXIT\n\n");
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
                       printf("\n\nEnter the Number to be deleted");
                       scanf("%d",&n);
                       rem(n);
                       print();
               }
               else if(ch==3)
               {
                       n=0;
                       temp=s1;
                       prv=temp;
                       while(temp->next!=NULL)
                       {
                               if((n++)%2==0)
                                  prv=prv->next;
                               temp=temp->next;
                       }
                       printf("\n\nThe Middle Element is %d .",prv->data);
               }
               else
                  break;
        }

}

