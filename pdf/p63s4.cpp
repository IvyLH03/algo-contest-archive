#include<cstdio>
#include<cstring>
using namespace std;
char wz[10001][101],dc[101];
char pd[1];
int situ(char wz[][101],char dc[])
{
	int y=0,i=0;
	while(y==0)
	{
		if(strcmp(wz[i],dc)==0)
		{
			y=i;break;
		}
		i++;
	}
	return y;
}
int sl(char wz[][101],char dc[])
{
	int s=0,i=0;
	while(strcmp(wz[i],pd)!=0)
	{
		//printf("%s.\n%s.\n------\n",wz[i],dc);
		if((strcmp(wz[i],dc))==0)
		{
			s++;
		}
		//printf("js\n");
		i++;
	}
	return s;
}

int main()
{
	int i=0;
	gets(dc);
	while((scanf("%s",wz[i++]))==1);
	strupr(dc);
	for(int j=0;j<i;j++)strupr(wz[j]);
			
			//for(int j=0;j<i;j++)
			//printf("%s",wz[j]);
			//printf("\n");
	//printf("%d",sl(wz,dc));
	if(sl(wz,dc)!=0)
		printf("%d %d",sl(wz,dc),situ(wz,dc));
	else printf("-1");
	return 0;
}
