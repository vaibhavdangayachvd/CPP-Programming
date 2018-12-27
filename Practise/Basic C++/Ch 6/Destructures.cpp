#include<iostream>
using namespace std;
class test
{
    int *ptr;
public:
    test(int s=0){ptr=new int[s];cout<<"Constructed !!\n";}
    ~test(){delete ptr;cout<<"Destructed !!\n";};
};
int main()
{
    test t1;
    return 0;
}
