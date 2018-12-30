#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
void hold_screen(void);
void hold_screen(void)
{
    cout<<"\n\n\tPress Enter to continue...";
    getch();
}
class vehicle
{
protected:
    string name;
    int price;
public:
    vehicle(string n,int p);
    void show_basic_details(void);
    void update_basic_details(void);
};
vehicle::vehicle(string n,int p)
{
    name=n;
    price=p;
}
void vehicle::show_basic_details(void)
{
    cout<<"Name : "<<name<<endl;
    cout<<"Price : "<<price<<endl;
}
void vehicle::update_basic_details(void)
{
    char option;
    while(1)
    {
        system("cls");
        cout<<"Choose what you want to update :-\n\n";
        cout<<"1 - Name\n2 - Price\n\\n\tBackspace - Back\n";
        option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            cout<<"Enter New Name : ";
            cin>>name;
            cout<<"\nName Updated !!";
            hold_screen();
            break;
        case '2':
            cout<<"Enter New Price : ";
            cin>>price;
            cout<<"\nPrice Updated !!";
            hold_screen();
            break;
        }
        if(option=='8')
            break;
    }
}
class electric
{
protected:
    int power;
    int battery;
public:
    electric(int p,int b){battery=b,power=p;}
    void show_stats(void);
};
void electric::show_stats(void)
{
    cout<<"Power : "<<power<<endl;
    cout<<"Battery : "<<battery<<endl;
}
class non_electric
{
protected:
    int mileage;
public:
    non_electric(int m){mileage=m;}
    void show_mileage(void);
};
void non_electric::show_mileage(void)
{
    cout<<"Mileage : "<<mileage<<endl;
}
class manual:public non_electric
{
protected:
    int gears;
public:
    manual(int m,int g):non_electric(m){gears=g;}
    void show_gears(void);
};
void manual::show_gears(void)
{
    cout<<"Gears : "<<gears<<endl;
}
class automatic:public non_electric
{
protected:
    string type;
public:
    automatic(int m,string t):non_electric(m){type=t;}
    void show_type(void);
};
void automatic::show_type(void)
{
    cout<<"Type : "<<type<<endl;
}
class two_wheeler_electric:public vehicle,public electric
{
public:
    two_wheeler_electric(string n,int pr,int po,int b):vehicle(n,pr),electric(po,b){}
    void details(void);
};
void two_wheeler_electric::details(void)
{
    show_basic_details();
    show_stats();
}
class four_wheeler_auto:public vehicle,public automatic
{
public:
    four_wheeler_auto(string n,int pr,int m,string t):vehicle(n,pr),automatic(m,t){}
    void details(void);
};
void four_wheeler_auto::details(void)
{
    show_basic_details();
    show_mileage();
    show_type();
}
int main()
{
    two_wheeler_electric m1("Zapa",12000,120,12);
    m1.details();
    return 0;
}
