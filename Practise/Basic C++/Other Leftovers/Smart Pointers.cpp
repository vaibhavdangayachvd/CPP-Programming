#include<iostream>
#include<memory>
class test
{
    int a;
public:
    test(int a){std::cout<<"Constructor Called\n";}
    ~test(){std::cout<<"Destructor Called\n";}
};
int main()
{
    std::unique_ptr<test> ptr=std::make_unique<test>(3);
    return 0;
}

