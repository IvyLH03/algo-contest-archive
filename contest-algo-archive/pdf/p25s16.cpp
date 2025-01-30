#include<cstdio>
using namespace std;
int main()
{
	int i,s=0,yusuan,shou=0,cun=0,cin=0,in,jincun=0;
	for(i=1;i<=12;i+=1)
	{	
		in=i;
		scanf("%d",&yusuan);
		shou+=300;
		if(yusuan>shou)
		{
			printf("-%d",in);
			cin=1;
			break;
		}
		else
		{
			if(shou-yusuan>=100)
			{
				jincun=shou-yusuan;
				jincun=jincun-jincun%100;
				cun+=jincun;
				shou=shou-jincun-yusuan;
				
			}
			else
			{	
				shou-=yusuan;
			}
		}

		jincun=0;
	}
	
	if(cin!=1)
	{
		s=cun*120/100+shou;
		
		printf("%d",s);
	}


	return 0;
} 
