#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
enum type{current,savings};
class account
{
private:
    string name;
    int acc_no;
    type acc_type;
    int balance;
    static int customers;
public:
    void create(void);
    void deposit(void);
    void withdraw(void);
    void check_balance(void);
};
int account::customers;
void account::create(void)
{
    char option;
    acc_no= ++customers;
    cout<<"Enter you name : ";
    cin>>name;
    do
    {
        cout<<"Choose Account Type:-\n1 - Saving\n2 - Current\n";
        option=getch();
        switch(option)
        {
        case '1':
            acc_type=savings;
            break;
        case '2':
            acc_type=current;
            break;
        default:
            cout<<"Choose Correct Option\n";
        }
    }while(option!='2' && option!='1');
    cout<<"Enter Initial Balance : ";
    cin>>balance;
    cout<<"\nAccount Created !!";
}
void account::deposit(void)
{
    int amount;
    cout<<"Enter Amount to deposit : ";
    cin>>amount;
    balance+=amount;
    cout<<"\nAmount Deposited !!";
}
void account::withdraw(void)
{
    int amount;
    cout<<"Enter Amount to withdraw : ";
    cin>>amount;
    if(amount>balance)
    {
        cout<<"You don't have enough balance !!";
        return;
    }
    balance-=amount;
    cout<<"\nCollect Cash !!";
}
inline void account::check_balance(void)
{
    cout<<"Name : "<<name<<endl<<"Account Balance : "<<balance;
}
void hold(void);
int main()
{
    account user;
    char option;
    while(1)
    {
        system("cls");
        cout<<"Choose Option :-\n\n1 - Create Account\n2 - Deposit Amount\n3 - Withdraw Amount\n4 - Check Balance\n\n\tBackspace - Exit\n";
        option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            user.create();
            hold();
            break;
        case '2':
            user.deposit();
            hold();
            break;
        case '3':
            user.withdraw();
            hold();
            break;
        case '4':
            user.check_balance();
            hold();
            break;
        case 8:
            return 0;
        }
    }
}
void hold(void)
{
    cout<<"\n\n\tPress Enter to continue...";
    getch();
}
