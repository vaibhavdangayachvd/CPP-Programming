#include<iostream>
namespace ios
{
    class test
    {
        int a;
    public:
        void set(void)
        {
            std::cout<<"Enter Number : ";
            std::cin>>a;
        }
        void get(void)
        {
            std::cout<<"Number : "<<a<<std::endl;
        }
    };
    void display(void);
}
namespace vd
{
    void display(void);
}
void vd::display(void)
{
    std::cout<<"Hi VD";
}
void ios::display(void)
{
    std::cout<<"Hi";
}
int main()
{
    vd::display();
    return 0;
}
