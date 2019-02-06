#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include "..\\headers\\head_tail.h"
#include "..\\headers\\extras.h"
using namespace std;
void head_tail::show_rules(void)
{
    cout<<"\n\n\t\tRules\n\n";
    cout<<"Choose a bet from 50 onwards. If you win , you get double the amount !!";
    hold();
    system("cls");
}
bool head_tail::play(void)
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
