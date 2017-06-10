
#include<stdio.h>
struct a{
double x;
double y;
};
struct numdem{
double num;
double dec;
};
int main(){
//struct numdem ndarr[1000];
struct a arr[1000];
int i,j,n;

double final1=0,X,num,dem;
printf("Enter number of complete points\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
   printf("Enter point x y%d\n",i+1);
   scanf("%lf %lf",&arr[i].x,&arr[i].y);
}
printf("Enter Value of X to find F(x)\n");
scanf("%lf",&X);
for(i=0;i<n;i++)
{
        num=1;dem=1;
    for(j=0;j<n;j++)
    {
        if(j!=i)
        {
             num*=X-arr[j].x;
             dem*=arr[i].x-arr[j].x;
            // printf("num %lf dem %lf\n",num,dem);
        }
    }
    if(dem!=0)
    final1+=(num/dem)*arr[i].y;
}
printf("The Value of F(X) is %lf\n",final1);
return 0;
}

