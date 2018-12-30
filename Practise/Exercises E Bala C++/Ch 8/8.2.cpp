#include<iostream>
using namespace std;
enum {sa,cr};
class account
{
    int acc_no;
    static int count_;
protected:
    int acc_type;
    int balance;
    string name;
public:
    account(const string &n,const int &b,const int &t);
    void show_acc_number(void);
    ostream &show_acc_number(ostream &dout);
    void show_name(void);
    void show_balance(void);
    void deposit(int b);
    void withdraw(int b);
};
class savings:public account
{
public:
    savings(string name,int balance):account(name,balance,sa){}
    void give_interest(void);
    friend ostream& operator<<(ostream &dout,savings &s);
};
class current:public account
{
public:
    current(string name,int balance):account(name,balance,cr){}
    void draw_check(int b);
    void check_min(void);
    friend ostream& operator<<(ostream &dout,current &s);
};
int account::count_;
account::account(const string &n,const int &b,const int &t)
{
    name=n;
    balance=b;
    acc_type=t;
    acc_no=++count_;
}
void account::show_acc_number(void)
{
    cout<<"Acc Number : "<<acc_no<<endl;
}
ostream &account::show_acc_number(ostream &dout)
{
    dout<<"Acc Number : "<<acc_no<<endl;
    return dout;
}
void account::show_name(void)
{
    cout<<"Account Holders Name : "<<name<<endl;
}
void account::show_balance(void)
{
    cout<<"Account Balance : "<<balance<<endl;
}
void account::deposit(int b)
{
    balance+=b;
    cout<<"Amount Deposited !!"<<endl;
}
void account::withdraw(int b)
{
    if(b>balance)
    {
        cout<<"You dont have enough amount !!"<<endl;
        return;
    }
    balance-=b;
    cout<<"Amount Withdrawn !!"<<endl;
}
void savings::give_interest(void)
{
    balance+=(7/100*balance);
    cout<<"Interest Added"<<endl;
}
void current::draw_check(int b)
{
    if(b>balance)
    {
        cout<<"You dont have enough amount !!"<<endl;
        return;
    }
    balance-=b;
    cout<<"Check Drawn !!"<<endl;
}
void current::check_min(void)
{
    if(balance<1000 && balance > 0)
    {
        cout<<"You don't have enough balance !!"<<endl;
        balance-=20;
        cout<<"Penalty of 20 imposed !!"<<endl;
    }
    else
        cout<<"You have sufficient Balance"<<endl;
}
ostream& operator<<(ostream &dout,savings &s)
{
    dout<<"Account Holder : "<<s.name<<endl;
    s.show_acc_number();
    dout<<"Account Type : Savings"<<endl;
    dout<<"Balance : "<<s.balance<<endl;
    return dout;
}
ostream& operator<<(ostream &dout,current &s)
{
    dout<<"Account Holder : "<<s.name<<endl;
    s.show_acc_number();
    dout<<"Account Type : Current"<<endl;
    dout<<"Balance : "<<s.balance<<endl;
    return dout;
}
int main()
{
    current c1("Vaibhav",2000);
    savings s1("Harsh",1000);
    cout<<c1<<endl<<s1;
    return 0;
}
