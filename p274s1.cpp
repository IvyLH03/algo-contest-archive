#include<cstdio>
using namespace std;
int res[1000001];
int main()
{
	int n=0,a,nw,nm;
	scanf("%d",&a);
	while(a!=0)
	{
		nw=0;
		int r=a,w,ls=a;
		while(r!=0)
		{
			w=r%2;
			if(w)nw++;
			r/=2;
		}
		n++;
		while(!res[n])
		{
			nm=0;
			ls++;
			r=ls;
			while(r!=0)
			{
				w=r%2;
				if(w)nm++;
				r/=2;
			}
			if(nm==nw)
				res[n]=ls;
		}
		scanf("%d",&a);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",res[i]);
	return 0;
}
