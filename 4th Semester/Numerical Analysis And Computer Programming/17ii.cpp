#include<stdio.h>
#include<math.h>

float func(float j)
{
    return exp(j+cos(2*j));
}


int main()
{
    float ul,ll,ss;
    int i=0;
    printf("\n Enter the Upper Limit : ");
    scanf("%f",&ul);

    printf("\n Enter the Lower Limit : ");
    scanf("%f",&ll);

    float X[13],Y[13],sum=0,addend;

    X[0]=ll;
    X[12]=ul;

    ss=(ul-ll)/12;
    Y[0]=func(X[0]);
    Y[12]=func(X[12]);

    //Populating X and Y

    for(i=1;i<12;i++)
    {
        X[i]=X[i-1]+ss;
        Y[i]=func(X[i]);
    }

    int c=0;
    printf("\n");
    for(i=0;i<13;i++)
    {

        if(c==0)
            addend=Y[i];
        else if(c==1)
            addend=3*Y[i];
        else if(c==2)
            addend=3*Y[i];
        else
        {
            addend=Y[i];
            c=-1;
            if(i!=12)
                i--;
        }
        c++;
        sum+=addend;

    }

    float integ=((3*ss)/8)*sum;
    printf("\nIntegration is %f",integ);
    return 1;
}
