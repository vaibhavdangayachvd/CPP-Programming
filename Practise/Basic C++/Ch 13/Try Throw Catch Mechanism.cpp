#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter two numbers : ";
    int a,b;
    cin>>a>>b;
    int x=a-b;
    try
    {
        if(x==0)
            throw(x);
    }
    catch(int x)
    {
        cout<<"Division by zero exception !!";
        return 1;
    }
    cout<<"Answer : "<<a/x<<endl;
    return 0;
}
