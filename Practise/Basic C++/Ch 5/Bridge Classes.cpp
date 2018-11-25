#include<iostream>
using namespace std;
class manager;
class worker
{
    int salary;
public:
    void set_salary(int a){salary=a;}
    friend void sum_salary(manager,worker);
};
class manager
{
    int salary;
public:
    void set_salary(int a){salary=a;}
    friend void sum_salary(manager,worker);
};
void sum_salary(manager m,worker w)
{
    cout<<"Total salary : "<<m.salary+w.salary<<endl;
}
int main()
{
    manager m;
    worker w;
    m.set_salary(3000);
    w.set_salary(2000);
    sum_salary(m,w);
    return 0;
}
