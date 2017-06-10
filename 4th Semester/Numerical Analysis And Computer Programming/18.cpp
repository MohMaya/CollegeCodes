#include<stdio.h>
#include<math.h>

float f(float x,float y)
{
	return (cos(x*y)/(1+(x*y)));
}


int main()
{
	float a,b,c,d,h,k,Z[12][12],ax[12],ans;
	int i,j,nx,ny;

	a=0.0,b=1.5,c=0.0,d=1.8,h=0.25,k=0.3;

	nx=(b-a)/h;
	ny=(d-c)/k;

	for(i=0;i<=nx;i++)
	{
		for(j=0;j<=ny;j++)
		{
			Z[i][j]=f(a+(i*h),c+(j*k));
		}
	}

	//Calculating ax
	for(i=0;i<=nx;i++)
	{
		ax[i]=0;
		for(j=0;j<=ny;j++)
		{
			if((j==0)||(j==ny))
				ax[i]+=Z[i][j];
			else if(j%2==0)
				ax[i]+=(2*Z[i][j]);
			else
				ax[i]+=(4*Z[i][j]);
		}
		ax[i]*=(k/3);
	}
	//Simpson's applied


	ans=ax[0]+ax[nx];
	for(i=1;i<nx;i++)
	{
		if((i%6==1)||(i%6==5))
			ans+=(5*ax[i]);
		else if((i%6==2)||(i%6==4))
			ans+=ax[i];
		else if(i%6==3)
			ans+=(6*ax[i]);
		else
			ans+=(2*ax[i]);

	}

	ans *= (0.3*h);
	printf("\n%f",ans);
	return 1;
}
