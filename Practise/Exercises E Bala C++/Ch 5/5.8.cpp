#include<iostream>
using namespace std;
class interest
{
    int p;
    int r;
    int t;
public:
    void set_amount(void);
    friend void calculate(interest a);
};
inline void interest::set_amount(void)
{
    cout<<"Enter Principle : ";
    cin>>p;
    cout<<"Enter Rate : ";
    cin>>r;
    cout<<"Enter Time : ";
    cin>>t;
    cout<<endl;
}
void calculate(interest a)
{
    interest *pa=&a;
    int interest::*pp=&interest::p;
    int interest::*pr=&interest::r;
    int interest::*pt=&interest::t;
    float amount=(pa->*pp * pa->*pr * pa->*pt)/100;
    cout<<"Amount = "<<amount;
}
int main()
{
    interest a;
    interest *pa=&a;
    void (interest::*p_set_amount)(void)=&interest::set_amount;
    (pa->*p_set_amount)();
    calculate(a);
    return 0;
}
