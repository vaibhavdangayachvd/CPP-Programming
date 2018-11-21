#include<iostream>
using namespace std;
class student
{
    int roll;
    char name[30];
public:
    void get_details(void);
    void print_details(void);
};
void student :: get_details(void)
{
    cout << "Enter Roll Number : ";
    cin >> roll;
    cout << "Enter Name : ";
    cin >> name;
}
void student :: print_details(void)
{
    cout << "\nYour name is " << name << " and your roll number is " << roll << "\n";
}
int main()
{
    student std1;
    std1.get_details();
    std1.print_details();
    return 0;
}
