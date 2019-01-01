#include<iostream>
#include<cstring>
using namespace std;
int sum(int,int);
int main()
{
    int(*psum)(int,int)=&sum;
    cout<<psum(3,4);
}
int sum(int a,int b)
{
    return a+b;
}
