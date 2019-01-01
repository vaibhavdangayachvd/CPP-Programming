#include<iostream>
using namespace std;
class number
{
    int num;
public:
    number(int n){num=n;}
    void show_num(void){cout<<num<<endl;}
    void swap_(number &n)
    {
        int temp=n.num;
        n.num=num;
        num=temp;
    }
};
int main()
{
    number n1(4),n2(2);
    number *ptr1=&n1,*ptr2=&n2;
    ptr1->swap_(*ptr2);
    ptr1->show_num();
    ptr2->show_num();
}
