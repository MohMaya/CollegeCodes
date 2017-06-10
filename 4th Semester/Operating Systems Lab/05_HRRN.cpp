//HRRN is a non Pre-emptive scheduling
#include "stdio.h"

int Process_no[20],Arrival_time[20],Burst_time[20],Priority[20],Job_status[20],completion_time[20],turn_around_time[20],wait_time[20],response_time[20];
float HRR[20];
int num_processes;

int suma(){
  int retval=0;
  for(int i=0;i<num_processes;i++)
  {
    retval+=Job_status[i];
  }
  return retval;
}

float Response_ratio(int x){
    float Wait = wait_time[x];
    float Burst = Burst_time[x];
    float Ratio = (Wait+Burst)/Burst;
    return Ratio;
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
        Job_status[i]=1;  //Implies Job unexecuted
        wait_time[i]=0;
    }

    while(suma()!=0){
      for(int i=0;i<num_processes;i++){
        HRR[i]=Response_ratio(i);
      }
      float max_hrr = -2;
      int ind_max_hrr = -2;
      for(int i=0;i<num_processes;i++){
        if((HRR[i]>max_hrr)&&(Job_status[i]==1)&&(Arrival_time[i]<=current_time)){
          max_hrr=HRR[i];
          ind_max_hrr=i;
        }
      }

      if(ind_max_hrr!=-2){
        printf("\nProcess %d Executed from %d seconds to ",ind_max_hrr+1,current_time);
        Job_status[ind_max_hrr]=0;
        current_time+=Burst_time[ind_max_hrr];
        completion_time[ind_max_hrr]=current_time;
        printf("%d seconds",current_time);
      }
      else{
        current_time++;
      }

      for(int i=0;i<num_processes;i++){
        wait_time[i]=(current_time - Arrival_time[i]);
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

