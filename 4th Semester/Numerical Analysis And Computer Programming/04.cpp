#include<stdio.h>
#include<math.h>
int main()
{
    float sum=0,var=0,sd=0;
    float val[15];
    printf("\nEnter the values(15)\n");

    for(int i=0;i<15;i++)
    {
        scanf("%f",&val[i]);

    }

    for(int i=0;i<15;i++)
    {
        sum+=val[i];
    }

    float mean = sum/15;

    float sqsum=0;
    float diff=0;
    for(int i =0; i<15;i++)
    {
        diff=mean-val[i];
        sqsum+=pow(diff,2);
    }
    var=sqsum/15;
    sd=sqrt(var);

    printf("\n %f %f %f",mean,var,sd);

}
