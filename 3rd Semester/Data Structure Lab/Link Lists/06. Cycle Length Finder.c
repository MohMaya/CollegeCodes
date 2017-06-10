//Program to Print CycleLength if cycle is present in a LL
//Demoed BY creating a LL of Size 7 where there is loop 3rd element onwards


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
        newnode->next=s1;
        s1=newnode;


}


int fin()
{
        int n=0;
        temp=s1;
        prv=s1;
        while(temp!=NULL)
        {
                if(n%2==1)
                        prv=prv->next;
                temp=temp->next;
                n++;
                if(temp==prv)
                {
            //            printf("\n\nLoop Present");
                        return 1;
                }

        }
     //   printf("\n\nNo loops Exist");
        return 0; // if no loop exists, temp will reach NULL thereby exiting the loop
}

int sf(int x)
{
        temp=s1;
        prv=s1;
        while((x--)>=0)
        {
               temp=temp->next;
        }
        while(temp!=prv)
        {
                temp=temp->next->next;
                prv=prv->next;
        }
        printf("\n\nThe Node With Data = %d is the beginning of the cycle",prv->data);
        return 1;
}

int le()
{
        int c=0;
        prv=s1;
        while(temp!=prv)
        {
                ++c;
                temp=temp->next->next;
                prv=prv->next;
        }
        return (--c);

}

int main()
{
        int n=0;
        s1=(struct node *)malloc(sizeof(struct node));
        s1=NULL;
        ins(1);
        ins(2);
        ins(3);
        ins(4);
        ins(5);
        ins(6);
        ins(7);
        ins(8);
        temp=s1;
        while(temp->next!=NULL)
        {
                temp=temp->next;
        }
        temp->next=s1->next->next;      //Created a loop from last Element to Third Element
        if(fin())
        {
                n=le();
                printf("\n\n%d is the length of cycle",n);
                sf(n);
        }
        else
        {
                printf("\n\nNo loops Exist");
        }

        //Making the Same LL again But this tym, No loops ;)
        s1=NULL;
        ins(1);
        ins(2);
        ins(3);
        ins(4);
        ins(5);
        ins(6);
        ins(7);
        if(fin())
        {
                printf("\n\n%d is the length of cycle",le());
        }
        else
        {
                printf("\n\nNo loops Exist");
        }
        return 1;

}


