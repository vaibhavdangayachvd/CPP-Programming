#include<iostream>
#include<cstdlib>
#include<conio.h>
#include "implementation\\game_settings.cpp"
void show_update_menu();
int main()
{
    game_settings * ins=game_settings::get_instance();
    while(true)
    {
        system("cls");
        std::cout<<"Choose Option :-\n\n1 - Update Settings\n2 - View Settings\n3 - Reset Settings\n\tBackspace - Exit\n";
        char option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            show_update_menu();
            break;
        case '2':
            ins->display_settings();
            getch();
            break;
        case '3':
            ins=game_settings::reset_settings();
            std::cout<<"Settings Reset Successful !!";
            getch();
            break;
        case 8:
            delete ins;
            return 0;
        }
    }
}
void show_update_menu()
{
    game_settings * ins=game_settings::get_instance();
    while(true)
    {
        system("cls");
        std::cout<<"Choose edit :-\n\n1 - Width\n2 - Height\n3 - Brightness\n\tBackspace - Back\n";
        char option=getch();
        system("cls");
        int temp;
        switch(option)
        {
        case '1':
            std::cout<<"Enter new width : ";
            std::cin>>temp;
            ins->set_width(temp);
            std::cout<<"\n New Width set !!";
            getch();
            break;
        case '2':
            std::cout<<"Enter new height : ";
            std::cin>>temp;
            ins->set_height(temp);
            std::cout<<"\nNew Height set !!";
            getch();
            break;
        case '3':
            std::cout<<"Enter new brightness : ";
            std::cin>>temp;
            ins->set_brightness(temp);
            std::cout<<"\nNew Brightness set !!";
            getch();
            break;
        case 8:
            return;
        }
    }
}

