#include<iostream>
#include<cmath>
using namespace std;
class power;
class number
{
    int num;
public:
    number(){num=0;}//Default Constructor
    number(const int n){num=n;}// Defacto Type Conversion Constructor
    operator int(void)//Conversion Function
    {
        return num;
    }
    int getnum(){return num;}
    istream & operator>>(istream &din)
    {
        din>>num;
        return din;
    }
    ostream & operator<<(ostream &dout)
    {
        dout<<num;
        return dout;
    }
    friend class power;
};
class power
{
    int num;
public:
    power(){num=0;}//Default Constructor
    power(const int n){num=n*n;}// Defacto Type Conversion Constructor
    operator int(void)//Conversion Function
    {
        return num;
    }
    operator number()
    {
        number temp;
        temp.num=sqrt(num);
        return temp;
    }
    power(number &p1)//Class Conversion Constructor
    {
        num=p1.getnum();
        num*=num;
    }
    int getnum(){return num;}
    istream & operator>>(istream &din)
    {
        din>>num;
        return din;
    }
    ostream & operator<<(ostream &dout)
    {
        dout<<num;
        return dout;
    }
};
int main()
{
    number n1=10;
    power n2=n1;
    cout<<n2;
}
