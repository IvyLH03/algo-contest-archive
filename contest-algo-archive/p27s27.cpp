#include<cstdio>
using namespace std;

int main()
{
	char c1='a';
	char c2='B';
	printf("%c %c\n",c1,c2);
	c1=c1-32;
	c2=c2+'a'-'A';
	printf("%c %c",c1,c2);
	return 0;
} 
