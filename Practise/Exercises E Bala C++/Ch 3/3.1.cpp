#include<iostream>
using namespace std;
void swap_num(int &a,int &b);
int main()
{
    int a,b;
    cout<<"Enter two numbers : ";
    cin>>a>>b;
    swap_num(a,b);
    cout<<"Number after swap : "<<a<<" , "<<b;
    return 0;
}
void swap_num(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
