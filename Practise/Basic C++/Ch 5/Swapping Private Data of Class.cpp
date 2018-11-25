#include<iostream>
using namespace std;
class worker;
class ceo
{
    int salary;
public:
    void set_salary(int s){salary=s;}
    void put_salary(void){cout<<"Salary : "<<salary<<endl;}
    friend ceo swap_sal(ceo &,worker &);
};
class worker
{
    int salary;
public:
    void set_salary(int s){salary=s;}
    void put_salary(void){cout<<"Salary : "<<salary<<endl;}
    friend ceo swap_sal(ceo &,worker &);
};
ceo swap_sal(ceo &c,worker &w)
{
    ceo baby;
    int temp=c.salary;
    c.salary=w.salary;
    w.salary=temp;
    baby.salary=c.salary+w.salary;
    return baby;
}
int main()
{
    ceo total,c;
    worker w;
    w.set_salary(1000);
    c.set_salary(4000);
    total=swap_sal(c,w);
    total.put_salary();
    w.put_salary();
    c.put_salarys();
    return 0;
}
