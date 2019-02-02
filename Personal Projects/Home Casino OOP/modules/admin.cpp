#include "..\\headers\\admin.h"
//using namespace std;
admin::admin()
{
    ifstream fin;
    fin.open("database\\admindata",ios::binary);
    if(fin)
    {
        fin.close();
        return;
    }
    ofstream fout;
    fout.open("database\\admindata",ios::binary);
    fout.close();
}
void admin::create_new_admin(void)const
{
    char str[30],pw[30];
    admin temp;
    int found=0;
    do
    {
        cout<<"Enter Admin Username : ";
        cin>>str;
        ifstream fin;
        fin.open("database\\admindata",ios::binary);
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
        get_password(str);
        cout<<"Re-Enter Password : ";
        get_password(pw);
        if(strcmp(str,pw))
            cout<<"Passwords do not match !! Try Again\n";
    }while(strcmp(str,pw));
    strcpy(temp.password,pw);
    temp.read_basic_details();
    ofstream fout("database\\admindata",ios::app|ios::binary);
    fout.write((char*)&temp,sizeof(admin));
    fout.close();
    cout<<"\nAdmin Successfully Created !!";
}
void admin::update_basic_details(void)
{
    read_basic_details();
    cout<<"\nDetails Updated !!";
}
//Show Credentials
void admin::show_credentials(void)const
{
    cout<<"Username : "<<username<<endl;
    cout<<"Password : "<<password<<endl;
}
//Change Password
void admin::change_password(void)
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
    cout<<"\nNew Password Set !!";
}
//Commit object to file
void admin::commit_to_adminfile(const admin &a)
{
    admin temp;
    fstream fp;
    int cnt=0;
    fp.open("database\\admindata",ios::ate|ios::in|ios::out|ios::binary);
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
//Display All admins details
void admin::show_all_admins(void)const
{
    admin temp;
    ifstream fin("database\\admindata",ios::binary);
    while(fin.read((char*)&temp,sizeof(admin)))
    {
        temp.show_basic_details();
        temp.show_credentials();
        cout<<endl;
    }
    fin.close();
}
//Return object of admin if found else throw bool exception
admin admin::get_admin_by_username(const char *str)
{
    admin temp;
    ifstream fin("database\\admindata",ios::binary);
    while(fin.read((char*)&temp,sizeof(admin)))
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
//Give Coins to specified user
void admin::give_coins(void)
{
    user temp;
    char str[20];
    cout<<"Enter username of receiver : ";
    cin>>str;
    try
    {
        temp=user::get_user_by_username(str);
    }
    catch(bool)
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
    user::commit_to_userfile(temp);
    cout<<"\nCoins Transferred !!";
}
//Login and return admin object else throw bool exception
admin admin::login(void)
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
    catch(bool)
    {
        cout<<"\nUsername not found !!";
        hold();
        throw;
    }
    cout<<"Enter Password : ";
    get_password(usr);
    if(!strcmp(usr,temp.password))
        return temp;
    else
    {
        cout<<"\nWrong Password !! Access denied !!";
        hold();
        throw false;
    }
}
//Display admin menu untill backspace is pressed
void admin::show_admin_menu(void)
{
    char option;
    while(1)
    {
        system("cls");
        cout<<"\t\tWelcome To Your Admin Menu !!\n\n";
        cout<<"Choose Option :-\n\n";
        cout<<"1 - Give Coins\n2 - Change Password\n3 - Show Personal Details\n4 - Update Personal Details\n5 - List All Users\n\tBackspace - Logout/Back\n";
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
			commit_to_adminfile(*this);
            hold();
            break;
        case '3':
            show_basic_details();
            hold();
            break;
        case '4':
            update_basic_details();
			commit_to_adminfile(*this);
            hold();
            break;
        case '5':
            user::show_all_users();
            hold();
            break;
        case 8:
            return;
        }
    }
}
