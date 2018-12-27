#include<iostream>
using namespace std;
const int size_ = 3;
class vector_
{
    int v[size_];
public:
    vector_();
    vector_(int *x);
    friend vector_ operator *(int a,vector_ b);
    friend vector_ operator *(vector_ b,int a);
    friend istream& operator>>(istream &,vector_ &);
    friend ostream& operator<<(ostream &,vector_ &);
};
vector_::vector_()
{
    for(int i=0;i<size_;++i)
        v[i]=0;
}
vector_::vector_(int *x)
{
    for(int i=0;i<size_;++i)
        v[i]=x[i];
}
vector_ operator*(int a,vector_ b)
{
    vector_ c;
    for(int i=0;i<size_;++i)
        c.v[i]=a*b.v[i];
    return c;
}
vector_ operator*(vector_ b,int a)
{
    vector_ c;
    for(int i=0;i<size_;++i)
        c.v[i]=b.v[i]*a;
    return c;
}
istream& operator>>(istream &din,vector_ &b)
{
    for(int i=0;i<size_;++i)
        din>>b.v[i];
    //return din;
}
ostream& operator<<(ostream &dout,vector_ &b)
{
    dout<<"("<<b.v[0];
    for(int i=1;i<size_;++i)
        dout<<","<<b.v[i];
    dout<<")";
    //return dout;
}
int x[size_]={2,4,6};
int main()
{
    vector_ m;
    vector_ n=x;
    cout<<"Enter Elements of vector m : ";
    cin>>m;
    cout<<endl;
    cout<<"m = "<<m<<endl;
}
