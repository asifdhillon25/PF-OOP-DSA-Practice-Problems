#include<iostream>

using namespace std;
 int main()
 {
     int a[10] ={12,34,23,46,76,26,48,78,38,79};

for(int i=0;i<10; i++)
{
    for(int i=0;i<10; i++)
     {
         if(a[i]>a[i+1])
         {
             int c,b;

            c= a[i];
             b=a[i+1];
             a[i+1]=c;
             a[i]=b;

         }

     }

}
for(int i=0;i<10; i++)
{
    cout<<a[i]<<endl;
}
    int mid,size,end,start,position=-1;

    size=10;
    start=0;
    end=size-1;
    int key;
    cout<<"enter number you want to find\n";
    cin>>key;



    while(start<=end)
    {
        mid=(start+end)/2;

        if(a[mid]==key)
        {
            position=1;
            break;
        }
        else if(a[mid]<key)
        {
            start=mid+1;
        }
        else if(a[mid]>key)
        {
            end=mid-1;
        }


    }

if(position==1)
{
    cout<<"your value is found at index "<<mid<<endl;

}
else if(position==-1)
{
    cout<<"value is not in the list";
}












 }
