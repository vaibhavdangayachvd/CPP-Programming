#include<iostream>
using namespace std;
inline int sq(int a);
int main()
{
    int a;
    cout<<"Enter number to square : ";
    cin>>a;
    a=sq(a);
    cout<<"Sq = "<<a;
    return 0;
}
inline int sq(int a){return a*a;}
