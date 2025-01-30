#include<cstdio>
using namespace std;
const int n=10;
int a[n+1];
float b[n+1];
int main()
{
	int i;
	float s=0;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	b[1]=28.9;b[2]=32.7;b[3]=45.6;b[4]=78;b[5]=35;b[6]=86.2;b[7]=27.8;b[8]=43;b[9]=56;b[10]=65;
	for(i=1;i<=n;i++)
		s+=a[i]*b[i];
	printf("%.1f",s);

}



