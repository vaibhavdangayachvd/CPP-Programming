#include<iostream>
using namespace std;
class complex_
{
    float x,y;
public:
    complex_(){}
    complex_(float a){x=y=a;}
    complex_(float rear,float imag){x=rear,y=imag;}
    friend complex_ sum(complex_,complex_);
    friend void show(complex_);
};
complex_ sum(complex_ c1,complex_ c2)
{
    complex_ c3;
    c3.x=c1.x+c2.x;
    c3.y=c1.y+c3.y;
    return c3;
}
inline void show(complex_ c)
{
    cout<<c.x<<" + j"<<c.y<<endl;
}
int main()
{
    complex_ a(3.7,3.5);
    complex_ b(1.6);
    complex_ c;
    c=sum(a,b);
    cout<<"A = ";show(a);
    cout<<"B = ";show(b);
    cout<<"C = ";show(c);
    return 0;
}
