#include<math.h>
#include<stdio.h>
#include<string.h>
int main()
{char s[100];char w[100];
int i,j,l,l2,flag=0,count=0;
	printf("\nEnter your String  ");
	gets(s);
	printf("\nEnter your substring to search  ");
	gets(w);
	l=strlen(s);
	l2=strlen(w);
	for(i=0;i<l;i++)
	{
		if(s[i]==w[0])
		{
			for(j=0;j<l2;j++)
			{
				if(s[i+j]!=w[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				count=count+1;
				printf("\nsubstring found at %d",(i+1));
			}
			else
			flag=0;
		}
	}
	printf("\nsubstring was found %d times",count);

	return 0;
}
