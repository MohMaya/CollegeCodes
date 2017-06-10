#include<stdio.h>
int arr1[100][100];
int arr2[100][100];
int arr3[100][100];
int main(){
    int i,j,k,sum=0,M,N,N1,L;
printf("ENTER THE M*N MATRIX A\n");
scanf("%d %d",&M,&N);
for(i=0;i<M;i++)
{
    for(j=0;j<N;j++)
        scanf("%d",&arr1[i][j]);
}
printf("ENTER THE N*L MATRIX B\n");
scanf("%d %d",&N1,&L);
if(N1!=N)
{
    printf("Invalid Input\n");
    return 0;
}
for(i=0;i<N;i++)
{
    for(j=0;j<L;j++)
        scanf("%d",&arr2[i][j]);
}
for(i=0;i<M;i++)
{
    for(j=0;j<L;j++)
        {sum=0;
           for(k=0;k<N;k++)
           {
              sum+=arr1[i][k]*arr2[k][j];
           }
           arr3[i][j]=sum;
        }
}
printf("FINAL MATRIX AB\n");
for(i=0;i<M;i++)
{
    for(j=0;j<L;j++){
        printf("%d ",arr3[i][j]);
    }
printf("\n");
}

return 1;
}
