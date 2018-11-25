#include<iostream>
using namespace std;
inline int max2(int a,int b){if(a>b) return a; else return b;}
inline int max3(int a,int b,int c){if((max2(a,b))>c) return max2(a,b); else return c;}
int main()
{
    int a=10,b=20,c=30,d;
    d=max3(a,b,c);
    cout<<d;
    return 0;
}
