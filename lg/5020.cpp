#include<cstdio>
#include<algorithm>				//��ȫ���� (ǡ��) ����
#include<cstring>				//��������Ż� (���仯������) 
using namespace std;
int T,n,a[10007],f[50007];		//f[i]��ʾ������f[i]��������������ֵi 
int main()
{
	int i,j,k,iiiii,tot;
	scanf("%d",&T);
	for(iiiii=1;iiiii<=T;iiiii++)
	{
		memset(f,-1,sizeof(f));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]); 
		sort(a+1,a+1+n);
		
		f[0]=0;
		for(i=1;i<=n;i++)	//ö�ٻ������� 
		{
			for(j=a[i];j<=a[n];j++)		//ö�ٱ�ʾ���  
			{
				if(f[j-a[i]]!=-1)
					f[j]=max(f[j],f[j-a[i]]+1);
			}
		}
		tot=n;
		for(i=n;i>=1;i--)
			if(f[a[i]]>1)
				tot--;
		
		printf("%d\n",tot);
	}
	return 0;
}
