#include<iostream>
using namespace std;
class myFloat
{
    float num;
public:
    myFloat(){num=0.0;}//Default Constructor
    myFloat(const float n){num=n;}//Float Constructor
    operator float()//Conversion Function
    {
        return num;
    }
    friend istream&operator>>(istream&din,myFloat &n);//Overloaded >>
    friend ostream&operator<<(ostream&dout,const myFloat &n);//Overloaded <<
    myFloat operator+(const myFloat&n);//Overloaded +
    myFloat operator-(const myFloat&n);//Overloaded -
    myFloat operator*(const myFloat&n);//Overloaded *
    myFloat operator/(const myFloat&n);//Overloaded /
};
istream&operator>>(istream&din,myFloat &n)
{
    din>>n.num;
    return din;
}
ostream&operator<<(ostream&dout,const myFloat &n)
{
    dout<<n.num;
    return cout;
}
myFloat myFloat::operator+(const myFloat&n)
{
    myFloat temp;
    temp.num=num+n.num;
    return temp;
}
myFloat myFloat::operator-(const myFloat&n)
{
    myFloat temp;
    temp.num=num-n.num;
    return temp;
}
myFloat myFloat::operator*(const myFloat&n)
{
    myFloat temp;
    temp.num=num*n.num;
    return temp;
}
myFloat myFloat::operator/(const myFloat&n)
{
    myFloat temp;
    temp.num=num/n.num;
    return temp;
}
int main()
{
    myFloat num1,num2,num3;
    cout<<"Enter Number 1 : ";
    cin>>num1;
    cout<<"Enter Number 2 : ";
    cin>>num2;
    num3=num1+num2;
    cout<<"Number 3 : "<<num3;
    return 0;
}
