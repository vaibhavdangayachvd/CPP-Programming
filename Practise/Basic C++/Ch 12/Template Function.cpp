#include<iostream>
using namespace std;
template<class t>
void mySwap(t &a,t &b)
{
    t temp;
    temp=a;
    a=b;
    b=temp;
}
template<class t>
void big(t &a,t &b)
{
    if(a>b)
        cout<<"A"<<endl;
    else
        cout<<"B"<<endl;
}
int main()
{
    int a=10,b=20;
    big<int>(a,b);
    mySwap<int>(a,b);
    big<int>(a,b);
    return 0;
}
