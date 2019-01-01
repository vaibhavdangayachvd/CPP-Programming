#include<iostream>
using namespace std;
class vaibhav
{
public:
    virtual void display(void)=0;
};
class harsh:public vaibhav
{
public:
    void display(void)
    {
        cout<<"My Name is Harsh"<<endl;
    }
};
class shivam:public vaibhav
{
public:
    void display(void)
    {
        cout<<"My Name is Shivam"<<endl;
    }
};
int main()
{
    vaibhav *ptr[2];
    harsh h;
    shivam s;
    ptr[0]=&h;
    ptr[1]=&s;
    ptr[0]->display();
    ptr[1]->display();
}
