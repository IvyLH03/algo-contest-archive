#include<cstdio>
#include<cmath>
using namespace std;
bool hw(int x);
bool ss(int x);
int main()
{
	for(int i=100;i<=999;i++)
		if(hw(i)==1&&ss(i)==1)printf("%5d",i);
	return 0;
}
bool hw(int x)
{
	if(x%10==x/100)return 1;
	else return 0;
}
bool ss(int x)
{
	int y=2;
	while(x%y!=0&&y<=sqrt(x))y++;
	if(x%y!=0)return 1;
	else return 0;
}
