#include<iostream>
using namespace std;
class person
{
    static int count_;
protected:
    string name;
    int code;
public:
    person(const string &n);
    void show_name(void);
    void show_code(void);
};
int person::count_;
person::person(const string &n)
{
    name=n;
    code=++count_;
}
void person::show_name(void)
{
    cout<<"Name : "<<name<<endl;
}
void person::show_code(void)
{
    cout<<"Code : "<<code<<endl;
}
class account:virtual public person
{
protected:
    int pay;
public:
    account(const string &n,const int &p);
    void show_pay(void);
    void update_pay(const int &p);
};
account::account(const string &n,const int &p):person(n)
{
    pay=p;
}
void account::show_pay(void)
{
    cout<<"Pay = "<<pay<<endl;
}
void account::update_pay(const int &p)
{
    pay=p;
}
class admin: virtual public person
{
protected:
    int experience;
public:
    admin(const string &n,const int &e);
    void show_experience(void);
};
admin::admin(const string &n,const int &e):person(n)
{
    experience=e;
}
void admin::show_experience(void)
{
    cout<<"Experience : "<<experience<<" Years"<<endl;
}
class master:public account,public admin
{
public:
    master(const string &n,const int &p,const int &e):person(n),account(n,p),admin(n,e){}
    friend ostream&operator<<(ostream &dout,master &m);
};
ostream&operator<<(ostream &dout,master &m)
{
    m.show_name();
    m.show_code();
    m.show_pay();
    m.show_experience();
    return dout;
}
int main()
{
    master vaibhav("Vaibhav",100000,23);
    cout<<vaibhav;
}
