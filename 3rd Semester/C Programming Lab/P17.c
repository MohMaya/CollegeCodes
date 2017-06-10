#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[50],s2[50];
    int i,flag=0;

    printf("Enter the two strings\n");
    scanf("%s",s1);

    scanf("%s",s2);

    for(i=0;s1[i] && s2[i];i++)
    {
        if(s1[i]>s2[i])
        {
            flag=1;break;
        }

        else if(s1[i]<s2[i])
        {
            flag=2;break;
        }

    }
    if(s1[i])
    {
        flag=1;
    }
    else if(s2[i])
    {
        flag=2;
    }

    if(flag==1)
    {
        printf("Strings are not equal. 1st string is greater\n");
    }

    else if(flag==2)
    {
        printf("Strings are not equal. 2nd string is greater\n");
    }
    else
    {
        printf("Strings are equal.\n");
    }

    return 0;
}

