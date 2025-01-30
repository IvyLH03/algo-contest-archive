#include<cstdio>
using namespace std;
double a,b,c,d;
double f(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	double x,x1,x2,i,l,r,m;
	int flag=0;
	for(i=-100;i<=99;i++)
	{
		if(flag==3)
			break;
		l=i;r=i+1;
		x1=f(l);x2=f(r);
		if(x1==0)
		{
			printf("%.2lf ",l);
			flag++;
		}
		if(x1*x2<0)
		{
			while(l<r&&r-l>0.001)
			{
				m=(l+r)/2;
				if(f(l)*f(m)<0)
					r=m;
				else l=m;
					
			}
			printf("%.2lf ",r);
		}
	}
	return 0;
}
