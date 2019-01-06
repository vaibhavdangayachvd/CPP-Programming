#include<iostream>
using namespace std;
template<class x>
void display(x a)
{
    cout<<"Template 1"<<endl;
}
template<class x,class y>
void display(x a,y b)
{
    cout<<"Template 2"<<endl;
}
void display(int a)
{
    cout<<"General Function"<<endl;
}
int main()
{
    display(3);
    display(2.3);
    display(2,3);
    return 0;
}
