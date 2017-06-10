#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r,c,i,j;
    int arr[100][100];
    printf("\n\nEnter the no. of rows :");
    scanf("%d",&r);
    printf("\n\nEnter the no. of columns :");
    scanf("%d",&c);
    printf("\n\nEnter the elements\n\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            scanf("%d",&arr[i][j]);
    }
    int rmin=0,cmin=0,counter=0,cmax=r*c;r--;c--;
    printf("\n\nFinal Output\n");
    while(counter<=cmax)
    {
      for(i=cmin;i<=c&&counter<=cmax;i++)
      printf(" % d",arr[rmin][i]);
    rmin++;
    for(i=rmin;i<=r&&counter<=cmax;i++)
        printf(" %d ",arr[i][c]);
    c--;
     for(i=c;i>=cmin&&counter<=cmax;i--)
        printf(" %d ",arr[r][i]);
    r--;
     for(i=r;i>=rmin&&counter<=cmax;i--)
        printf(" %d ",arr[i][cmin]);
    cmin++;
    }
    return 0;
}
