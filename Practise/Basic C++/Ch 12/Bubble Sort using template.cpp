#include<iostream>
using namespace std;
template<class t>
void mySwap(t &a, t&b)
{
    t temp;
    temp=a;
    a=b;
    b=temp;
}
template<class x>
void bubble(x *arr,int n)
{
    for(int i=0;i<n-1;++i)
        for(int j=0;j<n-i-1;++j)
            if(arr[j]>arr[j+1])
                mySwap(arr[j],arr[j+1]);
}
template<class y>
void display(y *arr,int n)
{
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int arr[5]={2,3,4,1,5};
    bubble(arr,5);
    display(arr,5);
    return 0;
}
