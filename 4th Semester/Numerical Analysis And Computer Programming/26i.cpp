//Program to solve given system of equations using gauss elimination

#include <stdio.h>

int main()
{
	int numVar,i,j,k;
	float A[20][20],mult,sum,x[10];
	printf("\nHow many variables do you need to find ? : ");
	scanf("%d",&numVar);
	printf("\nIt seems we'll need %d Equations to solve them",numVar);
	printf("\nEnter the equation in following fashion\n Coefficient of x\tCoefficient of y\t...\tCoefficient of %dth variable\tConstant term\n",numVar);

	for(i=0;i<numVar;i++)
	{
		for(j=0;j<=numVar;j++)
			scanf("%f",&A[i][j]);
	}

	for(i=0;i<numVar;i++)
	{
		for(j=i+1;j<numVar;j++)
		{
			mult=A[j][i]/A[i][i];
			for(k=0;k<=numVar;k++)
				A[j][k] = A[j][k] - A[i][k]*mult;

		}
	}
	//printing Augmented matrix
	printf("\nThe Augmented Matrix after Transformations is\n");
	for(i=0;i<numVar;i++)
	{
		for(j=0;j<=numVar;j++)
			printf("%f\t",A[i][j]);
		printf("\n");
	}

	//Code For back Calculating values of all the variables
	x[numVar-1]=A[numVar-1][numVar]/A[numVar-1][numVar-1];

	for (i= numVar-2;  i>=0 ; i--) {
		/* code */
		sum=0;
		for(j=i+1; j<numVar; j++)
		{
			sum=sum+A[i][j]*x[j];
		}
		x[i]=(A[i][numVar]-sum)/A[i][i];
	}

	printf("\nThe solution is: \n");
	for(i=0; i<numVar; i++)
	{
		printf("\nx%d=%f\t",i,x[i]);
	}
	printf("\n");
	return 1;
}
