#include<cstdio>
#include<cmath>
using namespace std;
int ws(int x)
{
	int s;
	if(x==0)return 0;
	else return 1+ws(x/10);

} 
int dx(int x,int r)
{
	if(x==0)return 0;
	else return (x%10)*pow(10,r-1)+dx(x/10,r-1);
}
int main()
{
	int x;
	scanf("%d",&x);
			//printf("%d",ws(x));
	printf("%d\n",dx(x,ws(x)));
	return 0;
} 
