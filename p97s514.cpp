#include<cstdio>
using namespace std;
int main()
{
	for(char letter='a';letter<='z';letter+=2)
		printf("%3c",letter);
	printf("\n");
	for(char letter='z';letter>='a';letter-=2)
		printf("%3c",letter);
	return 0;
}
