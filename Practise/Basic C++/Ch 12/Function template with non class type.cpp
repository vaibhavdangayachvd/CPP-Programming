#include<iostream>
using namespace std;
template<class t,int len>
void my(t *a)
{
    a=new t[len];
    cout<<sizeof(a);
}
int main()
{
    char *a;
    my<char,5>(a);
    return 0;
}
