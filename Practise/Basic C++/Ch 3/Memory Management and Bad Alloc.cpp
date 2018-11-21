#include<iostream>
#include<cstring>
using namespace std;
class student
{
private:
    char name[30];
    int roll;
public:
    void enter(char a[],int b)
    {
        strcpy(name,a);
        roll=b;
    }
    void display(void)
    {
        cout<<"Name : "<<name<<"\nRoll : "<<roll;
    }
};
int main()
{
    char name[20];
    student *std1;
    try
    {
        std1=new student;
    }
    catch(bad_alloc ba)
    {
        cout<<"Memory Not Availabe !!";
        return 0;
    }
    strcpy(name,"Vaibhav");
    std1->enter(name,56);
    std1->display();
    delete std1;
    return 0;
}
