#include<iostream>
#include<cstdlib>
#include<conio.h>
#include "..\\headers\\user.h"
#include "..\\headers\\head_tail.h"
#include "..\\headers\\extras.h"
using namespace std;
void show_game_menu(user *u)
{
    game_base *ptr;
    while(1)
    {
        system("cls");
        cout<<"\t\tWelcome to Casino !! Here you can play !!\n\n";
        cout<<"Choose Option:-\n\n";
        cout<<"1 - Head Tail\n2 - Stone Paper Scissor\n3 - 7Up7Down\n\tBackspace - Exit\n";
        char option=getch();
        int bet;
        system("cls");
        switch(option)
        {
    case '1':
            ptr=new head_tail;
            ptr->show_rules();
            while(1)
            {
                u->show_coin_balance();
                try
                {
                    bet=u->set_bet();
                }
                catch(bool)
                {
                    break;
                }
                if(ptr->play())
                    u->add_coins(bet);
                else
                    u->take_coins(bet);
                user::commit_to_userfile(*u);
                hold();
                system("cls");
            }
            break;
        case 8:
            return;
        }
    }
}
