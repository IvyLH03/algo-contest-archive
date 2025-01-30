#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if(a%100||a==0) cout<<"No";
	else cout<<"Yes";
	return 0;
}