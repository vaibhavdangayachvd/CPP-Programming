#include<iostream>
#include<memory>
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
    std::unique_ptr<base> ptr=std::make_unique<derived>();
    ptr->display();
    return 0;
}
