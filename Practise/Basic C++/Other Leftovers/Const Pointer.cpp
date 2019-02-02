#include<iostream>
using namespace std;
int main()
{
    const int a;
    const int *const ptr=&a;
    cout<<a;
    return 0;
}
