#include<iostream>
using namespace std;

int main(){
	//declaring 10 hdisks and 1 backup variable
	int hd1,hd2,hd3,hd4,hd5,hd6,hd7,hd8,hd9,hd10;
	long long int backhd;
	
	cout<<"enter one digit value for 10 hard disks\n";
	//asking value of 10 hddisks from user
	cin>>hd1>>hd2>>hd3>>hd4>>hd5>>hd6>>hd7>>hd8>>hd9>>hd10;
	
	backhd=0;
	
	//storin value of all hdd,s in backup drive
	backhd=(backhd*10)+hd1;	backhd=(backhd*10)+hd2;	backhd=(backhd*10)+hd3;
	backhd=(backhd*10)+hd4;	backhd=(backhd*10)+hd5;	backhd=(backhd*10)+hd6;
	backhd=(backhd*10)+hd7;	backhd=(backhd*10)+hd8;	backhd=(backhd*10)+hd9;
	backhd=(backhd*10)+hd10;
	
	long long n,m,temp;
	n=backhd;
	//enter user to tell corrupted disk
	cout<<"enter the no of corrupted hard disk\n";
	cin>>m;
	
	cout<<"Harddisk "<<m<<" has been corrupted\n";
	
	
	
	//thil loop will get corrupted disk value from backup disk
	for(int i=1; i<=11-m; i++){
		
		temp=n%10;
		n=n/10;
	}
	
	
	
	cout<<"From backup hdd your lost data is "<<temp<<endl;
	
	
	
	
}
