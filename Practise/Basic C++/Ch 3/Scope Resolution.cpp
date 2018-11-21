#include<iostream>
using namespace std;
int m=20;
int main()
{
    int m=10;
    cout<<"Local : "<<m<<"\nGlobal : "<<::m;
    return 0;
}
