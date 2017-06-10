#include<stdio.h>

int readyQueue[100],currenttime=0,quanta=1,start=0,end=0;
int NumProcess,arrivaltime[100],bursttime[100],completiontime[100],remainingtime[100],turnaroundtime[100];
int firstcpucycletime[100],waittime[100],jobstatus[100];



int allexec(){
  int sum=0;
  for(int q=0;q<NumProcess;q++)
  {
    sum+=jobstatus[q];
  }
  return sum;
}

int checkl()
{
  for(int w=0;w<100;w++)
  {
    if(readyQueue[w]!=-1)
    {
      return 1;
    }
  }
  return 0;
}


int putinback(int e)
{
    for(int r=0;r<100;r++)
    {
      if(readyQueue[r]==e)
      {
        return 1;
      }
    }
    readyQueue[end]=e;
    end+=1;
    return 0;
}

int removefromfront()
{
    readyQueue[start]=-1;
    start+=1;
    return 1;
}

int rq()
{
  printf("\n");
  printf("\nStart: %d ; End: %d\n",start,end);

  for(int r=0;r<100;r++)
  {
    if(readyQueue[r]!=-1)
      printf("%d\t",readyQueue[r]);
  }
  return 1;
}

int main(){
  int flag=0;
  printf("Welcome!!\n");
  printf("How many processes do you want to execute? : ");
  scanf("%d",&NumProcess);
  printf("\nOk. Now Enter the details of the processes as asked\n");
  for(int i=0;i<NumProcess;i++)
  {
    printf("\nArrival Time for P%d :",i+1);
    scanf("%d",&arrivaltime[i]);
    printf("\nBurst Time For P%d :",i+1);
    scanf("%d",&bursttime[i]);
    remainingtime[i]=bursttime[i];
    completiontime[i]=0;
    turnaroundtime[i]=0;
    firstcpucycletime[i]=0;
    waittime[i]=0;
    jobstatus[i]=1;  //=> Unexecuted
  }
  printf("\nWhat is the time quanta? : ");
  scanf("%d",&quanta);
  //Processes Entered

  printf("\n");
  for(int i=0;i<100;i++)
  {
    readyQueue[i]=-1;
  }


  while(allexec()!=0)
  {
    flag=0;
    for(int i=0;i<NumProcess;i++)
    {
      if(jobstatus[i]==1 && arrivaltime[i]<currenttime)
      {
        putinback(i);
        flag=1;
      }
    }
    //rq();
    if(flag==0)
    {
      if(checkl()==1)
      {
        flag=1;
      }
    }
    if(flag!=0)
    {
      int pnotoexecute=readyQueue[start];
      removefromfront();
      if(remainingtime[pnotoexecute]==bursttime[pnotoexecute])
      {
        firstcpucycletime[pnotoexecute]=currenttime;
      }
      if(remainingtime[pnotoexecute]<=quanta)
      {
        currenttime+=remainingtime[pnotoexecute];
        remainingtime[pnotoexecute]=0;
        jobstatus[pnotoexecute]=0;
        completiontime[pnotoexecute]=currenttime;
      }
      else{
        currenttime+=quanta;
        remainingtime[pnotoexecute]-=quanta;
        putinback(pnotoexecute);
      }
      printf("\nP%d   ",pnotoexecute+1);
    }
    for(int i=0;i<NumProcess;i++)
    {
      if(jobstatus[i]==1 && arrivaltime[i]==currenttime)
      {
        putinback(i);
      }
    }
    if(flag==0)
    {
      currenttime++;
    }
    for(int i=0;i<NumProcess;i++)
    {
      if(jobstatus[i]==1 && arrivaltime[i]==currenttime)
      {
        putinback(i);
      }
    }
    //rq();
    //printf("\nCurrent time %d ",currenttime);
  }

}
