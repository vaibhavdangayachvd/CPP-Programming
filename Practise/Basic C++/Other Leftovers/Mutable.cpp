#include<iostream>
class test
{
     mutable int a;
public:
    void display(void)const
    {
        a=10;
        std::cout<<a<<std::endl;
    }
};
int main()
{
    test a;
    a.display();
    return 0;
}
