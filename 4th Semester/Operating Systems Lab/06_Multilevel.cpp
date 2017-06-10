#include<stdio.h>
#include<stdlib.h>

struct pq
{
	int pno;
	int at,bt,ct,tat,wt,rt,st;
	struct pq* nextp;
}*tmp1,*tmp2,*tmp3;


struct pq *q1=NULL;
struct pq *q2=NULL;
struct pq *q3=NULL;
struct pq *q4=NULL;
struct pq *qd=NULL;
struct pq *nwnd=NULL;
int pnum=1;
int currt=0;

int insertq1(int arr,int bur)
{
	nwnd=(struct pq*)malloc(sizeof(struct pq));
	nwnd->pno=pnum++;
	nwnd->at=arr;
	nwnd->bt=bur;
	nwnd->ct=0;
	nwnd->rt=0;
	nwnd->tat=0;
	nwnd->wt=0;
	nwnd->st=0;
	tmp2=q1;
	if(q1==NULL)
	{
		nwnd->nextp=NULL;
		q1=nwnd;
		return 1;
	}
	
	while((tmp2->nextp!=NULL)&&(nwnd->at>=tmp2->at))
	{
		tmp1=tmp2;
		tmp2=tmp2->nextp;
	}
	
	if((tmp2==q1)&&(nwnd->at>=tmp2->at))
	{
		q1->nextp=nwnd;
		nwnd->nextp=NULL;
		return 1;
	}
	
	if((tmp2==q1)&&(nwnd->at<tmp2->at))
	{
		nwnd->nextp=q1;
		q1=nwnd;
		return 1;
	}
	
	
	if(nwnd->at<tmp2->at)
	{
		nwnd->nextp=tmp2;
		tmp1->nextp=nwnd;
		return 1;
	}
	if(tmp2->nextp==NULL)
	{
		tmp2->nextp=nwnd;
		nwnd->nextp=NULL;
		return 1;
	}
	return 0;
	
}



int insertq2(int arr,int bur)
{
	nwnd=(struct pq*)malloc(sizeof(struct pq));
	nwnd->pno=pnum++;
	nwnd->st=0;
	nwnd->at=arr;
	nwnd->bt=bur;
	nwnd->ct=0;
	nwnd->rt=0;
	nwnd->tat=0;
	nwnd->wt=0;
	tmp2=q2;
	if(q2==NULL)
	{
		nwnd->nextp=NULL;
		q2=nwnd;
		return 1;
	}
	
	while((tmp2->nextp!=NULL)&&(nwnd->at>=tmp2->at))
	{
		tmp1=tmp2;
		tmp2=tmp2->nextp;
	}
	
	if((tmp2==q2)&&(nwnd->at>=tmp2->at))
	{
		q2->nextp=nwnd;
		nwnd->nextp=NULL;
		return 1;
	}
	
	if((tmp2==q2)&&(nwnd->at<tmp2->at))
	{
		nwnd->nextp=q2;
		q2=nwnd;
		return 1;
	}
	
	
	if(nwnd->at<tmp2->at)
	{
		nwnd->nextp=tmp2;
		tmp1->nextp=nwnd;
		return 1;
	}
	if(tmp2->nextp==NULL)
	{
		tmp2->nextp=nwnd;
		nwnd->nextp=NULL;
		return 1;
	}
	return 0;
	
}



int insertq3(int arr,int bur)
{
	nwnd=(struct pq*)malloc(sizeof(struct pq));
	nwnd->pno=pnum++;
	nwnd->at=arr;
	nwnd->bt=bur;
	nwnd->ct=0;
	nwnd->rt=0;
	nwnd->tat=0;
	nwnd->st=0;
	nwnd->wt=0;
	tmp2=q3;
	if(q3==NULL)
	{
		nwnd->nextp=NULL;
		q3=nwnd;
		return 1;
	}
	
	while((tmp2->nextp!=NULL)&&(nwnd->at>=tmp2->at))
	{
		tmp1=tmp2;
		tmp2=tmp2->nextp;
	}
	
	if((tmp2==q3)&&(nwnd->at>=tmp2->at))
	{
		q3->nextp=nwnd;
		nwnd->nextp=NULL;
		return 1;
	}
	
	if((tmp2==q3)&&(nwnd->at<tmp2->at))
	{
		nwnd->nextp=q3;
		q3=nwnd;
		return 1;
	}
	
	
	if(nwnd->at<tmp2->at)
	{
		nwnd->nextp=tmp2;
		tmp1->nextp=nwnd;
		return 1;
	}
	if(tmp2->nextp==NULL)
	{
		tmp2->nextp=nwnd;
		nwnd->nextp=NULL;
		return 1;
	}
	return 0;
	
}



int insertq4(int arr,int bur)
{
	nwnd=(struct pq*)malloc(sizeof(struct pq));
	nwnd->pno=pnum++;
	nwnd->at=arr;
	nwnd->bt=bur;
	nwnd->st=0;
	nwnd->ct=0;
	nwnd->rt=0;
	nwnd->tat=0;
	nwnd->wt=0;
	tmp2=q4;
	if(q4==NULL)
	{
		nwnd->nextp=NULL;
		q4=nwnd;
		return 1;
	}
	
	while((tmp2->nextp!=NULL)&&(nwnd->at>=tmp2->at))
	{
		tmp1=tmp2;
		tmp2=tmp2->nextp;
	}
	
	if((tmp2==q4)&&(nwnd->at>=tmp2->at))
	{
		q4->nextp=nwnd;
		nwnd->nextp=NULL;
		return 1;
	}
	
	if((tmp2==q4)&&(nwnd->at<tmp2->at))
	{
		nwnd->nextp=q4;
		q4=nwnd;
		return 1;
	}
	
	
	if(nwnd->at<tmp2->at)
	{
		nwnd->nextp=tmp2;
		tmp1->nextp=nwnd;
		return 1;
	}
	if(tmp2->nextp==NULL)
	{
		tmp2->nextp=nwnd;
		nwnd->nextp=NULL;
		return 1;
	}
	return 0;
	
}

int insertqd(int prno,int art,int but,int compt,int strt)
{
	printf("\nInsertqd executed");
	nwnd=(struct pq*)malloc(sizeof(struct pq));
	nwnd->pno=prno;
	nwnd->at=art;
	nwnd->bt=but;
	nwnd->ct=compt;
	nwnd->tat=compt-nwnd->at;
	nwnd->wt=nwnd->tat-nwnd->bt;
	nwnd->rt=nwnd->wt;
	nwnd->st=strt;
	nwnd->nextp=NULL;
	tmp2=qd;
	if(qd==NULL)
	{
		nwnd->nextp=NULL;
		qd=nwnd;
		return 1;
	}
	
	while(tmp2->nextp!=NULL)
	{
		tmp2=tmp2->nextp;
	}
	
	tmp2->nextp=nwnd;
	return 1;
}

int disp1()
{
	tmp1=q1;
	while(tmp1!=NULL)
	{
		printf("  %d  ",tmp1->pno);
		tmp1=tmp1->nextp;
	}
}


int disp2()
{
	tmp1=q2;
	while(tmp1!=NULL)
	{
		printf("  %d  ",tmp1->pno);
		tmp1=tmp1->nextp;
	}
}


int disp3()
{
	tmp1=q3;
	while(tmp1!=NULL)
	{
		printf("  %d  ",tmp1->pno);
		tmp1=tmp1->nextp;
	}
}


int disp4()
{
	tmp1=q4;
	while(tmp1!=NULL)
	{
		printf("  %d  ",tmp1->pno);
		tmp1=tmp1->nextp;
	}
}


int dispfq()
{
	tmp1=qd;
	
	while(tmp1!=NULL)
	{
		printf("|%d  P%d  %d|->",tmp1->st,tmp1->pno,tmp1->ct);
		tmp1=tmp1->nextp;
	}
	tmp1=qd;
	printf("\nProcess no.\t|Arrival Time\t|Burst Time\t|Completion Time\t|Turn Around Time\t|Wait Time\t|Response Time|");
	while(tmp1!=NULL)
	{
		printf("\nP%d\t\t|%d\t\t|%d\t\t|%d\t\t\t|%d\t\t\t|%d\t\t\t|%d\t\t|\n",tmp1->pno,tmp1->at,tmp1->bt,tmp1->ct,tmp1->tat,tmp1->wt,tmp1->rt);
		tmp1=tmp1->nextp;
	}
}


int execu()
{
	//printf("\nInside Exec");
	int s=0;
	if(q1!=NULL)
	{
		//printf("\nINside q1");
	//	printf("%d",q1->bt);
		if(q1->at<=currt)
		{
		s=currt;
		currt+=q1->bt;
		
		insertqd(q1->pno,q1->at,q1->bt,currt,s);
		//printf("\nBack in q1");
		q1=q1->nextp;
		return 1;
		}
	}
	
	if(q2!=NULL)
	{
		//printf("\nINside q1");
	//	printf("%d",q1->bt);
		s=currt;
		if(q2->at<=currt)
		{
		
		currt+=q2->bt;
		
		insertqd(q2->pno,q2->at,q2->bt,currt,s);
		//printf("\nBack in q1");
		q2=q2->nextp;
		return 1;
		}
	}
	if(q3!=NULL)
	{
		//printf("\nINside q1");
	//	printf("%d",q1->bt);
		if(q3->at<=currt)
		{
		s=currt;
		
		currt+=q3->bt;
		
		insertqd(q3->pno,q3->at,q3->bt,currt,s);
		//printf("\nBack in q1");
		q3=q3->nextp;
		return 1;
		}
	}
	
	if(q4!=NULL)
	{
		//printf("\nINside q1");
	//	printf("%d",q1->bt);
		if(q4->at<=currt)
		{
		s=currt;
		currt+=q4->bt;
		
		insertqd(q4->pno,q4->at,q4->bt,currt,s);
		//printf("\nBack in q1");
		q4=q4->nextp;
		return 1;
		}
	}
	
	currt+=1;
	return 0;
		
}




int main()
{
	int ch=1,art=0,but=0,qno=0;
	
	
	while(true)
	{
		printf("\n\nEnter Your Choice\n1. Enter a new Process\n2. Execute all the processes\n3. Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("\nP%d-------------",pnum);
			printf("\nEnter the Arrival time : ");
			scanf("%d",&art);
			printf("\nEnter the Burst time     : ");
			scanf("%d",&but);
			printf("\nEnter the process queue[1=> Highest P., 4=> Lowest P.]  :");
			scanf("%d",&qno);
			if(qno==1)
			{
				insertq1(art,but);
			}
			else if(qno==2)
			{
				insertq2(art,but);
			}
			else if(qno==3)
			{
				insertq3(art,but);
			}
			else if(qno==4)
			{
				insertq4(art,but);
			}
			else
				printf("\nInvalid Queue Number");
			currt=0;
			
		}
		else if(ch==2)
		{
			printf("\n");
			disp1();
			printf("\n");
			disp2();
			printf("\n");
			disp3();
			printf("\n");
			disp4();
			
			printf("\nExecuting all the processes\n\n");
			//printf("\n%d %d %d %d",q1,q2,q3,q4);
			while((q1!=NULL)||(q2!=NULL)||(q3!=NULL)||(q4!=NULL))
			{
				//printf("\nInside While");
				//dispfq();
				//printf("\n%d %d %d %d",q1,q2,q3,q4);
				//printf("%d",execu());
				//printf("\nBack Inside While");
				execu();
				
			}
			printf("\n");
			dispfq();
			
			//exec();
		}
		else if(ch==3)
		{
			break;
		}
		else
		{
			printf("\nINVALID CHOICE!!!\n Re-Enter");
		}
	}
	return 1;
}

