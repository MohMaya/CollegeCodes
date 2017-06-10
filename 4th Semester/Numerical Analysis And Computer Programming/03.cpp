#include<stdio.h>
#include<math.h>
int main()
{
    float sum=0,var=0,sd=0;
    for(int i=1;i<=100;i++)
    {
        sum+=i;
    }
    float mean = sum/100;

    float sqsum=0;
    float diff=0;
    for(int i =1; i<=100;i++)
    {
        diff=mean-i;
        sqsum+=pow(diff,2);
    }
    var=sqsum/100;
    sd=sqrt(var);

    printf("\n %lf %lf %lf",mean,var,sd);

}
