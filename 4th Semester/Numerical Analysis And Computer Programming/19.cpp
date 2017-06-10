//Romberg's Method using Simpson's 1/3rd

#include <stdio.h>
#include <math.h>

float f(float x)
{
	return sqrt(pow(x,4)+pow(x,2));
}



int main()
{
	float ul,ll,sum=0,step_size,y;
	int n,i,npts,j,c=0,roundno = 1;
	float ss[10],I[10];


	printf("\nEnter The Lower Limit : ");
	scanf("%f",&ll);

	printf("\nEnter the Upper Limit : ");
	scanf("%f",&ul);

	printf("\nHow many step sizes will you enter ? : ");
	scanf("%d",&n);

	printf("\nEnter the Step Sizes : ");
	for(i=0;i<n;i++)
	{
		scanf("%f",&ss[i]);
	}

	for(i=0;i<n;i++)
	{
		//Calculating  I1, I2 , .... (First order)
		sum=0;
		step_size=ss[i];
		npts = (ul-ll)/step_size;
		for(j=0;j<=npts;j++)
		{
			y=ll+(j*step_size);
			if(y==0||y==ul)	//First + Last
				sum+=f(y);
			else if(j%2==0) //2(Even)
				sum+=(2*f(y));
			else			//4(Odd)
				sum+=(4*f(y));
		}
		sum *= (step_size/3);
		I[c++]=sum;
	}

	/*or(i=0;i<c;i++)
	{
		printf("\n%f",I[i]);
	}*/

	while(c>1)
	{
		for(i=0;i<c-1;i++)
		{
			I[i] = (16*roundno*I[i+1]-I[i])/((16*roundno)-1);
		}
		--c;
		roundno*=4;
	}

	printf("\nTherefore, Integration = %f \n",I[0]);

	return 0;
}