#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ans[30],n,m,a[31][31],f[31][31][30],temp[31],pow2[81][30],d[31],e[31];
void fplus(int x[],int y[],int z[])
{
	int sn=0,r,i;
	for(i=1;i<=29;i++)
	
	{
		r=x[i]+y[i];
		z[i]=r%10+sn;
		sn=r/10;
	}
}
void fmult(int x[],int y,int z[])
{
	int s=0,r,p,i; 
	for(i=1;i<=29;i++)
	{
		r=x[i]*y+s;
		s=r/10;
		z[i]=r%10; 
	}
} 
void fcpy(int x[],int y[])
{
	int i;
	for(i=1;i<=29;i++)
		x[i]=y[i];
}
void fmax(int x[],int y[],int z[])
{
	int i,lenx,leny;
	for(i=29;i>=1;i--)
		if(x[i])
		{
			lenx=i;break;
		}
	for(i=29;i>=1;i--)
		if(y[i])
		{
			leny=i;break;
		} 
	if(lenx>leny)
	{
		fcpy(z,x);return;
	}
	if(lenx<leny)
	{
		fcpy(z,y);return;
	}
	for(i=lenx;i>=1;i--)
	{
		if(z[i]>y[i])
		{
			fcpy(z,x);return;
		}
		if(z[i]<y[i])
		{
			fcpy(z,y);return;
		}
	}
	fcpy(z,x);return;
	
}
void printpow2()
{
	int i,j,r,len;
	for(i=1;i<=m;i++)
	{
		for(j=29;j>=1;j--)
			if(pow2[i][j])
			{
				len=j;break;
			}
		for(j=len;j>=1;j--)
			printf("%d",pow2[i][j]);
		printf(" ");
	}
	printf("\n");
}
void fprint(int x[])
{
	int len,i;bool flag=0;
	for(i=29;i>=1;i--)
		if(x[i])
		{
			len=i;flag=1;
			break;
		}
	if(!flag)
	{
		printf("0");return;
	}
	for(i=len;i>=1;i--)
		printf("%d",x[i]);
}
int main()
{
	
	int i,j,k,len;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	
	pow2[0][1]=1;
	for(i=1;i<=m;i++)
	{
		fmult(pow2[i-1],2,pow2[i]);
	}
//	printpow2();
	
	 
	for(k=1;k<=n;k++)
	{
		memset(f,0,sizeof(f));
		for(i=1;i<=m;i++)
		{
			for(j=m;j>=i;j--)
			//	f[i][j]=max(f[i-1][j]+a[k][i-1]*_2pow(m-j+i-1),f[i][j+1]+a[k][j+1]*_2pow(m-j+i-1));
			{
				memset(d,0,sizeof(d));
				memset(e,0,sizeof(e));
				fmult(pow2[m-j+i-1],a[k][i-1],d);
				fmult(pow2[m-j+i-1],a[k][j+1],e);
				fplus(d,f[i-1][j],d);
				fplus(e,f[i][j+1],e);
				fmax(d,e,f[i][j]);
			}	
		}
		
		for(i=1;i<=m;i++)
		{
			memset(d,0,sizeof(d));
			fmult(pow2[m],a[k][i],d);
			fplus(f[i][i],d,f[i][i]);
		}
		
		memset(temp,0,sizeof(temp));
		for(i=1;i<=m;i++)
			fmax(temp,f[i][i],temp);
							
						//	fprint(temp);
						//	printf(" ");
		fplus(ans,temp,ans);
	}
							//printf("*\n");
	
	fprint(ans);
		
	return 0;
}
