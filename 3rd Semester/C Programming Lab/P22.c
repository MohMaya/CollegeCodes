#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int dth(int dec)
{
        int x,c=0;
        char *A;
        A=(char *)malloc(sizeof(char)*50);

        if(dec==0)
        {
                printf("0");
                return 1;
        }
        while(dec!=0)
        {
              //  printf("\n\nINside While");
                x=dec%16;
                dec/=16;
                switch(x)
                {
                                case 0:A[c++]='0';
                                        break;
                                case 1:A[c++]='1';
                                        break;
                                case 2:A[c++]='2';
                                        break;
                                case 3:A[c++]='3';
                                        break;
                                case 4:A[c++]='4';
                                        break;
                                case 5:A[c++]='5';
                                        break;
                                case 6:A[c++]='6';
                                        break;
                                case 7:A[c++]='7';
                                        break;
                                case 8:A[c++]='8';
                                        break;
                                case 9:A[c++]='9';
                                        break;
                                case 10:A[c++]='A';
                                        break;
                                case 11:A[c++]='B';
                                        break;
                                case 12:A[c++]='C';
                                        break;
                                case 13:A[c++]='D';
                                        break;
                                case 14:A[c++]='E';
                                        break;
                                case 15:A[c++]='F';
                                        break;
                                default:printf("default case");

                  }
        }
        for(x=c-1;x>=0;x--)
        {
                printf("%c",A[x]);
        }
        return 0;

}

int bth()
{
        char *bin;
        int dec=0,in=0,i,l;
        bin=(char *)malloc(sizeof(char)*50);
        printf("\n\nEnter the Binary value : ");
        gets(bin);
        gets(bin);
        l=strlen(bin);
        for(i=0;i<l;i++)
        {
                if(bin[i]=='1')
                        dec+=pow(2,l-1-i);
        }
        printf("\n\nThe decimal value is %d",dec);
        printf("\n\nThe HexaDecimal Value is :");
        dth(dec);
        return 0;
}

int htd(char *hex)
{
        int l,i,dec=0;
        l=strlen(hex);
        for(i=0;i<l;i++)
        {
                if(hex[i]=='1')
                        dec+=pow(2,l-1-i);
                else if(hex[i]=='2')
                        dec+=(2*pow(16,l-1-i));
                else if(hex[i]=='3')
                        dec+=(3*pow(16,l-1-i));
                else if(hex[i]=='4')
                        dec+=(4*pow(16,l-1-i));
                else if(hex[i]=='5')
                        dec+=(5*pow(16,l-1-i));
                else if(hex[i]=='6')
                        dec+=(6*pow(16,l-1-i));
                else if(hex[i]=='7')
                        dec+=(7*pow(16,l-1-i));
                else if(hex[i]=='8')
                        dec+=(8*pow(16,l-1-i));
                else if(hex[i]=='9')
                        dec+=(9*pow(16,l-1-i));
                else if(hex[i]=='A')
                        dec+=(10*pow(16,l-1-i));
                else if(hex[i]=='B')
                        dec+=(11*pow(16,l-1-i));
                else if(hex[i]=='C')
                        dec+=(12*pow(16,l-1-i));
                else if(hex[i]=='D')
                        dec+=(13*pow(16,l-1-i));
                else if(hex[i]=='E')
                        dec+=(14*pow(16,l-1-i));
                else if(hex[i]=='F')
                        dec+=(15*pow(16,l-1-i));

        }
        return dec;

}

int htb()
{
        char *h;
        int A[50];
        int dec=0,c=0,x=0;
        h=(char *)malloc(sizeof(char)*50);
        printf("\n\nEnter the Hexadecimal value :");
        gets(h);
        gets(h);
        dec=htd(h);
        while(dec!=0)
        {
              //  printf("\n\nINside While");
                x=dec%2;
                dec/=2;
                switch(x)
                {
                                case 0:A[c++]='0';
                                        break;
                                case 1:A[c++]='1';
                                        break;
                }
        }
        printf("\n\nThe Binary value is : ");
        for(x=c-1;x>=0;x--)
        {
                printf("%c",A[x]);
        }
        return 1;
}

int main()
{
        int cho,dec;
        char *h;
        h=(char *)malloc(sizeof(char)*50);
        while(1)
        {
                printf("\n\nEnter Your Choice :\n1: Decimal to HexaDecimal\n2: Binary to HexaDecimal\n3:HexaDecimal to Decimal\n4: HexaDecimal to Binary \n ANYTHING ELSE TO EXIT ");
                scanf("%d",&cho);
                if(cho==1)
                {
                        printf("\n\nEnter the decimal value :");
                        scanf("%d",&dec);
                        printf("\n\nHexaDecimal value : ");
                        dth(dec);
                }
                else if(cho==2)
                        bth();
                else if(cho==3)
                {
                        printf("\n\nEnter the Hexadecimal value :");
                        gets(h);
                        gets(h);
                        printf("\n\nDecimal value : %d ",htd(h));

                }
                else if(cho==4)
                        htb();
                else
                        break;
        }
        return 0;

}

