#include<iostream>
using namespace std;
template<class x,class y>
void display(x a,y b)
{
    cout<<a<<","<<b<<endl;
}
int main()
{
    int a=10;
    float b=20.56;
    char c='c';
    display(a,b);
    display(b,c);
    display(c,a);
    return 0;
}
