#include<stdio.h>
#include<math.h>

unsigned long long int fact(int y)
{
    if(y<=1)
        return 1;
    return y*fact(y-1);
}

int main()
{
    int j;
    float angl,x,xpow,sum=0;
    printf("\nEnter the value of x in Degrees");
    scanf("%f",&angl);
    x=(3.14159265*angl)/180;


    for(int i=0;i<10;i++)
    {
        j=2*i+1;
        printf("\n%d",j);
        xpow=pow(x,j);
        printf("--- %lu",fact(j));
        if(i%2==0)
            sum+=(xpow/fact(j));
        else
            sum-=(xpow/fact(j));
        printf("--- %f",sum);

    }

    printf("\nSin(%f) = %f",angl,sum);
    return 1;
}
