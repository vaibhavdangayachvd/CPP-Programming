#include<iostream>
#include<conio.h>
using namespace std;
class _date;
class _date
{
    int date;
    int month;
    int year;
    static int max_days[13];
public:
    inline void print_date(void)
    {
        cout<<date<<"/"<<month<<"/"<<year;
    }
    inline void print_date(int date,int month,int year)
    {
        cout<<date<<"/"<<month<<"/"<<year;
    }
    void set_date(void);
    void print_date_after(int days);
};
void _date::set_date(void)
{
    date=0,month=0,year=0;
    do
    {
        cout<<"Input Today's Date(d m yyyy) : ";
        cin>>date>>month>>year;
        if(month<=12 && month>=1)//Set max days of Feb
        {
            if((year%4==0)&&(year%100!=0)||(year%400==0))//Check for leap year
                max_days[2]=29;
            else
                max_days[2]=28;
        }
        if((month>12||month<1)||(date<1 ||date>max_days[month]))
            cout<<"Wrong Input !!\n";
    }
    while((month>12||month<1)||(date<1 ||date>max_days[month]));
}
int _date::max_days[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
void _date::print_date_after(int days)
{
    int d=date,y=year,m=month;
    for(int i=days;i>0;--i)
    {
        if(d<max_days[m])//If days are left in a month
            ++(d);
        else if(m<12)//If month are left in a year
        {
            ++(m);
            d=1;
        }
        else//Goto next year
        {
            y++;
            m=1;
            d=1;
            if((y%4==0)&&(y%100!=0)||(y%400==0))
                max_days[2]=29;
            else
                max_days[2]=28;
        }
    }
    print_date(d,m,y);
}
int main()
{
    _date today;
    today.set_date();
    int days;
    cout<<"Enter number of days to skip : ";
    cin>>days;
    cout<<"Next Date : ";
    today.print_date_after(days);
    cout<<"\n\n\tPress Enter to exit...";
    getch();
    return 0;
}
