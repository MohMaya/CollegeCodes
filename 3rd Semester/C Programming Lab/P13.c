#include <stdio.h>
#include <stdlib.h>

int main()
{
     float a,b,c,d;
     int i,j;
    char S[50],ch1[10],ch2[10],ch3[10],ch4[10];

  printf("Enter the complex numbers in the following format\n(a,b),(c,d) \n");
    scanf("%s",S);

    j=-1;
    for(i=1;S[i]!=',';i++)
    {
        ch1[++j]=S[i];
    }
    ch1[++j]='\0';
    a=atof(ch1);



    j=-1;i++;
    for(;S[i]!=')';i++)
    {
        ch2[++j]=S[i];
    }

    b=atof(ch2);



    j=-1;i+=3;
    for(;S[i]!=',';i++)
    {
        ch3[++j]=S[i];
    }
    c=atof(ch3);



    j=-1;i++;
    for(;S[i]!=')';i++)
    {
        ch4[++j]=S[i];
    }
    d=atof(ch4);

   printf("Sum of two numbers is %0.3f +i%0.3f\n",a+c,b+d);
   printf("Difference of two numbers is %0.3f +i%0.3f\n",a-c,b-d);
   printf("Product of two numbers is %0.3f +i%0.3f\n",a*c-b*d,a*d+b*c);
   printf("Quotient of two numbers is %0.3f +i%0.3f\n",(a*c+b*d)/(c*c+d*d),(b*c-a*d)/(c*c+d*d));

    return 0;
}

