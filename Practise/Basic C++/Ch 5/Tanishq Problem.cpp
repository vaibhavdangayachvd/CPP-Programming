#include<iostream>
#include<cstdlib>
using namespace std;
class dist
{
private:
    int feets;
    int inches;
public:
    void get_dist(void);
    void print_dist(void) const;
    void print_dist(int) const;
    void sum(dist,dist);
};
void dist::get_dist(void)
{
    cout<<"Enter Distance in Feet : ";
    cin>>feets;
    do
    {
        cout<<"Enter Distance in Inches : ";
        cin>>inches;
        if(inches>11)
            cout<<"Wrong Input !! Try Again"<<endl;
    }while(inches>11);
    cout<<endl;
}
inline void dist::print_dist(void) const
{
    cout<<"Distance is "<<feets<<" Feets"<<" and "<<inches<<" Inches"<<endl;
}
inline void dist::print_dist(int) const
{
    cout<<endl<<"Sum of Distance is "<<feets<<" Feets"<<" and "<<inches<<" Inches"<<endl;
}
void dist::sum(const dist d1,const dist d2)
{
    inches=d1.inches+d2.inches;
    if(inches>12)
    {
        inches-=12;
        feets++;
    }
    feets+=d1.feets+d2.feets;
}
int main()
{
    dist d1,d2,d3;
    d1.get_dist();
    d2.get_dist();
    d3.sum(d1,d2);
    d1.print_dist();
    d2.print_dist();
    d3.print_dist(1);
    return 0;
}
