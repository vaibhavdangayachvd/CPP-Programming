#include<iostream>
using namespace std;
class number
{
    int num[5];
public:
    number(void);
    number(const int *);
    number(const number &);
    int &operator[](int num);
};
number::number(void)
{
    for(int i=0;i<5;++i)
        num[i]=0;
}
number::number(const int *n)
{
    for(int i=0;i<5;++i)
        num[i]=n[i];
}
number::number(const number &n)
{
    for(int i=0;i<5;++i)
        num[i]=2*n.num[i];
}
int& number::operator[](int i)
{
    return num[i];
}
int main()
{
    int arr[5]={0,1,2,3,4};
    number num1=arr;
    number num2=num1;
    number num3;
    num3=num1;
    cout<<num2[3]<<num3[3];
    return 0;
}
