#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
        int l1,l2,l3=0;
        int i;
        char *S1,*S2,*S3;
        S1=(char *)malloc(sizeof(char)*100);
        S2=(char *)malloc(sizeof(char)*100);
        S3=(char *)malloc(sizeof(char)*100);
        printf("\nEnter String one : ");
        gets(S1);
        printf("\nEnter String Two : ");
        gets(S2);
        l1=strlen(S1);
        l2=strlen(S2);

        for(i=0;i<l1;i++)
        {
                S3[l3++]=S1[i];
        }

        for(i=0;i<l2;i++)
        {
                S3[l3++]=S2[i];
        }

        printf("\n\nThe final String is : ");

        for(i=0;i<l3;i++)
        {
                printf("%c",S3[i]);
        }

        return 0;

}
