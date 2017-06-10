#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{int i,j,x,y,hx=0,tx=0,hy=2,ty=0,flag=0;char c;
	char a[10][10];
	printf("***THESE INTRUCTION WILL REMAIN FOR 10 SEC ONLY PLEASE READ CAREFULLY***\n");
	printf("SNAKE GAME\n");
	printf("instructions:\n");
	printf("1.to move up press u\n");
	printf("2.to move down press d\n");
	printf("3.to move right press r\n");
	printf("4.to move left press l\n");
	sleep(5);
	for(i=0;i<10;i++)
	for(j=0;j<10;j++)
	a[i][j]='-';
	a[0][0]='#';
	a[0][1]='#';
	a[0][2]='@';
	while(1)
	{ 
	 while(1)
	{
		x=rand()%10;
		y=rand()%10;
		if(a[x][y]=='#')
		continue;
		else
		break;
    }
		a[x][y]='*';
		system("cls");
		for(i=0;i<10;i++)
		{
	     for(j=0;j<10;j++)
	      printf("%c",a[i][j]);
	      printf("\n");
        }
		while(1)
		{
		scanf("%c",&c);
		
		if(c=='u')
		{
			if(hx==0)
			{
				flag=1;
				printf("###GAME OVER##");
				break;
			}
			else if(a[hx-1][hy]=='#')
			{
			flag=1;
			printf("###GAME OVER###");
			break;
		   }
			else if(a[hx-1][hy]=='*')
			{a[hx][hy]='#';
				a[hx-1][hy]='@';
				hx=hx-1;
				system("cls");
				for(i=0;i<10;i++)
		{
	     for(j=0;j<10;j++)
	      printf("%c",a[i][j]);
	      printf("\n");
        }break;
			}
			else
			{a[hx][hy]='#';
			a[hx-1][hy]='@';
				hx=hx-1;
				a[tx][ty]='-';
				if(a[tx+1][ty]=='#')
				tx=tx+1;
				else if(a[tx-1][ty]=='#')
			    tx=tx-1;
				else if(a[tx][ty+1]=='#')
				ty=ty+1;
				else
				ty=ty-1;
				
			}
			system("cls");
			for(i=0;i<10;i++)
		{
	     for(j=0;j<10;j++)
	      printf("%c",a[i][j]);
	      printf("\n");
        }
			}
	else if(c=='d')
	{
			if(hx==9)
			{
				flag=1;
				printf("###GAME OVER##");
				break;
			}
			else if(a[hx+1][hy]=='#')
			{
			flag=1;
			printf("###GAME OVER###");
			break;
		   }
			else if(a[hx+1][hy]=='*')
			{a[hx][hy]='#';
				a[hx+1][hy]='@';
				hx=hx+1;
				for(i=0;i<10;i++)
		{system("cls");
	     for(j=0;j<10;j++)
	      printf("%c",a[i][j]);
	      printf("\n");
        }
        break;
			}
			else
			{a[hx][hy]='#';
				a[hx+1][hy]='@';
				hx=hx+1;
				a[tx][ty]='-';
				if(a[tx+1][ty]=='#')
				tx=tx+1;
				else if(a[tx-1][ty]=='#')
			    tx=tx-1;
				else if(a[tx][ty+1]=='#')
				ty=ty+1;
				else
				ty=ty-1;
				
			}
			system("cls");
			for(i=0;i<10;i++)
		{
	     for(j=0;j<10;j++)
	      printf("%c",a[i][j]);
	      printf("\n");
        }
			}
	if(c=='r')
		{
			if(hy==9)
			{
				flag=1;
				printf("###GAME OVER##");
				break;
			}
			else if(a[hx][hy+1]=='#')
			{
			flag=1;
			printf("###GAME OVER###");
			break;
		   }
			else if(a[hx][hy+1]=='*')
			{a[hx][hy]='#';
				a[hx][hy+1]='@';
				hy=hy+1;
				system("cls");
				for(i=0;i<10;i++)
		{
	     for(j=0;j<10;j++)
	      printf("%c",a[i][j]);
	      printf("\n");
        }break;
			}
			else
			{a[hx][hy]='#';
			a[hx][hy+1]='@';
				hy=hy+1;
				a[tx][ty]='-';
				if(a[tx+1][ty]=='#')
				tx=tx+1;
				else if(a[tx-1][ty]=='#')
			    tx=tx-1;
				else if(a[tx][ty+1]=='#')
				ty=ty+1;
				else
				ty=ty-1;
				
			}
			system("cls");
			for(i=0;i<10;i++)
		{
	     for(j=0;j<10;j++)
	      printf("%c",a[i][j]);
	      printf("\n");
        }
			}
	else if(c=='l')
	{
			if(hy==0)
			{
				flag=1;
				printf("###GAME OVER##");
				break;
			}
			else if(a[hx][hy-1]=='#')
			{
			flag=1;
			printf("###GAME OVER###");
			break;
		   }
			else if(a[hx][hy-1]=='*')
			{a[hx][hy]='#';
				a[hx][hy-1]='@';
				hy=hy-1;
			system("cls");	
				for(i=0;i<10;i++)
		{
	     for(j=0;j<10;j++)
	      printf("%c",a[i][j]);
	      printf("\n");
        }
        break;
			}
			else
			{a[hx][hy]='#';
				a[hx][hy-1]='@';
				hy=hy-1;
				a[tx][ty]='-';
				if(a[tx+1][ty]=='#')
				tx=tx+1;
				else if(a[tx-1][ty]=='#')
			    tx=tx-1;
				else if(a[tx][ty+1]=='#')
				ty=ty+1;
				else
				ty=ty-1;
				
			}
			system("cls");
			for(i=0;i<10;i++)
		{
	     for(j=0;j<10;j++)
	      printf("%c",a[i][j]);
	      printf("\n");
        }
			}
		}
		if(flag==1)
		break;
	
	}
	
	return 0;
}
