#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int dj;
	int cl;
}a[5001];
bool comp(node i,node j)
{
	return i.dj<j.dj;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i].dj,&a[i].cl);
	sort(a+1,a+1+m,comp);
	int w=0,i=0,s,y=0;
	while(w<n)
	{
		i++;
		if(n-w<a[i].cl)
		{
			s=n-w;
			w=n;
			y+=s*a[i].dj; 
		}
		else
		{
			w+=a[i].cl;
			y+=a[i].cl*a[i].dj;
		}
	}
	printf("%d",y);
	return 0;
}
