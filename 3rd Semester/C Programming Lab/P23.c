#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int factor(int n,int x)
{
        int i=0;
        //printf("Inside Factor");

        while(n!=0)
        {
    //            printf("Inside Factor While");
                if(n%x==0)
                {
      //                  printf("Inside Factor i++");
                        i++;
                        n=n/x;
                }
                else
                        break;

        }
        if(i!=0)
                printf("(%d^%d)",x,i);
        return 0;

}

int isPrime(int n)
{
        int i,s;
  //      printf("Inside IsPrime");
        s=sqrt(n);
        for(i=2;i<=s;i++)
        {
//                printf("Inside IsPrime for loop");

                if(n%i==0)
                        return 0;
        }
        return 1;
}


int main()
{
        int nu,s,i;
        printf("\n\nEnter the Number whose prime factors are to be determined : ");
        scanf("%d",&nu);

        printf("\n\n\t%d  = ",nu);

        for(i=2;i<=nu;i++)
        {
    //            printf("Inside main for loop");
                if(isPrime(i))
                {
    //                    printf("Inside main if condition");
                        factor(nu,i);
                }
        }




        return 0;
}
