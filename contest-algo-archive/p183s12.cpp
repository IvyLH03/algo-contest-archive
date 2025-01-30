#include<cstdio>
#include<cstring>
using namespace std;
char a1[100],b1[100],temp[100];
int a[100],b[100],c[100];
int main()
{
	 gets(a1);gets(b1);
	 int i,x=0,lena=strlen(a1),lenb=strlen(b1),lenc=1;
	 if(lena<lenb||(lena==lenb&&strcmp(a1,b1)<0))
	 {
	 	strcpy(temp,a1);strcpy(a1,b1);strcpy(b1,temp);
		printf("-");  
	 }
	 for(i=0;i<lena;i++)a[lena-i]=a1[i]-'0';
	 for(i=0;i<lenb;i++)b[lenb-i]=b1[i]-'0';
	 while(lenc<=lena||lenc<=lenb)
	 {
	 	if(a[lenc]-b[lenc]<0)
	 	{
	 		a[lenc]+=10;a[lenc+1]--;
	 	}
	 	c[lenc]=a[lenc]-b[lenc];
	 	lenc++;
	 }
	 if(c[lenc]==0&&lenc>1)lenc--;
	 for(i=lenc;i>0;i--)printf("%d",c[i]);
	 printf("\n");
	 return 0;
} 
