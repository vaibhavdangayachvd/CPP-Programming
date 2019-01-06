#include<iostream>
using namespace std;
void test(int x) throw(int);
int main()
{
    try
    {
         test(1);
    }
    catch(double x)
    {
        cout<<"Double is caught in main()"<<endl;
    }
    return 0;
}
void test(int x) throw(int)
{
    try
    {
        if(x==1)
            throw(1.1);
    }
    catch(double)
    {
        cout<<"Caught Double in test"<<endl;
        throw;
    }
}
