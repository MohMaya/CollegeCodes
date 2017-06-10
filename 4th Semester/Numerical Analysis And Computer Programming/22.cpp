#include<stdio.h>

int main()
{
    float x[10],y[10],p[10];
    int n,i,j=1;
    float k,f,f1=1,f2=0;
    printf("\nEnter the number of Observations : ");
    scanf("%d",&n);

    printf("\nEnter the values of x y in pairs : \n");
    for(i=0;i<n;i++)
    {
        printf("\n Enter x[%d] y[%d] :",i,i);
        scanf("%f %f",&x[i],&y[i]);
        //printf("\n%f %f",x[i],y[i]);
    }


    f=y[0];

    printf("\nEnter the Value of k : ");
    scanf("%f",&k);

    do
    {
        for(i=0;i<n-1;i++)
        {
            p[i]=((y[i+1]-y[i])/(x[i+j]-x[i]));
            y[i]=p[i];
            //printf("\nFor i=%d ,j=%d y[%d]=%f",i,j,i,y[i]);
        }
        f1=1;
        for(i=0;i<j;i++)
        {
            //printf("\nFor i=%d f1=%f",i,f1);
            f1*=(k-x[i]);
        }
        f2+=y[0]*f1;
        //printf("\nFor n=%d f2=%f",n,f2);
        n--;
        j++;


    }while(n!=1);
    //printf("\n%f",f);
    //printf("\n%f",f2);

    f+=f2;
    //printf("\n%f",f);
    printf("\ny(%f) = %f",k,f);
    return 1;
}
