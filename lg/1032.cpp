#include<cstdio>
#include<cstring>
using namespace std;
char a[21],b[21],ls[21];
struct node
{
	char a[21],b[21],sz;
	int lena,lenb;
}gz[7];
struct jkl
{
	char s[21];
	int bs;
	int lens;
}que[100001];
int gzn;
bool pdc(int ws,int bh,int t)
{
	for(int i=ws;i<=ws+gz[bh].lena;i++)
		if(que[t].s[i]!=gz[bh].a[i])
			return 0;
	return 1;
}
void bh(int t,int w,int j,int i)
{
	int k,r;
	for(k=0;k<j;k++)
		ls[k]=que[t].s[k];
	r=0;
	for(k=j;k<j+gz[i].lenb;k++)
		ls[k]=gz[i].b[r++];
	r=j+gz[i].lena;
	for(k=j+gz[i].lena;k<que[t].lens;k++)
		ls[k]=que[t].s[k];
	que[w].s[k]='\0';
}
int main()
{
	scanf("%s%s",a,b);
	while(scanf("%s%s",gz[++gzn].a,gz[gzn].b))
	{			//	printf("7.\n");
		gz[gzn].lena=strlen(gz[gzn].a);
		gz[gzn].lenb=strlen(gz[gzn].b);
		gz[gzn].sz=gz[gzn].a[0];
	}
	
	int t=1,w=1;
	strcpy(que[1].s,a);
	que[1].bs=0;
	que[1].lens=strlen(que[1].s);
	
	while(t<=w)
	{	
		if(que[t].bs>10)
			break;
		if(strcmp(que[t].s,b)==0)
		{
			printf("%d",que[t].bs);
			return 0;
		}
		for(int i=1;i<=gzn;i++)//Ã¶¾Ù¹æÔò 
		{
			for(int j=0;j<que[t].lens;j++) 
			{
				if(pdc(j,i,t))
				{
					bh(t,w++,j,i);
					int r=0;
					for(int k=1;k<w;k++)
						if(!strcmp(ls,que[k].s))
						{
							r=1;break;
						}
					if(r)
						continue;
					strcpy(que[w].s,ls);
					que[w].bs=que[t].bs+1;
					que[w].lens=strlen(que[w].s);
				}
			}
		}
		t++;
	}
	printf("NO ANSWER!");
	return 0;
}
