#include<stdio.h>
#include<stdlib.h>

char b[3][3];
int Board()
{
	int i,j;

	printf("\n\t\t\t\tTIC TAC TOE BOARD");
	printf("\n\t\t\t\t*****************");
	printf("\n\n\n");
	printf("\n\t\t\t    1\t      2\t        3");
	for(i=0;i<3;i++)
	{
		printf("\n \t\t\t _____________________________");
		printf("\n \t\t\t¦\t  ¦\t   ¦\t     ¦");
		printf("\n\t\t%d\t",i+1);
		for(j=0;j<3;j++)
		{

			printf("    %c     ",b[i][j]);
			//printf("           ");


		}
		printf("\n\t\t\t¦\t  ¦\t   ¦\t     ¦");
	}
	printf("\n\t\t\t------------------------------");

}

int chk()
{
        int i;
        for(i=0;i<3;i++)
	{
		if(b[i][0]=='X' && b[i][1]=='X' && b[i][2]=='X')
		{

			printf("\n\nRESULT: Player wins!!");
			printf("\nPress any key............");
			return 1;
		}
	}
	for(i=0;i<3;i++)
	{
		if(b[0][i]=='X' && b[1][i]=='X' && b[2][i]=='X')
		{

			printf("\n\nRESULT: Player wins!!");
			printf("\nPress any key............");
			return 1;
		}
	}
	if(b[1][1]=='X' && b[2][2]=='X' && b[0][0]=='X')
	{


		printf("\n\nRESULT: Player wins!!");
                printf("\nPress any key......");
		return 1;
	}
	else if(b[0][2]=='X' && b[1][1]=='X' && b[2][0]=='X')
	{

		printf("\n\nRESULT: Player wins!!");
                printf("\nPress any key.....");
		return 1;
	}
	for(i=0;i<3;i++)
	{
		if(b[i][0]=='O' && b[i][1]=='O' && b[i][2]=='O')
		{

			printf("\n\nRESULT: Computer wins!!");
			printf("\nPress any key............");
			return 2;
		}
	}
	for(i=0;i<3;i++)
	{
		if(b[0][i]=='O' && b[1][i]=='O' && b[2][i]=='O')
		{

			printf("\n\nRESULT: Computer wins!!");
			printf("\nPress any key............");
			return 2;
		}
	}
	if(b[0][0]=='O' && b[1][1]=='O' && b[2][2]=='O')
	{


		printf("\n\nRESULT: Computer wins!!");
                printf("\nPress any key......");
		return 2;
	}
	else if(b[0][2]=='O' && b[1][1]=='O' && b[2][0]=='O')
	{

		printf("\n\nRESULT: Computer wins!!");
                printf("\nPress any key.....");
		return 2;
	}
	return 0;

}

int comtur()
{
        int i,j;
        for(i=0;i<3;i++)
	{
		if(b[i][1]=='O' && b[i][2]=='O' && b[i][0]==' ')
		{
                        b[i][0]='O';
                        return 1;
		}
		if(b[i][0]=='O' && b[i][2]=='O' && b[i][1]==' ')
		{
                        b[i][1]='O';
                        return 1;
		}
		if(b[i][1]=='O' && b[i][0]=='O' && b[i][2]==' ')
		{
                        b[i][2]='O';
                        return 1;
		}
	}
	for(i=0;i<3;i++)
	{
		if(b[1][i]=='O' && b[2][i]=='O'&& b[0][i]==' ')
		{
                        b[0][i]='O';
                        return 1;
		}
		if(b[0][i]=='O' && b[2][i]=='O' && b[1][i]==' ')
		{
                        b[1][i]='O';
                        return 1;
		}
		if(b[1][i]=='O' && b[0][i]=='O' && b[2][i]==' ')
		{
                        b[2][i]='O';
                        return 1;
		}
	}
	if(b[1][1]=='O' && b[2][2]=='O' && b[0][0]==' ')
        {
                b[0][0]='O';
                return 1;
        }
        if(b[2][2]=='O' && b[0][0]=='O' && b[1][1]==' ')
        {
                b[1][1]='O';
                return 1;
        }
        if(b[1][1]=='O' && b[0][0]=='O' &&  b[2][2]==' ')
        {
                b[2][2]='O';
                return 1;
        }

        if(b[2][0]=='O' && b[1][1]=='O' && b[0][2]==' ')
        {
                b[0][2]='O';
                return 1;
        }
        if(b[0][2]=='O' && b[1][1]=='O' && b[2][0]==' ')
        {
                b[2][0]='O';
                return 1;
        }
        if(b[2][0]=='O' && b[0][2]=='O' && b[1][1]==' ')
        {
                b[1][1]='O';
                return 1;
        }

        for(i=0;i<3;i++)
	{
		if(b[i][1]=='X' && b[i][2]=='X' && b[i][0]==' ')
		{
                        b[i][0]='O';
                        return 1;
		}
		if(b[i][0]=='X' && b[i][2]=='X' && b[i][1]==' ')
		{
                        b[i][1]='O';
                        return 1;
		}
		if(b[i][1]=='X' && b[i][0]=='X' && b[i][2]==' ')
		{
                        b[i][2]='O';
                        return 1;
		}
	}
	for(i=0;i<3;i++)
	{
		if(b[1][i]=='X' && b[2][i]=='X'&& b[0][i]==' ')
		{
                        b[0][i]='O';
                        return 1;
		}
		if(b[0][i]=='X' && b[2][i]=='X' && b[1][i]==' ')
		{
                        b[1][i]='O';
                        return 1;
		}
		if(b[1][i]=='X' && b[0][i]=='X' && b[2][i]==' ')
		{
                        b[2][i]='O';
                        return 1;
		}
	}
	if(b[1][1]=='X' && b[2][2]=='X' && b[0][0]==' ')
        {
                b[0][0]='O';
                return 1;
        }
        if(b[2][2]=='X' && b[0][0]=='X' && b[1][1]==' ')
        {
                b[1][1]='O';
                return 1;
        }
        if(b[1][1]=='X' && b[0][0]=='X' &&  b[2][2]==' ')
        {
                b[2][2]='O';
                return 1;
        }

        if(b[2][0]=='X' && b[1][1]=='X' && b[0][2]==' ')
        {
                b[0][2]='O';
                return 1;
        }
        if(b[0][2]=='X' && b[1][1]=='X' && b[2][0]==' ')
        {
                b[2][0]='O';
                return 1;
        }
        if(b[2][0]=='X' && b[0][2]=='X' && b[1][1]==' ')
        {
                b[1][1]='O';
                return 1;
        }
        for(i=0;i<3;i++)
        {
                if(b[i][i]==' ')
                {
                        b[i][i]='O';
                        return 1;
                }
        }

        for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                {
                        if(b[i][j]==' ')
                        {
                                b[i][j]='O';
                                return 1;
                        }
                }
        }

}

int main()
{

        char *name;
        int sta=0;
        char cho;
        name=(char *)malloc(sizeof(char)*50);
        int i,j,turn=0,r,c;
        for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                        b[i][j]=' ';
        }
        Board();
        printf("\n\nWhat is your name ? ");
        gets(name);
        printf("\n\nYou Get X");

        while(turn<=9)
        {
                printf("\n%s's Turn",name);
                printf("\n\nEnter the row number: ");
                scanf("%d",&r);
                printf("\n\nEnter the column number: ");
                scanf("%d",&c);
                if(b[r-1][c-1]!=' ')
                        continue;
                b[r-1][c-1]='X';
                Board();
                sta=chk();
                if(sta==1)
                        return 1;
                ++turn;
                if(turn>9)
                        break;
                printf("\n\nComputer's Turn");
                comtur();
                Board();
                sta=chk();
                if(sta==2)
                        return 1;

                ++turn;
                if(turn>9)
                        break;

        }
        if(sta==0)
                printf("\n\nMatch Draw");

        //Board(b);


        return 0;
}
