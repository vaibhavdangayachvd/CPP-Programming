#include<iostream>
using namespace std;
class students
{
    string name;
    int roll;
    friend void show_details(students);
public:
    void set_details(string,int);
};
inline void students::set_details(string n,int r)
{
    name=n,roll=r;
}
inline void show_details(students s)
{
    cout<<"Name : "<<s.name<<endl<<"Roll : "<<s.roll<<endl;
}
int main()
{
    students st1;
    st1.set_details("Vaibhav",56);
    show_details(st1);
    return 0;
}
