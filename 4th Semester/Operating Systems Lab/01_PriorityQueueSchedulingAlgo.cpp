//non-preemptive Priority Queue Scheduling
#include "stdio.h"

int Process_no[20],Arrival_time[20],Burst_time[20],Priority[20],Job_status[20],completion_time[20],turn_around_time[20],wait_time[20],response_time[20];
int num_processes;

int suma(){
  int retval=0;
  for(int i=0;i<num_processes;i++)
  {
    retval+=Job_status[i];
  }
  return retval;
}

int main(){
  int current_time=0;
  printf("\nEnter The Number of Processes : ");
  scanf("%d",&num_processes);
  for(int i=0;i<num_processes;i++)
  {
    printf("\nEnter following for Process number %d",i+1);
    printf("\nArrival Time : ");
    scanf("%d",&Arrival_time[i]);
    printf("\nBurst Time : ");
    scanf("%d",&Burst_time[i]);
    printf("\nPriority : ");
    scanf("%d",&Priority[i]);
    Job_status[i]=1;  //Implies Job unexecuted
  }


  while(suma()!=0){
    int min_priority = 23456;//Lower Priority value => Higher Priority Job
    int pno_to_execute=0;
    for(int i=0;i<num_processes;i++)
    {
      if ((Priority[i]<min_priority) && (Job_status[i]==1) && (Arrival_time[i]<=current_time)) {
        min_priority=Priority[i];
        pno_to_execute=i;
      }
    }
    if(min_priority==23456){
      current_time++;
    }
    else{
    //printf("\nProcess %d Executed",pno_to_execute+1);
    current_time += Burst_time[pno_to_execute];
    completion_time[pno_to_execute]=current_time;
    Job_status[pno_to_execute]=0; //=>Process Executed
    printf("|%d sec|P%d|%d sec|=>",completion_time[pno_to_execute]-Burst_time[pno_to_execute],pno_to_execute+1,completion_time[pno_to_execute]);

    }
}

  for(int i=0;i<num_processes;i++){
    turn_around_time[i]=completion_time[i]-Arrival_time[i];
    wait_time[i] = turn_around_time[i]-Burst_time[i];
    response_time[i]=wait_time[i];
  }

  for(int i=0;i<num_processes;i++){
    printf("\nProcess Number\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWait Time\tResponse Time\t");
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d",i+1,Arrival_time[i],Burst_time[i],completion_time[i],turn_around_time[i],wait_time[i],response_time[i]);
  }
  printf("\n");

  return 1;
}
