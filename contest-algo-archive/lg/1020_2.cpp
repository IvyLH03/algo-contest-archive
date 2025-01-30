#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100007;
int a[N],c[N],n;
int main()
{	
	
	while(~scanf("%d",&a[++n]));
	int len=1; c[1]=a[1];
	for(int i=2;a[i];i++)
	{
		int l=1,r=len,mid,p=0;
		while(l<=r)
		{
			mid=l+(r-l>>1);
			if(c[mid]>=a[i]) p=mid,l=mid+1;
			else r=mid-1;
		} 
	//	printf("a[%d]=%d,p=%d\n",i,a[i],p);
		c[p+1]=a[i];
		if(p==len) len++;
	}	
	printf("%d\n",len);
	for(int i=2;a[i];i++) c[i]=0;
	len=1;
	for(int i=2;a[i];i++)
	{
		int l=1,r=len,mid,p=0;
		while(l<=r)
		{
			mid=l+(r-l>>1);
			if(c[mid]<a[i]) p=mid,l=mid+1;
			else r=mid-1;
		}
		c[p+1]=a[i];
		if(p==len) len++;
	 } 
	printf("%d\n",len);
	return 0;
 } 
