#include<stdio.h>

long int fact(int x)
{
    if(x<=1)
        return 1;
    return x*fact(x-1);
}

int main()
{
    long factn,factr,factnr;
    long P,C;
    int n,r;
    printf("\nEnter The value of N R\n");
    scanf("%d %d",&n,&r);
    factn=fact(n);
    factr=fact(r);
    factnr=fact(n-r);
    P=factn/factr;
    C=P/factnr;
    printf("\nP(%d,%d) = %ld ",n,r,P);
    printf("\nC(%d,%d) = %ld ",n,r,C);


}
