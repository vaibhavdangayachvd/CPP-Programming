#include<iostream>
using namespace std;
class test
{
    const int a;
public:
    test():a(){}
    void show(void)
    {
        cout<<a;
    }
};
int main()
{
    test hi;
    hi.show();
    return 0;
}
