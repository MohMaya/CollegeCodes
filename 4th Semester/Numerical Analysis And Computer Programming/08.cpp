#include<stdio.h>
//Fibonacci Sequence of first 50 nos.
int main()
{
    unsigned long int F[50];
    F[0]=1;
    F[1]=1;
    for(int i=2;i<50;i++)
    {
        F[i]=F[i-1]+F[i-2];
    }
    for(int i=0;i<50;i++)
    {
        printf("  %lu  ",F[i]);
    }
    return 1;
}

