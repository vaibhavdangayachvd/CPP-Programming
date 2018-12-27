#include<iostream>
using namespace std;
class test
{
    int num;
public:
    test(int n=0){num=n;}
    test operator+(test);
    void display(void){cout<<num;}
};
inline test test::operator+(test n)
{
    return test(num+n.num);
}
int main()
{
    test num1=2,num2=3,num3=num1+num2;
    num3.display();
    return 0;
}
