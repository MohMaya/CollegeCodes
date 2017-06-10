//Program to implement Circular queue

#include<stdio.h>

void insert(int *,int *,int *,int);
void deletes(int *,int *,int *);
void display(int *,int *,int * );
int n;
void insert(int *cq, int *f, int *r,int ele )
{
	if((*r==(n-1)&& *f==0)||(*f-*r)==1)
	{
		printf("queue is full\n");
		return;
	}
	else
	{
		if(*r==-1)
		{*r=0;*f=0;
		}
		else if(*r==(n-1))
		{
			*r=0;
		}
		else
		*r=*r+1;
    }
    cq[*r]=ele;
    return;
}
void deletes(int *cq,int*f,int*r)
{
	if(*r==-1)
	{
		printf("queue is empty\n");
	}
	else
	{
		if(*f==*r)
		{
			*f=-1;
			*r=-1;
		}
		else if(*f==(n-1))
		{
			*f=0;
		}
		else
		*f=*f+1;
	}
	return;
}
void display(int *cq,int *f,int *r)
{
	int i;
	//printf("rear=%d\nfront=%d\n",(*r+1),(*f+1));
	if(*r==-1&&*f==-1)
	{
		printf("empty\n");
	}
	else if(*r>=*f)
	{
		for(i=*f;i<=*r;i++)
		{
			printf("%d ",cq[i]);
		}
	}
	else if(*r<=*f)
	{
		for(i=*f;i<n;i++)
			{
			printf("%d ",cq[i]);
		}
			for(i=0;i<=*r;i++)
			{
			printf("%d \n",cq[i]);
		}
	}
	return;
}
int main()
{
	int cq[20],f=-1,r=-1;
	printf("enter max elements\n");
	scanf("%d",&n);
	int ch,ele;
	do
	{
		printf("\nmenu \n1 insert \n2 delete \n3 dispaky \n4 exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("enter element\n");
			scanf("%d",&ele);
			insert(cq,&f,&r,ele);
			display(cq,&f,&r);
		}
		if(ch==2)
		{
			deletes(cq,&f,&r);
			display(cq,&f,&r);
		}
		if(ch==3)
		{
			display(cq,&f,&r);
		}
	}while(ch!=4);
	return 0;
	}
