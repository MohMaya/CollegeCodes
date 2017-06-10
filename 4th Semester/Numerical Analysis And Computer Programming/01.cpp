//programmes to calculate largest of 3 numbers
#include <stdio.h>
int main() {
        float a,b,c;
        printf("Enter the three Numbers\n");
        scanf("%f %f %f",&a,&b,&c);


        printf("\n");
        if (a>b)
        {
                if (a>c)
                {
                        printf("%f is the largest\n",a);
                }
                else
                {
                        printf("%f is the largest\n",c);
                }
        }
        else if(b>a)
        {
                if (b>c)
                {
                        printf("%f is the largest\n",b);
                }
                else
                {
                        printf("%f is the largest\n",c);
                }
        }
        else
        {
            if(a>c)
            {
                printf("%f is the largest\n",a);
            }
            else
            {
                printf("%f is the largest\n",c);
            }
        }

        return 0;
}
