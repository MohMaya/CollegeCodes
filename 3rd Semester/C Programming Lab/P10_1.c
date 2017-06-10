
#include<stdio.h>

int maxSubArraySum(int a[], int size)
{
    int max_so_far = 0, max_ending_here = 0,i;

    for (i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}


int main()
{
    int A[50];
    int n,i,max_sum;
    printf("\nEnter the number of elements  : ");
    scanf("%d", &n);

    printf("\nEnter the array elements  : ");
    for(i=0;i<n;i++)
    {
	scanf("%d",  &A[i]);
	printf("\n");
    }
    max_sum = maxSubArraySum(A, n);
    printf("\nMaximum contiguous sum is %d",max_sum);
    return 0;
}
