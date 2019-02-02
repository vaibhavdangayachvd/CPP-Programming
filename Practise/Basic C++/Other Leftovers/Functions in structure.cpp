#include<iostream>
using namespace std;
struct test
{
    int a;
    void show(void);
};
void test::show(void)
{
    cout<<a;
}
int main()
{
    test hi;
    hi.a=10;
    hi.show();
}
