#include<cstdio>
#include<cstring>
int n,m,q;
char a[201][201],s[201],pxs[201];
void px(int t)
{
	int i,j,r,jsq;
	bool flag;
	strcpy(pxs,s);
	strcat(pxs,pxs);
	for(i=1;i<=t;i++)
	{
		r=0;jsq=1;flag=0;
		if(s[1]>pxs[i])
		{
			for(j=i;j<=i+t;j++)
				s[++r]=pxs[j];
		}
		if(s[1]=pxs[i])
		{
			r=1;
			for(j=i+1;j<=i+t;j++)
			{
				if(s[++r]<pxs[j])
				{
					flag=1;break;
				}
				if(s[r]>pxs[j])
					jsq++;
			}
			if(flag)
				continue;
			if(jsq)
			{ 
				r=0;
				for(j=i;j<=i+t;j++)
					s[++r]=pxs[j];
			}
		}
	}
}
void cz()
{
	memset(s,0,sizeof(s));
	int x,y,t=0,i;
	scanf("%d%d",&x,&y);
	while(x<=n&&y<=m)
	{
		s[++t]=a[x][y];
		x++;y++;
	}
	s[t+1]='\0';
	px(t);
	for(i=1;i<=t;i++)
		printf("%c",s[i]);
	printf("\n");
}
int main()
{
	scanf("%d%d%d\n",&n,&m,&q);
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			scanf("%c",&a[i][j]);
		scanf("\n");
	}
			
	for(i=1;i<=q;i++)
		cz();
	return 0;
}
