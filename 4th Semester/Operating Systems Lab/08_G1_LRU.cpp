#include<stdio.h>
int li[100],ti[100],fin[100][40],page[100];
char fault[40];
int tim_stamp=0;
int p,q;

int isInTable(int x)
{
	for(int i=0;i<p;i++)
	{
		if(page[i]==x)
			return 1;
	}
	return 0;
}

int retInd(int x)
{
	for(int i=0;i<p;i++)
	{
		if(page[i]==x)
			return i;
	}
	return -1;
}


int main()
{
	
	printf("\nEnter the number of pages in page table : ");
	scanf("%d",&p);
	printf("\nEnter the number of page calls : ");
	scanf("%d",&q);
	printf("\nEnter the list of pages to be accessed : \n");
	for(int i=0;i<q;i++)
	{
		scanf("%d",&li[i]);
	}
	for(int i=0;i<p;i++)
	{
		ti[i]=-1;
		page[i]=-1;
	}
	int ind=0,indtoins=0;
	for(int i=0;i<q;i++)
	{
		if(isInTable(li[i]))
		{
			fault[i]='o';
			ind= retInd(li[i]);
			ti[ind]=tim_stamp++;
		}
		else
		{
			fault[i]='f';
			indtoins = retInd(-1);
			if(indtoins!=-1)
			{	//if empty
				page[indtoins]=li[i];
				ti[indtoins]=tim_stamp++;
			}
			else
			{
				//if full
				int mint=5000;
				indtoins=0;
				for(int k=0;k<p;k++)
				{
					if(ti[k]<mint)
					{
						mint=ti[k];
						indtoins=k;
					}
				}
				page[indtoins]=li[i];
				ti[indtoins]=tim_stamp++;
			}
		}
		
		for(int j=0;j<p;j++)
		{
			fin[j][i]=page[j];
		}
	}
	
	
	//printing
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<q;j++)
		{
			if(fin[i][j]==-1)
			{
				printf("\tNULL");
			}
			else
			{
				printf("\t%d",fin[i][j]);
			}
		}
		printf("\n");
	}
	int nfs=0;
	for(int i=0;i<q;i++)
	{
		if(fault[i]=='f')
			nfs++;
		printf("\t%c",fault[i]);
	}
	
	float perfault = float(nfs)/float(q);
	printf("\n\nFault Percentage : %f",perfault*100);
}
