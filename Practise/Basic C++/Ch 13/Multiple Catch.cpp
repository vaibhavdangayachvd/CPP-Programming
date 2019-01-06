#include<iostream>
using namespace std;
void test(int x);
int main()
{
    test(1);
    test(2);
    test(3);
    test(4);
    return 0;
}
void test(int x)
{
    try
    {
        if(x==1)
            throw 1;
        else if(x==2)
            throw '1';
        else if(x==3)
            throw 1.22;
        cout<<"Enter of Try !!"<<endl;
    }
    catch(int)
    {
        cout<<"Integer"<<endl;
    }
    catch(char)
    {
        cout<<"Character"<<endl;
    }
    catch(double)
    {
        cout<<"Double"<<endl;
    }
    cout<<"End of Catch"<<endl;
}
