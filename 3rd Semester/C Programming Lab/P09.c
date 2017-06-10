
#include<stdio.h>


struct date
{
    int d, m, y;
};

const int monthdays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};


int count(struct date d)
{
    int years = d.y;
    if (d.m <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}
int diff(struct date dt1,struct date dt2)
{
    int i;
    long int n1 = dt1.y*365 + dt1.d;
    for (i=0; i<dt1.m - 1; i++)
        n1 += monthdays[i];
    n1 += count(dt1);
    long int n2 = dt2.y*365 + dt2.d;
    for (i=0; i<dt2.m - 1; i++)
        n2 += monthdays[i];
    n2 += count(dt2);
    return (n2 - n1);
}

int main()
{  int m1,m2,d1,d2,y1,y2;
   struct date date1 ,date2;
    printf("Enter fist date(dd-mm-yyyy)     ->");
    scanf("%d-%d-%d",&d1,&m1,&y1);
    printf("\nEnter second date(dd-mm-yyyy)   ->");
    scanf("%d-%d-%d",&d1,&m2,&y2);
    date1.d=d1;
    date1.m=m1;
    date1.y=y1;
    date2.d=d2;
    date2.m=m2;
    date2.y=y2;
    printf("\nDifference between two dates is %d days\n",diff(date1, date2));

    return 0;
}
