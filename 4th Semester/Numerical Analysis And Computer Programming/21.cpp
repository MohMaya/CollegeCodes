//Solve Differential Equation by R.K. Method

#include <stdio.h>

float f(float a,float b,float c)
{
	return (1+(a*c));
}

float g(float a,float b,float c)
{
	return (-1*a*b);
}

int main()
{
	float x0,y0,z0,z,h;
	int i,n;
	float k[4],l[4];

	x0=0.0;
	y0=0.0;
	z0=1.0;
	h=0.1;

	for (i = 0; i < 5; ++i)
	{
		k[0]=h*f(x0,y0,z0);
		l[0]=h*g(x0,y0,z0);

		k[1]=h*f(x0+(h/2),y0+(k[0]/2),z0+(l[0]/2));
		l[1]=h*g(x0+(h/2),y0+(k[0]/2),z0+(l[0]/2));

		k[2]=h*f(x0+(h/2),y0+(k[1]/2),z0+(l[1]/2));
		l[2]=h*g(x0+(h/2),y0+(k[1]/2),z0+(l[1]/2));

		k[3]=h*f(x0+h,y0+k[2],z0+l[2]);
		l[3]=h*g(x0+h,y0+k[2],z0+l[2]);

		x0=x0+h;
		y0=y0+(k[0]+2*(k[1]+k[2])+k[3])/6;
		z0=z0+(l[0]+2*(l[1]+l[2])+l[3])/6;
	}

	printf("\ny(%f) = %f",x0,y0);
	printf("\nz(%f) = %f\n",x0,z0);

	return 1;
}
