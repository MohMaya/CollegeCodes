#include<stdio.h>

int main()
{
    int m,n;
    float A[20][20],B[20][20],C[20][20],D[20][20];
    printf("\n Enter the order of matrices M N : ");
    scanf("%d %d",&m,&n);
    printf("\nEnter the values for Matrix A \n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%f",&A[i][j]);
        }
    }

    printf("\nEnter the values for Matrix B \n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%f",&B[i][j]);
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            C[i][j]=A[i][j]+B[i][j];
            D[i][j]=A[i][j]-B[i][j];
        }
    }

    printf("\nMatrix C: \n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf(" %f ",C[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix D: \n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf(" %f " ,D[i][j]);
        }
        printf("\n");
    }

    printf("\nTranspose of A :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf(" %f ",A[j][i]);
        printf("\n");
    }

    printf("\nTranspose of B :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf(" %f ",B[j][i]);
        printf("\n");
    }

}
