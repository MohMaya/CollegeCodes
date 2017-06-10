#include<stdio.h>

int Page_table[100],Entry_Number[100],Future_Use[100],Final[100][40];
int FrameList[100];
char Fault[40];
int time_value=0;
int m,n,sum;

int check_future_use(int x){
	sum=0;
	for(int k=0;k<m;k++){
		for(int l=x+1;l<n;l++){
			if(Page_table[k]==FrameList[l]){
				Future_Use[k]=1;
				sum++;
			}
		}
		if(sum==m-1){
			return 0; // All but one processes have been found useful in future
		}
	}
	//Multiple processes are not being used in future. Apply FIFO for such cases
	return 1;
}

int reset_Future_Use(){
	for(int k=0;k<m;k++){
		Future_Use[k]=0;
	}
	return 1;
}

int findIndexOf(int x){
	for(int k=0;k<m;k++){
		if(Future_Use[k]==0){
			return k;
		}
	}
	return -1;
}

int main(){
	int entry=-1;
	int ind_to_ins=-1;
	printf("\nEnter the number of pages in page table : ");
	scanf("%d",&m);
	printf("\nEnter the number of frames calls: ");
	scanf("%d",&n);
	printf("\nEnter the list of frames to be accessed : \n");

	for(int i=0;i<n;i++)
	{
		scanf("%d",&FrameList[i]);
	}
	for(int i=0;i<m;i++)
	{
		Entry_Number[i]=-1;
		Future_Use[i]=0;
		Page_table[i]=-1;
	}

	for(int i=0;i<n;i++){
		int ind_to_ins=-1;
		int flag=0;

		for(int j=0;j<m;j++){
			if(Page_table[j]==FrameList[i]){
				//page Already Present; No fault happens
				flag=1;
				Entry_Number[j] = ++entry;
				Fault[i]='o';
				break;
			}
		}

		if(flag==0){
			for(int j=0;j<m;j++){
				if(Page_table[j]==-1){
					Page_table[j]=FrameList[i];	//Empty Location in the Page Table; No replacement required
					Entry_Number[j]=++entry;
					flag=2;
					Fault[i]='f';	//Fault happens
				}
				if(flag==2){
                    break;
				}
			}
			if(flag==0){
				//No empty Location present; replacement needs to be done
				Fault[i]='f';//Fault Happens
				int retval = check_future_use(i);//Update the futureUse Array of all the processes from current process onwards
				if(retval == 0){
					ind_to_ins=findIndexOf(0);
					if(ind_to_ins==-1){
						printf("\nError");
					}
				}else{
					//Applying FIFO amongst 0 future Use progs
					int min_entry = 23456;
					for(int k=0;k<m;k++){
						if((Entry_Number[k]<min_entry)&&(Future_Use[k]==0)){
							min_entry=Entry_Number[k];
							ind_to_ins=k;
						}
					}
				}
				Page_table[ind_to_ins]=FrameList[i];
				Entry_Number[ind_to_ins]=++entry;
			}
		}
        reset_Future_Use();
        for(int j=0;j<m;j++){
                Final[i][j]=Page_table[j];
			}
        printf("\n");
		}

	printf("\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(Final[j][i]==-1){
				printf("\tNULL");
			}
			else{
				printf("\t%d",Final[j][i]);
			}
		}
		printf("\n");
	}
	printf("\n");
	float num_faults = 0;
	for(int i=0;i<n;i++){
		printf("\t%c",Fault[i]);
		if(Fault[i]=='f'){
            num_faults++;
		}
	}
	printf("\nFault Percentage : %f",(num_faults/float(n))*100);
	printf("\n");

}
