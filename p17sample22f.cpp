#include<cstdio>
using namespace std;
//�����뾶�����������
//������S=4*pi*r^2
//�����=4/3*pi*r^3 
int main()
{
	const double pi=3.1415926;
	double r,v,s;
	scanf("%lf",&r);
	s=4*pi*r*r;
	v=4.0/3*pi*r*r*r; //��ʹ��4/3���������α������� 
	printf("s=%.3lf v=%.3lf",s,v);
	return 0;
}
