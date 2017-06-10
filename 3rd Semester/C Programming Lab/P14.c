#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[40];

    printf("Enter Email ID\n");
    fgets(s,40,stdin);

    int len = strlen(s);


    int end=len-2,i=0,flag=0;
    while(s[i])
    {
        if(s[i]=='@')
        {
            flag++;break;
        }
        i++;
    }


    if( s[end-3]=='.' && s[end-2]=='c' &&s[end-1]=='o'&&s[end]=='m')
        flag++;
    else if(  s[end-2]=='.' && s[end-1]=='i' &&s[end]=='n')
        flag++;
    else if(  s[end-5]=='.' && s[end-4]=='a' && s[end-3]=='c' && s[end-2]=='.' &&s[end-1]=='i'&&s[end]=='n')
        flag++;
   else if( s[end-5]=='.' &&   s[end-4]=='c' &&  s[end-3]=='o' && s[end-2]=='.' && s[end-1]=='i' &&s[end]=='n')
        flag++;

    if(flag==2)
            printf("VALID\n");
    else
            printf("INVALID\n");
    return 0;
}

