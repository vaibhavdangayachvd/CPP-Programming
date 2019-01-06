#include<iostream>
using namespace std;
void test(int x);
int main()
{
    try
    {
         test(1);
    }
    catch(double x)
    {
        cout<<"Double is caught in main()";
    }
    return 0;
}
void test(int x)
{
    try
    {
        if(x==1)
            throw(1.1);
    }
    catch(double)
    {
        throw;
    }
}
