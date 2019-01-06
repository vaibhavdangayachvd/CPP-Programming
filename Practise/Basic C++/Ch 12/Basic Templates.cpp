#include<iostream>
using namespace std;
const int _size=3;
template<class T>
class vactor
{
    T *n;
public:
    vactor()
    {
        n=new T[_size];
        for(int i=0;i<_size;++i)
            n[i]=0;
    }
    vactor(T *arr)
    {
         n=new T[_size];
         for(int i=0;i<_size;++i)
            n[i]=arr[i];
    }
    T operator*(vactor &a)
    {
        T sum=0;
        for(int i=0;i<_size;++i)
            sum+=n[i]*a.n[i];
        return sum;
    }
    void operator=(T *arr)
    {
        for(int i=0;i<_size;++i)
            n[i]=arr[i];
    }
    ~vactor(){delete n;}
};
int main()
{
    float arr1[3]={1.1,2.2,3.3},arr2[3]={4.4,5.5,6.6};
    vactor<float>a,b;
    a=arr1,b=arr2;
    cout<<"A*B="<<a*b;
    return 0;
}
