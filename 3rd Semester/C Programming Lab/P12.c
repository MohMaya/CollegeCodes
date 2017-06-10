#include<stdio.h>

int M,N;
int m,n;


int main()
   {
    int flag,p,q;
    printf("\nEnter the number of element in larger matrix M*N:");
    scanf("%d%d",&M,&N);
    printf("\nEnter the number of element in smaller matrix:");
    scanf("%d%d",&m,&n);
    int l[M][N];
    int s[m][n];   
    //large matix
    int i,j;
printf("Enter larger matrix\n");
    for(i=0;i<M;i++)
      for(j=0;j<N;j++)
         scanf("%d",&l[i][j]);
    //small matrix
printf("Enter smaller matrix\n");
     for(i=0;i<m;i++)
      for(j=0;j<n;j++)
         scanf("%d",&l[i][j]);
    
   

for(i=0; i<=(M-m); i++)
{
   for(j=0; j<=(N-n); j++)
   {
      flag=0;
      for(p=0; p<m; p++)
      {
         for(int q=0; q<n; q++)
         {
            if(l[i+p][j+q] != s[p][q])
            {
               flag=1;
               printf("\nflag==1");
               break;
            }
         }
      }
      if(flag==0)
      {
           printf("Match Found in the Main Matrix at starting location %d, %d",(i+1) ,(j+1));
         break;
      }
   }
   if(flag==0)
   {
        printf("Match Found in the Main Matrix at starting location %d, %d",(i+1) ,(j+1));
      break;
   }
}
if(flag==1)
   printf("Match not found!");

return 0;
}

