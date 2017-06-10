#include "stdio.h"


int NumPageFrame,NumProces;
int PageFrames[20],Process[20];
int AllocSta[20],MemSta[20],ProInMem[20];//AllocSta tells if process has been allocated a memory or not
                            //MemSta tells if a Frame has been allocated a process or not

int main(){

  printf("\nEnter the number of Page Frames : ");
  scanf("%d",&NumPageFrame);
  printf("\nEnter the Frame Sizes : ");
  for(int i=0;i<NumPageFrame;i++){
    scanf("%d",&PageFrames[i]);
    MemSta[i]=0;
  }

  printf("\nEnter the number of processes to be allocated : ");
  scanf("%d",&NumProces);

  printf("\nEnter the Process sizes : ");
  for(int i=0;i<NumProces;i++){
  //  printf("\nSize for process %d :",i+1);
    scanf("%d",&Process[i]);
    AllocSta[i]=0;
  }

  printf("\n");

  for(int i=0;i<NumProces;i++){
    if(AllocSta[i]==0){
      int max_size_available = -2;
      int ind_max_size = -1;
      for(int j=0;j<NumPageFrame;j++){
        if(MemSta[j]==0){
            if((PageFrames[j]>max_size_available)&&(PageFrames[j]>Process[i])){
              max_size_available=PageFrames[j];
              ind_max_size=j;
            }
          }
        }
        if(ind_max_size!=-1){
          AllocSta[i]=1;
          MemSta[ind_max_size]=1;
          ProInMem[ind_max_size]=Process[i];
        }
      }
    }


  for(int i=0;i<NumPageFrame;i++){
    if(MemSta[i]!=0){
    printf("\n%d Sized MemBlock Given Process %d ",PageFrames[i],ProInMem[i]);
  }else{
    printf("\n%d Sized MemBlock Unallocated ",PageFrames[i]);
  }
  }

  printf("\nUnallocated Processes' Size : ");
  for(int i=0;i<NumProces;i++){
    if(AllocSta[i]==0){
      printf("\t%d",Process[i]);
    }
  }

  printf("\nEmpty Page Frames' Size : ");
  for(int i=0;i<NumPageFrame;i++){
    if(MemSta[i]==0){
      printf("\t%d",PageFrames[i]);
    }
  }
  printf("\n");
}
