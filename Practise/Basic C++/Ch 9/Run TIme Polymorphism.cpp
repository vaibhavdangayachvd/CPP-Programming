#include<iostream>
using namespace std;
class student
{
protected:
    string name;
    int roll;
public:
    student(string n,int r){name=n,roll=r;}
    virtual void show(void){}
};
class marks:public student
{
    int mat;
    int sci;
public:
    marks(string n,int r,int m,int s):student(n,r)
    {
        mat=m;
        sci=s;
    }
    void show(void)
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Roll : "<<roll<<endl;
        cout<<"Maths : "<<mat<<endl;
        cout<<"Science : "<<sci<<endl;
    }
};
class hobbies:public student
{
    string hob;
public:
    hobbies(string n,int r,string h):student(n,r){hob=h;}
    void show(void)
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Roll : "<<roll<<endl;
        cout<<"Hobbie : "<<hob<<endl;
    }
};
int main()
{
    marks m1("Vaibhav",57,12,12);
    hobbies m2("Harsh",23,"Gaming");
    student *ptr[2];
    ptr[0]=&m1;
    ptr[1]=&m2;
    ptr[0]->show();
    cout<<endl;
    ptr[1]->show();
}
