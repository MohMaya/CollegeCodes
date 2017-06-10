// Program to implement a circular Link List

#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node* next;
}*s1,*temp,*newnode,*prv;


int ins(int sta,int dat)
{
        int pos,tm;
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=dat;
        newnode->next=NULL;
        temp=s1;
        if(s1==NULL)
        {
                s1=newnode;
                s1->next=s1;
                return 1;
        }
        if(sta==1)
        {
                newnode->next=s1->next;
                s1->next=newnode;
                tm=s1->data;
                s1->data=newnode->data;
                newnode->data=tm;
                return 1;

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
                while(temp->next!=s1)
                {
                        temp=temp->next;
                }
                temp->next=newnode;
                newnode->next=s1;
        }


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
        if(s1->data==dat)
        {
                if(s1->next==s1)
                     s1=NULL;
                else
                     {
                        s1->data=s1->next->data;
                        s1->next=s1->next->next;
                     }
                return 1;
        }
        temp=s1->next;
        while(temp->next!=s1)
        {
                if(temp->data==dat)
                {
                           temp->data=temp->next->data;
                           temp->next=temp->next->next;
                           return 1;
                }
                prv=temp;
                temp=temp->next;
        }
        if(temp->data==dat)
        {
              prv->next=s1;
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
        while(temp->next!=s1)
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
                printf("\n\nENter your Choice :\n1. Insert DATA\n2. Remove DATA\nANYTHING ELSE TO EXIT\n\n");
                scanf("%d",&ch);
                if(ch==1)
                {
                        while(1)
                        {
                                printf("\n\nEnter Where to enter :\n1. Insert in the beginning\n2. Insert at a given position\n3. Insert at the end\n\n");
                                scanf("%d",&sta);
                                if((sta>0)&&(sta<=3))
                                        break;
                                printf("\n\nInvalid Choice!!! Re-Enter");
                        }

                        printf("\n\nEnter the Number to be Inserted : ");
                        scanf("%d",&n);
                        ins(sta,n);
                        print();
               }
               else if(ch==2)
               {
                       printf("\n\nEnter the Number to be deleted");
                       scanf("%d",&n);
                       rem(n);
                       print();
               }
               else
                 break;
        }

}
