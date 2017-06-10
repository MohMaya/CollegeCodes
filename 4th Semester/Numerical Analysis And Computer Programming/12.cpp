#include<stdio.h>
#include<math.h>


int main()
{
    float X[100],Y[100];
    float sumx=0,sumy=0,sumxy=0,sumx2=0;
    float m,c;
    int n;
    printf("\nEnter The number of points you have : ");
    scanf("%d",&n);
    printf("\nEnter the Points in pairs as X Y\n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&X[i]);
        scanf("%f",&Y[i]);
    }

    for(int i=0;i<n;i++)
    {
        sumx+=X[i];
        sumy+=Y[i];
        sumx2+=pow(X[i],2);
        sumxy+=X[i]*Y[i];
    }

    m=((n*sumxy)-(sumx*sumy))/((n*sumx2)-pow(sumx,2));

    c=(sumy-(m*sumx))/n;

    printf("\n m = %f\t\tc = %f",m,c);
    printf("\nThe Line is y= %f x + %f",m,c);
    return 1;
}
