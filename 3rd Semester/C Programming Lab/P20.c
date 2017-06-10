<<<<<<< HEAD
=======
@@ -1,4 +1,155 @@
>>>>>>> a4d00570e66505e51a1cd0cf03ebe3b8ad8f27ce
//Program to print amount of money in words

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dig(int x)
{
        int one,ten,hun,digi;
        digi=x%100;
        one=x%10;
        x=x/10;
        ten=x%10;
        x=x/10;
        hun=x;
        switch(hun)
        {
                case 1: printf(" One hundred ");
                        break;
                case 2: printf(" Two hundred ");
                        break;
                case 3: printf(" Three hundred ");
                        break;
                case 4: printf(" Four hundred ");
                        break;
                case 5: printf(" Five hundred ");
                        break;
                case 6: printf(" Six hundred ");
                        break;
                case 7: printf(" Seven hundred ");
                        break;
                case 8: printf(" Eight hundred ");
                        break;
                case 9: printf(" Nine hundred ");
                        break;

        }
        //printf(" ");
        if(ten!=1)
        {

                switch(ten)
                {
                        case 2: printf(" Twenty ");
                                break;
                        case 3: printf(" Thirty ");
                                break;
                        case 4: printf(" Forty ");
                                break;
                        case 5: printf(" Fifty ");
                                break;
                        case 6: printf(" Sixty ");
                                break;
                        case 7: printf(" Seventy ");
                                break;
                        case 8: printf(" Eighty ");
                                break;
                        case 9: printf(" Ninty ");
                                break;

                }


                switch(one)
                {
                        case 1: printf(" One ");
                                break;
                        case 2: printf(" Two ");
                                break;
                        case 3: printf(" Three ");
                                break;
                        case 4: printf(" Four ");
                                break;
                        case 5: printf(" Five ");
                                break;
                        case 6: printf(" Six ");
                                break;
                        case 7: printf(" Seven ");
                                break;
                        case 8: printf(" Eight ");
                                break;
                        case 9: printf(" Nine ");
                                break;

                }
        }
        else
        {
                switch(digi)
                {
                        case 11: printf(" Eleven ");
                                break;
                        case 12: printf(" Twelve ");
                                break;
                        case 13: printf(" Thirteen ");
                                break;
                        case 14: printf(" Fourteen ");
                                break;
                        case 15: printf(" Fifteen ");
                                break;
                        case 16: printf(" Sixteen ");
                                break;
                        case 17: printf(" Seventeen ");
                                break;
                        case 18: printf(" Eighteen ");
                                break;
                        case 19: printf(" Ninteen ");
                                break;
                        case 10: printf(" Ten ");
                                break;
                }
        }
        return 0;
}

int cat(int x)
{
        switch(x)
        {
        case 1:
                break;
        case 2: printf(" Thousand ");
                break;
        case 3: printf(" Million ");
                break;
        case 4: printf(" Billion ");
                break;
        case 5: printf(" Trillion ");
                break;
        }
        return 0;
}

int main()
{
        int i,am,temp,c=0,n;
        int A[30];
        printf("\nEnter the amount :");
        scanf("%d",&am);
        temp=am;
        while(temp!=0)
        {
                n=temp%1000;
                temp/=1000;
                A[c++]=n;
        }
        for(i=c-1;i>=0;i--)
        {
                dig(A[i]);
                if(A[i]!=0)
                        cat(i+1);

        }
        return 0;
}
