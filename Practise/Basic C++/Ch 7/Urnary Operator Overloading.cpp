#include<iostream>
using namespace std;
class test
{
    int num;
public:
    test(){num=5;}
    void operator-();
    void display(void){cout<<num;}
};
inline void test::operator-(){num= -num;}
int main()
{
    test num1;
    -num1;
    num1.display();
    return 0;
}
