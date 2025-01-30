#include<cstdio>
using namespace std;
int main()
{
	float scall,schigh,sclow,high,low,sc;
	scall=6*9.6;
	schigh=5*9.4;
	sclow=5*9.8;
	high=scall-schigh;
	low=scall-sclow;
	sc=(scall-high-low)/4;
	printf("%5.2f\n",sc);
	return 0;
}
