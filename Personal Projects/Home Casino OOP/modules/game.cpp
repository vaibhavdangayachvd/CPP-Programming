#include "..\\headers\\game.h"
void game::show_head_tail_rules(void)
{
    cout<<"\n\n\t\tRules\n\n";
    cout<<"Choose a bet from 50 onwards. If you win , you get double the amount !!";
    hold();
    system("cls");
}
bool game::play_head_tail(void)
{
    cout<<"Choose :-\n\n1 - Head\n2 - Tail\n";
    int choice;
    do
    {
        char option=getch();
        switch(option)
        {
        case '1':
            choice=1;
            break;
        case '2':
            choice=2;
            break;
        default :
            choice=0;
        }
    }
    while(!choice);
    srand(time(0));
    int out=(rand()*101)%2;
    cout<<"Result : ";
    switch(out)
    {
    case 0:
        cout<<"Head :- ";
        break;
    case 1:
        cout<<"Tail :- ";
        break;
    }
    if(choice==out+1)
    {
        cout<<"You win !!"<<endl;
        return true;
    }
    else
    {
        cout<<"You Loose !!"<<endl;
        return false;
    }
}
