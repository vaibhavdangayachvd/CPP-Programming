#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include "..\\headers\\up_down.h"
#include "..\\headers\\extras.h"
using namespace std;
void up_down::show_rules(void)
{
    cout<<"\n\n\t\tRules\n\n";
    cout<<"Choose a bet from 50 onwards. If you win , you get double the amount !!";
    hold();
    system("cls");
}
bool up_down::play(void)
{
    cout<<"Choose :-\n\n1 - 7Up\n2 - 7Down\n";
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
    int dice1=(rand()*101)%6;
	int dice2=(rand()*101)%6;
    cout<<"Result : ";
    if(dice1+dice2+2 > 7)
        cout<<"7Up("<<dice1+dice2+2<<") :- ";
	else if(dice1+dice2+2 < 7)
        cout<<"7Down("<<dice1+dice2+2<<") :- ";
    if(choice==1 && dice1+dice2+2 > 7 || choice==2 && dice1+dice2+2 <7)
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
