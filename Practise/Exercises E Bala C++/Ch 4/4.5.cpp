#include<iostream>
#define MAX2(a,b) a>b?a:b
#define MAX3(a,b,c) MAX2(a,b)>c?MAX2(a,b):c
using namespace std;
int main()
{
    int a=10,b=20,c=30;
    int d=MAX3(a,b,c);
    cout<<d;
}
