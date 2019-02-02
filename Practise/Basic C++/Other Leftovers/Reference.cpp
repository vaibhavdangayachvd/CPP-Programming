#include<iostream>
using namespace std;
int main()
{
    int b;
    int &a=b=10;
    cout<<a;
}
