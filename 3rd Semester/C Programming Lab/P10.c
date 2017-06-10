#include<stdio.h>

int maxsum(int *A, int n)
{
	int current_sum=0,max_so_far=0,i;

	for(i=0;i<n;i++)
	{
		current_sum+=A[i];

		if(max_so_far<current_sum)
		max_so_far=current_sum;
    }

	   return max_so_far;

}



int main()
{

	int A[10],j,n,i;

	printf("\nEnter the number of elements  : ");
	scanf("%d", &n);

	printf("\nEnter the array elements  : ");
	for(i=0;i<n;i++)
	{
	scanf("%d",  &A[i]);
	printf("\n");
	}

	printf("\nThe array elements are : ");
	for(i=0;i<n;i++)
	{
	printf("%d  ", A[i]);
	}

	printf("\nThe maximum sum is  : ");
	int ans=maxsum(A, n);
	printf("%d", ans);

	return 0;
}
