#include<iostream>
class test
{
    int num;
public:
    explicit test(int a)
    {
        num=a;
        std::cout<<a<<std::endl;
    }
};
int main()
{
    test a=19;
    return 0;
}
