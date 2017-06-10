#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min,max,i,j,n,col,flag=0;

    printf("Enter the size of the matrix\n");
    scanf("%d",&n);

    int A[n][n];

    printf("Enter the matrix.\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &A[i][j]);
        }

    }

    for(i=0;i<n;i++)
    {
        min=99999;
        for(j=0;j<n;j++)
        {
            if(min>A[i][j])
            {
                min=A[i][j];
                col=j;
            }
        }

        max=min;

        for(j=0;j<n;j++)
        {
            if(max<A[j][col])
                max=A[j][col];
        }

        if(min==max)
        {
            printf("\nSaddle point is %d (Row = %d, Column = %d)\n",min,i,col);
            flag=1;break;
        }
    }
    if(flag==0)
        printf("No saddle point");


    return 0;
}

