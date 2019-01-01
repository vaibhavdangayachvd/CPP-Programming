#include<iostream>
using namespace std;
class aa
{
public:
    int a;
    virtual void show(void){cout<<"A = "<<a<<endl;}
};
class bb:public aa
{
public:
    int b;
    void show(void)
    {
        cout<<"A = "<<a<<endl;
        cout<<"B = "<<b<<endl;
    }
};
int main()
{
    aa baap;
    bb beta;
    bb *betap=&beta;
    aa *bptr=&baap;
    bptr->a=10;
    betap->b=10;
    bptr->show();
    bptr=betap;
    bptr->show();
}
