//Headear Files
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<conio.h>
using namespace std;
//Hold Screen Function
void hold(void)
{
    cout<<"\n\n\tPress Enter to continue...";
    getch();
}
//Person Base Class for basic details of admins and users
class person
{
protected:
    char fname[30];
    char lname[30];
    int age;
    char gender;
public:
    void read_basic_details(void);
    void show_basic_details(void)const;
};
void person::read_basic_details(void)
{
    cout<<"Enter First Name : ";
    cin>>fname;
    cout<<"Enter Last Name : ";
    cin>>lname;
    cout<<"Enter Age : ";
    cin>>age;
    do
    {
        cout<<"Choose Gender(m=Male,f=female,o=others) : ";
        cin>>gender;
        if(gender!='m' && gender!='f' && gender!='o')
            cout<<"Wrong Choice !! Try again !!\n";
    }while(gender!='m' && gender!='f' && gender!='o');
}
void person::show_basic_details(void)const
{
    cout<<"Name : "<<fname<<" "<<lname<<endl;
    cout<<"Gender : ";
    switch(gender)
    {
    case 'm':
        cout<<"Male"<<endl;
        break;
    case 'f':
        cout<<"Female"<<endl;
        break;
    case 'o':
        cout<<"Others"<<endl;
        break;
    }
    cout<<"Age : "<<age<<endl;
}
class user:public person
{
    int coin_balance;
    char username[30];
    char password[30];
public:
    void create_new_user(void);
    void show_user_by_name(void);
    void add_coins(int coins);
    void show_coin_balance(void);
    void change_password(void);
    static user get_user_by_username(const char *);
    void login(void);
    void show_user_menu(void);
    static void commit_to_userfile(const user &a);
    void show_creds(void);
};
void user::create_new_user(void)
{
    read_basic_details();
    char str[30],pw[30];
    user temp;
    int found=0;
    do
    {
        cout<<"Enter Username : ";
        cin>>str;
        ifstream fin;
        fin.open("userdata",ios::binary);
        while(fin.read((char*)&temp,sizeof(user)))
        {
            found=0;
            if(!strcmp(temp.username,str))
            {
                cout<<"User Already Exits !!\n";
                found=1;
                break;
            }
        }
        fin.close();
    }while(found);
    strcpy(username,str);
    do
    {
        cout<<"Enter Password : ";
        cin>>str;
        cout<<"Re-Enter Password : ";
        cin>>pw;
        if(strcmp(str,pw))
            cout<<"Passwords do not match !! Try Again\n";
    }while(strcmp(str,pw));
    strcpy(password,pw);
    ofstream fout("userdata",ios::app|ios::binary);
    strcpy(temp.fname,fname);
    strcpy(temp.lname,lname);
    temp.age=age;
    temp.gender=gender;
    temp.coin_balance=500;
    strcpy(temp.username,username);
    strcpy(temp.password,password);
    fout.write((char*)&temp,sizeof(user));
    fout.close();
    cout<<"\nUser Successfully Created !!";
}
void user::show_creds(void)
{
    cout<<"Username : "<<username<<endl;
    cout<<"Password : "<<password<<endl;
}
void user::show_user_by_name(void)
{
    char str[20];
    user temp;
    int found=0;
    cout<<"Enter first name to search : ";
    cin>>str;
    ifstream fin("userdata",ios::binary);
    while(fin.read((char*)&temp,sizeof(user)))
    {
        if(!strcmp(temp.fname,str))
        {
            cout<<"Name : "<<temp.fname<<" "<<temp.lname<<endl;
            cout<<"Username : "<<temp.username<<endl<<endl;
            found=1;
        }
    }
    fin.close();
    if(!found)
        cout<<"\nDetails not found !!";
}
void user::add_coins(int coins)
{
    coin_balance+=coins;
}
void user::show_coin_balance(void)
{
    cout<<"Coin Balance : "<<coin_balance<<endl;
}
void user::change_password(void)
{
    char pw[20],pwr[20];
    cout<<"Enter Current Password : ";
    cin>>pw;
    if(strcmp(password,pw))
    {
        cout<<"\nWrong Password !!";
        return;
    }
    do
    {
        cout<<"Enter New Password : ";
        cin>>pw;
        cout<<"Re-Enter New Password : ";
        cin>>pwr;
        if(strcmp(pw,pwr))
            cout<<"Passwords do not match !! Try Again\n";
    }while(strcmp(pw,pwr));
    strcpy(password,pwr);
    cout<<"\nNew Password Set !!";
}
user user::get_user_by_username(const char *str)
{
    user temp;
    ifstream fin("userdata",ios::binary);
    while(fin.read((char*)&temp,sizeof(user)))
    {
        if(!strcmp(temp.username,str))
        {
            fin.close();
            return temp;
        }
    }
    fin.close();
    throw 0;
}
void user::commit_to_userfile(const user &u)
{
    user temp;
    fstream fp;
    int cnt=0;
    fp.open("userdata",ios::ate|ios::in|ios::out|ios::binary);
    fp.seekg(ios::beg);
    while(fp.read((char*)&temp,sizeof(user)))
    {
        cnt++;
        if(!strcmp(u.username,temp.username))
            break;
    }
    cnt=(cnt-1)*sizeof(user);
    fp.seekp(cnt);
    fp.write((char*)&u,sizeof(user));
    fp.close();
}
void user::login(void)
{
    char usr[20];
    user temp;
    cout<<"\t\tWelcome To User Login Panel !!\n\n";
    cout<<"Enter Username : ";
    cin>>usr;
    try
    {
        temp=get_user_by_username(usr);
    }
    catch(int)
    {
        cout<<"\nUsername not found !!";
        hold();
        return;
    }
    cout<<"Enter Password : ";
    cin>>usr;
    if(!strcmp(usr,temp.password))
    {
        temp.add_coins(25);
        temp.show_user_menu();
        commit_to_userfile(temp);
    }
    else
    {
        cout<<"\nWrong Password !! Access denied !!";
        hold();
    }
}
void user::show_user_menu(void)
{
    char option;
    while(1)
    {
        system("cls");
        cout<<"\t\tWelcome to User Menu !!\n\n";
        cout<<"Choose Option :-\n\n";
        cout<<"1 - Open Casino\n2 - Show Personal Details\n3 - Change Password\n\tBackspace - Exit\n";
        option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            break;
        case '2':
            show_basic_details();
            show_coin_balance();
            hold();
            break;
        case '3':
            change_password();
            hold();
            break;
        case 8:
            return;
        }
    }
}
class admin:public person
{
protected:
    char username[30];
    char password[30];
public:
    friend class super;
    void change_password(void);
    void commit_to_adminfile(const admin &a);
    admin get_admin_by_username(const char *);
    void login(void);
    void show_admin_menu(void);
    void give_coins(void);
    void show_all_users(void);
    void show_creds(void);
};
void admin::show_creds(void)
{
    cout<<"Username : "<<username<<endl;
    cout<<"Password : "<<password<<endl;
}
void admin::change_password(void)
{
    char pw[20],pwr[20];
    cout<<"Enter Current Password : ";
    cin>>pw;
    if(strcmp(password,pw))
    {
        cout<<"\nWrong Password !!";
        return;
    }
    do
    {
        cout<<"Enter New Password : ";
        cin>>pw;
        cout<<"Re-Enter New Password : ";
        cin>>pwr;
        if(strcmp(pw,pwr))
            cout<<"Passwords do not match !! Try Again\n";
    }while(strcmp(pw,pwr));
    strcpy(password,pwr);
    cout<<"\nNew Password Set !!";
}
void admin::commit_to_adminfile(const admin &a)
{
    admin temp;
    fstream fp;
    int cnt=0;
    fp.open("admindata",ios::ate|ios::in|ios::out|ios::binary);
    fp.seekg(ios::beg);
    while(fp.read((char*)&temp,sizeof(admin)))
    {
        cnt++;
        if(!strcmp(a.username,temp.username))
            break;
    }
    cnt=(cnt-1)*sizeof(admin);
    fp.seekp(cnt);
    fp.write((char*)&a,sizeof(admin));
    fp.close();
}
void admin::login(void)
{
    char usr[20];
    admin temp;
    cout<<"\t\tWelcome To Admin Login Panel !!\n\n";
    cout<<"Enter Username : ";
    cin>>usr;
    try
    {
        temp=get_admin_by_username(usr);
    }
    catch(int)
    {
        cout<<"\nUsername not found !!";
        hold();
        return;
    }
    cout<<"Enter Password : ";
    cin>>usr;
    if(!strcmp(usr,temp.password))
    {
        temp.show_admin_menu();
        commit_to_adminfile(temp);
    }
    else
    {
        cout<<"\nWrong Password !! Access denied !!";
        hold();
    }
}
void admin::give_coins(void)
{
    user temp;
    char str[20];
    cout<<"Enter username to receiver : ";
    cin>>str;
    try
    {
        temp=user::get_user_by_username(str);
    }
    catch(int)
    {
        cout<<"User not found !!";
        return;
    }
    temp.show_basic_details();
    temp.show_coin_balance();
    cout<<"\nEnter amount of count you want to give : ";
    int amt;
    cin>>amt;
    temp.add_coins(amt);
    cout<<"\nCoins Transferred !!";
    user::commit_to_userfile(temp);
}
admin admin::get_admin_by_username(const char *str)
{
    admin temp;
    ifstream fin("admindata",ios::binary);
    while(fin.read((char*)&temp,sizeof(admin)))
    {
        if(!strcmp(temp.username,str))
        {
            fin.close();
            return temp;
        }
    }
    fin.close();
    throw 0;
}
void admin::show_admin_menu(void)
{
    char option;
    while(1)
    {
        system("cls");
        cout<<"\t\tWelcome To Your Admin Menu !!\n\n";
        cout<<"Choose Option :-\n\n";
        cout<<"1 - Give Coins\n2 - Change Password\n3 - Show Personal Details\n4 - List All Users\n\tBackspace - Exit\n";
        option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            give_coins();
            hold();
            break;
        case '2':
            change_password();
            hold();
            break;
        case '3':
            show_basic_details();
            hold();
            break;
        case '4':
            show_all_users();
            hold();
            break;
        case 8:
            return;
        }
    }
}
void admin::show_all_users(void)
{
    user temp;
    ifstream fin("userdata",ios::binary);
    while(fin.read((char*)&temp,sizeof(user)))
    {
        temp.show_basic_details();
        temp.show_coin_balance();
        temp.show_creds();
        cout<<endl;
    }
    fin.close();
}
class super:public admin
{
public:
    super();
    void create_new_admin(void);
    void reset_casino(void);
    void login(void);
    void show_super_menu(void);
    super get_super_by_username(const char *);
    void commit_to_superfile(const super &s);
    void show_all_admins(void);
};
super::super()
{
    ifstream fin;
    fin.open("superadmindata",ios::binary);
    if(fin)
    {
        fin.close();
        return;
    }
    ofstream fout;
    fout.open("superadmindata",ios::binary);

    super temp;

    strcpy(temp.fname,"Super");
    strcpy(temp.lname,"Admin");
    temp.gender='o';
    temp.age=0;
    strcpy(temp.username,"admin");
    strcpy(temp.password,"password");
    fout.write((char*)&temp,sizeof(super));
    fout.close();
}
void super::create_new_admin(void)
{
    char str[30],pw[30];
    admin temp;
    int found=0;
    do
    {
        cout<<"Enter Admin Username : ";
        cin>>str;
        ifstream fin;
        fin.open("admindata",ios::binary);
        while(fin.read((char*)&temp,sizeof(admin)))
        {
            found=0;
            if(!strcmp(temp.username,str))
            {
                cout<<"Admin Already Exits !!\n";
                found=1;
                break;
            }
        }
        fin.close();
    }while(found);
    strcpy(temp.username,str);
    do
    {
        cout<<"Enter Password : ";
        cin>>str;
        cout<<"Re-Enter Password : ";
        cin>>pw;
        if(strcmp(str,pw))
            cout<<"Passwords do not match !! Try Again\n";
    }while(strcmp(str,pw));
    strcpy(temp.password,pw);
    temp.read_basic_details();
    ofstream fout("admindata",ios::app|ios::binary);
    fout.write((char*)&temp,sizeof(admin));
    fout.close();
    cout<<"\nAdmin Successfully Created !!";
}
void super::show_all_admins(void)
{
    admin temp;
    ifstream fin("admindata",ios::binary);
    while(fin.read((char*)&temp,sizeof(admin)))
    {
        temp.show_basic_details();
        temp.show_creds();
        cout<<endl;
    }
    fin.close();
}
void super::commit_to_superfile(const super &s)
{
    super temp;
    fstream fp;
    int cnt=0;
    fp.open("superadmindata",ios::ate|ios::in|ios::out|ios::binary);
    fp.seekg(ios::beg);
    while(fp.read((char*)&temp,sizeof(super)))
    {
        cnt++;
        if(!strcmp(s.username,temp.username))
            break;
    }
    cnt=(cnt-1)*sizeof(super);
    fp.seekp(cnt);
    fp.write((char*)&s,sizeof(super));
    fp.close();
}
void super::reset_casino(void)
{
    cout<<"Do you want to Reset The Casino !! (Backspace - Back , Any Other Key to reset)\n";
    char option=getch();
    if(option==8)
        return;
    ofstream fout;
    fout.open("userdata",ios::binary);
    fout.close();
    fout.open("admindata",ios::binary);
    fout.close();
    fout.open("superadmindata",ios::binary);

    super temp;

    strcpy(temp.fname,"Super");
    strcpy(fname,"Super");

    strcpy(temp.lname,"Admin");
    strcpy(lname,"Admin");

    temp.gender='o';
    gender='o';

    temp.age=0;
    age=0;

    strcpy(temp.username,"admin");
    strcpy(username,"admin");

    strcpy(temp.password,"password");
    strcpy(password,"password");

    fout.write((char*)&temp,sizeof(super));
    fout.close();
    cout<<"\nCasino Reset Successful !!";
}
super super::get_super_by_username(const char *str)
{
    super temp;
    ifstream fin("superadmindata",ios::binary);
    while(fin.read((char*)&temp,sizeof(super)))
    {
        if(!strcmp(temp.username,str))
        {
            fin.close();
            return temp;
        }
    }
    fin.close();
    throw 0;
}
void super::login(void)
{
    char usr[20];
    super temp;
    cout<<"\t\tWelcome To Super Admin Login Panel !!\n\n";
    cout<<"Enter Username : ";
    cin>>usr;
    try
    {
        temp=get_super_by_username(usr);
    }
    catch(int)
    {
        cout<<"\nUsername not found !!";
        hold();
        return;
    }
    cout<<"Enter Password : ";
    cin>>usr;
    if(!strcmp(usr,temp.password))
    {
        temp.show_super_menu();
        commit_to_superfile(temp);
    }
    else
    {
        cout<<"\nWrong Password !! Access denied !!";
        hold();
    }
}
void super::show_super_menu(void)
{
    char option;
    while(1)
    {
        system("cls");
        cout<<"\t\tWelcome To Super Admin Menu !!\n\n";
        cout<<"Choose Option:-\n\n";
        cout<<"1 - Show Basic Admin Menu\n2 - Add New Admin\n3 - List All Admins\n4 - Reset Casino\n\tBackspace - Exit\n";
        option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            show_admin_menu();
            break;
        case '2':
            create_new_admin();
            hold();
            break;
        case '3':
            show_all_admins();
            hold();
            break;
        case '4':
            reset_casino();
            hold();
            break;
        case 8:
            return;
        }
    }
}
int main()
{
    char option;
    user u;
    admin a;
    super s;
    while(1)
    {
        system("cls");
        cout<<"\t\tWelcome To Home Casino by VD !!\n\n";
        cout<<"Choose Option :-\n\n";
        cout<<"1 - Create New User\n2 - Login User\n3 - Login Admin\n4 - Login Super Admin\n5 - Search User ID\n\tBackspace - Exit\n";
        option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            u.create_new_user();
            hold();
            break;
        case '2':
            u.login();
            break;
        case '3':
            a.login();
            break;
        case '4':
            s.login();
            break;
        case '5':
            u.show_user_by_name();
            hold();
            break;
        case 8:
            return 0;
        }
    }
}
