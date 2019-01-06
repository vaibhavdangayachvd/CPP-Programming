#include<iostream>
using namespace std;
template<class t,int len>
class num
{
    t arr[len];
public:
    num();
    void get_max(void);
    void get_min(void);
};
template<class t,int len>
num<t,len>::num()
{
    cout<<"Enter array elements : ";
    for(int i=0;i<len;++i)
        cin>>arr[i];
}
template<class t,int len>
void num<t,len>::get_max(void)
{
    int m=-999;
    for(int i=0;i<len;++i)
        if(arr[i]>m)
            m=arr[i];
    cout<<"Max = "<<m<<endl;
}
template<class t,int len>
void num<t,len>::get_min(void)
{
    int m=9999;
    for(int i=0;i<len;++i)
        if(arr[i]<m)
            m=arr[i];
    cout<<"Min = "<<m<<endl;
}
int main()
{
    num<int,5>a;
    a.get_min();
    a.get_max();
    return 0;
}
