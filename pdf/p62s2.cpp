#include<cstdio>
using namespace std;
int countf(int x);
int main()
{
	int n,s=0,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&y);
		s+=countf(y);
	}
	printf("%.1f",0.1*s);
	return 0;
}
int countf(int x)
{
	 int s=1,r=x-70;
	 while(r>0)
	 {
	 	s++;r-=70;
	 }
	 return s;
} 
