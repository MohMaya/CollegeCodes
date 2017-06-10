//Program to Take a linked list from user and Then Ask him to enter value of N thereby printing Nth Value in LL from End
#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node* next;
}*s1,*temp,*newnode,*prv;
//int c=0;

int fin(int n)
{
        int d=n;
        --n;
        temp=s1;
        while(temp!=NULL && n>0 )
        {
                temp=temp->next;
                n--;
        }
        if(temp==NULL)
        {
                printf("\n\nN larger than allowable");
                return 1;
        }
        prv=s1;
        while(temp->next!=NULL)
        {
                prv=prv->next;
                temp=temp->next;
        }
        printf("\n\n%dth element from last is : %d",d,prv->data);
        return 1;
}

int ins(int sta,int dat)
{
        int pos;
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=dat;
        newnode->next=NULL;
        temp=s1;
        if(s1==NULL)
        {
                s1=newnode;
                return 1;
        }
        if(sta==1)
        {
                newnode->next=s1;
                s1=newnode;
        }
        else if(sta==2)
        {
                printf("\n\nEnter the Position ");
                scanf("%d",&pos);
                if(pos==1)
                {
                        ins(1,dat);
                        return 1;
                }
                while((pos>1)&&(temp!=NULL))
                {
                        prv=temp;
                        temp=temp->next;

                        pos--;
                }
                prv->next=newnode;
                newnode->next=temp;

        }
        else
        {
                while(temp->next!=NULL)
                {
                        temp=temp->next;
                }
                temp->next=newnode;
        }
//        c++;


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
                printf("\n\nENter your Choice :\n1. Insert DATA\n2. Remove DATA\n3. Print Nth Element from Last\nANYTHING ELSE TO EXIT\n\n");
                scanf("%d",&ch);
                if(ch==1)
                {

                        printf("\n\nEnter the Number to be Inserted : ");
                        scanf("%d",&n);
                        ins(3,n);
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
                       printf("\n\nEnter the value of N : ");
                       scanf("%d",&n);
                       fin(n);
                       print();

               }
               else
                 break;
        }

}

