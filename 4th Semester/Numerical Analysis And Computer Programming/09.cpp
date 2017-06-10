#include<stdio.h>
#include<math.h>

int isPrime(int x)
{
    if(x<2)
        return 0;
    if(x==2)
        return 1;
    int j=int(sqrt(x));
    for(int i=2;i<=j;i++)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    int n,countn=0,j=1;
    printf("\nEnter the value of n\n");
    scanf("%d",&n);
    while(countn<=n)
    {
        if(isPrime(j))
        {
            if(!((j%5==0)||(j%7==0)))
                printf(" %d ",j);
            countn++;
        }
        j++;
    }
    return 1;
}
