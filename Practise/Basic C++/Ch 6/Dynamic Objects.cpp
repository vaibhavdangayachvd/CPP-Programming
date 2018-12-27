#include<iostream>
#include<string.h>
using namespace std;
class student
{
    char *name;
public:
    student(){name = new char;}
    student(char *n)
    {
        int len=strlen(n);
        name=new char[len+1];
        strcpy(name,n);
    }
    student(student &,student &);
    void display(void){cout<<name<<endl;}
};
student::student(student &first,student &last)
{
    delete name;
    int len=strlen(first.name)+strlen(last.name);
    name=new char[len+2];
    strcpy(name,first.name);
    name=strcat(name," ");
    name=strcat(name,last.name);
}
int main()
{
    student first=student("Vaibhav");
    student last=student("Dangayach");
    student full=student(first,last);
    first.display();
    last.display();
    full.display();
    return 0;
}
