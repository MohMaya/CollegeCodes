#include<stdio.h>

int main()
  {  
     int c,i,n;
     int a[1000]={0};
     printf("Enter the size of array:");
     scanf("%d",&n);
     printf("\nEnter the elements of array->");
     while(n--)
       {
         scanf("%d",&c);
         a[c]++;
       }
    for(i=0;i<1000;i++)
     {
        if(a[i]!=0)
         {
          printf("Frequency of %d -> %d\n",i,a[i]);
         } 
     }
   return 0;
  }   
