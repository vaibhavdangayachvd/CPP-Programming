#include<iostream>
using namespace std;
class alpha
{
protected:
    int al;
public:
    alpha(int a){al=a;}
};
class beta
{
protected:
    int bt1,bt2;
public:
    beta(int b):bt1(b){bt2=bt1*2;}
};
class gama:public alpha,public beta
{
    int gm;
public:
    gama(int a):
    alpha(a),beta(a),gm(al){}
    void display(void)
    {
        cout<<"A = "<<al<<endl;
        cout<<"B1 = "<<bt1<<endl;
        cout<<"B2 = "<<bt2<<endl;
        cout<<"G = "<<gm<<endl;
    }
};
int main()
{
    gama num(1);
    num.display();
    return 0;
}

