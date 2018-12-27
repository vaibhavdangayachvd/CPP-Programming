#include<iostream>
using namespace std;
class complex_
{
    float x,y;
public:
    complex_(){}
    complex_(float a){x=y=a;}
    complex_(float rear,float imag){x=rear,y=imag;}
    complex_ (complex_ &a){x=a.x,y=a.y;}
    complex_& more(complex_ &,complex_ &);
    void show(void);
};
complex_& complex_::more(complex_ &c1,complex_ &c2)
{
    if(c1.x>c2.x)
        return c1;
    else
        return c2;
}
inline void complex_::show(void)
{
    cout<<x<<" + j"<<y<<endl;
}
int main()
{
    complex_ a(3.7,3.5);
    complex_ b(1.6);
    complex_ &c=c.more(a,b);
    complex_ d=b;
    cout<<"A = ";a.show();
    cout<<"B = ";b.show();
    cout<<"C = ";c.show();
    cout<<"D = ";d.show();
    return 0;
}
