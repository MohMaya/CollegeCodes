#include<algorithm>
#include<stdio.h>

using namespace std;

int main(){

    int DiskLoc[30];
    int NDiskLoc,FirstStep,LastCyl,BegCyl=0,HeadStart;
    int suma=0;
    printf("\nEnter Last Cylinder's adress : ");
    scanf("%d",&LastCyl);

    printf("\nEnter the number of Disk locations : ");
    scanf("%d",&NDiskLoc);

    printf("\nEnter the disk Locations : ");
    for(int i=0;i<NDiskLoc;i++){
        scanf("%d",&DiskLoc[i]);
    }

    printf("\nEnter the starting position for the head : ");
    scanf("%d",&HeadStart);

    sort(DiskLoc,DiskLoc+NDiskLoc);
    int flag=0;//Will Decide whether to move left or to move right
    int i=0;
    while((DiskLoc[i]<HeadStart)&&(i<NDiskLoc)){
        i++;
    }
    i=i-1;
    FirstStep = i;
    int LeftDiff = HeadStart - DiskLoc[i];
    int RightDiff= DiskLoc[i+1]-HeadStart;
    printf("\n%d ---> ",HeadStart);
    if(LeftDiff>RightDiff){
        //Move Right
        printf("%d ---> ",DiskLoc[i+1]);
        suma+=(DiskLoc[i+1] - HeadStart);

        for(int j=i+2;j<NDiskLoc;j++){
            suma+=(DiskLoc[j] - DiskLoc[j-1]);
            printf("%d ---> ",DiskLoc[j]);
        }
        suma += LastCyl - DiskLoc[NDiskLoc-1];
        printf("%d ---> %d --->",LastCyl,BegCyl);
        suma += DiskLoc[0] - BegCyl;
        for(int j=0;j<i;j++){
            suma+=(DiskLoc[j+1] - DiskLoc[j]);
            printf("%d ---> ",DiskLoc[j]);
        }
        printf("%d\n",DiskLoc[i]);
    }else{
        //Move Left
        printf("%d ---> ",DiskLoc[i]);
        suma+=(HeadStart - DiskLoc[i]);

        for(int j=i-1;j>=0;j--){
            suma+=(DiskLoc[j+1] - DiskLoc[j]);
            printf("%d ---> ",DiskLoc[j]);
        }
        suma += DiskLoc[0]-BegCyl;
        printf("%d ---> %d ---> ",BegCyl,LastCyl);
        suma += LastCyl - DiskLoc[NDiskLoc-1];
        for(int j=NDiskLoc-1;j>i+1;j--){
            suma+=(DiskLoc[j] - DiskLoc[j-1]);
            printf("%d ---> ",DiskLoc[j]);
        }
        printf("%d\n",DiskLoc[i+1]);
    }

    printf("\nTotal Head Movements : %d ",suma);
    return 1;
}
