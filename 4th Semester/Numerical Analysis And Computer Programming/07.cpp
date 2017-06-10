#include<stdio.h>
#include<math.h>

int main()
{
    float a,b,c;
    printf("\nEnter the values of a b c (in QE aX^2+bX+c=0):\n");
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&c);
    float D=pow(b,2)-(4*a*c);

    if(D==0)
    {
        printf("\nRoots are Real and Equal!!!");
        float root=((-1)*b)/(2*a);
        printf("\nRoots are %f and %f",root,root);
    }
    else if(D>0)
    {
        printf("\nRoots are Real and Distinct!!!");
        float rtD=sqrt(D);
        float roota=(((-1)*b)-rtD)/(2*a);
        float rootb=(((-1)*b)+rtD)/(2*a);
        printf("\nRoots are %f and %f",roota,rootb);
    }
    else
    {
        printf("\nRoots are Imaginary");
        float rtD=sqrt(-D);
        float re = ((-1)*b)/(2*a);
        float im = (rtD)/(2*a);
        printf("\nRoots are %f+i(%f) and %f+i(%f)",re,im,re,im);

    }

    return 1;
}
