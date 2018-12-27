#include<iostream>
using namespace std;
class test
{
public:
    int num;
    test(){num=5;}
    test*operator->(void){return this;}
};
int main()
{
    test t1;
    cout<<t1->num;
}
