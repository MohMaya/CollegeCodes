#include<stdio.h>

int main()
{
    int m;
    float A[20][20];
    float rsum[20],csum[20],d1sum=0,d2sum=0;
    printf("\n Enter the order of the square matrix M : ");
    scanf("%d",&m);
    printf("\nEnter the values for Matrix A \n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%f",&A[i][j]);
        }
    }
    for(int i=0;i<20;i++)
    {
        rsum[i]=0;
        csum[i]=0;
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            rsum[i]+=A[i][j];
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
                csum[i]+=A[j][i];
        }
    }

    for(int i=0;i<m;i++)
        d1sum+=A[i][i];

    for(int i=0;i<m;i++)
        d2sum+=A[i][m-i-1];

    printf("\nColumn Wise Sum :");
    for(int i=0;i<m;i++)
        printf("\nColumn %d : %f",i,csum[i]);

    printf("\nRow Wise Sum :");
    for(int i=0;i<m;i++)
        printf("\nRow %d : %f",i,rsum[i]);

    printf("\n Diagonal 1 Sum = %f ",d1sum);
    printf("\n Diagonal 2 Sum = %f ",d2sum);
    return 1;

}




