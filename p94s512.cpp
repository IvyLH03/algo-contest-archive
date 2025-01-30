#include<cstdio>
using namespace std;
int main()
{
	char ch,letter[101];
	scanf("%c",&ch);
	int i=0,j=1;
	while(ch!='.')
	{
		i++;
		letter[i]=ch;
		scanf("%c",&ch);
	}
	while((j<i)&&letter[j]==letter[i])
	{
		i--;j++;
	}
	if(j>=i) printf("Yes");
	else printf("No");
}
