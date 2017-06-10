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
    scanf("%d",&Process[i]);
    AllocSta[i]=0;
  }

  printf("\n");

  for(int i=0;i<NumProces;i++){

    //if(AllocSta[i]==0){
      //for each unallocated process
      int mindiff=23456;
      int frame_no_to_alloc=23456;
      for(int j=0;j<NumPageFrame;j++){
        if(MemSta[j]==0){
          //check each unallocated Frame
          int diff = PageFrames[j]-Process[i];
          if((diff<mindiff)&&(diff>=0)){
            mindiff=diff;
            frame_no_to_alloc = j;
          }
        }
      }
      if(frame_no_to_alloc!=23456){
            ProInMem[frame_no_to_alloc]=Process[i];
            MemSta[frame_no_to_alloc]=1;
            AllocSta[i]=1;
      }
    //}
  }

  for(int i=0;i<NumPageFrame;i++){
    if(ProInMem[i]!=0){
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
  //Code For Fragmentation
}
