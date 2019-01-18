//Include Header Files
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<conio.h>
#include<direct.h>
//Include Modules
#include "modules\\extras.h"
#include "modules\\person.h"
#include "modules\\user.h"
#include "modules\\admin.h"
#include "modules\\super.h"
using namespace std;
int main()
{
    mkdir("database");
    user u;
    admin a;
    super s;
    //While Backspace is not pressed
    //Login Function throw boolean exception if not successful
    while(1)
    {
        system("cls");
        cout<<"\t\tWelcome To Home Casino by VD !!\n\n";
        cout<<"Choose Option :-\n\n";
        cout<<"1 - Create New User\n2 - Login User\n3 - Login Admin\n4 - Login Super Admin\n5 - Search User ID\n\tBackspace - Exit\n";
        char option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            u.create_new_user();
            hold();
            break;
        case '2':
            try
            {
                u=user::login();
            }
            catch(bool)
            {
                break;
            }
            u.show_user_menu();//Open User Panel
            break;
        case '3':
            try
            {
                a=admin::login();
            }
            catch(bool)
            {
                break;
            }
            a.show_admin_menu();
            break;
        case '4':
            try
            {
                s=super::login();
            }
            catch(bool)
            {
                break;
            }
            s.show_super_menu();
            break;
        case '5':
            user::show_user_by_name();
            hold();
            break;
        case 8:
            return 0;
        }
    }
}
