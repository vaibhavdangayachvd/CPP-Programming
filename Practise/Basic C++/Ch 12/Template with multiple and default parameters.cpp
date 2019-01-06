#include<iostream>
using namespace std;
template <class t1=int,class t2=int>
class num
{
    t1 a;
    t2 b;
public:
    num(t1 x,t2 y){a=x,b=y;}
    void display(void)
    {
        cout<<a<<","<<b<<endl;
    }
};
int main()
{
    num<int,int>vd(1,2);
    vd.display();
    return 0;
}
