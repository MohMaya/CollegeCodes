#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char text[1000];
    int j=-1,i;
    printf("Enter the text. Enter # in the end.\n");
    while(1)
    {
        char ch = getchar();
        if(ch=='#')
            break;

        else if(text[j] ==' ' && ch==' ' )
        {}

        else if(text[j] =='\n' && ch=='\n')
        {}

        else if(text[j]=='\t' && ch=='\t')
        {}
        else
        {
            text[++j]=ch;
        }

    }

    for(i=0;i<=j;i++)
    {
        printf("%c",text[i]);
    }

    return 0;
}


