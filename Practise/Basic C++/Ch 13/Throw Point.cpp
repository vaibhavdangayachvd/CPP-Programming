#include<iostream>
using namespace std;
void sum(int a,int b);
int main()
{
    cout<<"Enter two numbers : ";
    int a,b;
    cin>>a>>b;
    try
    {
        sum(a,b);
    }
    catch(int a)
    {
        cout<<"Error : Sum of zero terms"<<endl;
        return 1;
    }
    return 0;
}
void sum(int a,int b)
{
    int sum=a+b;
    if(sum==0)
        throw sum;
    else
        cout<<"Sum is "<<sum<<endl;
}
