#include<cstdio>
using namespace std;
int main()
{
	int i,j,n,k,ii;
	scanf("%d%d%d",&n,&i,&j);
	for(k=1;k<=n;k++)
		printf("(%d,%d)",i,k);
	printf("\n");
	for(k=1;k<=n;k++)
		printf("(%d,%d)",k,i);
	printf("\n");
	for(k=1;k<=n;k++)
		for(ii=1;ii<=n;ii++)
			if(k-ii==i-j) printf("(%d,%d)",k,ii);
	printf("\n");
	for(k=n;k>=1;k--)
		for(ii=1;ii<=n;ii++)
			if(k+ii==i+j) printf("(%d,%d)",k,ii);
	printf("\n");
	return 0;		
}
