#include<cstdio>
using namespace std;
int main()
{
	int m,n,i;
	scanf("%d%d",&m,&n);
	i=m>n? n:m;
	while(i>1&&(m%i!=0||n%i!=0))
	{
		i-=1;
	}
	printf("%d",i);
	return 0;
}
//ŷ������㷨/շת�����
//48/18=2����12
//18/12=1����6
//12/6=2����0
//*��ʱ6��Ϊ48��18�����Լ��* 
 
