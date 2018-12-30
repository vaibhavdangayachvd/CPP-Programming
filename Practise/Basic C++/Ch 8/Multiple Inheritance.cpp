#include<iostream>
using namespace std;
class num1
{
protected:
    int n1;
public:
        void getn1(int i){n1=i;}
};
class num2
{
protected:
    int n2;
public:
    void getn2(int i){n2=i;}
};
class number:public num1,public num2
{
public:
    void display(void)
    {
        cout<<"Num1 = "<<n1<<endl;
        cout<<"Num2 = "<<n2<<endl;
        cout<<"Sum = "<<n1+n2<<endl;
    }
};
int main()
{
    number n;
    n.getn1(2);
    n.getn2(3);
    n.display();
    return 0;
}
