#include<iostream>
using namespace std;
class employee
{
private:
    static int emp_count;
    string name;
    int salary;
public:
    void add_details(void);
    void get_details(void);
    static void get_count(void);
};
int employee::emp_count=0;
void employee::get_count(void)
{
    cout<<"Count : "<<emp_count<<endl;
}
void employee::add_details(void)
{
    cout<<"Enter name : ";
    cin>>name;
    cout<<"Enter salary : ";
    cin>>salary;
    ++emp_count;
}
inline void employee::get_details(void)
{
    cout<<"Name : "<<name<<endl<<"Salary : "<<salary<<endl;
}
const int n=3;
int main()
{
    employee manager[n],worker[n];
    manager[0].add_details();
    manager[0].get_details();
    worker[0].add_details();
    worker[0].get_details();
    employee::get_count();
    return 0;
}
