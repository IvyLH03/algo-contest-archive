#include<cstdio>
using namespace std;
int pmax(int a)
{
	int maxn=0;
	while(a)
	{
		if(a%10>maxn)maxn=a%10;
		a/=10;
	}
	return maxn;
}
int cj(int a,int B)
{
	int s=0,j=1;
	while(a)
	{
		s+=a%10*j;
		a/=10;
		j*=B;
	}
	return s;
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	int amax=pmax(a),bmax=pmax(b),cmax=pmax(c),maxn=bmax;
	if(amax>bmax)maxn=amax;
	if(cmax>amax)maxn=cmax;

	int q,p,i,r;
	for(i=maxn;i<=16;i++)
	{
		q=cj(a,i);p=cj(b,i);r=cj(c,i);
		if(q*p==r) break;
	}
	if(i>16)printf("0");
	else printf("%d",i);
	return 0;
}
