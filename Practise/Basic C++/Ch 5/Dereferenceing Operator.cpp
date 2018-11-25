#include<iostream>
using namespace std;
class student
{
private:
    string name;
    int roll;
public:
    void set_details(string n,int r){name=n,roll=r;}
    friend void get_details(student);
};
void get_details(student st)
{
    int student::*pr=&student::roll;
    string student::*pn=&student::name;
    cout<<"Name : "<<st.*pn<<endl<<"Roll Number : "<<st.*pr<<endl;
}
int main()
{
    student st;
    void (student::*pf)(string,int)=&student::set_details;
    student *ptr=&st;
    (ptr->*pf)("Vaibhav",56);
    get_details(*ptr);
    return 0;
}
