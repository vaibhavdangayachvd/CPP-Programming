#include<iostream>
#include<cstring>
#include<conio.h>
#include<cstdlib>
using namespace std;
void hold_screen(void);
void hold_screen(void)
{
    cout<<"\n\n\tPress Enter to continue...";
    getch();
}
class person
{
protected:
    int _count;
    char **username;
    char **password;
    char **first;
    char **last;
public:
    person();
    int get_id_by_name(char *user);
    void add_new_person(void);
    void show_basic_details(int i);
    void show_basic_details(char *n);
    void search_person_username(void);
    ~person();
};
person::person(void)
{
    _count=0;
    username=new char *[80];
    password=new char*[80];
    first=new char*[80];
    last=new char *[80];
}
person::~person()
{
    for(int i=0;i<_count;++i)
    {
        delete first[i];
        delete last[i];
        delete username[i];
        delete password[i];
    }
    delete first;
    delete last;
    delete username;
    delete password;
}
int person::get_id_by_name(char *user)
{
    for(int i=0;i<_count;++i)
    {
        if(!(strcmp(username[i],user)))
            return i;
    }
    return -1;
}
void person::search_person_username(void)
{
    char *n=new char[30];
    int found=0;
    cout<<"Enter name : ";
    cin>>n;
    for(int i=0;i<_count;++i)
    {
        if(!(strcmp(first[i],n)))
        {
            cout<<"Username : "<<username[i]<<endl;
            found=1;
        }
    }
    if(!found)
        cout<<"User not found !!";
}
void person::add_new_person(void)
{
    char *fname=new char[30],*lname=new char[30],*uname=new char[30],*pw1=new char[30],*pw2=new char[30];
    cout<<"Enter First Name : ";
    cin>>fname;
    cout<<"Enter Last Name : ";
    cin>>lname;
    do
    {
        cout<<"Enter User Name : ";
        cin>>uname;
        if(search_person(uname)!=-1)
            cout<<"User already exist!! Try again"<<endl;
    }while(search_person(uname)!=-1);
    do
    {
        cout<<"Enter Password : ";
        cin>>pw1;
        cout<<"Re-Enter Password ";
        cin>>pw2;
        if(strcmp(pw1,pw2))
            cout<<"Password Do Not Match !! Try again"<<endl;
    }while(strcmp(pw1,pw2));

    first[_count]=new char[strlen(fname)+1];
    strcpy(first[_count],fname);

    last[_count]=new char[strlen(lname)+1];
    strcpy(last[_count],lname);

    username[_count]=new char[strlen(uname)+1];
    strcpy(username[_count],uname);

    password[_count]=new char[strlen(pw1)+1];
    strcpy(password[_count],pw1);
    delete fname,lname,uname,pw1,pw2;
}
void person::show_basic_details(int i)
{
    cout<<"First Name : "<<first[i]<<endl;
    cout<<"Last Name : "<<last[i]<<endl;
    cout<<"User Name : "<<username[i]<<endl;
}
void person::show_basic_details(char *n)
{
    int i=get_id_by_name(n);
    if(i)
    {
        cout<<"First Name : "<<first[i]<<endl;
        cout<<"Last Name : "<<last[i]<<endl;
        cout<<"User Name : "<<username[i]<<endl;
    }
    else
        cout<<"User not found !!";
}
class user:public person
{
protected:
    long *coins;
public:
    user();
    void add_new_user(void);
    void show_coin_balance(char *);
    void show_coin_balance(int i);
    void show_user_details(char *);
    ~user(){delete coins;}
};
user::user(void)
{
    coins = new long[80];
}
void user::add_new_user(void)
{
    add_new_person();
    coins[_count]=500;
    ++_count;
    cout<<"\nUser Created !!";
}
void user::show_coin_balance(char *n)
{
    int i=search_person(n);
    if(i)
        cout<<"Coin Balance : "<<coins[i]<<endl;
    else
        cout<<"User not found !!"<<endl;
}
void user::show_coin_balance(int i)
{
    cout<<"Coin Balance : "<<coins[i]<<endl;
}
void user::show_user_details(char *n)
{
    int i=search_person(n);
    if(i)
    {
        show_basic_details(i);
        show_coin_balance(i);
    }
    else
        cout<<"User not found !!";
}
class admin:public person
{
public:
    admin();
    void add_new_admin(void);
};
admin::admin()
{
    first[_count]=new char[8];
    last[_count]=new char[6];
    username[_count]=new char[6];
    password[_count]=new char [9];
    strcpy(first[_count],"Default");
    strcpy(last[_count],"Admin");
    strcpy(username[_count],"admin");
    strcpy(password[_count],"password");
    ++_count;
}
void admin::add_new_admin(void)
{
    add_new_person();
    ++_count;
    cout<<"Admin Created !!";
}
int main()
{
    char option;
    user u;
    admin a;
    while(1)
    {
        system("cls");
        cout<<"Choose Option :-\n\n";
        cout<<"1 - Create New User\n";
        cout<<"2 - Login User Account\n";
        cout<<"3 - Login Admin Account\n";
        cout<<"4 - Search User\n\n\t";
        cout<<"Backspace - Exit\n";
        option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            u.add_new_user();
            hold_screen();
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            u.search_person_username();
            hold_screen();
            break;
        case 8:
            return 0;
        }
    }
}
