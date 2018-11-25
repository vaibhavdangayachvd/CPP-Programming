#include<iostream>
using namespace std;
class time
{
private:
    int hours;
    int minutes;
public:
    void get_time(int hours,int minutes);
    void put_time(void);
    void sum_time(time t1,time t2);
};
inline void time::get_time(int h,int m)
{
    hours=h,minutes=m;
}
inline void time::put_time(void)
{
    cout<<"Hours "<<hours<<" Minutes : "<<minutes<<endl;
}
void time::sum_time(time t1,time t2)
{
    minutes=t1.minutes+t2.minutes;
    hours=minutes/60;
    minutes=minutes%60;
    hours+=t1.hours+t2.hours;
}
int main()
{
    time t1,t2,t3;
    t1.get_time(2,45);
    t2.get_time(2,15);
    t3.sum_time(t1,t2);
    t1.put_time();
    t2.put_time();
    t3.put_time();
    return 0;
}
