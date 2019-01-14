#include<iostream>
using namespace std;
int main()
{
    double a,b;
    cout<<"Enter two value : ";
    try
    {
        cin>>a;
        if(cin.fail())
            throw a;
        cin>>b;
        if(cin.fail())
            throw b;
        if(a-b==0)
            throw 0;
        cout<<"Answer : "<<a/(a-b)<<endl;
    }
    catch(double b)
    {
        cout<<"Wrong value of double !!";
        return 1;
    }
    catch(int)
    {
        cout<<"Divide by zero exception";
        return 1;
    }
    return 0;
}
