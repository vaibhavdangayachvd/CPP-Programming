#include<iostream>
using namespace std;
class student
{
private:
    string name;
    int roll;
public:
    void add_std(void);
    void get_std(void);
};
void student::add_std(void)
{
    cout<<"Enter Name : ";
    cin>>name;
    cout<<"Enter Roll : ";
    cin>>roll;
}
inline void student::get_std(void){cout<<"\nYou name is "<<name<<" and your roll number is "<<roll;}
int main()
{
    student std1;
    std1.add_std();
    std1.get_std();
    return 0;
}
