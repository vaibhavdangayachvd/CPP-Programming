#include<iostream>
using namespace std;
class shape
{
protected:
    double d1;
    double d2;
public:
    shape(){}
    shape(double a,double b){d1=a,d2=b;}
    virtual void get_data(void)=0;
    virtual void area(void)=0;
};
class triangle:public shape
{
public:
    triangle(){}
    triangle(double a,double b):shape(a,b){};
    void get_data(void)
    {
        cout<<"Enter Base : ";
        cin>>d1;
        cout<<"Enter Height : ";
        cin>>d2;
    }
    void area(void){cout<<"Area = "<<((d1*d2)/2)<<endl;}
};
class circle:public shape
{
public:
    circle(){}
    circle(double a,double b=0):shape(a,b){};
    void get_data(void)
    {
        cout<<"Enter Radius : ";
        cin>>d1;
    }
    void area(void){cout<<"Area = "<<(22/7*d1*d1)<<endl;}
};
class square:public shape
{
public:
   square(){}
   square(double a,double b):shape(a,b){};
   void get_data(void)
   {
        cout<<"Enter Length : ";
        cin>>d1;
        cout<<"Enter Beadth : ";
        cin>>d2;
   }
   void area(void){cout<<"Area = "<<d1*d2<<endl;}
};
int main()
{
    triangle t1;
    square s1;
    circle c1;
    shape *ptr[3];
    ptr[0]=&t1;
    ptr[1]=&s1;
    ptr[2]=&c1;
    ptr[0]->get_data();
    ptr[1]->get_data();
    ptr[2]->get_data();
    ptr[0]->area();
    ptr[1]->area();
    ptr[2]->area();
    return 0;
}
