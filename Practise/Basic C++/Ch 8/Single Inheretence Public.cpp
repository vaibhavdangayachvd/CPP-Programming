#include<iostream>
using namespace std;
class number
{
    int num;
public:
    number(){num=0;}
    number(int n){num=n;}
    operator int(){return num;}
    int getnum(void){return num;}
    void setnum(const int n){num=n;}
    void shownum(void){cout<<num;}
};
class operation:public number
{
public:
    operation operator+(operation &n1);
};
operation operation::operator+(operation &n1)
{
    operation temp;
    temp.setnum(n1.getnum()+getnum());
    return temp;
}
int main()
{
    operation n1,n2,n3;
    n1.setnum(5);
    n2.setnum(5);
    n3=n1+n2;
    n3.shownum();
    return 0;
}
