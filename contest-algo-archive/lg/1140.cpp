#include<cstdio>
using namespace std;
int f[101][101],s1[101],s2[101],len1,len2;
int max(int a,int b)
{
	return a>b?a:b;
}
int sim[5][5]={
	{0,-3,-4,-2,-1},
	{-3,5,-1,-2,-1},
	{-4,-1,5,-3,-2},
	{-2,-2,-3,5,-2},
	{-1,-1,-2,-2,5}	
} ;
int main()
{
	char a;
	int i,j;
	scanf("%d ",&len1);
	for(i=1;i<=len1;i++)
	{
		scanf("%c",&a);
		switch(a)
		{
			case 'A':{s1[i]=1;break;}
			case 'C':{s1[i]=2;break;} 
			case 'G':{s1[i]=3;break;} 
			case 'T':{s1[i]=4;break;}
		}
	} 
	scanf("%d ",&len2);
	for(i=1;i<=len2;i++)
	{
		scanf("%c",&a);
		switch(a)
		{
			case 'A':{s2[i]=1;break;}
			case 'C':{s2[i]=2;break;} 
			case 'G':{s2[i]=3;break;} 
			case 'T':{s2[i]=4;break;}
		}
	}
	for(i=1;i<=len1;i++)
		f[i][0]=f[i-1][0]+sim[s1[i]][0];
	for(i=1;i<=len2;i++)
		f[0][i]=f[0][i-1]+sim[s2[i]][0];
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			f[i][j]=f[i-1][j-1]+sim[s1[i]][s2[j]];
			f[i][j]=max(f[i][j],f[i-1][j]+sim[s1[i]][0]);
			f[i][j]=max(f[i][j],f[i][j-1]+sim[s2[j]][0]);
		}
	}
	printf("%d",f[len1][len2]);
	return 0;
}


