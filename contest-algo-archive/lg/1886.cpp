#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6;
int que1[N][2],que2[N][2],head1,head2,tail1,tail2,a,n,k,ans1[N],ans2[N];
int main()
{
	int i;
	scanf("%d%d",&n,&k);
	head1=head2=1;
	if(k==1)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&ans1[i]);
			ans2[i]=ans1[i];
		}
	}
	for(i=1;i<=n;i++)
	{	
		if(k==1) break;
		scanf("%d",&a);
		while(que1[head1][0]+k<=i) head1++;
		while(que2[head2][0]+k<=i) head2++;
		while(que1[tail1][1]>a&&head1<=tail1) tail1--;
		while(que2[tail2][1]<a&&head2<=tail2) tail2--;
	//	while(que1[head1][1]>a&&head1<=tail1) head1++;
	//	while(que2[head2][1]<a&&head2<=tail2) head2++;
		que1[++tail1][1]=que2[++tail2][1]=a;
		que1[tail1][0]=que2[tail2][0]=i;
		if(i<k) continue;
		ans1[i]=que1[head1][1];	
		ans2[i]=que2[head2][1];
	//	head1++;head2++;
	}
	for(i=k;i<=n;i++)
		printf("%d ",ans1[i]);
	printf("\n");
	for(i=k;i<=n;i++)
		printf("%d ",ans2[i]);
	return 0;
}
