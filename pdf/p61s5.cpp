#include<cstdio>
using namespace std;
int yhe(int x);
int main()
{
	int y=1,t=0,b;
	while(t!=1)
	{
		b=yhe(y);
		if(y==yhe(b)&&y!=b)
		{
			t++;
			printf("(%d<>%d)",y,b);
		}
		y++;
	}
	return 0;
}
int yhe(int x)
{
	int s=0;
	for(int i=1;i<x;i++)
		if(x%i==0)s+=i;
	return s;
}
