#include<math.h>
#include<stdio.h>
#include<string.h>
int main()
{int i,j,n,cnt,cnt2=-1,flag=0,p1,p2,cnt3=0,flag3=0;
	printf("enter the no. of pairs ");
	scanf("%d\n",&n);
	char a[100][100];char b[n][100];char c[n][100];
	char temp[100];
	
	for(i=0;i<n;i++)
	{cnt=-1;
	for(j=0;j<=0;j--)
	{
		scanf("%c",&b[i][++cnt]);
		if(b[i][cnt]==' ')
		break;
	}flag=0;
	b[i][cnt]='\0';
if(cnt2==-1)
{
strcpy(a[++cnt2],b[i]);
}
else
{
	for(j=0;j<=cnt2;j++)
{
	if(strcmp(a[j],b[i])==0)
	{
	flag=1;
	break;
    }
    }
    if(flag==0)
    strcpy(a[++cnt2],b[i]);
}

	cnt=-1;
	for(j=0;j<=0;j--)
	{
		scanf("%c",&c[i][++cnt]);
		if(c[i][cnt]=='\n')
		break;
	}flag=0;
	c[i][cnt]='\0';
	for(j=0;j<=cnt2;j++)
	if(strcmp(c[i],a[j])==0)
	{
	flag=1;
	break;
    }
    if(flag==0)
    strcpy(a[++cnt2],c[i]);
	}
	cnt=0;
while(cnt<n)
{++cnt3;
	for(i=0;i<=cnt2;i++)
	{
	if(strcmp(a[i],b[cnt])==0)
	p1=i;
	else if(strcmp(a[i],c[cnt])==0)
	p2=i;	
	}
	if(p1>p2)
	{
		strcpy(temp,a[p1]);
		strcpy(a[p1],a[p2]);
		strcpy(a[p2],temp);
		cnt=0;
	}
	else
	++cnt;
	if(cnt3==-1)
	{printf("conflicting input,please verify the input data");
	flag3=1;
	break;
	}
}
if(flag3==0)
for(i=0;i<=cnt2;i++)
printf("%s\n",a[i]);
	
}
