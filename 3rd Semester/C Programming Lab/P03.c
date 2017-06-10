#include<stdio.h>


char str[1000];
int main()
{
    printf("ENTER THE STRING :");
    gets(str);
    int i=0,spaces=0,tab=0,line=0,vowels=0,words=0;
    while(str[i]!='\0')
    {
        if(str[i]==' ')
            spaces++;
        else if(str[i]=='\t')
            tab++;
        else if(str[i]=='\n')
            line++;
        else if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
            vowels++;
         if((i-1>=0)&&(str[i]==' '||str[i]=='\t')&&(str[i-1]!=' '&&str[i-1]!='\t'))
            words++;
        i++;
    }
    printf("\nWords: %d",words+1);
    printf("\nSpaces: %d",spaces);
    printf("\nTabs: %d",tab);
    printf("\nVowels: %d",vowels);
    printf("\nFinal String : ");
    i=0;
     while(str[i]!='\0')
    {
    if(str[i]==' '||str[i]=='\t')
    {
        while(str[i]!='\0'&&(str[i]==' '||str[i]=='\t'))
            i++;
            printf(" ");
    }
    printf("%c",str[i]);

    i++;
    }
return 0;
}
