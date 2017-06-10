//Gauss Jordan method to solve simultaneous equation
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
		for(j=0;j<numVar;j++)
		{
      if(i!=j)
      {
        mult=A[j][i]/A[i][i];
  			for(k=0;k<=numVar;k++)
  				A[j][k] = A[j][k] - A[i][k]*mult;
      }
		}
	}

  printf("\nThe Augmented Matrix after Transformations is\n");
	for(i=0;i<numVar;i++)
	{
		for(j=0;j<=numVar;j++)
			printf("%f\t",A[i][j]);
		printf("\n");
	}

  for(i=0;i<numVar;i++)
  {
    x[i]=A[i][numVar]/A[i][i];
  }

  for(i=0;i<numVar;i++)
  {
    printf("\nx%d = %f\n",i+1,x[i]);
  }

  printf("\n");
  return 1;
}
