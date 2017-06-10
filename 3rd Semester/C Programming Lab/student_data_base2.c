//student database 
// in this program it is assumed that filenew.txt exist in same folder of code
// if not please create it.....


#include<stdio.h>
#include<stdlib.h>

int main()
  { char name[50];
  int class;
  char sec;
  int rollno;
  float per;
   int d;
    FILE *fp=fopen("filenew.txt","a");
    fseek(fp, 0, SEEK_END);
    int s=ftell(fp);
    if(s==0)
   {
    fprintf(fp,"%-15s","ROLL_NO:");
    fprintf(fp,"%-50s ","NAME");
    fprintf(fp,"%-19s","CLASS");
    fprintf(fp,"%-15s","SEC");
    fprintf(fp,"%-15s\n","PERCENTAGE");
   }
  do
   {
     printf("\n1 :Enter student detail\n");
     printf("2 :Exit\n");
     scanf("%d",&d);
     switch(d)
      {
        case 1: printf("\nEnter the name of student:"); getchar();
                gets(name);
                printf("\nEnter the class of student:");
                scanf("%d",&class);

                printf("\nEnter the section of student:");getchar();
                scanf("%c",&sec);
               
         	printf("\nEnter the rollno of student:");getchar();
                scanf("%d",&rollno);
                
                printf("\nEnter the percentage of student:");getchar();
                scanf(" %f",&per);
                
                fprintf(fp,"%-15d",rollno);
    		fprintf(fp,"%-50s",name);
    		fprintf(fp,"%-20d",class);
   		fprintf(fp,"%-15c",sec);
    		fprintf(fp,"%-15.2f\n",per);
                
      break;
        case 2: fclose(fp);
                exit(0);
      break;
        default : printf("\nWrong input");
         }
    }while(1);  
     fclose(fp);   
    return 0;
  }
