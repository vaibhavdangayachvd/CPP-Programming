#include<iostream>
#include<cstring>
using namespace std;
class error
{
    int id;
    char *msg;
public:
    error(){}
    error(const int &i,const char *m)
    {
        id=i;
        msg=new char[strlen(m)+1];
        strcpy(msg,m);
    }
    void display(void)
    {
        cout<<"Error ID : "<<id<<endl<<"Error Message : "<<msg<<endl;
    }
    ~error(){delete msg;}
};
class number:public error
{
    int num;
public:
    number(int n):error()
    {
        try
        {
            if(n==0)
                throw error(1,"Number is zero");
            num=n;
        }
        catch(error e)
        {
            throw;
        }
    }
    void display(void)
    {
        cout<<"Number = "<<num<<endl;
    }
};
int main()
{
    try
    {
        number n1(1);
        n1.display();
    }
    catch(error e)
    {
        e.display();
    }
    return 0;
}
