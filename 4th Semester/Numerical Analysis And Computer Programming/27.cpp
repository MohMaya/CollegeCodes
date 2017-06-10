//
// Created by Shivanshu Chaudhary on 13/04/17.
// to fit parabola y = a + bx + cx^2

#include <stdio.h>

int main()
{
    int i,j,k,n;
    float a,b,c,x,y,xsq,temp;
    float d[3][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0}};

    printf("\nEnter the value of N : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\n Enter x and y as : x<tab>y\n");
        scanf("%f\t%f",&x,&y);

        xsq=x*x;

        d[0][0]=n;
        d[0][1]+=x;
        d[0][2]+=xsq;
        d[1][2]+=xsq*x;
        d[2][2]+=xsq*xsq;
        d[0][3]+=y;
        d[1][3]+=x*y;
        d[2][3]+=y*xsq;
        d[1][0]=d[0][1];
        d[1][1]=d[0][2];
        d[2][0]=d[0][2];
        d[2][1]=d[1][2];

    }

    //Input taken and augmented matrix taken

    //Normal Equation matrix
    for (i = 0; i < 3; ++i)
    {
        for(j=0;j<4;j++)
        {
            printf("%f\t",d[i][j]);
        }
        printf("\n");
    }


    //Applying Gauss Jordan to get a,b,c

    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 3; ++i) {
            if(i!=j)
            {
                temp = d[i][j]/d[j][j];

                for (int k = 0; k <=3 ; ++k) {
                    d[i][k]=d[i][k] - (d[j][k]*temp);
                }
            }
        }
    }


    a=d[0][3]/d[0][0];
    b=d[1][3]/d[1][1];
    c=d[2][3]/d[2][2];
    printf("\n The Parabolic equation is : y = (%f) + (%f)x + (%f)x^2 \n",a,b,c);


    return 1;
}