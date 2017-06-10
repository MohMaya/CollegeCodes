#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct sll
{
	int data;
	struct sll* next;
}
*start1,*start2,*newnode,*mer=NULL;
struct sll* insert(struct sll *start,int ele)
{printf("enter data\n");
	while(ele!=0)
	{
	newnode=(struct sll*)malloc(sizeof(struct sll));

	scanf("%d",&newnode->data);
	if(start==NULL)
	{
		newnode->next=NULL;
		start=newnode;
	}
	else
	{
		struct sll *temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		newnode->next=NULL;
		temp->next=newnode;
	}
	ele--;
}
return start;
}
struct sll* merge(struct sll* a, struct sll* b)
{
	struct sll* result;
	if(a==NULL)
	return b;
	if(b==NULL)
	return a;
	if(a->data<=b->data)
	{
		result=(struct sll*)malloc(sizeof(struct sll));
		result=a;
		result->next=merge(a->next,b);
	}
    else
    {
    	result=b;
    	result->next=merge(a,b->next);
	}
	return result;
}
void print(struct sll* h)
{
	struct sll* temp=h;
	while(temp->next!=NULL)
	{
		printf("|%d|->",temp->data);
		temp=temp->next;
	}
	printf("|%d|",temp->data);
}
int main()
{
	int elements;
	printf("enter the elements of first linkk list\n");
	scanf("%d",&elements);
	start1=insert(start1,elements);
	printf("enter the elements of second linkk list\n");
	scanf("%d",&elements);
	start2=insert(start2,elements);
	mer=merge(start1,start2);
	print(mer);
	return 0;

}
