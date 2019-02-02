#include "..\\headers\\super.h"
using namespace std;
super::super()
{
    ifstream fin;
    fin.open("database\\superdata",ios::binary);
    if(fin)
    {
        fin.close();
        return;
    }
    ofstream fout;
    fout.open("database\\superdata",ios::binary);

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
void super::commit_to_superfile(const super &s)
{
    super temp;
    fstream fp;
    int cnt=0;
    fp.open("database\\superdata",ios::ate|ios::in|ios::out|ios::binary);
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
    char pw[20];
    cout<<"Enter Password to continue : ";
    get_password(pw);
    if(strcmp(pw,password))
    {
        cout<<"\nIncorrect Password !!";
        return;
    }
	cout<<"Press Enter to reset !! ( Backspace to go back) \n";
    char option=getch();
    if(option==8)
        return;
	//Reset Values
	strcpy(fname,"Super");
    strcpy(lname,"Admin");
    gender='o';
    age=0;
    strcpy(username,"admin");
    strcpy(password,"password");
    //Updates Files
	ofstream fout;
    fout.open("database\\userdata",ios::binary);
    fout.close();
    fout.open("database\\admindata",ios::binary);
    fout.close();
    fout.open("database\\superdata",ios::binary);
    fout.write((char*)this,sizeof(super));
    fout.close();
    cout<<"\nCasino Reset Successful !!";
}
//Return super object else throw bool exception
super super::get_super_by_username(const char *str)
{
    super temp;
    ifstream fin("database\\superdata",ios::binary);
    while(fin.read((char*)&temp,sizeof(super)))
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
//Try to login if successful return super object else throw bool exception
super super::login(void)
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
void super::show_super_menu(void)
{
    char option;
    while(1)
    {
        system("cls");
        cout<<"\t\tWelcome To Super Admin Menu !!\n\n";
        cout<<"Choose Option:-\n\n";
        cout<<"1 - Give Coins\n2 - List All Users\n3 - Add New Admin\n4 - List All Admins\n5 - Show Personal Details\n6 - Update Personal Details\n7 - Change Password\n8 - Reset Casino\n\tBackspace - Logout\n";
        option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            give_coins();
			hold();
            break;
		case '2':
			user::show_all_users();
            hold();
            break;
        case '3':
            create_new_admin();
            hold();
            break;
		case '4':
            show_all_admins();
            hold();
            break;
		case '5':
            show_basic_details();
            hold();
            break;
        case '6':
            update_basic_details();
			commit_to_superfile(*this);
            hold();
            break;
		case '7':
            change_password();
			commit_to_superfile(*this);
            hold();
            break;
        case '8':
            reset_casino();
            hold();
            break;
        case 8:
            return;
        }
    }
}
