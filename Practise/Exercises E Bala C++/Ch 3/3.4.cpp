#include<iostream>
using namespace std;
float check(int p,float r,int n);
int main()
{
    float v,r;
    int p,n;
    cout<<"Enter P,R,N : ";
    cin>>p>>r>>n;
    v=check(p,r,n);
    cout<<"V = "<<v;
    return 0;
}
float check(int p,float r,int n)
{
    if(n==0)
        return p;
    float v;
    v=p*(1+r);
    v=check(v,r,n-1);
    return v;
}
