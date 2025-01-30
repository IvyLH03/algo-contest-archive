#include<cstdio>
using namespace std;
int pow(int b)
{
	int t=1;
	for(int i=1;i<=b;i++)
		t*=2;
	return t;
}
int mx(int x,int n,int t)
{
	if(x<=n&&x*2>n)
		return t;
	else return mx(x*2,n,++t);
}
void f(int p,int time)
{
	if(p==1)
	return;
		
	if(time!=1)
		printf("(");
	if(p==2)
	{
		printf("2");
		//return;
	}
	
	else
	{
		int temp=p,t=0;
		
		while(temp)
		{
			int s=mx(1,temp,0);	
			if(++t!=1)
				printf("+");
			temp-=pow(s);	
			printf("2");
			if(s!=1&&s!=0)
				f(s,time+1);
			else if(s==0)
					printf("(0)");
		}
	}
	if(time!=1)
		printf(")");
}
int main()
{
	int n;
	scanf("%d",&n);
	f(n,1);
	return 0;
}
