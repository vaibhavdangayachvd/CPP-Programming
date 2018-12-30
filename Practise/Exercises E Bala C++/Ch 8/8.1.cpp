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
    void create_account(void);
    void show_acc_number(void);
    void show_name(void);
    void show_balance(void);
    void deposit(int b);
    void withdraw(int b);
};
class savings:public account
{
public:
    void give_interest(void);

};
class current:public account
{
public:
    void draw_check(int b);
    void check_min(void);
};
int account::count_;
void account::create_account(void)
{
    cout<<"Enter your name : ";
    cin>>name;
    do
    {
        cout<<"Choose Acc Type : ";
        cin>>acc_type;
    }while(acc_type!=cr && acc_type!=sa);
    cout<<"Enter initial amount : ";
    cin>>balance;
    acc_no=++count_;
}
void account::show_acc_number(void)
{
    cout<<"Acc Number : "<<acc_no<<endl;
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
int main()
{
    current vaibhav;
    savings harsh;
    vaibhav.create_account();
    harsh.create_account();
    vaibhav.check_min();
    harsh.deposit(200);
    harsh.show_name();
}
