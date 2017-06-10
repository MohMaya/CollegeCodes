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
    float sum=1,x=0.012,num,den,xpow;
    for(int i=1;i<=6;i++)
    {
        xpow=pow(x,i);
        if(i%2==0)
        {
            den=fact(2*i);
            num=i*xpow;
        }
        else
        {
            den=i;
            num=xpow;
        }
        sum+=(num/den);
    }
    printf("Sum = %f",sum);
    return 1;
}
