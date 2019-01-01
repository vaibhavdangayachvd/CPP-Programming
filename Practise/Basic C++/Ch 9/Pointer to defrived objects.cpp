#include<iostream>
using namespace std;
class aa
{
public:
    int a;
    void show(void){cout<<"A = "<<a<<endl;}
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
    aa *bptr=&beta;
    bptr->a=10;
    ((bb*)bptr)->b=20;
    ((bb*)bptr)->show();//call bb using cast on aa pointer
}
