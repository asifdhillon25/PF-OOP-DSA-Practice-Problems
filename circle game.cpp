#include<iostream>
using namespace std;

int main()
{
	cout<<"hello welcom to the circle creation game\n";
	typedef double d;
	d  radius,circum,area;
	const d PI=3.1428;
	cout<<"what radius you want for your circle?\n";
	cin>>radius;
	
	area=PI*radius*radius;
	circum=PI*(radius*2);
	
	cout<<"area of circle is = "<<area<<endl;
	cout<<"circum of circle is = "<<circum;
}
