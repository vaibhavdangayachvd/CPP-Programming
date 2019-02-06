#include<iostream>
#include<typeinfo>
class base
{
public:
    virtual void display(void)=0;
    virtual ~base(){std::cout<<"Lol Base"<<std::endl;}
};
class derived:public base
{
public:
    void display(void){std::cout<<"Hi Derived"<<std::endl;};
    ~derived(){std::cout<<"Lol Derived"<<std::endl;};
};
int main()
{
    base *ptr=new derived;
    std::cout<<typeid(*ptr).name();
    return 0;
}
