#include<string.h>
#include<math.h>
#include<stdio.h>
int main()
{char s[100];int a=0,i,k,l,flag=0;
	printf("write the paragraph\n");
	gets(s);
	l=strlen(s);
    for(i=0;i<l;i++)
    {
    	if(s[i]=='.')
    	{
    		for(k=a;k<=((i-1)/2)-1;k++) 
    		{
    			if(s[k]!=s[i-1+a-k])
    			{
    				flag=1;
    				break;
				}
			}
		if(flag==0)
		{
			for(k=a;k<i;k++)
			printf("%c",s[k]);
			printf("\n");
		a=i+1;
		}
		else
		{
		flag=0;
		a=i+1;
	}
		}
		
	}
	return 0;
}
