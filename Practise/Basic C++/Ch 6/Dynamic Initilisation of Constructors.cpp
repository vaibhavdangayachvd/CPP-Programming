#include<iostream>
using namespace std;
class time
{
    int hour;
    int minute;
    int second;
public:
    time(int h=12,int m=12,int s=12){hour=h,minute=m,second=s;}
    void display(void){cout<<hour<<":"<<minute<<":"<<second<<endl;}
};
int main()
{
    time t1;
    int h,m,s;
    cout<<"Enter time : ";
    cin>>h>>m>>s;
    t1=time(h,m,s);
    t1.display();
    return 0;
}
