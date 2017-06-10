#include <stdio.h>

float F(float x,float y)
{
	return ((x*x*x)+(3*y));
}

int main()
{
	float x[10],y[10],f[10];
	float ypred,fpred,ycorr,xin,h=0.2;
	int n,i;
	
	
	x[0]=3;
	x[1]=3.2;
	x[2]=3.4;
	x[3]=3.6;
	
	y[0]=2.7;
	y[1]=12.366;
	y[2]=27.324;
	y[3]=47.574;
	
	for (i = 0; i < 4; ++i)
	{
		/* code */
		f[i]=F(x[i],y[i]);
		printf("\nf[%d] = %f",i,f[i]);
	}
	xin=3.8;


	ypred = y[0] +(((4*h)/3)*((2*f[1])-f[2]+(2*f[3])));
	fpred = F(xin,ypred);
	ycorr = y[2] + ((h/3)*(f[2]+(4*f[3])+fpred));

	printf("\nypredicted = %f",ypred);
	printf("\nfpredicted = %f",fpred);
	printf("\nycorrected = %f\n",ycorr);

	return 1;
}