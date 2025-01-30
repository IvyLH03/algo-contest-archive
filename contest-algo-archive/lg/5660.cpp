#include<cstdio>
using namespace std;
int main()
{
	char c;int num=0;
	for(int i=1;i<=8;i++)
	{
		c=getchar();
		if(c=='1') num++;
	}
	printf("%d",num);
	return 0;
 } 
