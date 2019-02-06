#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<conio.h>
#include "..\\headers\\user.h"
#include "..\\headers\\game_menu.h"
#include "..\\headers\\extras.h"
using namespace std;
user::user()
{
    ifstream fin;
    fin.open("database\\userdata",ios::binary);
    if(fin)
    {
        fin.close();
        return;
    }
    ofstream fout;
    fout.open("database\\userdata",ios::binary);
    fout.close();
}
void user::create_new_user(void)
{
    read_basic_details();//Call base class read basic details function
    char str[30],pw[30];
    user temp;
    int found=0;
    //Check if user name already exist
    do
    {
        cout<<"Enter username(type exit to go back): ";
        cin>>str;
        if(!strcmp(str,"exit"))
            return;
        ifstream fin;
        fin.open("database\\userdata",ios::binary);
        while(fin.read((char*)&temp,sizeof(user)))
        {
            found=0;
            if(!strcmp(temp.username,str))//If match found
            {
                cout<<"User Already Exits !!\n";
                found=1;
                break;
            }
        }
        fin.close();
    }while(found);
    strcpy(username,str);
    //Read Password
    do
    {
        cout<<"Enter Password : ";
        get_password(str);
        cout<<"Re-Enter Password : ";
        get_password(pw);
        if(strcmp(str,pw))
            cout<<"Passwords do not match !! Try Again\n";
    }while(strcmp(str,pw));
    strcpy(password,pw);
    coin_balance=500;
    ofstream fout("database\\userdata",ios::app|ios::binary);
    fout.write((char*)this,sizeof(user));
    fout.close();
    cout<<"\nUser Successfully Created !!";
}
//Display All User Details
void user::show_all_users(void)
{
    user temp;
    ifstream fin("database\\userdata",ios::binary);
    while(fin.read((char*)&temp,sizeof(user)))
    {
        temp.show_basic_details();
        temp.show_coin_balance();
        temp.show_credentials();
        cout<<endl;
    }
    fin.close();
}
//Give Specified Coins
void user::add_coins(int coins)
{
	coin_balance+=coins;
}
void user::take_coins(int coins)
{
    if(coins>coin_balance)
    {
        cout<<"Not enough Coins !!";
        return;
    }
    coin_balance-=coins;
}
int user::set_bet(void)const
{
    int bet;
    do
    {
        cout<<"\nEnter Bet amount >= 50 (character to exit) : ";
        cin>>bet;
        if(cin.fail())
        {
            cout<<"\nThanks for Playing !!";
            cin.clear();
            cin.sync();
            hold();
            throw false;
        }
        if(bet<50 || bet>coin_balance)
            cout<<"Wrong Amount !!\n";
    }
    while(bet<50 || bet>coin_balance);
    cout<<"Bet Set !!\n\n";
    //cin.sync();
    return bet;
}
//Update password
void user::change_password(void)
{
    char pw[20],pwr[20];
    cout<<"Enter Current Password : ";
    get_password(pw);
    if(strcmp(password,pw))
    {
        cout<<"\nWrong Password !!";
        return;
    }
    do
    {
        cout<<"Enter New Password : ";
        get_password(pw);
        cout<<"Re-Enter New Password : ";
        get_password(pwr);
        if(strcmp(pw,pwr))
            cout<<"Passwords do not match !! Try Again\n";
    }while(strcmp(pw,pwr));
    strcpy(password,pwr);
    commit_to_userfile(*this);
    cout<<"\nNew Password Set !!";
}
//Update Basic details using base class function and commit
void user::update_basic_details()
{
    read_basic_details();
    commit_to_userfile(*this);
    cout<<"\nDetails Updated !!";
}
//Show username and using name
void user::show_user_by_name(void)
{
    char str[20];
    user temp;
    int found=0;
    cout<<"Enter first name to search : ";
    cin>>str;
    ifstream fin("database\\userdata",ios::binary);
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
//Show username and password
void user::show_credentials(void) const
{
    cout<<"Username : "<<username<<endl;
    cout<<"Password : "<<password<<endl;
}
int user::get_coin_balance(void)const
{
    return coin_balance;
}
//Display Coin Balance
void user::show_coin_balance(void)const
{
    cout<<"Coin Balance : "<<coin_balance<<endl;
}
//Read The File until the user name is found else throw bool exception
user user::get_user_by_username(const char *str)
{
    user temp;
    ifstream fin("database\\userdata",ios::binary);
    while(fin.read((char*)&temp,sizeof(user)))
    {
        if(!strcmp(temp.username,str))
        {
            fin.close();
            return temp;
        }
    }
    fin.close();
    throw false;
}
//Count the users and update the file
void user::commit_to_userfile(const user &u)
{
    user temp;
    fstream fp;
    int cnt=0;
    fp.open("database\\userdata",ios::ate|ios::in|ios::out|ios::binary);
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
//Login and return user object else throw bool flag
user user::login(void)
{
    char usr[20];
    user temp;
    cout<<"\t\tWelcogameme To User Login Panel !!\n\n";
    cout<<"Enter Username : ";
    cin>>usr;
    try
    {
        temp=get_user_by_username(usr);
    }
    catch(bool)
    {
        cout<<"\nUsername not found !!";
        hold();
        //Re throw exception in main
        throw;
    }
    cout<<"Enter Password : ";
    get_password(usr);
    //If login Successful
    if(!strcmp(usr,temp.password))
    {
        temp.add_coins(25);//Give 25 bonus coins
        return temp;
    }
    else
    {
        cout<<"\nWrong Password !! Access denied !!";
        hold();
        throw false;
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
        cout<<"1 - Open Casino\n2 - Show Personal Details\n3 - Update Basic Details\n4 - Change Password\n\tBackspace - Logout\n";
        option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            show_game_menu(this);
            break;
        case '2':
            show_basic_details();
            show_coin_balance();
            hold();
            break;
        case '3':
            update_basic_details();
            hold();
            break;
        case '4':
            change_password();
            hold();
            break;
        case 8:
            return;
        }
    }
}
