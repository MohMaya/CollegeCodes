//A program that accepta a list of Programs, Their Burst Times and their Arrival Time and print the order in which they would be executed
//as per the FCFS Scheduling Algorithm
// Written By Shivanshu Chaudhary on 21 April, 2017 at 4:56 PM

#include<stdio.h>

int main() {
  int numProcess;
  float arrTime[17],burTime[17],sta[17];

  printf("\nEnter the number of processes you will enter: ");
  scanf("%d",&numProcess);

  printf("\nEnter the Process Data in the format :\nProcess Number\tArrival Time\tBurst Time");
  for(int i=0;i<numProcess;i++)
  {
    printf("\nP%d\t",i+1);
    scanf("%f %f",&arrTime[i],&burTime[i]);
    sta[i]=0;//Means Unexecuted
  }

  printf("\nYour Entered processes are\nProcess Number\tArrival Time\tBurst Time");
  for(int i=0;i<numProcess;i++)
  {
    printf("\nP%d\t\t%f\t%f",i+1,arrTime[i],burTime[i]);
  }

  for(int i=0;i<numProcess;i++)
  {
    
  }

  printf("\n");
  return 0;
}
