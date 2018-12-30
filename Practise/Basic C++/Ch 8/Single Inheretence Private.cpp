#include<iostream>
using namespace std;
class ab
{
    int a;
public:
    int b;
    void set_ab(void){a=10,b=20;}
    int get_a(void){return a;}
    void show_a(void){cout<<a;}
};
class bc:private ab
{
    int c;
public:
    void mul(void)
    {
        set_ab();
        c=b*get_a();
    }
    void display(void){cout<<"A = "<<get_a()<<endl<<"B = "<<b<<endl<<"C = "<<c<<endl;}
};
int main()
{
    bc test;
    test.mul();
    test.display();
    return 0;
}
