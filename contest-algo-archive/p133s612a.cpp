#include<cstdio>
using namespace std;
int ys(int m,int n)
{
	if(m==n)return m;
	if(m<n) return ys(n,m);
	 
	if(m%2==0)
	{
		if(n%2==0)return 2*ys(m/2,n/2);
	 	else return ys(m/2,n);
	}
	else
	{
		if(n%2==0)return ys(m,n/2);
		else return ys(n,m-n);
	}

}
int main()
{
	int m,n;
	scanf("%d%d",m,n);
	printf("%d\n",ys(m,n));
	return 0;
}
