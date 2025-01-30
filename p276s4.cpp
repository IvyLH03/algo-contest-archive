#include<cstdio>
#include<algorithm>
using namespace std;
int num[7],tot;
int  main()
{
	int i,delt2;
	for(i=1;i<=6;i++)
		scanf("%d",&num[i]);
	while(num[1]+num[2]+num[3]+num[4]+num[5]+num[6])
	{
		tot=num[6]+num[5]+num[4];
		num[1]-=min(num[1],num[5]*11);
		
		
		if(num[4]*5>num[2])
		{
			num[1]-=min((num[4]*5-num[2])*4,num[1]); 
			num[2]=0;
		}
		
		if(num[3]%4)
		{
			delt2=0;
			tot+=num[3]/4+1;
			if(num[3]%4==1)
			{
				 delt2=min(num[2],5);
				 num[2]-=delt2;
				 num[1]-=min(num[1],7+4*(5-delt2));
			}
			if(num[3]%4==2)
			{
				delt2=min(num[2],3);
				num[2]-=delt2;
				num[1]-=min(num[1],6+4*(3-delt2));
			}
			if(num[3]%4==3)
			{
				delt2=min(num[2],1);
				num[2]-=delt2;
				num[1]-=min(num[1],5+4*(1-delt2));
				
			}
		} 
		else
			tot+=num[3]/4;
		
		
		tot+=num[2]/9;
		num[1]-=min(num[1],num[2]%9*4);
		tot+=num[1]/36;
		if(num[2]%9)
			tot++;
		if(num[1]%36)
			tot++;
		
		printf("%d\n",tot);
		
		for(i=1;i<=6;i++)
			scanf("%d",&num[i]);
	}
}
