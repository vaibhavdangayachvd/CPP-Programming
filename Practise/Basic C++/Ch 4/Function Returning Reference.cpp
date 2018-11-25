#include<iostream>
using namespace std;
int &greatest(int &a,int &b);
int main()
{
    int a=10,b=20;
    int &c=greatest(a,b);
    cout<<c;
    return 0;
}
int &greatest(int &a,int &b)
{
    if(a>b)
        return a;
    else
        return b;
}
