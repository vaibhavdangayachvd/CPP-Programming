#include<iostream>
using namespace std;
void test(int x);
int main()
{
    test(1);
    test(2);
    test(3);
    return 0;
}
void test(int x)
{
    try
    {
        if(x==1)
            throw 1;
        else if(x==2)
            throw 2;
        else if(x==3)
            throw 3;
    }
    catch(...)
    {
        cout<<"Caught"<<endl;
    }
}
